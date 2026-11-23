#include "chosesong.h"
#include "ui_chosesong.h"
#include <QDebug>
#include <QFileInfo>
#include <QDir>
#include <QFileDialog>
#include <QMessageBox>
#include "QDirIterator"
#include "QString"
#include <QUrl>

ChoseSong::ChoseSong(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChoseSong),
    mainPlayer(nullptr)
{
    ui->setupUi(this);

    ui->lineEdit_path->setText("/mnt/hgfs/vmshare/QTmake/player/music");

    connect(ui->btn_back, &QPushButton::clicked, this, &ChoseSong::on_btn_back_clicked);
    connect(ui->btn_scan, &QPushButton::clicked, this, &ChoseSong::on_btn_scan_clicked);
    connect(ui->btn_play, &QPushButton::clicked, this, &ChoseSong::on_btn_play_clicked);
    connect(ui->btn_browse, &QPushButton::clicked, this, [this]()
            {
                QString dir = QFileDialog::getExistingDirectory(this, "选择音乐文件夹", ui->lineEdit_path->text());
                if (!dir.isEmpty())
                {
                    ui->lineEdit_path->setText(dir);
                }
            });
    connect(ui->songList, &QListWidget::itemDoubleClicked, this, &ChoseSong::on_songList_itemDoubleClicked);
    connect(ui->songList, &QListWidget::itemClicked, this, &ChoseSong::on_songList_itemClicked);
}

ChoseSong::~ChoseSong()
{
    delete ui;
}

void ChoseSong::setPlayer(QMediaPlayer *player)
{
    mainPlayer = player;
}

void ChoseSong::scanMusicFiles(const QString &directory)
{
    musicFiles.clear();

    QDir dir(directory);
    if (!dir.exists())
    {
        QMessageBox::warning(this, "错误", "目录不存在！");
        return;
    }

    QStringList filters;
    filters << "*.mp3" << "*.wav" << "*.flac" << "*.m4a" << "*.aac" << "*.ogg";

    QDirIterator it(directory, filters, QDir::Files, QDirIterator::Subdirectories);
    while (it.hasNext())
    {
        QString filePath = it.next();
        musicFiles.append(filePath);
    }

    if (musicFiles.isEmpty())
    {
        QMessageBox::information(this, "提示", "该目录下没有找到音乐文件！");
    }
    else
    {
        ui->label_count->setText(QString("共找到 %1 首歌曲").arg(musicFiles.size()));
        loadMusicToList();
    }
}

void ChoseSong::loadMusicToList()
{
    ui->songList->clear();

    for (const QString &filePath : musicFiles)
    {
        QFileInfo fileInfo(filePath);
        QString fileName = fileInfo.fileName();
        QString displayText = QString("%1").arg(fileName);

        QListWidgetItem *item = new QListWidgetItem(displayText);
        item->setData(Qt::UserRole, filePath);
        ui->songList->addItem(item);
    }

    ui->label_count->setText(QString("共 %1 首歌曲").arg(musicFiles.size()));
}

void ChoseSong::playSelectedSong()
{
    if (currentSongPath.isEmpty())
    {
        QMessageBox::information(this, "提示", "请先选择一首歌曲");
        return;
    }

    if (mainPlayer) {
        mainPlayer->setSource(QUrl::fromLocalFile(currentSongPath));
        mainPlayer->play();

        QFileInfo fileInfo(currentSongPath);
        QString songName = fileInfo.fileName();
        qDebug() << "开始播放：" << songName;

        emit songSelected(songName, currentSongPath);
    }
    else
    {
        QMessageBox::warning(this, "错误", "播放器未初始化");
    }
}

void ChoseSong::on_btn_scan_clicked()
{
    QString directory = ui->lineEdit_path->text();
    scanMusicFiles(directory);
}

void ChoseSong::on_btn_play_clicked()
{
    playSelectedSong();
}

void ChoseSong::on_songList_itemDoubleClicked(QListWidgetItem *item)
{
    if (item)
    {
        currentSongPath = item->data(Qt::UserRole).toString();
        playSelectedSong();
    }
}

void ChoseSong::on_songList_itemClicked(QListWidgetItem *item)
{
    if (item)
    {
        currentSongPath = item->data(Qt::UserRole).toString();
        QFileInfo fileInfo(currentSongPath);
        ui->label_selected->setText("当前选中：" + fileInfo.fileName());
    }
}

void ChoseSong::on_btn_back_clicked()
{
    this->deleteLater();
}