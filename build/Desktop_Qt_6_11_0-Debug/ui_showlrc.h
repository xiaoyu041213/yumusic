/********************************************************************************
** Form generated from reading UI file 'showlrc.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWLRC_H
#define UI_SHOWLRC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_showlrc
{
public:
    QPushButton *btn_back;
    QTextEdit *textEdit_lyric;
    QLabel *label_status;
    QLabel *label_picture;

    void setupUi(QWidget *showlrc)
    {
        if (showlrc->objectName().isEmpty())
            showlrc->setObjectName("showlrc");
        showlrc->resize(800, 480);
        showlrc->setMaximumSize(QSize(800, 480));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Base, brush);
        QBrush brush1(QColor(250, 212, 93, 255));
        brush1.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Window, brush1);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Base, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Window, brush1);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Base, brush1);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Window, brush1);
        showlrc->setPalette(palette);
        btn_back = new QPushButton(showlrc);
        btn_back->setObjectName("btn_back");
        btn_back->setGeometry(QRect(20, 20, 89, 25));
        textEdit_lyric = new QTextEdit(showlrc);
        textEdit_lyric->setObjectName("textEdit_lyric");
        textEdit_lyric->setGeometry(QRect(210, 10, 371, 151));
        label_status = new QLabel(showlrc);
        label_status->setObjectName("label_status");
        label_status->setGeometry(QRect(590, 60, 231, 61));
        label_picture = new QLabel(showlrc);
        label_picture->setObjectName("label_picture");
        label_picture->setGeometry(QRect(250, 169, 301, 301));
        label_picture->setMaximumSize(QSize(310, 310));
        label_picture->setStyleSheet(QString::fromUtf8("font: 57 italic 20pt \"Ubuntu\";"));

        retranslateUi(showlrc);

        QMetaObject::connectSlotsByName(showlrc);
    } // setupUi

    void retranslateUi(QWidget *showlrc)
    {
        showlrc->setWindowTitle(QCoreApplication::translate("showlrc", "Form", nullptr));
        btn_back->setText(QCoreApplication::translate("showlrc", "<back", nullptr));
        label_status->setText(QString());
        label_picture->setText(QCoreApplication::translate("showlrc", "              enjoy music", nullptr));
    } // retranslateUi

};

namespace Ui {
    class showlrc: public Ui_showlrc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWLRC_H
