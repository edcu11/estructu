QT += core
QT -= gui

TARGET = Prim
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    arista.cpp \
    connect.cpp \
    nodo.cpp

HEADERS += \
    arista.h \
    connect.h \
    nodo.h

