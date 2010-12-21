#ifndef LISTA_H
#define LISTA_H

#include <QString>

struct utwor{
    QString idp;
    QString wykonawca;
    QString tytul;
    QString plyta;
    QString rok;
};

struct list
{
    utwor aktualny;
    utwor nastepny;
};


#endif // LISTA_H
