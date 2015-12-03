#-------------------------------------------------
#
# Project created by QtCreator 2015-12-02T18:11:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = key-mouse-tool
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    hook.cpp \
    applog.cpp \
    worker.cpp

HEADERS  += mainwindow.h \
    hook.h \
    applog.h \
    worker.h

FORMS    += mainwindow.ui
