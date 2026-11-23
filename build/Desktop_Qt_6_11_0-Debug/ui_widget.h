/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *quxiao;
    QPushButton *fpassword;
    QCommandLinkButton *wenti;
    QLineEdit *name;
    QLineEdit *password;
    QCheckBox *checkBox;
    QPushButton *denlu;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCommandLinkButton *commandLinkButton_2;
    QLabel *label_4;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(800, 480);
        Widget->setMinimumSize(QSize(800, 480));
        Widget->setMaximumSize(QSize(800, 480));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Base, brush);
        QBrush brush1(QColor(64, 191, 183, 255));
        brush1.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Window, brush1);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Base, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Window, brush1);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Base, brush1);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Window, brush1);
        Widget->setPalette(palette);
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(340, 100, 191, 51));
        label_2 = new QLabel(Widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(180, 160, 81, 41));
        label_3 = new QLabel(Widget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(180, 230, 81, 41));
        quxiao = new QPushButton(Widget);
        quxiao->setObjectName("quxiao");
        quxiao->setGeometry(QRect(260, 304, 89, 31));
        fpassword = new QPushButton(Widget);
        fpassword->setObjectName("fpassword");
        fpassword->setGeometry(QRect(260, 344, 89, 31));
        wenti = new QCommandLinkButton(Widget);
        wenti->setObjectName("wenti");
        wenti->setGeometry(QRect(430, 390, 101, 41));
        name = new QLineEdit(Widget);
        name->setObjectName("name");
        name->setGeometry(QRect(260, 160, 261, 41));
        password = new QLineEdit(Widget);
        password->setObjectName("password");
        password->setGeometry(QRect(260, 230, 261, 41));
        password->setEchoMode(QLineEdit::Password);
        checkBox = new QCheckBox(Widget);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(260, 270, 191, 41));
        denlu = new QPushButton(Widget);
        denlu->setObjectName("denlu");
        denlu->setEnabled(true);
        denlu->setGeometry(QRect(430, 304, 89, 31));
        checkBox_2 = new QCheckBox(Widget);
        checkBox_2->setObjectName("checkBox_2");
        checkBox_2->setGeometry(QRect(430, 350, 381, 23));
        checkBox_3 = new QCheckBox(Widget);
        checkBox_3->setObjectName("checkBox_3");
        checkBox_3->setGeometry(QRect(530, 240, 181, 31));
        commandLinkButton_2 = new QCommandLinkButton(Widget);
        commandLinkButton_2->setObjectName("commandLinkButton_2");
        commandLinkButton_2->setGeometry(QRect(250, 390, 181, 41));
        label_4 = new QLabel(Widget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(340, 40, 201, 41));
        label_4->setStyleSheet(QString::fromUtf8("font: 57 20pt \"Ubuntu\";\n"
"font: 57 italic 25pt \"Ubuntu\";"));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\346\254\242\350\277\216\346\202\250\357\274\214\350\257\267\347\231\273\345\275\225\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\345\257\206    \347\240\201\357\274\232", nullptr));
        quxiao->setText(QCoreApplication::translate("Widget", "\345\217\226\346\266\210", nullptr));
        fpassword->setText(QCoreApplication::translate("Widget", "\345\277\230\350\256\260\345\257\206\347\240\201", nullptr));
        wenti->setText(QCoreApplication::translate("Widget", "\351\227\256\351\242\230\345\217\215\351\246\210", nullptr));
        checkBox->setText(QCoreApplication::translate("Widget", "\350\256\260\344\275\217\345\257\206\347\240\201", nullptr));
        denlu->setText(QCoreApplication::translate("Widget", "\347\231\273\345\275\225", nullptr));
        checkBox_2->setText(QCoreApplication::translate("Widget", "\346\230\257\345\220\246\345\220\214\346\204\217\343\200\212\347\224\250\346\210\267\351\232\220\347\247\201\345\215\217\350\256\256\343\200\213", nullptr));
        checkBox_3->setText(QCoreApplication::translate("Widget", "\346\230\276\347\244\272\345\257\206\347\240\201", nullptr));
        commandLinkButton_2->setText(QCoreApplication::translate("Widget", "\344\270\215\346\230\257\347\224\250\346\210\267\357\274\237\345\216\273\346\263\250\345\206\214", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "\345\256\207\351\237\263\344\271\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
