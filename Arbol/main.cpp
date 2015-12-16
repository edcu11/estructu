#include <QCoreApplication>
#include <iostream>
#include <nodo.h>

using namespace std;


Nodo* raiz;

void agregar(Nodo* n, Nodo* viajero){
    if(raiz==NULL){
        raiz=n;
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

    if(v==viajero->val)
        return viajero;

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
        cout<<"no hay nada"<<endl;
        return NULL;
}
//no funciona
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
       int opc;
       int valor;
       while(true){
           cout<<"1-Agregar"<<endl;
           cout<<"2-Buscar"<<endl;
           cout<<"3-Eliminar"<<endl;
           cout<<"4-Imprimir"<<endl;
           cin>>opc;
           switch(opc){
               case 1:
                    cin>>valor;
                    agregar(new Nodo(valor),raiz); break;
               case 2:
                    cin>>valor;
                    cout<<buscar(valor,raiz)->val<<endl; break;
               case 3:
                    cin>>valor;
                    eliminar(valor,raiz);break;
               case 4:
                    imprimir(raiz); break;
           }
       }


    return a.exec();
}

