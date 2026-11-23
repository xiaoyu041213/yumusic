#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QMediaPlayer>
#include <QFileDialog>
#include "chosesong.h"
#include <QAudioOutput>
#include <QUrl>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();

private slots:
    void on_btn_play_clicked();
    void on_btn_pause_clicked();
    void on_btn_stop_clicked();
    void on_btn_select_clicked();
    void on_volume_slider_valueChanged(int value);
    void on_btn_back_clicked();
    void onPositionChanged(qint64 position);
    void onDurationChanged(qint64 duration);
    void on_btn_chose_clicked();
    void onSongSelected(const QString &songName, const QString &songPath);
    void onMediaStatusChanged(QMediaPlayer::MediaStatus status);
    void on_progress_slider_moved(int position);
    void on_pushButton_clicked();

private:
    Ui::Form *ui;
    QMediaPlayer *player;
    QAudioOutput *audioOutput;
    QString currentSong;
    ChoseSong *choseSongWindow;

    QString getPicturePath(const QString &songName);
    void loadSongPicture(const QString &songName);
    void playFile(const QString &filePath);
};

#endif // FORM_H