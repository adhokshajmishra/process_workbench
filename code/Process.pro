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
    convert.cpp \
    fileutils.cpp \
    stringutils.cpp \
    process_window.cpp

HEADERS  += mainwindow.h \
    process.h \
    process_collection.h \
    convert.h \
    fileutils.h \
    types.h \
    stringutils.h \
    process_window.h

FORMS    += mainwindow.ui \
    process_window.ui

unix:!macx: LIBS += -L$$PWD/../../../../../usr/lib/ -lboost_system -lboost_regex -lboost_filesystem

INCLUDEPATH += $$PWD/../../../../../usr/include
DEPENDPATH += $$PWD/../../../../../usr/include
