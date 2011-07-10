#include "mainwindow.h"
#include "ui_oknoprogramu.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent), ui(new Ui::OknoProgramu) {
	isPlay = false;

	setApplicationSettings();

    splash = new QSplashScreen(this, QPixmap(":/splashHeader.jpg"));
    splash->show();
    splash->showMessage(tr("Tworzenie okna"), Qt::AlignCenter | Qt::AlignBottom);


    QStringList capabiliteisList = Phonon::BackendCapabilities::availableMimeTypes();
    capabiliteisList.sort();
    qDebug("########Cap Start###########");
    for(int i = 0;i < capabiliteisList.size();i++){
        qDebug() << QString(capabiliteisList[i]);
    }
    qDebug("########Cap End###########");


    //proxy
    proxyDial = new proxyDialog(this);
    //options
    optionsDial = new Options(this);

    setWindowObjects();

    splash->showMessage(tr("Uruchamianie phonon"), Qt::AlignCenter | Qt::AlignBottom);

    startPhonon();

    createMainWindowObjectVariables();

    //file parser
    //this class add stations to window
    splash->showMessage(tr("Ładowanie listy stacji"), Qt::AlignCenter | Qt::AlignBottom);

    //download and parse playlist
    p = new Parser();
    //add parsed data from QMapIterator<QString,QString> to window
    connect(p, SIGNAL(send(QMap<QString,QString>*,QMap<QString,QString>*)),
			this, SLOT(recive(QMap<QString,QString>*,QMap<QString,QString>*)));
    connect(p, SIGNAL(fail()), this, SLOT(stationsFailed()));
    p->start();

    connectSignalsAndSlots();

    //timer
    timer = new QTimer(this);
    //timer run update function
    connect(timer, SIGNAL(timeout()), this, SLOT(checkPlayList()));
    //run this function every 5 second
    timer->start(5000);
    //center
    move((QApplication::desktop()->width() / 2 - width() / 2), (QApplication::desktop()->height() / 2 - height() / 2));
    audioOutput->setVolume((qreal)(1));

	tray.setIcon(QIcon(":/images/icon.ico"));
	tray.show();
}

void MainWindow::setVolume(int i) {
	audioOutput->setVolume((qreal) i / 100.f);
}

void MainWindow::iconClicked(QSystemTrayIcon::ActivationReason event) {
	if (event == QSystemTrayIcon::DoubleClick) {
		if (isVisible())
			setVisible(false);
		else
			setVisible(true);
	}
}

void MainWindow::stationsFailed() {
	splash->finish(this);

	if (QMessageBox::Ok == QMessageBox::information(
			this, tr("Błąd"), tr( "<center>Błąd przy odbieraniu listy stacji. <br>Ponowić próbę?</center>"), QMessageBox::Ok, QMessageBox::Cancel))
	{
		splash->show();
		p->start();
	}

	else
	{
		close();
	}
}

void MainWindow::about() {
	QMessageBox::about(
			this,
			tr("Informacje o programie"),
			tr(
					"<center>"
						"Autor: Adrian Skoczylas<br><br>"
						"Program do słuchania stacji MiastaMuzyki<br><br>"
						"Wersja: " + version.toAscii()
							+ "<br><br>"
								"Nowe wersje programu można ściągnąć ze strony: <a href='http://sourceforge.net/projects/miastomuzyki/'>http://sourceforge.net/projects/miastomuzyki</a><br><br>"
								"Na powyższej stronie można również dokonać dotacji na projekt<br><br>"
								"Program udostępniony jest na wolnej licencji. Jego kod można ściągnąć ze strony:<br>"
								"<a href='http://github.com/skoczo/MiastoMuzyki'>http://github.com/skoczo/MiastoMuzyki</a>"
								"</center>"));
}

//test slot
void MainWindow::test(int i) {
	std::stringstream ss;
	ss << i;
	qDebug("test buffer: ");
	qDebug() << ss.str().c_str();
	progressBar->setValue(i);
}

/*proxy setup function*/
void MainWindow::setProxy(QNetworkProxy p) {
	mediaObject->stop();

	QNetworkProxy::setApplicationProxy(p);

	qDebug("Proxy setup");
}

bool MainWindow::newData() {
	static list old;
	bool result = false;

	if (old.actual.disk != lis->actual.disk) {
		result = true;
		old.actual.disk = lis->actual.disk;
	}

	if (old.actual.artist != lis->actual.artist) {
		result = true;
		old.actual.artist = lis->actual.artist;
	}

	if (old.actual.idp != lis->actual.idp) {
		result = true;
		old.actual.idp = lis->actual.idp;
	}

	if (old.actual.title != lis->actual.title) {
		result = true;
		old.actual.title = lis->actual.title;
	}

	if (old.actual.year != lis->actual.year) {
		result = true;
		old.actual.year = lis->actual.year;
	}

	if (old.next.disk != lis->next.disk) {
		result = true;
		old.next.disk = lis->next.disk;
	}

	if (old.next.artist != lis->next.artist) {
		result = true;
		old.next.artist = lis->next.artist;
	}

	if (old.next.idp != lis->next.idp) {
		result = true;
		old.next.idp = lis->next.idp;
	}

	if (old.next.title != lis->next.title) {
		result = true;
		old.next.title = lis->next.title;
	}

	if (old.next.year != lis->next.year) {
		result = true;
		old.next.year = lis->next.year;
	}

	return result;
}

void MainWindow::showTrayMessage() {
	if (optionsDial->isChecket()) {
		tray.showMessage(
				"Aktualna piosenka",
				"Artysta: " + lis->actual.artist + tr("\nTytuł: ")
				+ lis->actual.title, QSystemTrayIcon::NoIcon, 3000);
	}
}

/*this function update information about
 track in window. Load title and others information
 and cd picture
 */
void MainWindow::update() {
	if (lis != NULL) {
		if (newData()) {
			showTrayMessage();

			//load txt data
			ui->TerazPlyta->setText(
					"<font color=yellow>" + stringChange(lis->actual.disk)
							+ "</font>");

			ui->TerazRok->setText(
					"<font color=yellow>" + stringChange(lis->actual.year)
							+ "</font>");

			ui->TerazTytul->setText(
					"<font color=yellow>" + stringChange(lis->actual.title)
							+ "</font>");

			ui->TerazWykonawca->setText(
					"<font color=yellow>" + stringChange(lis->actual.artist)
							+ "</font>");

			ui->NastepnaWykonawca->setText(
					"<font color=yellow>" + stringChange(lis->next.artist)
							+ "</font>");

			ui->NastepnaPlyta->setText(
					"<font color=yellow>" + stringChange(lis->next.disk)
							+ "</font>");

			ui->NastepnaRok->setText(
					"<font color=yellow>" + stringChange(lis->next.year)
							+ "</font>");

			ui->NastepnaTytul->setText(
					"<font color=yellow>" + stringChange(lis->next.title)
							+ "</font>");

			//this loads played track picture
			//url picture depends aktualny->ipd length
			if (lis->actual.idp.length() > 4) {
				load->load(
						"http://doc.rmf.pl/media/img_muzyka/plyta/"
								+ lis->actual.idp[0] + lis->actual.idp[1] + "/"
								+ lis->actual.idp + ".jpg");
				qDebug() << ("http://doc.rmf.pl/media/img_muzyka/plyta/"
						+ lis->actual.idp[0] + lis->actual.idp[1] + "/"
						+ lis->actual.idp + ".jpg");
			} else if (lis->actual.idp.length() == 4) {
				load->load(
						"http://doc.rmf.pl/media/img_muzyka/plyta/"
								+ lis->actual.idp[0] + "/" + lis->actual.idp
								+ ".jpg");
				qDebug() << ("http://doc.rmf.pl/media/img_muzyka/plyta/"
						+ lis->actual.idp[0] + "/" + lis->actual.idp + ".jpg");
			} else {
				if (lis->actual.idp.length() > 0)
					load->load(
							"http://doc.rmf.pl/media/img_muzyka/plyta/0/"
									+ lis->actual.idp + ".jpg");
				else {
					image(new QPixmap(":/zaslepka.jpg"));
					//image(NULL);
				}

				qDebug() << ("http://doc.rmf.pl/media/img_muzyka/plyta/0/"
						+ lis->actual.idp + ".jpg");
			}

			//this do that same but for the next song
			if (lis->next.idp.length() > 4) {
				loadNext->load(
						"http://doc.rmf.pl/media/img_muzyka/plyta/"
								+ lis->next.idp[0] + lis->next.idp[1] + "/"
								+ lis->next.idp + ".jpg");
				qDebug() << ("http://doc.rmf.pl/media/img_muzyka/plyta/"
						+ lis->next.idp[0] + lis->next.idp[1] + "/"
						+ lis->next.idp + ".jpg");
			} else if (lis->next.idp.length() == 4) {
				loadNext->load(
						"http://doc.rmf.pl/media/img_muzyka/plyta/"
								+ lis->next.idp[0] + "/" + lis->next.idp
								+ ".jpg");
				qDebug() << ("http://doc.rmf.pl/media/img_muzyka/plyta/"
						+ lis->next.idp[0] + "/" + lis->next.idp + ".jpg");
			} else {
				if (lis->next.idp > 0)
					loadNext->load(
							"http://doc.rmf.pl/media/img_muzyka/plyta/0/"
									+ lis->next.idp + ".jpg");
				else {
					imageNext(new QPixmap(":/zaslepka.jpg"));
					//imageNext(NULL);
				}

				qDebug() << ("http://doc.rmf.pl/media/img_muzyka/plyta/0/"
						+ lis->next.idp + ".jpg");
			}
		}
	}
}

/*
 this function add to string <br>
 <br> makes new line
 */
QString MainWindow::stringChange(QString s) {
	int i = 10;

	while (i < s.length()) {
		for (int j = i; j < i + 6; j++) {
			if (j < s.length()) {
				if (s[j] == ' ') {
					s.insert(j, "<br>");
					i = j;
					break;
				}
			}
		}
		i += 12;
	}
	return s;
}

/*
 load image actual track
 */
void MainWindow::image(QPixmap *p) {
	if (p != NULL) {
		ui->Okladka->setPixmap(*p);
	} else {
		ui->Okladka->setPixmap(QPixmap(":/zaslepka.jpg"));
	}

	this->adjustSize();
}

/*
 load image next track
 */
void MainWindow::imageNext(QPixmap *p) {
	if (p != NULL) {
		ui->NastepnaOkladka->setPixmap(*p);
	} else {
		ui->NastepnaOkladka->setPixmap(QPixmap(":/zaslepka.jpg"));
	}

	this->adjustSize();
}

/*
 this slot update information about tracks
 */
void MainWindow::checkPlayList() {
	if (actualStation.length() > 0 && isPlay)
		info->show(actualStation);
}

void MainWindow::recive(QMap<QString, QString>* s, QMap<QString, QString>* i) {
	splash->finish(this);
	stations = s;
	identificators = i;

	this->loadDataToList();
	info->setInfo(i);

	ui->listWidget->setCurrentRow(0);

	this->show();
}

/*
 add stations names to window list widget
 */
void MainWindow::loadDataToList() {
	QMapIterator<QString, QString> i(*stations);

	while (i.hasNext()) {
		i.next();

		ui->listWidget->addItem(tr(i.key().toAscii()));
	}
}

MainWindow::~MainWindow() {
	delete ui;

        if (mediaObject != NULL)
		delete mediaObject;

	if (audioOutput != NULL)
		delete audioOutput;

	if (stations != NULL)
		delete stations;

	if (identificators != NULL)
		delete identificators;

        if (timer != NULL)
                delete timer;

	if (info != NULL)
		delete info;

	if (lis != NULL)
		delete lis;

	if (load != NULL)
		delete load;

	if (loadNext != NULL)
		delete loadNext;

	if (proxyDial != NULL)
		delete proxyDial;

	if (optionsDial != NULL)
		delete optionsDial;

	if (progressBar != NULL)
		delete progressBar;

	if (p != NULL)
		delete p;

	if (splash != NULL)
		delete splash;
}

/**
 play clicked station
 */
void MainWindow::on_listWidget_doubleClicked(QModelIndex index) {
	if (isPlay) {
		mediaObject->stop();
	} else {
		isPlay = true;
		ui->play_pause->setText("Stop");
	}

	int row = index.row();
	actualStation = ui->listWidget->item(row)->text();
	qDebug() << "Station name: " + ui->listWidget->item(row)->text() + "\n";
	qDebug() << "Station url: " + (*stations)[actualStation] + "\n";
	mediaObject->setCurrentSource(QUrl((*stations)[actualStation]));
	mediaObject->play();

	info->show(actualStation);
}

/**
 * play/stop button clicked
 */
void MainWindow::play_pause() {
	if (!isPlay) {
		mediaObject->stop();
		int row = ui->listWidget->currentRow();
		actualStation = ui->listWidget->item(row)->text();
		qDebug() << "Station name: " + ui->listWidget->item(row)->text() + "\n";
		qDebug() << "Station url: " + (*stations)[actualStation] + "\n";
		mediaObject->setCurrentSource(
				Phonon::MediaSource(QUrl((*stations)[actualStation])));
		mediaObject->play();
		info->show(actualStation);
		ui->play_pause->setText("Stop");
		isPlay = true;
	} else {
		mediaObject->stop();
		ui->play_pause->setText("Play");
		isPlay = false;
	}

}

void MainWindow::on_actionUstawienia_triggered() {
	QMessageBox::information(this, tr("Nie przetestowane"),
			tr("Nie testowałem tej opcji.<br>"
				"Jeśli działa lub nie to proszę dać znać na<br>"
				"stronie programu."));
	proxyDial->show();
}

void MainWindow::options() {
	optionsDial->show();
}

void MainWindow::setApplicationSettings()
{
    setWindowIcon(QIcon(":/images/icon.ico"));
    //set application name
    QCoreApplication::setApplicationName("MiastoMuzyki");
    ui->setupUi(this);
    setWindowTitle("Miasto Muzyki");
}

void MainWindow::setWindowObjects()
{
    //set description colors
    ui->tytul->setText(tr("<font color=yellow>Tytuł: </font>"));
    ui->wykonawca->setText(tr("<font color=yellow>Artysta: </font>"));
    ui->teraz->setText(tr("<font color=yellow>Teraz leci</font>"));
    ui->plyta->setText(tr("<font color=yellow>Płyta: </font>"));
    ui->rok->setText(tr("<font color=yellow>Rok: </font>"));
    ui->label->setText(tr("<font color=yellow>Następna</font>"));
    ui->label_2->setText(tr("<font color=yellow>Artysta: </font>"));
    ui->label_3->setText(tr("<font color=yellow>Tytuł: </font>"));
    ui->label_4->setText(tr("<font color=yellow>Płyta: </font>"));
    ui->label_5->setText(tr("<font color=yellow>Rok: </font>"));
    //add header with MiastoMuzyki logo
    ui->header->setPixmap(QPixmap(":/header.jpg").scaledToWidth(250));
    //set background
    setStyleSheet("QMainWindow { background-color: #182838; }");
}

void MainWindow::startPhonon() {
	mediaObject = new Phonon::MediaObject(this);
	audioOutput = new Phonon::AudioOutput(Phonon::MusicCategory, this);
	if (mediaObject == NULL || mediaObject->errorType() != 0 || audioOutput
			== NULL) {
		if (mediaObject != NULL)
			QMessageBox::critical(
					this,
					tr("Błąd!"),
					tr(
							"Nie można uruchomić serwera dźwięku.\nByć może jest zjęty przez inny program.")
							+ tr(
									"\nAplikacja zostanie zamknięta."
											+ mediaObject->errorType()),
					QMessageBox::Ok);

		else
			QMessageBox::critical(
					this,
					tr("Błąd!"),
					tr(
							"Nie można uruchomić serwera dźwięku.\nByć może jest zjęty przez inny program.")
							+ tr("\nAplikacja zostanie zamknięta."),
					QMessageBox::Ok);

		exit(-1);
	}
	path = Phonon::createPath(mediaObject, audioOutput);
	while (!path.isValid()) {
		if (QMessageBox::Ok == QMessageBox::critical(this, tr("Błąd!"),
				tr("Path is not vaild.\nAplikacja zostanie zamknięta."),
				QMessageBox::Ok | QMessageBox::Retry))
			exit(-1);

		else
			path.reconnect(mediaObject, audioOutput);

	}
	//debuging audio output
	if (audioOutput->isMuted()) {
		std::cout << "Volume: MUTED!\n";
	} else {
		std::cout << "Volume: NOT MUTED.\n";
	}
	if (mediaObject->state() == Phonon::LoadingState) {
		std::cout << "state 0\n";
	}
	if (mediaObject->isSeekable()) {
		std::cout << "Seekable!\n";
	} else {
		std::cout << "NOT SEEKABLE!\n";
	}
}

void MainWindow::createMainWindowObjectVariables() {
	//this object gets <station_name,station_url>
	//need this for play station
	stations = new QMap<QString, QString> ;
	//this object gets <station_name,station_number>
	//need this for get actual information about station
	identificators = new QMap<QString, QString> ;
	//class which load images
	load = new imageLoad();
	loadNext = new imageLoad();
	//this is list of tracks (actual and next)
	lis = new list();
	//this class puts track info to lis
	//lis get info about actual and next track
	info = new trackInfo(identificators, lis);
	//progress bar
	progressBar = new QProgressBar(ui->statusBar);
	//hide progress bar because it does`t work
	progressBar->setVisible(false);
	progressBar->setRange(0, 100);
	//connect(mediaObject, SIGNAL(bufferStatus(int)), this, SLOT(test(int)));
	//set volume widget
	//hide old volume widget
	ui->volume->setVisible(false);

    //new volume widget which set volume to clicked
	FastSlider *volume = new FastSlider(this);
	volume->setRange(0, 100);
	volume->setValue(100);
	volume->setOrientation(Qt::Horizontal);
	ui->horizontalLayout_5->addWidget(volume);
	connect(volume, SIGNAL(valueChanged(int)), this, SLOT(setVolume(int)));
}

void MainWindow::connectSignalsAndSlots()
{
    //if track info emit e_dane run update function
    connect(info, SIGNAL(dataReady()), this, SLOT(update()));
    //this function load actual track image to label
    connect(load, SIGNAL(image(QPixmap*)), this, SLOT(image(QPixmap*)));
    //this function load next track image to label
    connect(loadNext, SIGNAL(image(QPixmap*)), this, SLOT(imageNext(QPixmap*)));
    //proxy setup
    connect(proxyDial, SIGNAL(data_ok(QNetworkProxy)), this,
			SLOT(setProxy(QNetworkProxy)));
    connect(ui->play_pause, SIGNAL(clicked()), this, SLOT(play_pause()));
    connect(ui->actionO_programie, SIGNAL(triggered()), this, SLOT(about()));
    connect(&tray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this,
			SLOT(iconClicked(QSystemTrayIcon::ActivationReason)));
    //play on enter key push
    connect(ui->listWidget, SIGNAL(activated(QModelIndex)), this,
			SLOT(on_listWidget_doubleClicked(QModelIndex)));
    connect(ui->actionOpcje, SIGNAL(triggered()), this, SLOT(options()));
}
