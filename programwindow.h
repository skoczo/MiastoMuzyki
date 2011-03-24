#ifndef OKNOPROGRAMU_H
#define OKNOPROGRAMU_H

#include <QMainWindow>

namespace Ui {
    class ProgramWindow;
}

class ProgramWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ProgramWindow(QWidget *parent = 0);
    ~ProgramWindow();

private:
    Ui::ProgramWindow *ui;
};

#endif // OKNOPROGRAMU_H
