QT += multimedia multimediawidgets widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = jiemian
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++17

SOURCES += \
        main.cpp \
        widget.cpp \
        form.cpp \
        newuser.cpp \
        chosesong.cpp \
        showlrc.cpp

HEADERS += \
        widget.h \
        form.h \
        newuser.h \
        chosesong.h \
        showlrc.h

FORMS += \
        widget.ui \
        form.ui \
        newuser.ui \
        chosesong.ui \
        showlrc.ui