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
    brushtoolsetupwidget.cpp \
    texttoolsetupwidget.cpp \
    fontpickerwidget.cpp \
    brushpreviewwidget.cpp \
    brushsizeeditorwidget.cpp \
    fontpickerwidget2.cpp \
    fontlistmodel.cpp

HEADERS  += \
    mainwindow.h \
    colorpickeraction.h \
    canvas.h \
    painttool.h \
    brushtool.h \
    texttool.h \
    registry.h \
    brushtoolsetupwidget.h \
    texttoolsetupwidget.h \
    fontpickerwidget.h \
    brushpreviewwidget.h \
    brushsizeeditorwidget.h \
    fontpickerwidget2.h \
    fontlistmodel.h \
    scopedinc.h

RESOURCES += \
    main.qrc
