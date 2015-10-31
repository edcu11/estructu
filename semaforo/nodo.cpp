#include "nodo.h"

Nodo::Nodo(string nom)
{
    this->nombre=nom;
    this->fase=1;
    this->n_aris=0;
}

void Nodo::addAristas(Nodo* n){

    aristas[n_aris]=n;
    n_aris++;

}

bool Nodo::checkFase(){


}
