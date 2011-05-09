#############################################################################
# Makefile for building: MiastoMuzyki
# Generated by qmake (2.01a) (Qt 4.7.0) on: niedz. maj 8 18:30:16 2011
# Project:  MiastoMuzyki.pro
# Template: app
# Command: /home/skoczo/qtsdk-2010.05/qt/bin/qmake -spec ../../../qtsdk-2010.05/qt/mkspecs/linux-g++ CONFIG+=debug -o Makefile MiastoMuzyki.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT_LIB -DQT_PHONON_LIB -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I../../../qtsdk-2010.05/qt/mkspecs/linux-g++ -I. -I../../../qtsdk-2010.05/qt/include/QtCore -I../../../qtsdk-2010.05/qt/include/QtNetwork -I../../../qtsdk-2010.05/qt/include/QtGui -I../../../qtsdk-2010.05/qt/include/phonon -I../../../qtsdk-2010.05/qt/include/QtWebKit -I../../../qtsdk-2010.05/qt/include -I../../../qtsdk-2010.05/qt/include/phonon_compat -I. -I.
LINK          = g++
LFLAGS        = -Wl,-rpath,/home/skoczo/qtsdk-2010.05/qt/lib
LIBS          = $(SUBLIBS)  -L/home/skoczo/qtsdk-2010.05/qt/lib -lQtWebKit -lphonon -L/home/berlin/dev/qt-4.7.0-opensource-shipping/this_path_is_supposed_to_be_very_long_hopefully_this_is_long_enough/qt/lib -lQtDBus -L/home/skoczo/qtsdk-2010.05/qt/lib -lQtXml -L/usr/X11R6/lib -lQtGui -lQtNetwork -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /home/skoczo/qtsdk-2010.05/qt/bin/qmake
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
		trackinfo.cpp \
		parser.cpp \
		imageload.cpp \
		proxydialog.cpp moc_mainwindow.cpp \
		moc_trackinfo.cpp \
		moc_parser.cpp \
		moc_imageload.cpp \
		moc_proxydialog.cpp \
		qrc_resources.cpp
OBJECTS       = main.o \
		mainwindow.o \
		trackinfo.o \
		parser.o \
		imageload.o \
		proxydialog.o \
		moc_mainwindow.o \
		moc_trackinfo.o \
		moc_parser.o \
		moc_imageload.o \
		moc_proxydialog.o \
		qrc_resources.o
DIST          = ../../../qtsdk-2010.05/qt/mkspecs/common/g++.conf \
		../../../qtsdk-2010.05/qt/mkspecs/common/unix.conf \
		../../../qtsdk-2010.05/qt/mkspecs/common/linux.conf \
		../../../qtsdk-2010.05/qt/mkspecs/qconfig.pri \
		../../../qtsdk-2010.05/qt/mkspecs/modules/qt_webkit_version.pri \
		../../../qtsdk-2010.05/qt/mkspecs/features/qt_functions.prf \
		../../../qtsdk-2010.05/qt/mkspecs/features/qt_config.prf \
		../../../qtsdk-2010.05/qt/mkspecs/features/exclusive_builds.prf \
		../../../qtsdk-2010.05/qt/mkspecs/features/default_pre.prf \
		../../../qtsdk-2010.05/qt/mkspecs/features/debug.prf \
		../../../qtsdk-2010.05/qt/mkspecs/features/default_post.prf \
		../../../qtsdk-2010.05/qt/mkspecs/features/warn_on.prf \
		../../../qtsdk-2010.05/qt/mkspecs/features/qt.prf \
		../../../qtsdk-2010.05/qt/mkspecs/features/unix/thread.prf \
		../../../qtsdk-2010.05/qt/mkspecs/features/moc.prf \
		../../../qtsdk-2010.05/qt/mkspecs/features/resources.prf \
		../../../qtsdk-2010.05/qt/mkspecs/features/uic.prf \
		../../../qtsdk-2010.05/qt/mkspecs/features/yacc.prf \
		../../../qtsdk-2010.05/qt/mkspecs/features/lex.prf \
		../../../qtsdk-2010.05/qt/mkspecs/features/include_source_dir.prf \
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

$(TARGET): ui_oknoprogramu.h ui_proxyDialog.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: MiastoMuzyki.pro  ../../../qtsdk-2010.05/qt/mkspecs/linux-g++/qmake.conf ../../../qtsdk-2010.05/qt/mkspecs/common/g++.conf \
		../../../qtsdk-2010.05/qt/mkspecs/common/unix.conf \
		../../../qtsdk-2010.05/qt/mkspecs/common/linux.conf \
		../../../qtsdk-2010.05/qt/mkspecs/qconfig.pri \
		../../../qtsdk-2010.05/qt/mkspecs/modules/qt_webkit_version.pri \
		../../../qtsdk-2010.05/qt/mkspecs/features/qt_functions.prf \
		../../../qtsdk-2010.05/qt/mkspecs/features/qt_config.prf \
		../../../qtsdk-2010.05/qt/mkspecs/features/exclusive_builds.prf \
		../../../qtsdk-2010.05/qt/mkspecs/features/default_pre.prf \
		../../../qtsdk-2010.05/qt/mkspecs/features/debug.prf \
		../../../qtsdk-2010.05/qt/mkspecs/features/default_post.prf \
		../../../qtsdk-2010.05/qt/mkspecs/features/warn_on.prf \
		../../../qtsdk-2010.05/qt/mkspecs/features/qt.prf \
		../../../qtsdk-2010.05/qt/mkspecs/features/unix/thread.prf \
		../../../qtsdk-2010.05/qt/mkspecs/features/moc.prf \
		../../../qtsdk-2010.05/qt/mkspecs/features/resources.prf \
		../../../qtsdk-2010.05/qt/mkspecs/features/uic.prf \
		../../../qtsdk-2010.05/qt/mkspecs/features/yacc.prf \
		../../../qtsdk-2010.05/qt/mkspecs/features/lex.prf \
		../../../qtsdk-2010.05/qt/mkspecs/features/include_source_dir.prf \
		/home/skoczo/qtsdk-2010.05/qt/lib/libQtWebKit.prl \
		/home/skoczo/qtsdk-2010.05/qt/lib/libphonon.prl \
		/home/skoczo/qtsdk-2010.05/qt/lib/libQtDBus.prl \
		/home/skoczo/qtsdk-2010.05/qt/lib/libQtXml.prl \
		/home/skoczo/qtsdk-2010.05/qt/lib/libQtCore.prl \
		/home/skoczo/qtsdk-2010.05/qt/lib/libQtGui.prl \
		/home/skoczo/qtsdk-2010.05/qt/lib/libQtNetwork.prl
	$(QMAKE) -spec ../../../qtsdk-2010.05/qt/mkspecs/linux-g++ CONFIG+=debug -o Makefile MiastoMuzyki.pro
../../../qtsdk-2010.05/qt/mkspecs/common/g++.conf:
../../../qtsdk-2010.05/qt/mkspecs/common/unix.conf:
../../../qtsdk-2010.05/qt/mkspecs/common/linux.conf:
../../../qtsdk-2010.05/qt/mkspecs/qconfig.pri:
../../../qtsdk-2010.05/qt/mkspecs/modules/qt_webkit_version.pri:
../../../qtsdk-2010.05/qt/mkspecs/features/qt_functions.prf:
../../../qtsdk-2010.05/qt/mkspecs/features/qt_config.prf:
../../../qtsdk-2010.05/qt/mkspecs/features/exclusive_builds.prf:
../../../qtsdk-2010.05/qt/mkspecs/features/default_pre.prf:
../../../qtsdk-2010.05/qt/mkspecs/features/debug.prf:
../../../qtsdk-2010.05/qt/mkspecs/features/default_post.prf:
../../../qtsdk-2010.05/qt/mkspecs/features/warn_on.prf:
../../../qtsdk-2010.05/qt/mkspecs/features/qt.prf:
../../../qtsdk-2010.05/qt/mkspecs/features/unix/thread.prf:
../../../qtsdk-2010.05/qt/mkspecs/features/moc.prf:
../../../qtsdk-2010.05/qt/mkspecs/features/resources.prf:
../../../qtsdk-2010.05/qt/mkspecs/features/uic.prf:
../../../qtsdk-2010.05/qt/mkspecs/features/yacc.prf:
../../../qtsdk-2010.05/qt/mkspecs/features/lex.prf:
../../../qtsdk-2010.05/qt/mkspecs/features/include_source_dir.prf:
/home/skoczo/qtsdk-2010.05/qt/lib/libQtWebKit.prl:
/home/skoczo/qtsdk-2010.05/qt/lib/libphonon.prl:
/home/skoczo/qtsdk-2010.05/qt/lib/libQtDBus.prl:
/home/skoczo/qtsdk-2010.05/qt/lib/libQtXml.prl:
/home/skoczo/qtsdk-2010.05/qt/lib/libQtCore.prl:
/home/skoczo/qtsdk-2010.05/qt/lib/libQtGui.prl:
/home/skoczo/qtsdk-2010.05/qt/lib/libQtNetwork.prl:
qmake:  FORCE
	@$(QMAKE) -spec ../../../qtsdk-2010.05/qt/mkspecs/linux-g++ CONFIG+=debug -o Makefile MiastoMuzyki.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/MiastoMuzyki1.0.0 || $(MKDIR) .tmp/MiastoMuzyki1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/MiastoMuzyki1.0.0/ && $(COPY_FILE) --parents mainwindow.h trackinfo.h parser.h lista.h imageload.h proxydialog.h .tmp/MiastoMuzyki1.0.0/ && $(COPY_FILE) --parents resources.qrc .tmp/MiastoMuzyki1.0.0/ && $(COPY_FILE) --parents main.cpp mainwindow.cpp trackinfo.cpp parser.cpp imageload.cpp proxydialog.cpp .tmp/MiastoMuzyki1.0.0/ && $(COPY_FILE) --parents oknoprogramu.ui proxyDialog.ui .tmp/MiastoMuzyki1.0.0/ && (cd `dirname .tmp/MiastoMuzyki1.0.0` && $(TAR) MiastoMuzyki1.0.0.tar MiastoMuzyki1.0.0 && $(COMPRESS) MiastoMuzyki1.0.0.tar) && $(MOVE) `dirname .tmp/MiastoMuzyki1.0.0`/MiastoMuzyki1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/MiastoMuzyki1.0.0


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

compiler_moc_header_make_all: moc_mainwindow.cpp moc_trackinfo.cpp moc_parser.cpp moc_imageload.cpp moc_proxydialog.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainwindow.cpp moc_trackinfo.cpp moc_parser.cpp moc_imageload.cpp moc_proxydialog.cpp
moc_mainwindow.cpp: parser.h \
		trackinfo.h \
		lista.h \
		imageload.h \
		proxydialog.h \
		mainwindow.h
	/home/skoczo/qtsdk-2010.05/qt/bin/moc $(DEFINES) $(INCPATH) mainwindow.h -o moc_mainwindow.cpp

moc_trackinfo.cpp: lista.h \
		trackinfo.h
	/home/skoczo/qtsdk-2010.05/qt/bin/moc $(DEFINES) $(INCPATH) trackinfo.h -o moc_trackinfo.cpp

moc_parser.cpp: parser.h
	/home/skoczo/qtsdk-2010.05/qt/bin/moc $(DEFINES) $(INCPATH) parser.h -o moc_parser.cpp

moc_imageload.cpp: imageload.h
	/home/skoczo/qtsdk-2010.05/qt/bin/moc $(DEFINES) $(INCPATH) imageload.h -o moc_imageload.cpp

moc_proxydialog.cpp: proxydialog.h
	/home/skoczo/qtsdk-2010.05/qt/bin/moc $(DEFINES) $(INCPATH) proxydialog.h -o moc_proxydialog.cpp

compiler_rcc_make_all: qrc_resources.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_resources.cpp
qrc_resources.cpp: resources.qrc \
		images/strzalka.gif \
		images/header.jpg \
		images/brak.jpg \
		images/zaslepka.jpg
	/home/skoczo/qtsdk-2010.05/qt/bin/rcc -name resources resources.qrc -o qrc_resources.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_oknoprogramu.h ui_proxyDialog.h
compiler_uic_clean:
	-$(DEL_FILE) ui_oknoprogramu.h ui_proxyDialog.h
ui_oknoprogramu.h: oknoprogramu.ui
	/home/skoczo/qtsdk-2010.05/qt/bin/uic oknoprogramu.ui -o ui_oknoprogramu.h

ui_proxyDialog.h: proxyDialog.ui
	/home/skoczo/qtsdk-2010.05/qt/bin/uic proxyDialog.ui -o ui_proxyDialog.h

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
		trackinfo.h \
		lista.h \
		imageload.h \
		proxydialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainwindow.o: mainwindow.cpp mainwindow.h \
		parser.h \
		trackinfo.h \
		lista.h \
		imageload.h \
		proxydialog.h \
		ui_oknoprogramu.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

trackinfo.o: trackinfo.cpp trackinfo.h \
		lista.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o trackinfo.o trackinfo.cpp

parser.o: parser.cpp parser.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o parser.o parser.cpp

imageload.o: imageload.cpp imageload.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o imageload.o imageload.cpp

proxydialog.o: proxydialog.cpp proxydialog.h \
		ui_proxyDialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o proxydialog.o proxydialog.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

moc_trackinfo.o: moc_trackinfo.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_trackinfo.o moc_trackinfo.cpp

moc_parser.o: moc_parser.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_parser.o moc_parser.cpp

moc_imageload.o: moc_imageload.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_imageload.o moc_imageload.cpp

moc_proxydialog.o: moc_proxydialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_proxydialog.o moc_proxydialog.cpp

qrc_resources.o: qrc_resources.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_resources.o qrc_resources.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

