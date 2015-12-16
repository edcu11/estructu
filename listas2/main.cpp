#include <QCoreApplication>
#include <iostream>
using namespace std;

class Nodo{
public:
    int valor;
    Nodo *next;
    Nodo(int valor){
        this->valor=valor;
    }
};

Nodo* begin;
Nodo* final;

void agregar(int x){
    if(begin==NULL){
        begin=new Nodo(x);
        final=begin;
    }
    else{
       final->next=new Nodo(x);
       final=final->next;

    }

}

Nodo* buscar(int valor){
    Nodo* child=begin;
    while(child!=NULL){
        if(child->next->valor==valor)
            return child;
        else
            child=child->next;
    }
    return NULL;

}

bool eliminar(int valor){

    Nodo* nu=buscar(valor);
    if(nu==NULL)
        return false;

    Nodo* borrar=nu->next;
    borrar->next=NULL;
    nu->next=nu->next->next;
    return true;

}

void insertar(int buscado, int x){
    Nodo* in=new Nodo(x);
    Nodo* nu=buscar(buscado);

    in->next=nu->next;
    nu->next=in;

}

void imprimir(){
    Nodo* child=begin;
    cout<<"----NODOS-----"<<endl;

    while(child!=NULL){
        cout<<child->valor<<endl;
        child=child->next;

    }

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
        cout<<"4-Insertar"<<endl;
        cout<<"5-Imprimir"<<endl;
        cin>>opc;
        switch(opc){
            case 1:
                cin>>valor;
                agregar(valor); break;
            case 2:
                cin>>valor;
                cout<<"Valor= ";
                if(buscar(valor)==NULL){
                    cout<<"No esta"<<endl;
                    break;
                }
                cout<<buscar(valor)->next->valor<<endl; break;
            case 3:
                cin>>valor;
                eliminar(valor); break;
            case 4:
                int pos;
                cin>>valor;
                cin>>pos;
                insertar(valor, pos); break;
            case 5:
                imprimir(); break;
        }
    }

    return a.exec();
}
