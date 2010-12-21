#include <QtGui/QApplication>
#include <QTextCodec>
#include "mainwindow.h"
#include "loader.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName( "iso-8859-2" ));
    QTextCodec::setCodecForTr (QTextCodec::codecForName ("UTF-8"));

    //loader o;
    //o.show();

    MainWindow w;
    w.show();

    return a.exec();
}