#ifndef OPTIONS_H
#define OPTIONS_H

#include <QObject>
#include <QPushButton>
#include <QDialog>
#include <QString>
#include <QFile>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QXmlStreamAttributes>
#include <QDebug>
#include "ui_options.h"

namespace Ui {
class OptionsClass;
}

class Options: public QDialog {
Q_OBJECT

public:
	Options(QWidget *parent = 0);
	~Options();
	bool isChecket();

private:
	Ui::OptionsClass *ui;
	QPushButton *ok,*cancel;

private slots:
	void slot_cancel();
	void slot_ok();
};

#endif // OPTIONS_H
