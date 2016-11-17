#-------------------------------------------------
#
# Project created by QtCreator 2016-11-10T21:05:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = InvGUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    login.cpp \
    invmain.cpp \
    p1add.cpp \
    p2del.cpp \
    p3mod.cpp \
    p4print.cpp \
    p5extra.cpp

HEADERS  += mainwindow.h \
    login.h \
    invmain.h \
    p1add.h \
    p2del.h \
    p3mod.h \
    p4print.h \
    p5extra.h

FORMS    += mainwindow.ui \
    login.ui \
    invmain.ui \
    p1add.ui \
    p2del.ui \
    p3mod.ui \
    p4print.ui \
    p5extra.ui
