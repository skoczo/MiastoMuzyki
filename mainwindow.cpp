#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_oknoprogramu.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    //ui(new Ui::MainWindow)
    ui(new Ui::OknoProgramu)
{
    //set application name
    QCoreApplication::setApplicationName("MiastoMuzyki");
    ui->setupUi(this);
    setWindowTitle("Miasto Muzyki");

    //set description colors
    ui->tytul->setText(tr("<font color=yellow>Tutuł: </font>"));
    ui->wykonawca->setText(tr("<font color=yellow>Artysta: </font>"));
    ui->teraz->setText(tr("<font color=yellow>Teraz leci</font>"));
    ui->plyta->setText(tr("<font color=yellow>Plyta: </font>"));
    ui->rok->setText(tr("<font color=yellow>Rok: </font>"));

    ui->label->setText(tr("<font color=yellow>Następna</font>"));
    ui->label_2->setText(tr("<font color=yellow>Artysta: </font>"));
    ui->label_3->setText(tr("<font color=yellow>Tutuł: </font>"));
    ui->label_4->setText(tr("<font color=yellow>Plyta: </font>"));
    ui->label_5->setText(tr("<font color=yellow>Rok: </font>"));

    //add deader with MiastoMuzyki logo
    ui->header->setPixmap(QPixmap(":/header.jpg").scaledToWidth(250));

    //set background
    setStyleSheet("QMainWindow { background-color: #182838; }");

    //ui->listWidget->setStyleSheet("QWidget {background-color: #182838;}");

    mediaObject = new Phonon::MediaObject(this);
    audioOutput = new Phonon::AudioOutput(Phonon::MusicCategory, this);

    if(mediaObject==NULL||mediaObject->errorType()!=0||audioOutput==NULL)
    {
        if(mediaObject!=NULL)
            QMessageBox::critical(this,tr("Błąd!"),tr("Nie można uruchomić serwera dźwięku.\nByć może jest zjęty przez inny program.")+
                              tr("\nAplikacja zostanie zamknięta."+mediaObject->errorType())
                              ,QMessageBox::Ok);
        else
            QMessageBox::critical(this,tr("Błąd!"),tr("Nie można uruchomić serwera dźwięku.\nByć może jest zjęty przez inny program.")+
                              tr("\nAplikacja zostanie zamknięta.")
                              ,QMessageBox::Ok);
        exit(-1);
    }

    path = Phonon::createPath(mediaObject, audioOutput);

    while(!path.isValid())
    {
        if(QMessageBox::Ok==QMessageBox::critical(this,tr("Błąd!"),tr("Path is not vaild.\nAplikacja zostanie zamknięta."),QMessageBox::Ok|QMessageBox::Retry))
            exit(-1);
        else
            path.reconnect(mediaObject,audioOutput);
    }

    //debuging audio output
    if (audioOutput->isMuted()) { std::cout << "Volume: MUTED!\n"; } else { std::cout << "Volume: NOT MUTED.\n"; }
    if (mediaObject->state() == Phonon::LoadingState) { std::cout << "state 0\n"; }
    if (mediaObject->isSeekable()) { std::cout << "Seekable!\n"; } else { std::cout << "NOT SEEKABLE!\n"; }

    //this object gets <station_name,station_url>
    //need this for play station
    stations=new QMap<QString,QString>;

    //this object gets <station_name,station_number>
    //need this for get actual information about station
    identificators=new QMap<QString,QString>;

    //file parser
    //this class add stations to window
    Parser *p=new Parser(stations,identificators);
    p->start();

    //class which load images
    load=new imageLoad();
    loadNext=new imageLoad();

    //this is list of tracks (actual and next)
    lis=new list();

    //this class puts track info to lis
    //lis get info about actual and next track
    info=new trackInfo(identificators,lis);

    //add parsed data from QMapIterator<QString,QString> to window
    this->loadDataToList();

    //wait for new song
    data=new dataUpdater(mediaObject);

    //if new song
    connect(data,SIGNAL(newSong()),this,SLOT(newSong()));
    //if track info emit e_dane run aktualizacja function
    connect(info,SIGNAL(dataReady()),this,SLOT(update()));
    //this function load actual track image to label
    connect(load,SIGNAL(image(QPixmap*)),this,SLOT(image(QPixmap*)));
    //this function load next track image to label
    connect(loadNext,SIGNAL(image(QPixmap*)),this,SLOT(imageNext(QPixmap*)));

    //timer
    timer=new QTimer(this);
    //timer run update function
    connect(timer,SIGNAL(timeout()),data,SLOT(update()));
    //run this function every 1 second
    timer->start(1000);
}

/*this function update information about
  track in window. Load title and others information
  and cd picture
  */
void MainWindow::update()
{
    if(lis!=NULL)
    {
    //load txt data
    ui->TerazPlyta->setText("<font color=yellow>"+stringChange(lis->aktualny.plyta)+"</font>");
    ui->TerazRok->setText("<font color=yellow>"+stringChange(lis->aktualny.rok)+"</font>");
    ui->TerazTytul->setText("<font color=yellow>"+stringChange(lis->aktualny.tytul)+"</font>");
    ui->TerazWykonawca->setText("<font color=yellow>"+stringChange(lis->aktualny.wykonawca)+"</font>");

    ui->NastepnaWykonawca->setText("<font color=yellow>"+stringChange(lis->nastepny.wykonawca)+"</font>");
    ui->NastepnaPlyta->setText("<font color=yellow>"+stringChange(lis->nastepny.plyta)+"</font>");
    ui->NastepnaRok->setText("<font color=yellow>"+stringChange(lis->nastepny.rok)+"</font>");
    ui->NastepnaTytul->setText("<font color=yellow>"+stringChange(lis->nastepny.tytul)+"</font>");


    //this if`s loads played track picture
    //url picture depends aktualny->ipd length
    if(lis->aktualny.idp.length()>4)
    {
        load->load("http://doc.rmf.pl/media/img_muzyka/plyta/"+lis->aktualny.idp[0]+lis->aktualny.idp[1]+"/"+lis->aktualny.idp+".jpg");
        qDebug(("http://doc.rmf.pl/media/img_muzyka/plyta/"+lis->aktualny.idp[0]+lis->aktualny.idp[1]+"/"+lis->aktualny.idp+".jpg").toAscii());
    }
    else if(lis->aktualny.idp.length()==4)
    {
        load->load("http://doc.rmf.pl/media/img_muzyka/plyta/"+lis->aktualny.idp[0]+"/"+lis->aktualny.idp+".jpg");
        qDebug(("http://doc.rmf.pl/media/img_muzyka/plyta/"+lis->aktualny.idp[0]+"/"+lis->aktualny.idp+".jpg").toAscii());
    }
    else
    {
        if(lis->aktualny.idp.length()>0)
            load->load("http://doc.rmf.pl/media/img_muzyka/plyta/0/"+lis->aktualny.idp+".jpg");
        else
            image(new QPixmap(":/brak.jpg"));

        qDebug(("http://doc.rmf.pl/media/img_muzyka/plyta/0/"+lis->aktualny.idp+".jpg").toAscii());
    }

    //this if`s do that same but to next song
    if(lis->nastepny.idp.length()>4)
    {
        loadNext->load("http://doc.rmf.pl/media/img_muzyka/plyta/"+lis->nastepny.idp[0]+lis->nastepny.idp[1]+"/"+lis->nastepny.idp+".jpg");
        qDebug(("http://doc.rmf.pl/media/img_muzyka/plyta/"+lis->nastepny.idp[0]+lis->nastepny.idp[1]+"/"+lis->nastepny.idp+".jpg").toAscii());
    }
    else if(lis->nastepny.idp.length()==4)
    {
        loadNext->load("http://doc.rmf.pl/media/img_muzyka/plyta/"+lis->nastepny.idp[0]+"/"+lis->nastepny.idp+".jpg");
        qDebug(("http://doc.rmf.pl/media/img_muzyka/plyta/"+lis->nastepny.idp[0]+"/"+lis->nastepny.idp+".jpg").toAscii());
    }
    else
    {
        if(lis->nastepny.idp>0)
            loadNext->load("http://doc.rmf.pl/media/img_muzyka/plyta/0/"+lis->nastepny.idp+".jpg");
        else
            imageNext(new QPixmap(":/brak.jpg"));

        qDebug(("http://doc.rmf.pl/media/img_muzyka/plyta/0/"+lis->nastepny.idp+".jpg").toAscii());
    }
    }
}

/*
 this function add to string <br>
 <br> makes new line
 */
QString MainWindow::stringChange(QString s)
{
    int i=10;

    while(i<s.length())
    {
        for(int j=i;j<i+6;j++)
        {
            if(j<s.length())
            {
                if(s[j]==' ')
                {
                    s.insert(j,"<br>");
                    i=j;
                    break;
                }
            }
        }
        i+=12;
    }
    return s;
}

/*
 load image actual track
 */
void MainWindow::image(QPixmap *p)
{
    if(p!=NULL)
    {
        ui->Okladka->setPixmap(*p);
        ui->Okladka->adjustSize();
    }
    else
    {
        ui->Okladka->setPixmap(QPixmap(":/brak.jpg"));
        ui->Okladka->adjustSize();
    }

    this->adjustSize();
}

/*
 load image next track
 */
void MainWindow::imageNext(QPixmap *p)
{
    if(p!=NULL)
    {
        ui->NastepnaOkladka->setPixmap(*p);
        ui->NastepnaOkladka->adjustSize();
    }
    else
    {
        ui->NastepnaOkladka->setText("<font color=yellow>Brak obrazka</font>");
        ui->NastepnaOkladka->adjustSize();
    }

    this->adjustSize();
}

/*
 this slot update information about tracks
 */
void MainWindow::newSong()
{
//    info->show(ui->listWidget->item(ui->listWidget->currentRow())->text());
    if(actualStation.length()>0)
        info->show(actualStation);
}

/*
 add stations names to window list widget
 */
void MainWindow::loadDataToList()
{
    QMapIterator<QString,QString> i(*stations);

    while(i.hasNext())
    {
        i.next();

        ui->listWidget->addItem(i.key());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
play clicked station
 */
void MainWindow::on_listWidget_doubleClicked(QModelIndex index)
{
    mediaObject->stop();
    int row=index.row();
    actualStation=ui->listWidget->item(row)->text();
    mediaObject->setCurrentSource(Phonon::MediaSource((*stations)[actualStation]));
    mediaObject->play();

    info->show(actualStation);
}
