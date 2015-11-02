#include <QCoreApplication>
#include <iostream>

using namespace std;


class Pila{
public:
    char valor;
    Pila *ante;
    Pila(char v){
        this->valor=v;
    }
};

Pila* tail;

void push(char valor){
    if(tail!=NULL){
        Pila* temp=new Pila(valor);
        temp->ante=tail;
        tail=temp;
    }
    else
        tail=new Pila(valor);

}

Pila* pop(){
    if(tail!=NULL){
        Pila* tempo=tail;
        cout<<tempo->valor<<endl;
        tail=tempo->ante;
        return tempo;
    }
    return NULL;
}

Pila* touch(){
    return tail;
}

void imprimir(){
    Pila* temp=tail;
    while(temp->ante!=NULL){
        cout<<temp->valor<<endl;
        temp=temp->ante;
    }

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int opc;
    char valor;
    while(true){
        cout<<"1-Push"<<endl;
        cout<<"2-Pop"<<endl;
        cout<<"3-touch"<<endl;
        cout<<"4-Imprimir"<<endl;
        cin>>opc;
        switch(opc){
            case 1:
                cin>>valor;
                push(valor); break;
            case 2:
                pop(); break;
            case 3:
                cout<<touch()->valor<<endl;break;
            case 4:
                imprimir(); break;
        }
    }
    return a.exec();
}

