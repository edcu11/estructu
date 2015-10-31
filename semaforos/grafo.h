#ifndef GRAFO_H
#define GRAFO_H
#include <iostream>
#include <string>
#include "nodo.h"

using namespace std;


class Grafo
{
public:
    Grafo();
    Nodo* nodos[15];
    int nds_u;
    void addNodo(Nodo* n);
    void resolver();


};

#endif // GRAFO_H
