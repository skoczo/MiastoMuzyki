#include "options.h"

Options::Options(QWidget *parent) :
	QDialog(parent), ui(new Ui::OptionsClass) {
	ui->setupUi(this);
	setWindowTitle("Opcje");
	ok = new QPushButton(tr("Ok"), this);
	cancel = new QPushButton(tr("Anuluj"), this);
	ui->buttons->addWidget(ok);
	ui->buttons->addWidget(cancel);

	connect(cancel, SIGNAL(clicked()), this, SLOT(slot_cancel()));
	connect(ok, SIGNAL(clicked()), this, SLOT(slot_ok()));

	QString *xmlFile;
	QFile f("options.xml");
	f.open(QFile::ReadOnly);
	xmlFile = new QString(f.readAll());
	f.close();

	QXmlStreamReader * xmlReader = new QXmlStreamReader(*xmlFile);

	while (!xmlReader->atEnd()) {
		xmlReader->readNext();
		if (xmlReader->isStartElement()) {
			// Read the tag name.
			QString sec(xmlReader->name().toString());
			// Check in settings map, whether there's already an entry. If not, insert.
			if (sec.contains("options")) {
				QXmlStreamAttributes a = xmlReader->attributes();
				QStringRef ref = a.value("notifications");

				qDebug() << "Notifications attributes: ";
				qDebug() << ref.toString();

				if (ref.toString() == "\"false\"") {
					ui->notyfikacje->setCheckState(Qt::Unchecked);
				} else {
					ui->notyfikacje->setCheckState(Qt::Checked);
				}
			}
		}
	}
}

Options::~Options() {

}

bool Options::isChecket() {
	return ui->notyfikacje->checkState() == Qt::Checked;
}

void Options::slot_ok() {
	QString *xmlFile = new QString();
	QXmlStreamWriter xml(xmlFile);
	xml.setAutoFormatting(true);
	xml.writeStartDocument();
	xml.writeStartElement("options");

	if (ui->notyfikacje->checkState() == Qt::Checked)
		xml.writeAttribute("notifications", "true");
	else
		xml.writeAttribute("notifications", "false");

	xml.writeEndElement();
	xml.writeEndDocument();

	QFile f("options.xml");
	f.open(QFile::WriteOnly);
	f.write(xmlFile->toAscii());
	f.close();

	hide();
}

void Options::slot_cancel() {
	hide();
}
