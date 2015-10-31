#include "grafo.h"
#include <string>
#include "nodo.h"

Grafo::Grafo()
{
    nds_u=0;
}

void Grafo::addNodo(Nodo *n)
{
    nodos[nds_u]=n;
    nds_u++;
}

void Grafo::resolver()
{
    int c_nodos=nds_u;
    int fase=1;
    for(int n=0;n<c_nodos;n++){
        for(int c=0;c<nds_u;c++){
            if(nodos[c]->fase==0){
                for(int x=0;x<nodos[c]->aristas_u;x++){
                    if(nodos[c]->aristas[x]->fase==fase){
                        nodos[c]->fase=fase;
                        c_nodos--;
                    }
                }
            }
        }
        fase++;
    }

}

