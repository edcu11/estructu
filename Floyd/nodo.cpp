#include "nodo.h"
#include "arista.h"
#include <iostream>

using namespace std;

Arista* last;

Nodo::Nodo(int v)
{
    this->valor=v;
    adj=NULL;
}

void Nodo::add_A(Arista *arista)
{
    if(adj==NULL){
        adj=arista;
        last=arista;
    }
    else{
        last->sig=arista;
        last=last->sig;
   }
}
