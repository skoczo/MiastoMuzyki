# -------------------------------------------------
# Project created by QtCreator 2010-11-26T18:53:52
# -------------------------------------------------
QT += core \
    gui \
    phonon \
    network \
    webkit
TARGET = MiastoMuzyki
TEMPLATE = app
SOURCES += options.cpp \
    main.cpp \
    mainwindow.cpp \
    trackinfo.cpp \
    parser.cpp \
    imageload.cpp \
    proxydialog.cpp
HEADERS += options.h \
    mainwindow.h \
    trackinfo.h \
    parser.h \
    lista.h \
    imageload.h \
    proxydialog.h
FORMS += options.ui \
    oknoprogramu.ui \
    proxyDialog.ui
RESOURCES += resources.qrc
RC_FILE = myapp.rc
