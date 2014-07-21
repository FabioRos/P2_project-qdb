#############################################################################
# Makefile for building: prjP2New
# Generated by qmake (2.01a) (Qt 4.8.6) on: lun lug 21 12:14:04 2014
# Project:  prjP2New.pro
# Template: app
# Command: /usr/lib/x86_64-linux-gnu/qt4/bin/qmake -o Makefile prjP2New.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++-64 -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -I.
LINK          = g++
LFLAGS        = -m64 -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib/x86_64-linux-gnu -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/lib/x86_64-linux-gnu/qt4/bin/qmake
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

SOURCES       = bicicletta.cpp \
		bicicomuni.cpp \
		bicidacorsa.cpp \
		eccezioni.cpp \
		finestra_principale.cpp \
		main.cpp \
		negozio.cpp moc_finestra_principale.cpp
OBJECTS       = bicicletta.o \
		bicicomuni.o \
		bicidacorsa.o \
		eccezioni.o \
		finestra_principale.o \
		main.o \
		negozio.o \
		moc_finestra_principale.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		prjP2New.pro
QMAKE_TARGET  = prjP2New
DESTDIR       = 
TARGET        = prjP2New

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

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: prjP2New.pro  /usr/share/qt4/mkspecs/linux-g++-64/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/x86_64-linux-gnu/libQtGui.prl \
		/usr/lib/x86_64-linux-gnu/libQtCore.prl
	$(QMAKE) -o Makefile prjP2New.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/shared.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/x86_64-linux-gnu/libQtGui.prl:
/usr/lib/x86_64-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile prjP2New.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/prjP2New1.0.0 || $(MKDIR) .tmp/prjP2New1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/prjP2New1.0.0/ && $(COPY_FILE) --parents bicicletta.h bicicomuni.h bicidacorsa.h container.h eccezioni.h finestra_principale.h negozio.h .tmp/prjP2New1.0.0/ && $(COPY_FILE) --parents bicicletta.cpp bicicomuni.cpp bicidacorsa.cpp eccezioni.cpp finestra_principale.cpp main.cpp negozio.cpp .tmp/prjP2New1.0.0/ && (cd `dirname .tmp/prjP2New1.0.0` && $(TAR) prjP2New1.0.0.tar prjP2New1.0.0 && $(COMPRESS) prjP2New1.0.0.tar) && $(MOVE) `dirname .tmp/prjP2New1.0.0`/prjP2New1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/prjP2New1.0.0


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

compiler_moc_header_make_all: moc_finestra_principale.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_finestra_principale.cpp
moc_finestra_principale.cpp: negozio.h \
		bicicletta.h \
		eccezioni.h \
		bicidacorsa.h \
		bicicomuni.h \
		container.h \
		finestra_principale.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) finestra_principale.h -o moc_finestra_principale.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

bicicletta.o: bicicletta.cpp bicicletta.h \
		eccezioni.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bicicletta.o bicicletta.cpp

bicicomuni.o: bicicomuni.cpp bicicomuni.h \
		bicicletta.h \
		eccezioni.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bicicomuni.o bicicomuni.cpp

bicidacorsa.o: bicidacorsa.cpp bicidacorsa.h \
		bicicletta.h \
		eccezioni.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bicidacorsa.o bicidacorsa.cpp

eccezioni.o: eccezioni.cpp eccezioni.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o eccezioni.o eccezioni.cpp

finestra_principale.o: finestra_principale.cpp finestra_principale.h \
		negozio.h \
		bicicletta.h \
		eccezioni.h \
		bicidacorsa.h \
		bicicomuni.h \
		container.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o finestra_principale.o finestra_principale.cpp

main.o: main.cpp container.h \
		negozio.h \
		bicicletta.h \
		eccezioni.h \
		bicidacorsa.h \
		bicicomuni.h \
		finestra_principale.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

negozio.o: negozio.cpp negozio.h \
		bicicletta.h \
		eccezioni.h \
		bicidacorsa.h \
		bicicomuni.h \
		container.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o negozio.o negozio.cpp

moc_finestra_principale.o: moc_finestra_principale.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_finestra_principale.o moc_finestra_principale.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

