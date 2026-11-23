#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void test();
private slots:
    void on_checkBox_3_stateChanged(int arg1);

    void on_denlu_clicked();

    void on_checkBox_2_stateChanged(int arg1);

    void on_checkBox_stateChanged(int arg1);

    void on_wenti_clicked();

    void on_fpassword_clicked();

    void on_commandLinkButton_2_clicked();

private:
    Ui::Widget *ui;
private:
    bool userExists(const QString &username);
    bool resetPassword(const QString &username, const QString &newPassword);
    bool checkUserFromFile(const QString &username, const QString &password);  // 新增
};

#endif // WIDGET_H
