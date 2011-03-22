#############################################################################
# Makefile for building: MiastoMuzyki
# Generated by qmake (2.01a) (Qt 4.7.0) on: wt. mar 22 17:02:30 2011
# Project:  MiastoMuzyki.pro
# Template: app
# Command: /usr/bin/qmake -o Makefile MiastoMuzyki.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_WEBKIT_LIB -DQT_PHONON_LIB -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtNetwork -I/usr/include/qt4/QtGui -I/usr/include/phonon -I/usr/include/qt4/QtWebKit -I/usr/include/qt4 -I/usr/include/qt4/phonon_compat -I. -I.
LINK          = g++
LFLAGS        = -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib -lQtWebKit -lphonon -lQtGui -lQtNetwork -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		mainwindow.cpp \
		parser.cpp \
		dataupdater.cpp \
		trackinfo.cpp \
		imageload.cpp \
		oknoprogramu.cpp \
		loader.cpp \
		proxydialog.cpp moc_mainwindow.cpp \
		moc_dataupdater.cpp \
		moc_trackinfo.cpp \
		moc_imageload.cpp \
		moc_oknoprogramu.cpp \
		moc_proxydialog.cpp \
		qrc_resources.cpp
OBJECTS       = main.o \
		mainwindow.o \
		parser.o \
		dataupdater.o \
		trackinfo.o \
		imageload.o \
		oknoprogramu.o \
		loader.o \
		proxydialog.o \
		moc_mainwindow.o \
		moc_dataupdater.o \
		moc_trackinfo.o \
		moc_imageload.o \
		moc_oknoprogramu.o \
		moc_proxydialog.o \
		qrc_resources.o
DIST          = /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		MiastoMuzyki.pro
QMAKE_TARGET  = MiastoMuzyki
DESTDIR       = 
TARGET        = MiastoMuzyki

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_mainwindow.h ui_oknoprogramu.h ui_loader.h ui_proxyDialog.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: MiastoMuzyki.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/libQtWebKit.prl \
		/usr/lib/libQtGui.prl \
		/usr/lib/libQtNetwork.prl \
		/usr/lib/libQtCore.prl
	$(QMAKE) -o Makefile MiastoMuzyki.pro
/usr/share/qt4/mkspecs/common/g++.conf:
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/libQtWebKit.prl:
/usr/lib/libQtGui.prl:
/usr/lib/libQtNetwork.prl:
/usr/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile MiastoMuzyki.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/MiastoMuzyki1.0.0 || $(MKDIR) .tmp/MiastoMuzyki1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/MiastoMuzyki1.0.0/ && $(COPY_FILE) --parents mainwindow.h parser.h dataupdater.h trackinfo.h lista.h imageload.h oknoprogramu.h loader.h proxydialog.h .tmp/MiastoMuzyki1.0.0/ && $(COPY_FILE) --parents resources.qrc .tmp/MiastoMuzyki1.0.0/ && $(COPY_FILE) --parents main.cpp mainwindow.cpp parser.cpp dataupdater.cpp trackinfo.cpp imageload.cpp oknoprogramu.cpp loader.cpp proxydialog.cpp .tmp/MiastoMuzyki1.0.0/ && $(COPY_FILE) --parents mainwindow.ui oknoprogramu.ui loader.ui proxyDialog.ui .tmp/MiastoMuzyki1.0.0/ && (cd `dirname .tmp/MiastoMuzyki1.0.0` && $(TAR) MiastoMuzyki1.0.0.tar MiastoMuzyki1.0.0 && $(COMPRESS) MiastoMuzyki1.0.0.tar) && $(MOVE) `dirname .tmp/MiastoMuzyki1.0.0`/MiastoMuzyki1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/MiastoMuzyki1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_mainwindow.cpp moc_dataupdater.cpp moc_trackinfo.cpp moc_imageload.cpp moc_oknoprogramu.cpp moc_proxydialog.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainwindow.cpp moc_dataupdater.cpp moc_trackinfo.cpp moc_imageload.cpp moc_oknoprogramu.cpp moc_proxydialog.cpp
moc_mainwindow.cpp: parser.h \
		dataupdater.h \
		trackinfo.h \
		lista.h \
		imageload.h \
		proxydialog.h \
		mainwindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) mainwindow.h -o moc_mainwindow.cpp

moc_dataupdater.cpp: dataupdater.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) dataupdater.h -o moc_dataupdater.cpp

moc_trackinfo.cpp: lista.h \
		trackinfo.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) trackinfo.h -o moc_trackinfo.cpp

moc_imageload.cpp: imageload.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) imageload.h -o moc_imageload.cpp

moc_oknoprogramu.cpp: oknoprogramu.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) oknoprogramu.h -o moc_oknoprogramu.cpp

moc_proxydialog.cpp: proxydialog.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) proxydialog.h -o moc_proxydialog.cpp

compiler_rcc_make_all: qrc_resources.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_resources.cpp
qrc_resources.cpp: resources.qrc \
		images/strzalka.gif \
		images/header.jpg \
		images/brak.jpg
	/usr/bin/rcc -name resources resources.qrc -o qrc_resources.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_mainwindow.h ui_oknoprogramu.h ui_loader.h ui_proxyDialog.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainwindow.h ui_oknoprogramu.h ui_loader.h ui_proxyDialog.h
ui_mainwindow.h: mainwindow.ui
	/usr/bin/uic-qt4 mainwindow.ui -o ui_mainwindow.h

ui_oknoprogramu.h: oknoprogramu.ui
	/usr/bin/uic-qt4 oknoprogramu.ui -o ui_oknoprogramu.h

ui_loader.h: loader.ui
	/usr/bin/uic-qt4 loader.ui -o ui_loader.h

ui_proxyDialog.h: proxyDialog.ui
	/usr/bin/uic-qt4 proxyDialog.ui -o ui_proxyDialog.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean compiler_uic_clean 

####### Compile

main.o: main.cpp mainwindow.h \
		parser.h \
		dataupdater.h \
		trackinfo.h \
		lista.h \
		imageload.h \
		proxydialog.h \
		loader.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainwindow.o: mainwindow.cpp mainwindow.h \
		parser.h \
		dataupdater.h \
		trackinfo.h \
		lista.h \
		imageload.h \
		proxydialog.h \
		ui_mainwindow.h \
		ui_oknoprogramu.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

parser.o: parser.cpp parser.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o parser.o parser.cpp

dataupdater.o: dataupdater.cpp dataupdater.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o dataupdater.o dataupdater.cpp

trackinfo.o: trackinfo.cpp trackinfo.h \
		lista.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o trackinfo.o trackinfo.cpp

imageload.o: imageload.cpp imageload.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o imageload.o imageload.cpp

oknoprogramu.o: oknoprogramu.cpp oknoprogramu.h \
		ui_oknoprogramu.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o oknoprogramu.o oknoprogramu.cpp

loader.o: loader.cpp loader.h \
		ui_loader.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o loader.o loader.cpp

proxydialog.o: proxydialog.cpp proxydialog.h \
		ui_proxyDialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o proxydialog.o proxydialog.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

moc_dataupdater.o: moc_dataupdater.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_dataupdater.o moc_dataupdater.cpp

moc_trackinfo.o: moc_trackinfo.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_trackinfo.o moc_trackinfo.cpp

moc_imageload.o: moc_imageload.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_imageload.o moc_imageload.cpp

moc_oknoprogramu.o: moc_oknoprogramu.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_oknoprogramu.o moc_oknoprogramu.cpp

moc_proxydialog.o: moc_proxydialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_proxydialog.o moc_proxydialog.cpp

qrc_resources.o: qrc_resources.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_resources.o qrc_resources.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

