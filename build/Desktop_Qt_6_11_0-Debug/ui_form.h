/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QLabel *label_song;
    QPushButton *btn_select;
    QPushButton *btn_chose;
    QWidget *widget_buttons;
    QHBoxLayout *horizontalLayout;
    QSlider *progress_slider;
    QPushButton *btn_pause;
    QPushButton *btn_play;
    QPushButton *btn_stop;
    QLabel *label_time;
    QWidget *widget_volume;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_volume_icon;
    QSlider *volume_slider;
    QLabel *label_volume_value;
    QPushButton *btn_back;
    QLabel *label_picture;
    QPushButton *pushButton;
    QLabel *label_duration;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(800, 480);
        Form->setMinimumSize(QSize(800, 480));
        Form->setMaximumSize(QSize(800, 480));
        Form->setStyleSheet(QString::fromUtf8("background-color: rgb(64, 191, 183);"));
        label_song = new QLabel(Form);
        label_song->setObjectName("label_song");
        label_song->setGeometry(QRect(50, 20, 331, 51));
        QFont font;
        font.setPointSize(11);
        label_song->setFont(font);
        label_song->setAlignment(Qt::AlignCenter);
        btn_select = new QPushButton(Form);
        btn_select->setObjectName("btn_select");
        btn_select->setGeometry(QRect(50, 90, 331, 40));
        QFont font1;
        font1.setPointSize(12);
        btn_select->setFont(font1);
        btn_chose = new QPushButton(Form);
        btn_chose->setObjectName("btn_chose");
        btn_chose->setGeometry(QRect(50, 150, 331, 40));
        btn_chose->setFont(font1);
        widget_buttons = new QWidget(Form);
        widget_buttons->setObjectName("widget_buttons");
        widget_buttons->setGeometry(QRect(50, 250, 701, 81));
        horizontalLayout = new QHBoxLayout(widget_buttons);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        progress_slider = new QSlider(widget_buttons);
        progress_slider->setObjectName("progress_slider");
        progress_slider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(progress_slider);

        btn_pause = new QPushButton(widget_buttons);
        btn_pause->setObjectName("btn_pause");
        btn_pause->setFont(font);

        horizontalLayout->addWidget(btn_pause);

        btn_play = new QPushButton(widget_buttons);
        btn_play->setObjectName("btn_play");
        btn_play->setFont(font);

        horizontalLayout->addWidget(btn_play);

        btn_stop = new QPushButton(widget_buttons);
        btn_stop->setObjectName("btn_stop");
        btn_stop->setFont(font);

        horizontalLayout->addWidget(btn_stop);

        label_time = new QLabel(Form);
        label_time->setObjectName("label_time");
        label_time->setGeometry(QRect(50, 230, 41, 16));
        QFont font2;
        font2.setPointSize(10);
        label_time->setFont(font2);
        widget_volume = new QWidget(Form);
        widget_volume->setObjectName("widget_volume");
        widget_volume->setGeometry(QRect(50, 330, 701, 81));
        horizontalLayout_2 = new QHBoxLayout(widget_volume);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_volume_icon = new QLabel(widget_volume);
        label_volume_icon->setObjectName("label_volume_icon");
        label_volume_icon->setFont(font);

        horizontalLayout_2->addWidget(label_volume_icon);

        volume_slider = new QSlider(widget_volume);
        volume_slider->setObjectName("volume_slider");
        volume_slider->setMinimum(0);
        volume_slider->setMaximum(100);
        volume_slider->setValue(50);
        volume_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(volume_slider);

        label_volume_value = new QLabel(widget_volume);
        label_volume_value->setObjectName("label_volume_value");
        label_volume_value->setMinimumSize(QSize(30, 0));
        label_volume_value->setFont(font);

        horizontalLayout_2->addWidget(label_volume_value);

        btn_back = new QPushButton(Form);
        btn_back->setObjectName("btn_back");
        btn_back->setGeometry(QRect(50, 430, 81, 31));
        label_picture = new QLabel(Form);
        label_picture->setObjectName("label_picture");
        label_picture->setGeometry(QRect(469, 10, 231, 221));
        label_picture->setMaximumSize(QSize(240, 240));
        label_picture->setStyleSheet(QString::fromUtf8("font: 57 italic 20pt \"Ubuntu\";"));
        pushButton = new QPushButton(Form);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(350, 430, 101, 31));
        QPalette palette;
        QBrush brush(QColor(64, 191, 183, 255));
        brush.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Button, brush);
        QBrush brush1(QColor(115, 210, 22, 255));
        brush1.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Text, brush1);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Base, brush);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Window, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Button, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Text, brush1);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Base, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Window, brush);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Button, brush);
        QBrush brush2(QColor(190, 190, 190, 255));
        brush2.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Text, brush2);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Base, brush);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Window, brush);
        pushButton->setPalette(palette);
        label_duration = new QLabel(Form);
        label_duration->setObjectName("label_duration");
        label_duration->setGeometry(QRect(90, 230, 41, 20));
        label_duration->setFont(font2);
        label_duration->setAlignment(Qt::AlignRight);

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "\351\237\263\344\271\220\346\222\255\346\224\276\345\231\250", nullptr));
        label_song->setStyleSheet(QCoreApplication::translate("Form", "color: blue; background-color: white; border-radius: 5px; padding: 5px;", nullptr));
        label_song->setText(QCoreApplication::translate("Form", "\346\234\252\351\200\211\346\213\251\346\255\214\346\233\262", nullptr));
        btn_select->setStyleSheet(QCoreApplication::translate("Form", "background-color: rgb(100, 200, 100); color: white; border-radius: 5px;", nullptr));
        btn_select->setText(QCoreApplication::translate("Form", "\351\200\211\346\213\251\346\234\254\345\234\260\351\237\263\344\271\220\346\226\207\344\273\266", nullptr));
        btn_chose->setStyleSheet(QCoreApplication::translate("Form", "background-color: rgb(100, 100, 200); color: white; border-radius: 5px;", nullptr));
        btn_chose->setText(QCoreApplication::translate("Form", "\346\234\254\345\234\260\346\255\214\346\233\262\345\210\227\350\241\250", nullptr));
        btn_pause->setStyleSheet(QCoreApplication::translate("Form", "background-color: rgb(200, 150, 0); color: white; border-radius: 5px; padding: 8px;", nullptr));
        btn_pause->setText(QCoreApplication::translate("Form", " \346\232\202\345\201\234", nullptr));
        btn_play->setStyleSheet(QCoreApplication::translate("Form", "background-color: rgb(0, 150, 0); color: white; border-radius: 5px; padding: 8px;", nullptr));
        btn_play->setText(QCoreApplication::translate("Form", "\342\226\266 \346\222\255\346\224\276", nullptr));
        btn_stop->setStyleSheet(QCoreApplication::translate("Form", "background-color: rgb(200, 0, 0); color: white; border-radius: 5px; padding: 8px;", nullptr));
        btn_stop->setText(QCoreApplication::translate("Form", "\345\201\234\346\255\242", nullptr));
        label_time->setText(QCoreApplication::translate("Form", "00:00", nullptr));
        label_volume_icon->setText(QCoreApplication::translate("Form", "\351\237\263\351\207\217:", nullptr));
        label_volume_value->setText(QCoreApplication::translate("Form", "50", nullptr));
        btn_back->setStyleSheet(QCoreApplication::translate("Form", "background-color: rgb(100, 100, 200); color: white; border-radius: 5px;", nullptr));
        btn_back->setText(QCoreApplication::translate("Form", "\342\206\220 \350\277\224\345\233\236", nullptr));
        label_picture->setText(QCoreApplication::translate("Form", "       enjoy music", nullptr));
        pushButton->setText(QCoreApplication::translate("Form", "\346\230\276\347\244\272\346\255\214\350\257\215", nullptr));
        label_duration->setText(QCoreApplication::translate("Form", "/ 00:00", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
