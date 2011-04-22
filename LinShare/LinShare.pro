#-------------------------------------------------
#
# Project created by QtCreator 2011-04-16T21:28:49
#
#-------------------------------------------------

QT       += core gui network

TARGET = LinShare
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

LIBS += -L/home/mark/projects/MessageAPI/MessageAPI-build-desktop -lMessageAPI
INCLUDEPATH = /home/mark/projects/MessageAPI/MessageAPI/
