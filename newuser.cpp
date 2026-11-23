#include "newuser.h"
#include "ui_newuser.h"
#include "widget.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QDebug>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QDebug>
#include <QCoreApplication>
#include "QString"

newuser::newuser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newuser)
{
    ui->setupUi(this);

    // 设置密码输入框为密码模式
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    ui->lineEdit_3->setEchoMode(QLineEdit::Password);
}

newuser::~newuser()
{
    delete ui;
}
//返回登陆界面
void newuser::on_pushButton_clicked()//返回登陆界面
{
    // 查找已存在的登录界面
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

    // 如果没有找到，创建新的
    if (!loginWidget)
    {
        loginWidget = new Widget();
    }

    loginWidget->show();
    this->deleteLater();  // 删除当前注册界面
}
// 确认注册按钮
void newuser::on_pushButton_2_clicked()
{
    QString username = ui->lineEdit->text();      // 用户名
    QString password = ui->lineEdit_2->text();     // 密码
    QString confirmPwd = ui->lineEdit_3->text();   // 确认密码

    // 1. 验证输入
    if (!validateInput(username, password, confirmPwd))
    {
        return;
    }

    // 2. 检查用户是否已存在
    if (checkUserExists(username))
    {
        QMessageBox::warning(this, "注册失败", "用户名已存在，请使用其他用户名！");
        return;
    }

    // 3. 保存用户
    if (saveUser(username, password))
    {
        QMessageBox::information(this, "注册成功", "注册成功！请返回登录界面登录。");

        // 注册成功后自动返回登录界面
        // 注册成功后自动返回登录界面
        if (saveUser(username, password))
        {
            QMessageBox::information(this, "注册成功", "注册成功！请返回登录界面登录。");

            // 查找已存在的登录界面
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
    } else
    {
        QMessageBox::critical(this, "注册失败", "保存用户信息失败，请重试！");
    }
}

// 验证输入
bool newuser::validateInput(const QString &username, const QString &password, const QString &confirmPwd)
{
    // 检查用户名是否为空
    if (username.isEmpty())
    {
        QMessageBox::warning(this, "提示", "用户名不能为空！");
        return false;
    }

    // 检查用户名长度（至少6位，因为你的学号是12位）
    if (username.length() < 6)
    {
        QMessageBox::warning(this, "提示", "用户名长度不能少于6位！");
        return false;
    }

    // 检查密码是否为空
    if (password.isEmpty())
    {
        QMessageBox::warning(this, "提示", "密码不能为空！");
        return false;
    }

    // 检查密码长度
    if (password.length() < 6)
    {
        QMessageBox::warning(this, "提示", "密码长度不能少于6位！");
        return false;
    }

    // 检查两次密码是否一致
    if (password != confirmPwd)
    {
        QMessageBox::warning(this, "提示", "两次输入的密码不一致！");
        return false;
    }

    return true;
}

// 检查用户是否存在
bool newuser::checkUserExists(const QString &username)
{
    // 用户数据文件路径
     QString userFile = "/mnt/hgfs/vmshare/QTmake/player/users.dat";

    QFile file(userFile);
    if (!file.exists())
    {
        // 文件不存在，说明没有用户
        return false;
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "无法打开用户文件：" << userFile;
        return false;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split("|");
        if (parts.size() >= 1 && parts[0] == username) {
            file.close();
            return true;  // 用户已存在
        }
    }

    file.close();
    return false;  // 用户不存在
}

// 保存用户
bool newuser::saveUser(const QString &username, const QString &password)
{
    // 用户数据文件路径
    QString userFile = "/mnt/hgfs/vmshare/QTmake/player/users.dat";

    QFile file(userFile);

    // 以追加模式打开文件
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        qDebug() << "无法打开用户文件进行写入：" << userFile;
        return false;
    }

    QTextStream out(&file);

    // 获取当前时间
    QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

    // 格式：用户名|密码|注册时间
    out << username << "|" << password << "|" << currentTime << "\n";

    file.flush();
    file.close();

    qDebug() << "用户注册成功：" << username << "时间：" << currentTime;

    return true;
}

void newuser::on_checkBox_stateChanged(int arg1)//显示密码
{
    if(arg1==2)//2为勾选
        {
        ui->lineEdit_2->setEchoMode(QLineEdit::Normal);
        ui->lineEdit_3->setEchoMode(QLineEdit::Normal);
        }
    else
    {
        ui->lineEdit_2->setEchoMode(QLineEdit::Password);
        ui->lineEdit_3->setEchoMode(QLineEdit::Password);
    }
}
