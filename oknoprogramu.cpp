#include "oknoprogramu.h"
#include "ui_oknoprogramu.h"

OknoProgramu::OknoProgramu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OknoProgramu)
{
    ui->setupUi(this);
}

OknoProgramu::~OknoProgramu()
{
    delete ui;
}
