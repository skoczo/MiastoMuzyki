#include <QtCore/QCoreApplication>
#include <QMap>
#include "parsertest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ParserTest pTest(a);

    return a.exec();
}
