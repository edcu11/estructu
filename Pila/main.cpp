#include <QCoreApplication>


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
    if(tail=NULL){
        Pila* temp=new Pila(valor);
        temp->ante=tail;
        tail=temp;
    }
    else
        tail=new Pila(valor);

}

Pila* pop(){
    if(tail==NULL){
        Pila* tempo=tail;
        tail=tempo->ante;
        return tempo;
    }
    return NULL;
}

Pila* touch(){
    return tail;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}

