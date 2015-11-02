#include <QCoreApplication>
#include <iostream>

using namespace std;

class Cola{
public:
    char valor;
    Cola *next;
    Cola(char v){
        this->valor=v;
    }
};

Cola* begin;
Cola* tail;

void push(char v){
    if(begin==NULL){
        begin=new Cola(v);
        tail=begin;
    }
    else{
        tail->next=new Cola(v);
        tail=tail->next;
    }
}

Cola* pop(){
    Cola* temp=begin;
    cout<<temp->valor<<endl;
    begin=temp->next;
    return temp;
}

Cola* touch(){
    return begin;
}

void imprimir(){
    Cola* temp=begin;
    while(temp!=NULL){
    cout<<"Valor= ";
    cout<<temp->valor<<endl;
    temp=temp->next;
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

