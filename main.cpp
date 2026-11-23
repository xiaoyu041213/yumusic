#include "widget.h"
#include <QApplication>
#include "QDebug"
#include "QString"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    w.test();

    return a.exec();
}
