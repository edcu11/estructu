#include <iostream>


class cursor{
public:
    char valor;
    int next;
};

using namespace std;

int contador=0;
const int tam=10;
cursor array[tam];
int listas[10];

int nextAvailable(){
    for(int n=0;n<tam;n++){
        if(listas[n]==-1)
            return n;
    }
    return -1;

}

void add(char valor){
    int primerDisp=listas[0];
    listas[0]=array[primerDisp].next;
    array[primerDisp].valor=valor;
    array[primerDisp].next=-1;
    listas[nextAvailable()]=primerDisp;
    contador++;
}

int buscar(int pos_L, char val ){
    cursor* i= &array[listas[pos_L]];
    while(i->next==-1 || array[i->next].valor!=val){
        i=&array[i->next];
    }
    if(array[i->next].valor==val)
        return i->next;
    return -1;

}

void agregar_V(char val, int list){
    int disp=listas[0];
    cursor* i= &array[listas[list]];
    while(i->next!=-1){
        i=&array[i->next];
    }
    i->next=disp;
    listas[disp].valor=val;
    listas[0]=array[disp].next;
    array[disp].next=-1;
    contador++;
}

void insertar(char val, int pos_l, char val_pos){

    int pos= buscar(pos_l,val_pos);
    cursor* i= &array[listas[pos_l]];






    if(cont<10){
        int nextDisp=listas[0];
        Nodo* temp=&arreglo[listas[lista]];
        while(temp->next!=-1){
            if(temp->valor==despuesDe){
                arreglo[nextDisp].valor=valor;
                listas[0]=arreglo[nextDisp].next;
                arreglo[nextDisp].next=temp->next;
                temp->next=nextDisp;
                cont++;
            }
        temp=&arreglo[temp->next];
        }
    }
}








int main()
{



    return 0;
}

