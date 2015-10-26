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
    if(elementos+1<limite){
        array[elementos+1]=valor;
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
        if(array[n]==valor)
            return n;
    }

    return -1;
}


int main()
{
    int resp;
    int valoring, valor2;
    while(resp!=5){
        cout<<"----Menu-----"<<endl;
        cout<<"1. Añadir"<<endl;
        cout<<"2. Buscar"<<endl;
        cout<<"3. Insertar"<<endl;
        cout<<"4. Borrar"<<endl;
        cout<<"5. Salir"<<endl;

        cin>>resp;
        if(resp==5)
            break;

        switch(resp){
            case 1:
                add(cin>>valoring);break;
            case 2:
                buscar(cin>>valoring);break;
            case 3:
                insert(cin>>valoring,cin>>valor2);break;
            case 4:
                eliminar(cin>>valoring);break;
        }
    }
    return 0;
}

