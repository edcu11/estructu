QT += core
QT -= gui

TARGET = Dijkstra
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    nodo.cpp \
    arista.cpp \
    connect.cpp

HEADERS += \
    nodo.h \
    arista.h \
    connect.h

