#-------------------------------------------------
#
# Project created by QtCreator 2016-03-04T10:34:45
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = hello-layouts
TEMPLATE = app


SOURCES += main.cpp\
    mainwindow.cpp \
    colorpickeraction.cpp \
    canvas.cpp \
    painttool.cpp \
    brushtool.cpp \
    texttool.cpp \
    brushtoolsetupwidget.cpp

HEADERS  += \
    mainwindow.h \
    colorpickeraction.h \
    canvas.h \
    painttool.h \
    brushtool.h \
    texttool.h \
    registry.h \
    brushtoolsetupwidget.h

RESOURCES += \
    main.qrc
