#include "loader.h"
#include "ui_loader.h"
#include <QMovie>
#include <QPixmap>

loader::loader(QWidget *parent): QWidget(parent), ui(new Ui::Form)
{
    ui->setupUi(this);
    QMovie *m=new QMovie(":/strzalka.gif");
    ui->gif->setMovie(m);
    m->start();

    setWindowFlags( Qt::FramelessWindowHint);

    setFixedSize(200,200);
}
