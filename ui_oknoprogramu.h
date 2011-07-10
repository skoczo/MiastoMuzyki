/********************************************************************************
** Form generated from reading UI file 'oknoprogramu.ui'
**
** Created: Sun Jul 10 11:42:51 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OKNOPROGRAMU_H
#define UI_OKNOPROGRAMU_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OknoProgramu
{
public:
    QAction *actionO_programie;
    QAction *actionUstawienia;
    QAction *actionOpcje;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_3;
    QLabel *teraz;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QLabel *Okladka;
    QSpacerItem *horizontalSpacer_2;
    QFormLayout *formLayout;
    QLabel *wykonawca;
    QLabel *tytul;
    QLabel *plyta;
    QLabel *rok;
    QLabel *TerazWykonawca;
    QLabel *TerazTytul;
    QLabel *TerazPlyta;
    QLabel *TerazRok;
    QFrame *line;
    QLabel *label;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_4;
    QLabel *NastepnaOkladka;
    QSpacerItem *horizontalSpacer_3;
    QFormLayout *formLayout_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *NastepnaWykonawca;
    QLabel *NastepnaTytul;
    QLabel *NastepnaPlyta;
    QLabel *NastepnaRok;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *play_pause;
    QSlider *volume;
    QLabel *header;
    QListWidget *listWidget;
    QMenuBar *menubar;
    QMenu *menuUstawienia;
    QMenu *menuPomoc;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *OknoProgramu)
    {
        if (OknoProgramu->objectName().isEmpty())
            OknoProgramu->setObjectName(QString::fromUtf8("OknoProgramu"));
        OknoProgramu->resize(476, 418);
        actionO_programie = new QAction(OknoProgramu);
        actionO_programie->setObjectName(QString::fromUtf8("actionO_programie"));
        actionUstawienia = new QAction(OknoProgramu);
        actionUstawienia->setObjectName(QString::fromUtf8("actionUstawienia"));
        actionOpcje = new QAction(OknoProgramu);
        actionOpcje->setObjectName(QString::fromUtf8("actionOpcje"));
        centralwidget = new QWidget(OknoProgramu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        teraz = new QLabel(centralwidget);
        teraz->setObjectName(QString::fromUtf8("teraz"));

        verticalLayout_2->addWidget(teraz);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        Okladka = new QLabel(centralwidget);
        Okladka->setObjectName(QString::fromUtf8("Okladka"));

        horizontalLayout_3->addWidget(Okladka);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_3);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        wykonawca = new QLabel(centralwidget);
        wykonawca->setObjectName(QString::fromUtf8("wykonawca"));

        formLayout->setWidget(1, QFormLayout::LabelRole, wykonawca);

        tytul = new QLabel(centralwidget);
        tytul->setObjectName(QString::fromUtf8("tytul"));

        formLayout->setWidget(2, QFormLayout::LabelRole, tytul);

        plyta = new QLabel(centralwidget);
        plyta->setObjectName(QString::fromUtf8("plyta"));

        formLayout->setWidget(3, QFormLayout::LabelRole, plyta);

        rok = new QLabel(centralwidget);
        rok->setObjectName(QString::fromUtf8("rok"));

        formLayout->setWidget(4, QFormLayout::LabelRole, rok);

        TerazWykonawca = new QLabel(centralwidget);
        TerazWykonawca->setObjectName(QString::fromUtf8("TerazWykonawca"));

        formLayout->setWidget(1, QFormLayout::FieldRole, TerazWykonawca);

        TerazTytul = new QLabel(centralwidget);
        TerazTytul->setObjectName(QString::fromUtf8("TerazTytul"));

        formLayout->setWidget(2, QFormLayout::FieldRole, TerazTytul);

        TerazPlyta = new QLabel(centralwidget);
        TerazPlyta->setObjectName(QString::fromUtf8("TerazPlyta"));

        formLayout->setWidget(3, QFormLayout::FieldRole, TerazPlyta);

        TerazRok = new QLabel(centralwidget);
        TerazRok->setObjectName(QString::fromUtf8("TerazRok"));

        formLayout->setWidget(4, QFormLayout::FieldRole, TerazRok);


        verticalLayout_2->addLayout(formLayout);

        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        NastepnaOkladka = new QLabel(centralwidget);
        NastepnaOkladka->setObjectName(QString::fromUtf8("NastepnaOkladka"));

        horizontalLayout_4->addWidget(NastepnaOkladka);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_4);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_4);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_5);

        NastepnaWykonawca = new QLabel(centralwidget);
        NastepnaWykonawca->setObjectName(QString::fromUtf8("NastepnaWykonawca"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, NastepnaWykonawca);

        NastepnaTytul = new QLabel(centralwidget);
        NastepnaTytul->setObjectName(QString::fromUtf8("NastepnaTytul"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, NastepnaTytul);

        NastepnaPlyta = new QLabel(centralwidget);
        NastepnaPlyta->setObjectName(QString::fromUtf8("NastepnaPlyta"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, NastepnaPlyta);

        NastepnaRok = new QLabel(centralwidget);
        NastepnaRok->setObjectName(QString::fromUtf8("NastepnaRok"));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, NastepnaRok);


        verticalLayout_2->addLayout(formLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        play_pause = new QPushButton(centralwidget);
        play_pause->setObjectName(QString::fromUtf8("play_pause"));

        horizontalLayout_5->addWidget(play_pause);

        volume = new QSlider(centralwidget);
        volume->setObjectName(QString::fromUtf8("volume"));
        volume->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(volume);


        verticalLayout->addLayout(horizontalLayout_5);

        header = new QLabel(centralwidget);
        header->setObjectName(QString::fromUtf8("header"));

        verticalLayout->addWidget(header);

        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setBaseSize(QSize(250, 200));

        verticalLayout->addWidget(listWidget);


        horizontalLayout->addLayout(verticalLayout);


        horizontalLayout_2->addLayout(horizontalLayout);

        OknoProgramu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(OknoProgramu);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 476, 25));
        menuUstawienia = new QMenu(menubar);
        menuUstawienia->setObjectName(QString::fromUtf8("menuUstawienia"));
        menuPomoc = new QMenu(menubar);
        menuPomoc->setObjectName(QString::fromUtf8("menuPomoc"));
        OknoProgramu->setMenuBar(menubar);
        statusBar = new QStatusBar(OknoProgramu);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        OknoProgramu->setStatusBar(statusBar);

        menubar->addAction(menuUstawienia->menuAction());
        menubar->addAction(menuPomoc->menuAction());
        menuUstawienia->addAction(actionUstawienia);
        menuUstawienia->addAction(actionOpcje);
        menuPomoc->addAction(actionO_programie);

        retranslateUi(OknoProgramu);

        QMetaObject::connectSlotsByName(OknoProgramu);
    } // setupUi

    void retranslateUi(QMainWindow *OknoProgramu)
    {
        OknoProgramu->setWindowTitle(QApplication::translate("OknoProgramu", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionO_programie->setText(QApplication::translate("OknoProgramu", "O programie", 0, QApplication::UnicodeUTF8));
        actionUstawienia->setText(QApplication::translate("OknoProgramu", "Proxy", 0, QApplication::UnicodeUTF8));
        actionOpcje->setText(QApplication::translate("OknoProgramu", "Opcje", 0, QApplication::UnicodeUTF8));
        teraz->setText(QApplication::translate("OknoProgramu", "Teraz", 0, QApplication::UnicodeUTF8));
        Okladka->setText(QString());
        wykonawca->setText(QApplication::translate("OknoProgramu", "Wykonawca:", 0, QApplication::UnicodeUTF8));
        tytul->setText(QApplication::translate("OknoProgramu", "Tytul:", 0, QApplication::UnicodeUTF8));
        plyta->setText(QApplication::translate("OknoProgramu", "P\305\202yta:", 0, QApplication::UnicodeUTF8));
        rok->setText(QApplication::translate("OknoProgramu", "Rok", 0, QApplication::UnicodeUTF8));
        TerazWykonawca->setText(QString());
        TerazTytul->setText(QString());
        TerazPlyta->setText(QString());
        TerazRok->setText(QString());
        label->setText(QApplication::translate("OknoProgramu", "Nast\304\231pna", 0, QApplication::UnicodeUTF8));
        NastepnaOkladka->setText(QString());
        label_2->setText(QApplication::translate("OknoProgramu", "Wykonawca:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("OknoProgramu", "Tytul:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("OknoProgramu", "P\305\202yta:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("OknoProgramu", "Rok:", 0, QApplication::UnicodeUTF8));
        NastepnaWykonawca->setText(QString());
        NastepnaTytul->setText(QString());
        NastepnaPlyta->setText(QString());
        NastepnaRok->setText(QString());
        play_pause->setText(QApplication::translate("OknoProgramu", "Play", 0, QApplication::UnicodeUTF8));
        header->setText(QString());
        menuUstawienia->setTitle(QApplication::translate("OknoProgramu", "Ustawienia", 0, QApplication::UnicodeUTF8));
        menuPomoc->setTitle(QApplication::translate("OknoProgramu", "Pomoc", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OknoProgramu: public Ui_OknoProgramu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OKNOPROGRAMU_H
