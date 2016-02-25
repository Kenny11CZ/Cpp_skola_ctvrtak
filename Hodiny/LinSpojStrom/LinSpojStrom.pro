QT += core
QT -= gui

TARGET = LinSpojStrom
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    strom.cpp \
    prvek.cpp

HEADERS += \
    strom.h \
    prvek.h

