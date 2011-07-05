#include "imageload.h"


imageLoad::imageLoad()
{
    access=new QNetworkAccessManager(this);

    //when download data is finished finished slot is called
    connect(access,SIGNAL(finished(QNetworkReply*)),this,SLOT(finished(QNetworkReply*)));
}

imageLoad::~imageLoad()
{
	if(access != NULL)
		delete access;
}

void imageLoad::load(QString url)
{
    //get data from url
    access->get(QNetworkRequest(url));
}

void imageLoad::finished(QNetworkReply *reply)
{
    //if no error
    if(reply->error()==0)
    {
        //new pixmap variable
        QPixmap *p=new QPixmap;

        //convert QByteArray to QPixmap
        p->loadFromData(reply->readAll());

        qDebug("Image load succeed");

        //send QPixmap
        emit image(p);
    }
    //if error send NULL
    else
    {
        qDebug("Image load failed");
        emit image(NULL);
    }
}
