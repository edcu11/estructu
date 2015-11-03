#include "nodo.h"

Nodo::Nodo(string name)
{
    nombre=name;
    aristas_u=0;
    fase=0;

}


void Nodo::add_A(Nodo *n)
{
    aristas[aristas_u]=n;
    aristas_u++;

}

bool Nodo::validar(int fase)
{
    for(int y=0; y<aristas_u; y++){
            if(aristas[y]->fase==fase)
                return true;
        }
        return false;

}

