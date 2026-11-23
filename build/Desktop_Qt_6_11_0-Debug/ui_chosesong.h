/********************************************************************************
** Form generated from reading UI file 'chosesong.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOSESONG_H
#define UI_CHOSESONG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChoseSong
{
public:
    QLabel *label_title;
    QWidget *widget_path;
    QHBoxLayout *horizontalLayout_path;
    QLabel *label_path;
    QLineEdit *lineEdit_path;
    QPushButton *btn_browse;
    QPushButton *btn_scan;
    QListWidget *songList;
    QLabel *label_count;
    QLabel *label_selected;
    QWidget *widget_buttons;
    QHBoxLayout *horizontalLayout_buttons;
    QPushButton *btn_play;
    QPushButton *btn_back;

    void setupUi(QWidget *ChoseSong)
    {
        if (ChoseSong->objectName().isEmpty())
            ChoseSong->setObjectName("ChoseSong");
        ChoseSong->resize(800, 500);
        ChoseSong->setMinimumSize(QSize(600, 500));
        ChoseSong->setMaximumSize(QSize(800, 500));
        ChoseSong->setStyleSheet(QString::fromUtf8("background-color: rgb(64, 191, 183);"));
        label_title = new QLabel(ChoseSong);
        label_title->setObjectName("label_title");
        label_title->setGeometry(QRect(300, 0, 200, 40));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        label_title->setFont(font);
        label_title->setAlignment(Qt::AlignCenter);
        widget_path = new QWidget(ChoseSong);
        widget_path->setObjectName("widget_path");
        widget_path->setGeometry(QRect(120, 40, 560, 40));
        horizontalLayout_path = new QHBoxLayout(widget_path);
        horizontalLayout_path->setObjectName("horizontalLayout_path");
        horizontalLayout_path->setContentsMargins(0, 0, 0, 0);
        label_path = new QLabel(widget_path);
        label_path->setObjectName("label_path");

        horizontalLayout_path->addWidget(label_path);

        lineEdit_path = new QLineEdit(widget_path);
        lineEdit_path->setObjectName("lineEdit_path");

        horizontalLayout_path->addWidget(lineEdit_path);

        btn_browse = new QPushButton(widget_path);
        btn_browse->setObjectName("btn_browse");

        horizontalLayout_path->addWidget(btn_browse);

        btn_scan = new QPushButton(widget_path);
        btn_scan->setObjectName("btn_scan");

        horizontalLayout_path->addWidget(btn_scan);

        songList = new QListWidget(ChoseSong);
        songList->setObjectName("songList");
        songList->setGeometry(QRect(120, 80, 560, 280));
        label_count = new QLabel(ChoseSong);
        label_count->setObjectName("label_count");
        label_count->setGeometry(QRect(120, 360, 200, 25));
        label_selected = new QLabel(ChoseSong);
        label_selected->setObjectName("label_selected");
        label_selected->setGeometry(QRect(120, 390, 560, 25));
        widget_buttons = new QWidget(ChoseSong);
        widget_buttons->setObjectName("widget_buttons");
        widget_buttons->setGeometry(QRect(120, 430, 560, 40));
        horizontalLayout_buttons = new QHBoxLayout(widget_buttons);
        horizontalLayout_buttons->setObjectName("horizontalLayout_buttons");
        horizontalLayout_buttons->setContentsMargins(0, 0, 0, 0);
        btn_play = new QPushButton(widget_buttons);
        btn_play->setObjectName("btn_play");

        horizontalLayout_buttons->addWidget(btn_play);

        btn_back = new QPushButton(widget_buttons);
        btn_back->setObjectName("btn_back");

        horizontalLayout_buttons->addWidget(btn_back);


        retranslateUi(ChoseSong);

        QMetaObject::connectSlotsByName(ChoseSong);
    } // setupUi

    void retranslateUi(QWidget *ChoseSong)
    {
        ChoseSong->setWindowTitle(QCoreApplication::translate("ChoseSong", "\351\200\211\346\213\251\346\255\214\346\233\262", nullptr));
        label_title->setText(QCoreApplication::translate("ChoseSong", "\351\237\263\344\271\220\345\210\227\350\241\250", nullptr));
        label_path->setText(QCoreApplication::translate("ChoseSong", "\351\237\263\344\271\220\347\233\256\345\275\225\357\274\232", nullptr));
        lineEdit_path->setPlaceholderText(QCoreApplication::translate("ChoseSong", "\350\257\267\350\276\223\345\205\245\351\237\263\344\271\220\346\226\207\344\273\266\345\244\271\350\267\257\345\276\204", nullptr));
        btn_browse->setStyleSheet(QCoreApplication::translate("ChoseSong", "background-color: rgb(100, 150, 200); color: white; border-radius: 3px; padding: 5px;", nullptr));
        btn_browse->setText(QCoreApplication::translate("ChoseSong", "\346\265\217\350\247\210", nullptr));
        btn_scan->setStyleSheet(QCoreApplication::translate("ChoseSong", "background-color: rgb(100, 200, 100); color: white; border-radius: 3px; padding: 5px;", nullptr));
        btn_scan->setText(QCoreApplication::translate("ChoseSong", "\346\211\253\346\217\217", nullptr));
        songList->setStyleSheet(QCoreApplication::translate("ChoseSong", "background-color: white; border-radius: 5px; font-size: 12px;", nullptr));
        label_count->setText(QCoreApplication::translate("ChoseSong", "\345\205\261 0 \351\246\226\346\255\214\346\233\262", nullptr));
        label_selected->setStyleSheet(QCoreApplication::translate("ChoseSong", "color: blue; background-color: white; border-radius: 3px; padding: 3px;", nullptr));
        label_selected->setText(QCoreApplication::translate("ChoseSong", "\346\234\252\351\200\211\346\213\251\346\255\214\346\233\262", nullptr));
        btn_play->setStyleSheet(QCoreApplication::translate("ChoseSong", "background-color: rgb(0, 150, 0); color: white; border-radius: 5px; padding: 8px; font-size: 12px;", nullptr));
        btn_play->setText(QCoreApplication::translate("ChoseSong", "\342\226\266 \346\222\255\346\224\276\351\200\211\344\270\255\346\255\214\346\233\262", nullptr));
        btn_back->setStyleSheet(QCoreApplication::translate("ChoseSong", "background-color: rgb(100, 100, 200); color: white; border-radius: 5px; padding: 8px; font-size: 12px;", nullptr));
        btn_back->setText(QCoreApplication::translate("ChoseSong", "\342\206\220 \350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChoseSong: public Ui_ChoseSong {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOSESONG_H
