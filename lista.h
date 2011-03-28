#ifndef LISTA_H
#define LISTA_H

#include <QString>

struct utwor{
    QString idp;
    QString artist;
    QString title;
    QString disk;
    QString year;
};

struct list
{
    utwor actual;
    utwor next;
};


#endif // LISTA_H
