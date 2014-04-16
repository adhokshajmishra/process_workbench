#-------------------------------------------------
#
# Project created by QtCreator 2014-04-15T21:25:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Process
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    process.cpp \
    process_collection.cpp \
    process_information.cpp

HEADERS  += mainwindow.h \
    process.h \
    process_collection.h \
    process_information.h \
    error_codes.h

FORMS    += mainwindow.ui
