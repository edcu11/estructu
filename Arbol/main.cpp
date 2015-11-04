#include <QCoreApplication>
#include <iostream>
#include <nodo.h>

using namespace std;


Nodo* raiz;

void agregar(Nodo* n, Nodo* viajero){
    if(raiz==NULL){
        raiz=n;
        cout<<"ediu"<<endl;
        return;
    }
    if(n->val > viajero->val){
        if(viajero->der==NULL){
            viajero->der=n;
            return;
        }
        agregar(n,viajero->der);
    }
    if(n->val < viajero->val){
        if(viajero->izq==NULL){
            viajero->izq=n;
            return;
        }
        agregar(n,viajero->izq);

    }

    if(n->val==viajero->val){
        cout<<"valor ya existe"<<endl;
        return;
    }

}

Nodo* buscar(int v,Nodo* viajero){
    if(v > viajero->val){
        if(viajero->der->val==v){
            return viajero->der;
        }
        buscar(v,viajero->der);
    }
    if(v < viajero->val){
        if(viajero->izq->val==v){
            return viajero->izq;
        }
        buscar(v,viajero->izq);
    }
    else
        return NULL;
}

void eliminar(int x, Nodo* viajero){
    if(viajero==raiz){
        if(!buscar(x,raiz)){
            cout<<"No existe el valor"<<endl;
            return;
        }
        else
            viajero=buscar(x,raiz);
    }





}

void imprimir(Nodo* n){
    cout<<"Nodo= "<<n->val<<endl;

    if(n->izq!=NULL)
        imprimir(n->izq);
    if(n->der!=NULL)
        imprimir(n->der);


}



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    agregar(new Nodo(5),raiz);
    agregar(new Nodo(6),raiz);
    agregar(new Nodo(1),raiz);
    agregar(new Nodo(2),raiz);
    agregar(new Nodo(3),raiz);
    agregar(new Nodo(8),raiz);
    agregar(new Nodo(8),raiz);
    agregar(new Nodo(9),raiz);
    agregar(new Nodo(4),raiz);
    agregar(new Nodo(7),raiz);
    cout<<"ed"<<endl;
    imprimir(raiz);
    cout<<"buscando 2= "<<buscar(2,raiz)<<endl;
    cout<<buscar(2,raiz)->val<<endl;




    return a.exec();
}

