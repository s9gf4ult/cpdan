#-------------------------------------------------
#
# Project created by QtCreator 2013-01-15T23:39:18
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cpdan
TEMPLATE = app


SOURCES += main.cpp\
        CPDanWindow.cpp \
    DatabaseSelector.cpp

HEADERS  += CPDanWindow.h \
    DatabaseSelector.h

FORMS    += CPDanWindow.ui \
    DatabaseSelector.ui
