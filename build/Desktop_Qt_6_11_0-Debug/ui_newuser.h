/********************************************************************************
** Form generated from reading UI file 'newuser.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWUSER_H
#define UI_NEWUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_newuser
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QCheckBox *checkBox;

    void setupUi(QWidget *newuser)
    {
        if (newuser->objectName().isEmpty())
            newuser->setObjectName("newuser");
        newuser->resize(800, 480);
        newuser->setMaximumSize(QSize(800, 480));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Base, brush);
        QBrush brush1(QColor(14, 255, 188, 255));
        brush1.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Window, brush1);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Base, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Window, brush1);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Base, brush1);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Window, brush1);
        newuser->setPalette(palette);
        label = new QLabel(newuser);
        label->setObjectName("label");
        label->setGeometry(QRect(310, 70, 181, 31));
        label->setStyleSheet(QString::fromUtf8("font: 15pt \"Ubuntu\";"));
        label_2 = new QLabel(newuser);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(220, 150, 71, 31));
        label_2->setStyleSheet(QString::fromUtf8("font: 15pt \"Ubuntu\";\n"
"font: 13pt \"Ubuntu\";"));
        label_3 = new QLabel(newuser);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(230, 210, 71, 31));
        label_3->setStyleSheet(QString::fromUtf8("font: 13pt \"Ubuntu\";"));
        label_4 = new QLabel(newuser);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(210, 270, 91, 31));
        label_4->setStyleSheet(QString::fromUtf8("font: 13pt \"Ubuntu\";"));
        lineEdit = new QLineEdit(newuser);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(300, 150, 181, 31));
        lineEdit_2 = new QLineEdit(newuser);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(300, 210, 181, 31));
        lineEdit_3 = new QLineEdit(newuser);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(300, 270, 181, 31));
        pushButton = new QPushButton(newuser);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(270, 340, 89, 31));
        QPalette palette1;
        QBrush brush2(QColor(239, 41, 41, 255));
        brush2.setStyle(Qt::BrushStyle::SolidPattern);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Text, brush2);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Text, brush2);
        QBrush brush3(QColor(190, 190, 190, 255));
        brush3.setStyle(Qt::BrushStyle::SolidPattern);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Text, brush3);
        pushButton->setPalette(palette1);
        pushButton_2 = new QPushButton(newuser);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(420, 340, 89, 31));
        checkBox = new QCheckBox(newuser);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(500, 280, 92, 23));

        retranslateUi(newuser);

        QMetaObject::connectSlotsByName(newuser);
    } // setupUi

    void retranslateUi(QWidget *newuser)
    {
        newuser->setWindowTitle(QCoreApplication::translate("newuser", "Form", nullptr));
        label->setText(QCoreApplication::translate("newuser", "\346\254\242\350\277\216\346\202\250\346\263\250\345\206\214\345\256\207\351\237\263\344\271\220~", nullptr));
        label_2->setText(QCoreApplication::translate("newuser", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_3->setText(QCoreApplication::translate("newuser", "\345\257\206\347\240\201", nullptr));
        label_4->setText(QCoreApplication::translate("newuser", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        pushButton->setText(QCoreApplication::translate("newuser", "\345\217\226\346\266\210", nullptr));
        pushButton_2->setText(QCoreApplication::translate("newuser", "\347\241\256\350\256\244", nullptr));
        checkBox->setText(QCoreApplication::translate("newuser", "\346\230\276\347\244\272\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class newuser: public Ui_newuser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWUSER_H
