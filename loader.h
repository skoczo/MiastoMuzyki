#ifndef LOADER_H
#define LOADER_H

#include <QWidget>

namespace Ui {
    class Form;
}

class loader : public QWidget
{
public:
    explicit loader(QWidget *parent=0);
private:
    Ui::Form *ui;
};

#endif // LOADER_H
