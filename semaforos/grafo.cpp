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
    int c_nodos;
    int fase=1;
    bool valido=true;
    for(c_nodos = nds_u; c_nodos > 0; fase++){
        for(int x=0; x<nds_u; x++){
            if(nodos[x]->fase==0 && validar(nodos[x],fase)){
                nodos[x]->fase=fase;
                c_nodos--;
            }
        }
   }

}

bool Grafo::validar(Nodo* n,int fase){

    for(int y=0; y<n->aristas_u; y++){
        if(n->aristas[y]->fase==fase)
            return false;
    }
    return true;


}

void Grafo::imprimir(){
    int c_nodos=nds_u;
    for(int n=0;n<c_nodos;n++){
        cout<<endl;
        cout<<nodos[n]->nombre<<endl;
        cout<<"---ARISTAS---"<<endl;
        for(int c=0;c<nodos[n]->aristas_u;c++){
            cout<<nodos[n]->aristas[c]->nombre;
            cout<<"= "<<nodos[n]->aristas[c]->fase<<endl;
        }
    }
}

