#include "trackinfo.h"

trackInfo::trackInfo(QMap<QString,QString> *info,list *l)
{
    this->info=info;
    this->l=l;

    access=new QNetworkAccessManager(this);

    connect(access,SIGNAL(finished(QNetworkReply*)),this,SLOT(finished(QNetworkReply*)));
}

void trackInfo::setInfo(QMap<QString,QString> *info)
{
    this->info = info;
}

/*
get file with play list
*/
void trackInfo::show(QString station)
{
    //QString num=(*info)[station];

    access->get(QNetworkRequest("http://www.miastomuzyki.pl/stacje/stacje_gramy_"+(*info)[station]+".txt"));
}

void trackInfo::clean()
{
	l->actual.artist = "";
	l->actual.disk = "";
	l->actual.idp = "";
	l->actual.title = "";
	l->actual.year = "";

	l->next.artist="";
	l->next.disk="";
	l->next.idp="";
	l->next.title="";
	l->next.year="";
}

/*
if file dowloaded
start get info from it
*/
void trackInfo::finished(QNetworkReply *reply)
{
    if(reply->error()!=0)
    {
        qDebug()<<("error while load track info\ntrackInfo::finished\n "+QString::number(reply->error())).toAscii();
        qDebug()<<reply->url().toString().toAscii();
        l=NULL;
    }
    else
    {
    	clean();

        utwor *u=NULL;
        QString dane(reply->readAll());

        if(dane.length()!=0)
        {

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
                    u=&l->actual;
                }
                else if(tmp=="pozniej")
                {
                    u=&l->next;
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
                        u->artist=tmp;
                    }
                }
                else if(tmp=="tyt")
                {
                    if(u!=NULL)
                    {
                        szukanie(tmp,i,dane,petla);
                        u->title=tmp;
                    }
                }
                else if(tmp=="ply")
                {
                    if(u!=NULL)
                    {
                        szukanie(tmp,i,dane,petla);
                        u->disk=tmp;
                    }
                }
                else if(tmp=="rok")
                {
                    if(u!=NULL)
                    {
                        szukanie(tmp,i,dane,petla);
                        u->year=tmp;
                    }
                }
            }
        }
        qDebug("player list file parsed succeed\n");
        qDebug()<<("\nidp: "+l->actual.idp+" plyta:"+l->actual.disk+" rok:"+l->actual.year+" tytul:"+l->actual.title+" wykonawca:"+l->actual.artist).toAscii();
        qDebug()<<("\nidp: "+l->next.idp+" plyta:"+l->next.disk+" rok:"+l->next.year+" tytul:"+l->next.title+" wykonawca:"+l->next.artist).toAscii();

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
