#ifndef SHOWLRC_H
#define SHOWLRC_H

#include <QWidget>
#include <QVector>
#include <QFile>
#include <QFileInfo>
#include <QPixmap>

namespace Ui {
class showlrc;
}

struct LyricLine {
    qint64 time;      // 时间戳（毫秒）
    QString text;     // 歌词文本
};

class showlrc : public QWidget
{
    Q_OBJECT

public:
    explicit showlrc(QWidget *parent = nullptr);
    ~showlrc();

    // 设置要显示的歌词文件
    void setLyricFile(const QString &songName);
    // 更新当前显示的歌词
    void updateLyric(qint64 currentTime);

private slots:
    void on_btn_back_clicked();  // 返回按钮槽函数

private:
    Ui::showlrc *ui;
    QVector<LyricLine> lyrics;    // 存储所有歌词行
    int currentLyricIndex;        // 当前显示的歌词索引

    // 解析歌词文件
    bool parseLyricFile(const QString &filePath);
    // 解析一行歌词（支持标准LRC格式）
    LyricLine parseLyricLine(const QString &line);
    // 获取图片路径
    QString getPicturePath(const QString &songName);
    // 加载并显示图片
    void loadSongPicture(const QString &songName);
};

#endif // SHOWLRC_H
