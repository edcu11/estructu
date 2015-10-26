#include <iostream>
#include <nodos.h>

using namespace std;



nodos* begin;
nodos* final;



void add(int x){
   if(begin==NULL){
       begin=new nodos(x);
       final=new nodos(x);
   }
   else{
        nodos* child= begin;
        while(child.next!=NULL)
            child=child.next;
        child.next=new Nodos(x);
   }

}

bool insert(int pos,int x){
    nodos* child=begin;
    nodos in=new nodos(x);
    if(child==NULL)
        child=new nodos(x);
    else{
        for(int n=0;n<pos;child=child.next){

        }
        in.next=child.next;
        child.next=in;
    }

}

bool borrar(int valor){
    nodos child=begin;
    while(child.next.valor!=valor){
        child=child.next;
        if(child.next==NULL)
            return false;
    }
    nodos borre=child.next;
    child.next=child.next.next;
    borre.next=NULL;
    return true;

}

nodos buscar(int valor){
    nodos child=begin;
    while(child.next.valor!=valor)
        child=child.next;
    return child;

}

void imprimir(){
    if(begin==NULL){
        cout<<"No hay nada viejo"<<endl;
        return;
    }
    nodos child=begin;

    while(child.next!=NULL){
        cout<<child.valor<<endl;

    }


}


int main()
{
    int resp;
    int valoring, valor2;
    while(resp!=6){
        cout<<"----Menu-----"<<endl;
        cout<<"1. Añadir Nodo"<<endl;
        cout<<"2. Buscar Nodo"<<endl;
        cout<<"3. Insertar Nodo"<<endl;
        cout<<"4. Borrar Nodo"<<endl;
        cout<<"5. Imprimir Nodos"<<endl;
        cout<<"6. Salir"<<endl;

        cin>>resp;
        if(resp==6)
            break;

        switch(resp){
            case 1:
                add(cin>>valoring);break;
            case 2:
                buscar(cin>>valoring);break;
            case 3:
                insert(cin>>valoring,cin>>valor2);break;
            case 4:
                borrar(cin>>valoring);break;
            case 5:
                imprimir();break;

        }
    }
    return 0;
}

