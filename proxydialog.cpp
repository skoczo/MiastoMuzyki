#include "proxydialog.h"
#include "ui_proxyDialog.h"

proxyDialog::proxyDialog(QWidget *parent) : QDialog(parent),
ui(new Ui::proxyDialog)
{
	ui->setupUi(this);

    if(parent==0||parent==NULL)
    {
        QMessageBox::critical(this,tr("Błąd aplikacji"),
                              tr("Do okna ustawień przekazany został błędny wskaźnik. "
                                 "Skontaktuj się z autorem programu.")
                              ,QMessageBox::Ok);
        this->hide();
    }
    else
    {
        this->parent=parent;
        ok=new QPushButton(tr("Ok"),this);
        cancel=new QPushButton(tr("Anuluj"),this);
        ui->buttons->addWidget(ok);
        ui->buttons->addWidget(cancel);

        connect(ui->type,SIGNAL(currentIndexChanged(int)),this,SLOT(type_change(int)));
        connect(ok,SIGNAL(clicked()),this,SLOT(slot_ok()));
        connect(cancel,SIGNAL(clicked()),this,SLOT(slot_cancel()));

        ui->name->setDisabled(true);
        ui->port->setDisabled(true);
        ui->password->setDisabled(true);
        ui->user->setDisabled(true);

        ui->type->setCurrentIndex(2);
    }
}

proxyDialog::~proxyDialog() {
	if (ui != NULL)
		delete ui;

	if (ok != NULL)
		delete ok;

	if (cancel != NULL)
		delete cancel;
}

void proxyDialog::type_change(int c)
{
    if(c==2)
    {
        ui->name->setDisabled(true);
        ui->port->setDisabled(true);
        ui->password->setDisabled(true);
        ui->user->setDisabled(true);
    }
    else
    {
        ui->name->setEnabled(true);
        ui->port->setEnabled(true);
        ui->password->setEnabled(true);
        ui->user->setEnabled(true);
    }

}

void proxyDialog::slot_ok()
{
    QNetworkProxy proxy;
    proxy.setUser(ui->user->text());
    proxy.setPort(ui->port->text().toInt());
    proxy.setPassword(ui->password->text());
    proxy.setHostName(ui->name->text());
    proxy.setType((QNetworkProxy::ProxyType)ui->type->currentIndex());

    emit data_ok(proxy);

    hide();
}

void proxyDialog::slot_cancel()
{
    hide();
}
