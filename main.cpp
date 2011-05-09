#include <QtGui/QApplication>
#include <QTextCodec>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("ISO 8859-2"));
    QTextCodec::setCodecForTr (QTextCodec::codecForName ("UTF-8"));

    MainWindow w;
    w.hide();

    return a.exec();
}
