#include "widget.h"
#include "ui_widget.h"
#include "QDebug"
#include "QString"
#include "QMessageBox"
#include <QSettings>
#include <QInputDialog>
#include "form.h"
#include "newuser.h"
#include "QFile"
#include "QTextStream"
#include <QDateTime>
int key;
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 记住密码
    QSettings settings("MyCompany", "MyApp");
    if (settings.value("RememberPassword", false).toBool())
    {
        ui->name->setText(settings.value("Username", "").toString());
        ui->password->setText(settings.value("Password", "").toString());
        ui->checkBox->setChecked(true);
    }
}

Widget::~Widget()
{
    delete ui;
}
void Widget::test()
{
    ui->name->setEchoMode(QLineEdit::Normal);
    ui->password->setEchoMode(QLineEdit::Password);
    ui->denlu->setEnabled(0);
    QString username = ui->name->text();
    QString userpassword = ui->password->text();
}

void Widget::on_checkBox_3_stateChanged(int arg1)//显示密码
{
    if(arg1==2)//2为勾选
        ui->password->setEchoMode(QLineEdit::Normal);
    else
        ui->password->setEchoMode(QLineEdit::Password);
}

void Widget::on_denlu_clicked()//点击登录
{
    QString username = ui->name->text();
    QString userpassword = ui->password->text();

    // 新增：从文件验证用户
    if (checkUserFromFile(username, userpassword))
    {
        //QMessageBox::information(this,"提示","登录成功");
        Form *p=new Form;
        p->show();
        this->close();
        key=1;

        // 记住密码
        QSettings settings("MyCompany", "MyApp");
        if (ui->checkBox->isChecked())
        {
            settings.setValue("RememberPassword", true);
            settings.setValue("Username", username);
            settings.setValue("Password", userpassword);
        }
        else
        {
            settings.setValue("RememberPassword", false);
            settings.remove("Username");
            settings.remove("Password");
        }
    }
    else
    {
        // 原有的错误提示逻辑可以保留
        if(username != "" && userpassword != "" )
            QMessageBox::information(this,"提示","用户名或密码错误");
        if(username == ""&& userpassword == "")
            QMessageBox::information(this,"提示","输入不能为空");
        if(userpassword == "" && username != "")
           QMessageBox::information(this,"提示","密码不能为空");
        if(userpassword != "" && username == "")
        QMessageBox::information(this,"提示","用户名不能为空");
    }
}

//验证函数
bool Widget::checkUserFromFile(const QString &username, const QString &password)
{
    QString userFile = "/mnt/hgfs/vmshare/QTmake/player/users.dat";

    QFile file(userFile);
    if (!file.exists())
    {
        return false;
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return false;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split("|");
        if (parts.size() >= 2 && parts[0] == username && parts[1] == password) {
            file.close();
            return true;  // 验证成功
        }
    }

    file.close();
    return false;  // 验证失败
}
void Widget::on_checkBox_2_stateChanged(int arg2)//同意用户协议
{
    if(arg2==2)
        ui->denlu->setEnabled(1);
    else
        ui->denlu->setEnabled(0);
}

void Widget::on_checkBox_stateChanged(int arg3)//记住密码
{
    // 记住密码功能：取消勾选时清除保存的密码
    if (arg3 == 0)
    {
        QSettings settings("MyCompany", "MyApp");
        settings.setValue("RememberPassword", false);
        settings.remove("Username");
        settings.remove("Password");
    }
}

void Widget::on_wenti_clicked()//问题反馈
{
    bool ok;
    QString feedback = QInputDialog::getMultiLineText(this,"问题反馈","输入你的反馈","",&ok);
        if(ok && !feedback.isEmpty())
    {
            QMessageBox::information(this,"提交成功","感谢反馈！\n\n");
    }
        else if(ok && feedback.isEmpty())
            QMessageBox::warning(this,"提示","反馈不能为空");

}
void Widget::on_fpassword_clicked()//忘记密码
{
    bool ok;

    // 第一步：输入用户名
    QString username = QInputDialog::getText(this, "忘记密码","请输入要重置密码的用户名：",QLineEdit::Normal, "", &ok);

    if (!ok || username.isEmpty()) {
        return;
    }

    // 检查用户名是否存在
    if (!userExists(username))
    {
        QMessageBox::warning(this, "提示", "用户名不存在！");
        return;
    }

    // 第二步：输入新密码
    QString newPassword = QInputDialog::getText(this, "重置密码","请输入新密码（至少6位）：",QLineEdit::Password, "", &ok);

    if (!ok || newPassword.isEmpty())
    {
        return;
    }

    // 检查密码长度
    if (newPassword.length() < 6)
    {
        QMessageBox::warning(this, "提示", "密码长度不能少于6位！");
        return;
    }

    // 第三步：确认密码
    QString confirmPassword = QInputDialog::getText(this, "确认密码","请再次输入新密码：",QLineEdit::Password, "", &ok);

    if (!ok || confirmPassword.isEmpty())
    {
        return;
    }

    // 检查两次密码是否一致
    if (newPassword != confirmPassword)
    {
        QMessageBox::warning(this, "提示", "两次输入的密码不一致！");
        return;
    }

    // 执行密码重置
    if (resetPassword(username, newPassword))
    {
        QMessageBox::information(this, "成功", "密码重置成功！请使用新密码登录。");

        // 自动填充用户名到登录框
        ui->name->setText(username);
        ui->password->clear();
    } else {
        QMessageBox::critical(this, "失败", "密码重置失败，请重试！");
    }
}

// 重置密码
bool Widget::resetPassword(const QString &username, const QString &newPassword)
{
    QString userFile = "/mnt/hgfs/vmshare/QTmake/player/users.dat";

    // 读取所有用户数据
    QFile file(userFile);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "无法打开用户文件";
        return false;
    }

    QStringList lines;
    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList parts = line.split("|");

        // 如果是目标用户，更新密码
        if (parts.size() >= 2 && parts[0] == username)
        {
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
            line = username + "|" + newPassword + "|" + currentTime + " (密码已重置)";
        }
        lines.append(line);
    }
    file.close();

    // 重新写入文件
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "无法写入用户文件";
        return false;
    }

    QTextStream out(&file);
    for (const QString &line : lines)
    {
        out << line << "\n";
    }

    file.flush();
    file.close();

    return true;
}

void Widget::on_commandLinkButton_2_clicked()//go to newuser
{
    newuser *p=new newuser;
    p->show();
    this->close();
}

// 检查用户是否存在
bool Widget::userExists(const QString &username)
{
    QString userFile = "/mnt/hgfs/vmshare/QTmake/player/users.dat";

    QFile file(userFile);
    if (!file.exists())
    {
        return false;
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return false;
    }

    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList parts = line.split("|");
        if (parts.size() >= 1 && parts[0] == username) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

