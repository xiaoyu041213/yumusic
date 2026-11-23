#ifndef CHOSESONG_H
#define CHOSESONG_H

#include <QWidget>
#include <QMediaPlayer>
#include <QListWidgetItem>
#include <QUrl>

namespace Ui {
class ChoseSong;
}

class ChoseSong : public QWidget
{
    Q_OBJECT

public:
    explicit ChoseSong(QWidget *parent = nullptr);
    ~ChoseSong();

    void setPlayer(QMediaPlayer *player);
    void scanMusicFiles(const QString &directory);

signals:
    void songSelected(const QString &songName, const QString &songPath);

private slots:
    void on_btn_back_clicked();
    void on_btn_scan_clicked();
    void on_btn_play_clicked();
    void on_songList_itemDoubleClicked(QListWidgetItem *item);
    void on_songList_itemClicked(QListWidgetItem *item);

private:
    Ui::ChoseSong *ui;
    QMediaPlayer *mainPlayer;
    QString currentSongPath;
    QStringList musicFiles;

    void loadMusicToList();
    void playSelectedSong();
};

#endif // CHOSESONG_H