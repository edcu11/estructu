QT += core
QT -= gui

TARGET = semaforos
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    nodo.cpp \
    grafo.cpp

HEADERS += \
    nodo.h \
    grafo.h

