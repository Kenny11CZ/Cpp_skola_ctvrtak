QT += core
QT -= gui

TARGET = Rekurze-kalkulacka
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    prvekkalk.cpp \
    stromkalk.cpp

HEADERS += \
    prvekkalk.h \
    stromkalk.h

