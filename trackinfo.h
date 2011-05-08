#ifndef TRACKINFO_H
#define TRACKINFO_H

#include <QObject>
#include <QMap>
#include <QUrl>
#include <QFile>
#include <QTextStream>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QDebug>
#include <iostream>
#include "lista.h"

class trackInfo : public QObject
{
    Q_OBJECT
private:
    QMap<QString,QString> *info;
    list *l;
    QNetworkAccessManager *access;

public:
    trackInfo(QMap<QString,QString> *info,list *l);
    void setInfo(QMap<QString,QString> *info);

private:
    void clean();

public slots:
    void finished(QNetworkReply* reply);
    void show(QString station);

signals:
        void dataReady();
};

void szukanie(QString &tmp,int &i,QString &dane,bool &petla);
#endif // TRACKINFO_H

