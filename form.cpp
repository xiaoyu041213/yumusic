#include "form.h"
#include "ui_form.h"
#include <QDebug>
#include <QFileInfo>
#include <QMessageBox>
#include <QPushButton>
#include <QDir>
#include <QCoreApplication>
#include <QTimer>
#include "widget.h"
#include "chosesong.h"
#include "showlrc.h"
#include <QAudioOutput>
#include <QUrl>

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);

    connect(player, &QMediaPlayer::positionChanged, this, &Form::onPositionChanged);
    connect(player, &QMediaPlayer::durationChanged, this, &Form::onDurationChanged);
    connect(player, &QMediaPlayer::mediaStatusChanged, this, &Form::onMediaStatusChanged);

    connect(ui->volume_slider, &QSlider::valueChanged, this, &Form::on_volume_slider_valueChanged);
    connect(ui->btn_back, &QPushButton::clicked, this, &Form::on_btn_back_clicked);
    connect(ui->progress_slider, &QSlider::sliderMoved, this, &Form::on_progress_slider_moved);

    ui->volume_slider->setValue(20);
    audioOutput->setVolume(0.2);
    ui->label_volume_value->setText("20");

    choseSongWindow = new ChoseSong();
    choseSongWindow->setPlayer(player);

    connect(ui->btn_chose, &QPushButton::clicked, this, &Form::on_btn_chose_clicked);
    connect(choseSongWindow, &ChoseSong::songSelected, this, &Form::onSongSelected);

    QTimer *lyricTimer = new QTimer(this);
    connect(lyricTimer, &QTimer::timeout, this, [this]() {
        QList<QWidget*> widgets = qApp->topLevelWidgets();
        for (QWidget *widget : widgets) {
            showlrc *window = qobject_cast<showlrc*>(widget);
            if (window && window->isVisible()) {
                window->updateLyric(player->position());
            }
        }
    });
    lyricTimer->start(100);
}

Form::~Form()
{
    delete player;
    delete audioOutput;
    delete ui;
}

void Form::playFile(const QString &filePath)
{
    if (!filePath.isEmpty()) {
        player->setSource(QUrl::fromLocalFile(filePath));
        player->play();
        QFileInfo fileInfo(filePath);
        currentSong = fileInfo.fileName();
        ui->label_song->setText("当前歌曲：" + currentSong);
        loadSongPicture(currentSong);
        qDebug() << "开始播放：" << filePath;
    }
}

void Form::on_btn_chose_clicked()
{
    choseSongWindow->show();
}

void Form::onSongSelected(const QString &songName, const QString &songPath)
{
    Q_UNUSED(songName);
    playFile(songPath);
}

void Form::on_btn_select_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "选择音乐文件",
                                                    "/mnt/hgfs/vmshare/QTmake/player/music",
                                                    "音频文件 (*.mp3 *.wav *.flac *.m4a)");

    if (!filePath.isEmpty()) {
        playFile(filePath);
    }
}

void Form::on_btn_play_clicked()
{
    player->play();
    if (!currentSong.isEmpty()) {
        loadSongPicture(currentSong);
    }
}

void Form::on_btn_pause_clicked()
{
    player->pause();
}

void Form::on_btn_stop_clicked()
{
    player->stop();
}

void Form::on_volume_slider_valueChanged(int value)
{
    audioOutput->setVolume(value / 100.0);
    ui->label_volume_value->setText(QString::number(value));
}

void Form::on_btn_back_clicked()
{
    player->stop();

    QList<QWidget*> widgets = qApp->topLevelWidgets();
    Widget *loginWidget = nullptr;
    for (QWidget *widget : widgets)
    {
        if (widget->inherits("Widget"))
        {
            loginWidget = static_cast<Widget*>(widget);
            break;
        }
    }

    if (!loginWidget)
    {
        loginWidget = new Widget();
    }

    loginWidget->show();
    this->deleteLater();
}

void Form::onPositionChanged(qint64 position)
{
    ui->progress_slider->setValue(position);

    qint64 seconds = position / 1000;
    qint64 minutes = seconds / 60;
    seconds = seconds % 60;
    QString timeStr = QString("%1:%2").arg(minutes, 2, 10, QChar('0'))
                          .arg(seconds, 2, 10, QChar('0'));
    ui->label_time->setText(timeStr);
}

void Form::onDurationChanged(qint64 duration)
{
    ui->progress_slider->setRange(0, duration);

    qint64 seconds = duration / 1000;
    qint64 minutes = seconds / 60;
    seconds = seconds % 60;
    QString timeStr = QString("%1:%2").arg(minutes, 2, 10, QChar('0'))
                          .arg(seconds, 2, 10, QChar('0'));
    ui->label_duration->setText("/ " + timeStr);
}

void Form::onMediaStatusChanged(QMediaPlayer::MediaStatus status)
{
    if (status == QMediaPlayer::LoadedMedia) {
        loadSongPicture(currentSong);
    }
}

QString Form::getPicturePath(const QString &songName)
{
    QString pictureDir = "/mnt/hgfs/vmshare/QTmake/player/songpicture";
    QString baseName = QFileInfo(songName).baseName();
    QStringList extensions;
    extensions << ".jpg" << ".jpeg" << ".png" << ".bmp" << ".gif";

    for (const QString &ext : extensions)
    {
        QString picturePath = pictureDir + "/" + baseName + ext;
        if (QFile::exists(picturePath))
        {
            return picturePath;
        }
    }

    QString defaultPicture = pictureDir + "/default.jpg";
    if (QFile::exists(defaultPicture))
    {
        return defaultPicture;
    }

    return QString();
}

void Form::loadSongPicture(const QString &songName)
{
    QString picturePath = getPicturePath(songName);

    if (!picturePath.isEmpty())
    {
        QPixmap pixmap(picturePath);

        if (!pixmap.isNull())
        {
            QPixmap scaledPixmap = pixmap.scaled(ui->label_picture->size(),
                                                 Qt::KeepAspectRatio,
                                                 Qt::SmoothTransformation);
            ui->label_picture->setPixmap(scaledPixmap);
            ui->label_picture->setScaledContents(false);
            qDebug() << "加载图片成功：" << picturePath;
        }
        else
        {
            qDebug() << "图片加载失败：" << picturePath;
            ui->label_picture->clear();
        }
    }
    else
    {
        qDebug() << "未找到歌曲对应的图片：" << songName;
        ui->label_picture->clear();
    }
}

void Form::on_pushButton_clicked()
{
    showlrc *p = new showlrc;
    p->setAttribute(Qt::WA_DeleteOnClose);
    if (!currentSong.isEmpty())
    {
        p->setLyricFile(currentSong);
    }
    p->show();
}

void Form::on_progress_slider_moved(int position)
{
    player->setPosition(position);
}