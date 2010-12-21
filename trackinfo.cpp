#include "trackinfo.h"

trackInfo::trackInfo(QMap<QString,QString> *info,list *l)
{
    this->info=info;
    this->l=l;

    access=new QNetworkAccessManager(this);

    connect(access,SIGNAL(finished(QNetworkReply*)),this,SLOT(finished(QNetworkReply*)));
}

/*
 get file with play list
 */
void trackInfo::show(QString station)
{
    //QString num=(*info)[station];

    access->get(QNetworkRequest("http://www.miastomuzyki.pl/stacje/stacje_gramy_"+(*info)[station]+".txt"));
}

/*
 if file dowloaded
 start get info from it
 */
void trackInfo::finished(QNetworkReply *reply)
{
    if(reply->error()!=0)
    {
        qDebug(("error while load track info\ntrackInfo::finished\n "+QString::number(reply->error())).toAscii());
        qDebug(reply->url().toString().toAscii());
        l=NULL;
    }
    else
    {
        utwor *u=NULL;
        QString dane(reply->readAll());
        QString tmp;
        QChar c;

        int i=0;

        bool petla=true;
        while(petla)
        {
            tmp="";
            while(dane[i]!='\'')
                i++;

            i++;
            if(i<dane.length())
               c=dane.at(i);

            while(c!='\'')
            {
                i++;

                if(i>=dane.length())
                {
                    petla=false;
                    break;
                }

                tmp.append(c);
                c=dane.at(i);
            }

            if(tmp=="teraz")
            {
                u=&l->aktualny;
            }
            else if(tmp=="pozniej")
            {
                u=&l->nastepny;
            }
            else if(tmp=="idp")
            {
                if(u!=NULL)
                {
                    szukanie(tmp,i,dane,petla);
                    u->idp=tmp;
                }
            }
            else if(tmp=="wyk")
            {
                if(u!=NULL)
                {
                    szukanie(tmp,i,dane,petla);
                    u->wykonawca=tmp;
                }
            }
            else if(tmp=="tyt")
            {
                if(u!=NULL)
                {
                    szukanie(tmp,i,dane,petla);
                    u->tytul=tmp;
                }
            }
            else if(tmp=="ply")
            {
                if(u!=NULL)
                {
                    szukanie(tmp,i,dane,petla);
                    u->plyta=tmp;
                }
            }
            else if(tmp=="rok")
            {
                if(u!=NULL)
                {
                    szukanie(tmp,i,dane,petla);
                    u->rok=tmp;
                }
            }
        }
        qDebug("player list file parsed succeed\n");
        qDebug(("\nidp: "+l->aktualny.idp+" plyta:"+l->aktualny.plyta+" rok:"+l->aktualny.rok+" tytul:"+l->aktualny.tytul+" wykonawca:"+l->aktualny.wykonawca).toAscii());
        qDebug(("\nidp: "+l->nastepny.idp+" plyta:"+l->nastepny.plyta+" rok:"+l->nastepny.rok+" tytul:"+l->nastepny.tytul+" wykonawca:"+l->nastepny.wykonawca).toAscii());

        emit dataReady();
    }
}

/*
this funtion get value
and write it to tmp variable
 */
void szukanie(QString &tmp,int &i,QString &dane,bool &petla)
{
    tmp="";

    i++;
    while(dane[i]!='\'')
        i++;

    i++;

    QChar c=dane.at(i);

    while(c!='\'')
    {
        i++;

        if(i>dane.length())
        {
            petla=false;
            break;
        }

        tmp.append(c);
        c=dane.at(i);
        while(c=='\\')
        {
            i+=2;
            c=dane.at(i);
            tmp.append('\'');
        }
    }
}
