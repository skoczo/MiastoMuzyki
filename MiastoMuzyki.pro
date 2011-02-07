#-------------------------------------------------
#
# Project created by QtCreator 2010-11-26T18:53:52
#
#-------------------------------------------------

QT       += core gui phonon network webkit

TARGET = MiastoMuzyki
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    parser.cpp \
    dataupdater.cpp \
    trackinfo.cpp \
    imageload.cpp \
    oknoprogramu.cpp \
    loader.cpp \
    proxydialog.cpp

HEADERS  += mainwindow.h \
    parser.h \
    dataupdater.h \
    trackinfo.h \
    lista.h \
    imageload.h \
    oknoprogramu.h \
    loader.h \
    proxydialog.h

FORMS    += mainwindow.ui \
    oknoprogramu.ui \
    loader.ui \
    proxyDialog.ui

RESOURCES += \
    resources.qrc

win32 {
debug {
    CONFIG+= console
    DESTDIR = ../debug
 } else {
    DESTDIR = ../release
    }
}
