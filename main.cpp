#include <QtGui/QApplication>
#include <QTextCodec>
#include "mainwindow.h"
#include "loader.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("ISO 8859-2"));
    QTextCodec::setCodecForTr (QTextCodec::codecForName ("UTF-8"));
//QTextCodec::setCodecForLocale(QTextCodec::codecForName("ISO 8859-1"));

    //loader o;
    //o.show();

    MainWindow w;
    w.show();

    return a.exec();
}
