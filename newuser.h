#ifndef NEWUSER_H
#define NEWUSER_H

#include <QWidget>

namespace Ui {
class newuser;
}

class newuser : public QWidget
{
    Q_OBJECT

public:
    explicit newuser(QWidget *parent = 0);
    ~newuser();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_checkBox_stateChanged(int arg1);

private:
    Ui::newuser *ui;
    bool checkUserExists(const QString &username);
    bool saveUser(const QString &username, const QString &password);
    bool validateInput(const QString &username, const QString &password, const QString &confirmPwd);
};

#endif // NEWUSER_H
