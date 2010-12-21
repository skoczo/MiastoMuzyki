#include "parser.h"

/*
 Put station name, station id and station url to map
 */
Parser::Parser(QMap<QString, QString> *s,QMap<QString,QString> *i)
{
    stacje=s;
    identyfikatory=i;
}

/*
 this function parse all.pls file
 and put information from this file
 to maps
 */
void Parser::start()
{
    QFile plik(":/all.pls");
    plik.open(QFile::ReadOnly);
    char *c=new char;

    for(int i=0;i<2;i++)
    {
        while(plik.getChar(c))
        {
            if(*c=='\n')
                break;
        }
    }

    //variable for remember file name
    QString file,ident;

    while(!plik.atEnd())
    {
        //get char for parse
        if(!plik.getChar(c))
            break;

        //variable for help
        QString tmp="";
        tmp.append(*c);

        //get first three chars
        for(int i=0;i<3;i++)
        {
            if(!plik.getChar(c))
                break;
            tmp.append(*c);
        }

        //if it`s file
        if(tmp=="File")
        {
            //gets all chars to '=' char
            while(*c!='=')
            {
                if(!plik.getChar(c))
                    break;
            }

            //clear tmp
            tmp="";

            //get one char
            if(!plik.getChar(c))
                break;

            while(*c!='\n')
            {
                //remember chars to string
                tmp.append(*c);

                //if getChar gets false break loop
                if(!plik.getChar(c))
                    break;
            }

            //qDebug(("file "+tmp).toAscii());
            //remember result
            file=tmp;
        }

        if(tmp=="Iden")
        {
            //gets all chars to '=' char
            while(*c!='=')
            {
                if(!plik.getChar(c))
                    break;
            }

            //clear tmp
            tmp="";

            //get one char
            if(!plik.getChar(c))
                break;

            while(*c!='\n')
            {
                //remember chars to string
                tmp.append(*c);

                //if getChar gets false break loop
                if(!plik.getChar(c))
                    break;
            }

            //qDebug(("file "+tmp).toAscii());
            //remember result
            ident=tmp;
        }


        //if this is title
        if(tmp=="Titl")
        {
            //gets all chars to '=' char
            while(*c!='=')
            {
                if(!plik.getChar(c))
                    break;
            }

            //clear tmp variable
            tmp="";

            //get one char
            if(!plik.getChar(c))
                break;

            //get all chars to new line
            while(*c!='\n')
            {
                //remember chars to tmp
                tmp.append(*c);

                if(!plik.getChar(c))
                    break;
            }
            //remember results to map
            (*stacje)[tmp]=file;
            (*identyfikatory)[tmp]=ident;
        }

    }
    qDebug("Stations list parsed");
}
