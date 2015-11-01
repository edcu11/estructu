#include <QCoreApplication>

class Cola{
public:
    char valor;
    Cola *next;
    Nodo(char v){
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
    begin=temp->next;
    return temp;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}

