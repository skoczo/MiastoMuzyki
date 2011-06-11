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
	//window ui
	//Ui::MainWindow *ui;
	Ui::OknoProgramu *ui;

	//phonon objects to play music
	Phonon::MediaObject *mediaObject;
	Phonon::AudioOutput *audioOutput;
	Phonon::Path path;

	/**
	 *this maps have information about stations
	 *    stations<station name, station url>
	 *    identyficators<station name, station number>
	 */
	QMap<QString, QString> *stations;
	QMap<QString, QString> *identificators;

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
	Options *optionsDial;

	QProgressBar *progressBar;
	Parser *p;

	QSplashScreen *splash;

	QSystemTrayIcon tray;

	void loadDataToList();
	void hideShow(QWidget*, QWidget*, int);
	bool newData();
	void showTrayMessage();

private slots:
	void on_actionUstawienia_triggered();
	void on_listWidget_doubleClicked(QModelIndex index);
	void checkPlayList();
	//update listy utworow
	void update();
	//ustawienie obrazka dla aktualnego utworu
	void image(QPixmap *p);
	//ustawienie obrazka dla nastepnego utworu
	void imageNext(QPixmap *p);
	//ustawienie proxy dla aplikacji
	void setProxy(QNetworkProxy p);
	//funkcja do testowania bufora
	void test(int i);
	//ustawienie glosnosci
	void setVolume(int);
	// obsluga play\pause
	void play_pause();
	//okno informacji o programie
	void about();
	//funkcja odbierajaca liste stacji
	void recive(QMap<QString, QString>*, QMap<QString, QString>*);
	//jesli nie powiedzie sie odebranie listy stacji
	void stationsFailed();
	//jesli ikona kliknieta
	void iconClicked(QSystemTrayIcon::ActivationReason event);
	//pokazanie okna opcji
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
