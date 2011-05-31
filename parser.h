#ifndef PARSER_H
#define PARSER_H

#include <QMap>
#include <QFile>
#include <QHttp>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QDebug>

class Parser: public QObject
{
	Q_OBJECT
private:
	QMap<QString, QString> *stacje;
	QMap<QString, QString> *identyfikatory;
	QNetworkAccessManager *access;

public:
        Parser();

	void start();

private slots:
	//this slot is called when gettin data is finished
	void finished(QNetworkReply* reply);

signals:
        void send(QMap<QString, QString> *s, QMap<QString, QString> *i);
        void fail();

};

#endif // PARSER_H
