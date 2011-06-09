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
    test.assert((*i)[string].toStdString(), std::string("82"));

    string = "RMF Ziom";
    test.assert((*i)[string].toStdString(), std::string("52"));

    this->a->quit();
}

void ParserTest::fail()
{
    test.error();
}
