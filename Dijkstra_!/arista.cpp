#include "arista.h"
#include <iostream>

using namespace std;

Arista::Arista(Nodo* nodo, int peso)
{
    this->apunt=nodo;
    this->peso=peso;
    this->sig=NULL;
}

