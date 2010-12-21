#ifndef OKNOPROGRAMU_H
#define OKNOPROGRAMU_H

#include <QMainWindow>

namespace Ui {
    class OknoProgramu;
}

class OknoProgramu : public QMainWindow
{
    Q_OBJECT

public:
    explicit OknoProgramu(QWidget *parent = 0);
    ~OknoProgramu();

private:
    Ui::OknoProgramu *ui;
};

#endif // OKNOPROGRAMU_H
