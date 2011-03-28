#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <QStringList>
#include <QWaitCondition>
#include <QFile>
#include <QPicture>
#include <QMainWindow>
#include <QListWidget>
#include <QtWebKit/QWebView>
#include <QThread>
#include <QUrl>
#include <QMap>
#include <QMapIterator>
#include <QTimer>
#include <phonon/MediaObject>
#include <phonon/phonon>
#include <phonon/AudioOutput>
#include <QMessageBox>
#include <QNetworkProxy>
#include <BackendCapabilities>
#include <QProgressBar>
#include "parser.h"
#include "trackinfo.h"
#include "lista.h"
#include "imageload.h"
#include "proxydialog.h"
#include "loader.h"

namespace Ui {
    class MainWindow;
    class OknoProgramu;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void setLoader(loader &l);
    ~MainWindow();

private:
    //window ui
    //Ui::MainWindow *ui;
    Ui::OknoProgramu *ui;

    loader *l;

    //phonon objects to play music
    Phonon::MediaObject *mediaObject;
    Phonon::AudioOutput *audioOutput;
    Phonon::Path path;

    /**
    *this maps have information about stations
    *    stations<station name, station url>
    *    identyficators<station name, station number>
    */
    QMap<QString,QString> *stations;
    QMap<QString,QString> *identificators;

    //variable to check play/stop
    bool isPlay;

    QTimer *timer;
    trackInfo *info;
    list *lis;
    imageLoad *load;
    imageLoad *loadNext;

    QString stringChange(QString s);
    QString actualStation;

    proxyDialog *proxyDial;

    QProgressBar *progressBar;

    void loadDataToList();

private slots:
    void on_actionUstawienia_triggered();
    void on_listWidget_doubleClicked(QModelIndex index);
    void checkPlayList();
    void update();
    void image(QPixmap *p);
    void imageNext(QPixmap *p);
    void setProxy(QNetworkProxy p);
    void test(int i);
    void setVolume(int);
    void play_pause();

   signals:
    void closeLoader();
};

#endif // MAINWINDOW_H
