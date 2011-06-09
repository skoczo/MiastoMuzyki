#ifndef PARSERTEST_H
#define PARSERTEST_H

#include <QObject>
#include <QMap>
#include <QString>
#include <QCoreApplication>
#include "parser.h"
#include "../test.h"

class ParserTest : public QObject
{
    Q_OBJECT

private:
    Test test;
    QCoreApplication *a;

public:
    ParserTest(QCoreApplication &a);

private slots:
    void recive(QMap<QString, QString>* s, QMap<QString, QString>* i);
    void fail();
};

#endif // PARSERTEST_H
