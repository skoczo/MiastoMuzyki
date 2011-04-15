#ifndef PROXYDIALOG_H
#define PROXYDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QNetworkProxy>
#include <QMessageBox>

namespace Ui {
    class proxyDialog;
}

class proxyDialog : public QDialog
{
    Q_OBJECT
public:
    explicit proxyDialog(QWidget *parent=0);

private:
    QWidget *parent;
    Ui::proxyDialog *ui;
    QPushButton *ok,*cancel;

public slots:
    void slot_ok();
    void slot_cancel();
    void type_change(int c);

signals:
    void data_ok(QNetworkProxy);

};

#endif // PROXYDIALOG_H
