#include "programwindow.h"
#include "ui_programwindow.h"

ProgramWindow::ProgramWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ProgramWindow)
{
    ui->setupUi(this);
}

ProgramWindow::~ProgramWindow()
{
    delete ui;
}
