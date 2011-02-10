/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Feb 10 18:43:12 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout;
    QLabel *teraz;
    QLabel *wykonawca;
    QLabel *TerazWykonawca;
    QLabel *tytul;
    QLabel *plyta;
    QLabel *TerazPlyta;
    QLabel *rok;
    QLabel *TerazRok;
    QLabel *Okladka;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QLabel *TerazTytul;
    QLabel *label;
    QLabel *NastepnaOkladka;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *NastepnaWykonawca;
    QLabel *NastepnaTytul;
    QLabel *NastepnaPlyta;
    QLabel *NastepnaRok;
    QVBoxLayout *verticalLayout;
    QLabel *header;
    QListWidget *listWidget;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(575, 430);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        teraz = new QLabel(centralWidget);
        teraz->setObjectName(QString::fromUtf8("teraz"));

        formLayout->setWidget(1, QFormLayout::LabelRole, teraz);

        wykonawca = new QLabel(centralWidget);
        wykonawca->setObjectName(QString::fromUtf8("wykonawca"));

        formLayout->setWidget(2, QFormLayout::LabelRole, wykonawca);

        TerazWykonawca = new QLabel(centralWidget);
        TerazWykonawca->setObjectName(QString::fromUtf8("TerazWykonawca"));

        formLayout->setWidget(2, QFormLayout::FieldRole, TerazWykonawca);

        tytul = new QLabel(centralWidget);
        tytul->setObjectName(QString::fromUtf8("tytul"));

        formLayout->setWidget(3, QFormLayout::LabelRole, tytul);

        plyta = new QLabel(centralWidget);
        plyta->setObjectName(QString::fromUtf8("plyta"));

        formLayout->setWidget(4, QFormLayout::LabelRole, plyta);

        TerazPlyta = new QLabel(centralWidget);
        TerazPlyta->setObjectName(QString::fromUtf8("TerazPlyta"));

        formLayout->setWidget(4, QFormLayout::FieldRole, TerazPlyta);

        rok = new QLabel(centralWidget);
        rok->setObjectName(QString::fromUtf8("rok"));

        formLayout->setWidget(5, QFormLayout::LabelRole, rok);

        TerazRok = new QLabel(centralWidget);
        TerazRok->setObjectName(QString::fromUtf8("TerazRok"));

        formLayout->setWidget(5, QFormLayout::FieldRole, TerazRok);

        Okladka = new QLabel(centralWidget);
        Okladka->setObjectName(QString::fromUtf8("Okladka"));

        formLayout->setWidget(1, QFormLayout::FieldRole, Okladka);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(0, QFormLayout::LabelRole, verticalSpacer);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formLayout->setItem(0, QFormLayout::FieldRole, horizontalSpacer);

        TerazTytul = new QLabel(centralWidget);
        TerazTytul->setObjectName(QString::fromUtf8("TerazTytul"));

        formLayout->setWidget(3, QFormLayout::FieldRole, TerazTytul);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label);

        NastepnaOkladka = new QLabel(centralWidget);
        NastepnaOkladka->setObjectName(QString::fromUtf8("NastepnaOkladka"));

        formLayout->setWidget(6, QFormLayout::FieldRole, NastepnaOkladka);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(8, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(9, QFormLayout::LabelRole, label_4);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(10, QFormLayout::LabelRole, label_5);

        NastepnaWykonawca = new QLabel(centralWidget);
        NastepnaWykonawca->setObjectName(QString::fromUtf8("NastepnaWykonawca"));

        formLayout->setWidget(7, QFormLayout::FieldRole, NastepnaWykonawca);

        NastepnaTytul = new QLabel(centralWidget);
        NastepnaTytul->setObjectName(QString::fromUtf8("NastepnaTytul"));

        formLayout->setWidget(8, QFormLayout::FieldRole, NastepnaTytul);

        NastepnaPlyta = new QLabel(centralWidget);
        NastepnaPlyta->setObjectName(QString::fromUtf8("NastepnaPlyta"));

        formLayout->setWidget(9, QFormLayout::FieldRole, NastepnaPlyta);

        NastepnaRok = new QLabel(centralWidget);
        NastepnaRok->setObjectName(QString::fromUtf8("NastepnaRok"));

        formLayout->setWidget(10, QFormLayout::FieldRole, NastepnaRok);


        horizontalLayout->addLayout(formLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        header = new QLabel(centralWidget);
        header->setObjectName(QString::fromUtf8("header"));

        verticalLayout->addWidget(header);

        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);


        horizontalLayout->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 575, 23));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        teraz->setText(QApplication::translate("MainWindow", "Teraz", 0, QApplication::UnicodeUTF8));
        wykonawca->setText(QApplication::translate("MainWindow", "Wykonawca:", 0, QApplication::UnicodeUTF8));
        TerazWykonawca->setText(QString());
        tytul->setText(QApplication::translate("MainWindow", "Tytu\305\202:", 0, QApplication::UnicodeUTF8));
        plyta->setText(QApplication::translate("MainWindow", "P\305\202yta:", 0, QApplication::UnicodeUTF8));
        TerazPlyta->setText(QString());
        rok->setText(QApplication::translate("MainWindow", "Rok:", 0, QApplication::UnicodeUTF8));
        TerazRok->setText(QString());
        Okladka->setText(QString());
        TerazTytul->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Nast\304\231pna", 0, QApplication::UnicodeUTF8));
        NastepnaOkladka->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Wykonawca:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Tytu\305\202:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "P\305\202yta:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Rok:", 0, QApplication::UnicodeUTF8));
        NastepnaWykonawca->setText(QString());
        NastepnaTytul->setText(QString());
        NastepnaPlyta->setText(QString());
        NastepnaRok->setText(QString());
        header->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
