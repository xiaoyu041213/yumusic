#include "showlrc.h"
#include "ui_showlrc.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QRegularExpression>
#include <QFileInfo>
#include <QFont>
#include <QTextCursor>
#include <QPushButton>
#include <QStringDecoder>
#include <QPixmap>

showlrc::showlrc(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::showlrc),
    currentLyricIndex(-1)
{
    ui->setupUi(this);

    // 连接返回按钮
    connect(ui->btn_back, &QPushButton::clicked, this, &showlrc::on_btn_back_clicked);

    // 设置歌词显示区域为只读
    ui->textEdit_lyric->setReadOnly(true);
    // 设置字体大小
    QFont font = ui->textEdit_lyric->font();
    font.setPointSize(12);
    ui->textEdit_lyric->setFont(font);
}

showlrc::~showlrc()
{
    delete ui;
}

QString showlrc::getPicturePath(const QString &songName)
{
    // 图片存放目录
    QString pictureDir = "/mnt/hgfs/vmshare/QTmake/player/songpicture";

    // 去掉歌曲名的扩展名
    QString baseName = QFileInfo(songName).baseName();

    // 支持的图片格式
    QStringList extensions;
    extensions << ".jpg" << ".jpeg" << ".png" << ".bmp" << ".gif";

    // 查找对应的图片文件
    for (const QString &ext : extensions)
    {
        QString picturePath = pictureDir + "/" + baseName + ext;
        if (QFile::exists(picturePath))
        {
            return picturePath;
        }
    }

    // 如果没有找到对应的图片，返回默认图片路径
    QString defaultPicture = pictureDir + "/default.jpg";
    if (QFile::exists(defaultPicture))
    {
        return defaultPicture;
    }

    return QString();
}

void showlrc::loadSongPicture(const QString &songName)
{
    QString picturePath = getPicturePath(songName);

    if (!picturePath.isEmpty()) {
        QPixmap pixmap(picturePath);

        if (!pixmap.isNull())
        {
            QPixmap scaledPixmap = pixmap.scaled(ui->label_picture->size(),
                                                   Qt::KeepAspectRatio,
                                                   Qt::SmoothTransformation);
            ui->label_picture->setPixmap(scaledPixmap);
            ui->label_picture->setScaledContents(false);
            qDebug() << "歌词窗口加载图片成功：" << picturePath;
        }
        else
        {
            qDebug() << "歌词窗口图片加载失败：" << picturePath;
            ui->label_picture->clear();
        }
    }
    else
    {
        qDebug() << "歌词窗口未找到歌曲图片：" << songName;
        ui->label_picture->clear();
    }
}

void showlrc::setLyricFile(const QString &songName)
{
    // 清空现有歌词
    lyrics.clear();
    ui->textEdit_lyric->clear();
    currentLyricIndex = -1;

    // 构建歌词文件路径（使用 songlrc 文件夹）
    QString lyricPath = "/mnt/hgfs/vmshare/QTmake/player/songlrc/" + QFileInfo(songName).baseName() + ".lrc";

    qDebug() << "尝试加载歌词文件：" << lyricPath;

    // 解析歌词文件
    if (parseLyricFile(lyricPath))
    {
        ui->label_status->setText("歌词加载成功，共" + QString::number(lyrics.size()) + "行");
        qDebug() << "成功加载" << lyrics.size() << "行歌词";
    } else
    {
        ui->label_status->setText("未找到歌词文件");
        ui->textEdit_lyric->setPlainText("暂无歌词\n\n请将.lrc歌词文件放在songlrc文件夹中\n\n歌词文件命名：\n歌曲名.lrc\n例如：告白气球.lrc");
        qDebug() << "歌词文件加载失败：" << lyricPath;
    }

    // 加载歌曲图片
    loadSongPicture(songName);
}

bool showlrc::parseLyricFile(const QString &filePath)
{
    QFile file(filePath);
    if (!file.exists()) {
        return false;
    }

    if (!file.open(QIODevice::ReadOnly)) {
        return false;
    }

    QByteArray rawData = file.readAll();
    file.close();

    // Qt6: 使用 QStringDecoder 替代 QTextCodec
    QString content;

    // 先尝试 UTF-8
    content = QString::fromUtf8(rawData);

    // 检查是否有乱码
    bool hasChinese = false;
    bool hasGarbled = false;
    for (int i = 0; i < content.length() && i < 500; i++)
    {
        QChar ch = content[i];
        if (ch.unicode() >= 0x4E00 && ch.unicode() <= 0x9FFF)
        {
            hasChinese = true;
            break;
        }
        if (ch.unicode() > 0x80 && (ch.unicode() < 0x4E00 || ch.unicode() > 0x9FFF)) {
            hasGarbled = true;
        }
    }

    if (!hasChinese && hasGarbled)
    {
        QStringDecoder decoder("GBK");
        content = decoder.decode(rawData);
        qDebug() << "使用GBK编码";
    } else {
        qDebug() << "使用UTF-8编码";
    }

    QTextStream in(&content);

    QStringList lines = content.split("\n");
    for (const QString &line : lines)
    {
        if (!line.trimmed().isEmpty())
        {
            LyricLine lyric = parseLyricLine(line);
            if (lyric.time >= 0) {
                lyrics.append(lyric);
            }
        }
    }

    std::sort(lyrics.begin(), lyrics.end(),
              [](const LyricLine &a, const LyricLine &b)
              {
                  return a.time < b.time;
              });

    return !lyrics.isEmpty();
}

LyricLine showlrc::parseLyricLine(const QString &line)
{
    LyricLine result;
    result.time = -1;

    QRegularExpression regex("\\[(\\d{2}):(\\d{2})(?:\\.(\\d{2}))?\\](.*)");
    QRegularExpressionMatch match = regex.match(line);

    if (match.hasMatch())
    {
        int minutes = match.captured(1).toInt();
        int seconds = match.captured(2).toInt();
        int centiseconds = match.captured(3).isEmpty() ? 0 : match.captured(3).toInt();

        result.time = (minutes * 60 + seconds) * 1000 + centiseconds * 10;
        result.text = match.captured(4).trimmed();
    }

    return result;
}

void showlrc::updateLyric(qint64 currentTime)
{
    if (lyrics.isEmpty()) {
        return;
    }

    // 调试：显示第一句歌词的时间
    static bool firstDebug = true;
    if (firstDebug && lyrics.size() > 0) {
        qDebug() << "=== 歌词调试信息 ===";
        qDebug() << "第一句歌词时间:" << lyrics[0].time << "ms";
        qDebug() << "最后一句歌词时间:" << lyrics[lyrics.size()-1].time << "ms";
        qDebug() << "前5句歌词时间:";
        for (int i = 0; i < qMin(5, lyrics.size()); i++) {
            qDebug() << "  [" << i << "] 时间:" << lyrics[i].time << "ms 歌词:" << lyrics[i].text;
        }
        firstDebug = false;
    }

    int newIndex = -1;
    for (int i = 0; i < lyrics.size(); i++)
    {
        if (currentTime >= lyrics[i].time)
        {
            newIndex = i;
        } else {
            break;
        }
    }

    // 如果当前时间小于第一句歌词时间，显示第一句但不高亮
    if (newIndex == -1 && lyrics.size() > 0)
    {
        // 显示前几行歌词
        QString displayText;
        int showLines = qMin(7, lyrics.size());
        for (int i = 0; i < showLines; i++)
        {
            if (i == 0)
            {
                displayText += "<b><font color='#888888'>▶ " + lyrics[i].text + "</font></b><br>";
            }
            else
            {
                displayText += "  " + lyrics[i].text + "<br>";
            }
        }
        ui->textEdit_lyric->setHtml(displayText);
        return;
    }

    if (newIndex != currentLyricIndex && newIndex >= 0)
    {
        currentLyricIndex = newIndex;
        qDebug() << "切换到歌词[" << currentLyricIndex << "]:" << lyrics[currentLyricIndex].text;

        QString displayText;
        int startIndex = qMax(0, currentLyricIndex - 2);
        int endIndex = qMin(lyrics.size() - 1, currentLyricIndex + 3);

        for (int i = startIndex; i <= endIndex; i++)
        {
            if (i == currentLyricIndex)
            {
                displayText += "<b><font color='#FF6B6B'>▶ " + lyrics[i].text + "</font></b><br>";
            }
            else
            {
                displayText += "  " + lyrics[i].text + "<br>";
            }
        }

        ui->textEdit_lyric->setHtml(displayText);

        QTextCursor cursor = ui->textEdit_lyric->textCursor();
        cursor.movePosition(QTextCursor::Start);
        for (int i = 0; i < currentLyricIndex - startIndex; i++)
        {
            cursor.movePosition(QTextCursor::Down);
        }
        ui->textEdit_lyric->setTextCursor(cursor);
    }
}

void showlrc::on_btn_back_clicked()
{
    this->close();
}
