#include "parsertest.h"

ParserTest::ParserTest(QCoreApplication &a)
{
    Parser *p = new Parser();
    this->a=&a;

    p->start();

    connect(p, SIGNAL(send(QMap<QString,QString>*,QMap<QString,QString>*)),
            this, SLOT(recive(QMap<QString,QString>*,QMap<QString,QString>*)));
    connect(p, SIGNAL(fail()), this, SLOT(fail()));
}

void ParserTest::recive(QMap<QString, QString>* s, QMap<QString, QString>* i)
{
    test.assert(s->size(),i->size());

    QString string = "RMF 20 lat";
    test.assert(std::string("82"), (*i)[string].toStdString());

    string = "RMF Ziom";
    test.assert(std::string("52"), (*i)[string].toStdString());

    string = "RMF Hot New";
    test.assert(std::string("27"), (*i)[string].toStdString());

    this->a->quit();
}

void ParserTest::fail()
{
    test.error();
}
