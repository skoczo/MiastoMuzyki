#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <QFile>
#include <QPicture>
#include <QMainWindow>
#include <QListWidget>
#include <QtWebKit/QWebView>
#include <QUrl>
#include <QMap>
#include <QMapIterator>
#include <QTimer>
#include <phonon/MediaObject>
#include <phonon/phonon>
#include <phonon/AudioOutput>
#include <QMessageBox>
#include "parser.h"
#include "dataupdater.h"
#include "trackinfo.h"
#include "lista.h"
#include "imageload.h"

namespace Ui {
    class MainWindow;
    class OknoProgramu;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    //window ui
    //Ui::MainWindow *ui;
    Ui::OknoProgramu *ui;

    //phonon objects to play music
    Phonon::MediaObject *mediaObject,*music;
    Phonon::AudioOutput *audioOutput;
    Phonon::Path path;

    /*this maps have information about stations
        stations<station name, station url>
        identyficators<station name, station number>
    */
    QMap<QString,QString> *stations;
    QMap<QString,QString> *identificators;


    dataUpdater *data;
    QTimer *timer;
    trackInfo *info;
    list *lis;
    imageLoad *load;
    imageLoad *loadNext;

    QString stringChange(QString s);
    QString actualStation;
    void loadDataToList();

private slots:
    void on_listWidget_doubleClicked(QModelIndex index);
    void newSong();
    void update();
    void image(QPixmap *p);
    void imageNext(QPixmap *p);
};

#endif // MAINWINDOW_H
