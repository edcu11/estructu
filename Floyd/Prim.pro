QT += core
QT -= gui

TARGET = Prim
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    nodo.cpp \
    arista.cpp

HEADERS += \
    nodo.h \
    arista.h

