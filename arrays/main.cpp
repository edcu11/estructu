#include <iostream>

using namespace std;

int elementos=0, lim=10;
int array[10];

bool eliminar(int posicion)
{
    if(posicion>elementos)
        return false;

    for(int n=posicion;n<elementos;n++){
        array[n]=array[n+1];
    }
    return true;
}

bool add(int x)
{
    if(elementos+1<lim){
        array[elementos+1]=x;
        elementos++;
        return true;
    }
    return false;
}

bool insert(int valor, int pos){

    if(pos>lim+1)
        return false;

    for(int n=elementos+1;n>pos;n--){
        array[n]=array[n-1];
    }
    array[pos]=valor;
    return true;

}

int buscar(int valor){

    for(int n=0;n<=elementos;n++){
        if(array[n]==valor){
            return n;
        }
    }

    return -1;
}

void imprimir(){

    for(int c=0;c<10;c++){
        cout<<array[c]<<endl;
    }
}


int main()
{
    int resp;
    int valoring, valor2;
    while(resp!=5){
        cout<<"----Menu-----"<<endl;
        cout<<"1-> Añadir"<<endl;
        cout<<"2-> Buscar"<<endl;
        cout<<"3-> Insertar"<<endl;
        cout<<"4-> Borrar"<<endl;
        cout<<"5-> Imprimir"<<endl;

        cin>>resp;
        if(resp==6)
            break;

        switch(resp){
            case 1:
                cin>>valoring;
                add(valoring);
                break;
            case 2:
                 cin>>valoring;
                buscar(valoring);break;
            case 3:
                 cin>>valoring;
                 cin>>valor2;
                cout<<insert(valoring,valor2)<<endl;break;
            case 4:
                cin>>valoring;
                eliminar(valoring);break;
            case 5:
                imprimir();
                break;
        }
    }
    return 0;
}

