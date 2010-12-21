#ifndef PARSER_H
#define PARSER_H

#include <QMap>
#include <QFile>
#include <iostream>

class Parser{
    private:

    QMap<QString,QString> *stacje;
    QMap<QString,QString> *identyfikatory;

public:
    Parser(QMap<QString,QString> *s,QMap<QString,QString> *i);

    void start();
};

#endif // PARSER_H
