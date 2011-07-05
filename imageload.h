#ifndef IMAGELOAD_H
#define IMAGELOAD_H

#include <QObject>
#include <QString>
#include <QPixmap>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QPixmap>

/*
 this class load image from url
 to QPixmap
 */
class imageLoad : public QObject
{
    Q_OBJECT
public:
    imageLoad();
    ~imageLoad();
    //get image url
    void load(QString url);

private:
    //this variable get data from url
    QNetworkAccessManager *access;

private slots:
    //this slot is called when gettin data is finished
    void finished(QNetworkReply* reply);

signals:
    //this signal is emitted when data from url was loaded to QPixmap
    void image(QPixmap*);
};

#endif // IMAGELOAD_H
