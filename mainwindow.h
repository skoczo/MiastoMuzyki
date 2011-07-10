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
#include <QDesktopWidget>
#include <QTimer>
#include <phonon/MediaObject>
#include <phonon/phonon>
#include <phonon/AudioOutput>
#include <QMessageBox>
#include <QNetworkProxy>
#include <BackendCapabilities>
#include <QProgressBar>
#include <QMouseEvent>
#include <QMessageBox>
#include <QSplashScreen>
#include <QSystemTrayIcon>
#include <QThread>
#include "parser.h"
#include "trackinfo.h"
#include "lista.h"
#include "imageload.h"
#include "proxydialog.h"
#include "options.h"

namespace Ui {
class MainWindow;
class OknoProgramu;
}
//program version
static QString version = "0.4.1";

class MainWindow: public QMainWindow {
Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

private:
    Ui::OknoProgramu *ui;
    Phonon::MediaObject *mediaObject;
    Phonon::AudioOutput *audioOutput;
    Phonon::Path path;
    QMap<QString,QString> *stations;
    QMap<QString,QString> *identificators;
    bool isPlay;
    QTimer *timer;
    trackInfo *info;
    list *lis;
    imageLoad *load;
    imageLoad *loadNext;
    QString stringChange(QString s);
    QString actualStation;
    proxyDialog *proxyDial;
    Options *optionsDial;
    QProgressBar *progressBar;
    Parser *p;
    QSplashScreen *splash;
    QSystemTrayIcon tray;
    void connectSignalsAndSlots();
    void loadDataToList();
    void hideShow(QWidget*, QWidget*, int);
    bool newData();
    void showTrayMessage();
    void startPhonon();
    void setApplicationSettings();
    void setWindowObjects();
    void createMainWindowObjectVariables();

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
    void about();
    void recive(QMap<QString,QString>*, QMap<QString,QString>*);
    void stationsFailed();
    void iconClicked(QSystemTrayIcon::ActivationReason event);
    void options();
};

class FastSlider: public QSlider {
Q_OBJECT
public:
	FastSlider(QWidget * parent = 0) :
		QSlider(parent) {
	}
private:
protected:
	void mousePressEvent(QMouseEvent * e) {
		int length, position;
		if (orientation() == Qt::Horizontal) {
			length = width();
			position = e->x();
		} else {
			length = height();
			position = e->y();
		}
		int valueRange = maximum() - minimum();
		int calculatedValue;
		if (orientation() == Qt::Horizontal)
			calculatedValue = (int) ((double) position / length * valueRange
					+ minimum());
		else
			calculatedValue = (int) ((double) (length - position) / length
					* valueRange + minimum());// orientations of y axis and value axis differs?
		setValue(calculatedValue);

		QSlider::mousePressEvent(e);
	}
};

#endif // MAINWINDOW_H
