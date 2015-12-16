#ifndef ARISTA_H
#define ARISTA_H

#include "nodo.h"
class Nodo;
class Arista
{
public:
    Arista(Nodo* n, int p);
    int peso;
    Nodo* apunt;
    Arista* sig;
};

#endif // ARISTA_H
