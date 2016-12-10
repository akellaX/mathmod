#-------------------------------------------------
#
# Project created by QtCreator 2016-12-09T20:45:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = mnk_2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cgauss.cpp \
    cMatrix.cpp \
    method.cpp \
    qcustomplot.cpp \
    mnk.cpp

HEADERS  += mainwindow.h \
    cgauss.h \
    cMatrix.h \
    method.h \
    qcustomplot.h \
    mnk.h

FORMS    += mainwindow.ui
