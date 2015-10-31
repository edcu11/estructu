#include "nodo.h"

Nodo::Nodo(string name)
{
    nombre=name;
    aristas_u=0;
    fase=1;

}


void Nodo::add_A(Nodo *n)
{
    aristas[aristas_u]=n;
    aristas_u++;

}

