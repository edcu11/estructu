#include <QCoreApplication>
#include <nodo.h>
#include <arista.h>
#include <stdlib.h>
#include <connect.h>

Connect* nodos[20];
int cant;

void I_nodos(int cant){

    for(int i=0;i<cant;i++){
        nodos[i]=new Connect(new Nodo(i));
    }

    int r_pos,r_cos;
    //MAKING ARISTAS

    for(int i=0; i<cant;i++){
        r_pos=rand()%(cant-1),r_cos=rand()%10+1;

        nodos[i]->nodo->add_A( new Arista(nodos[r_pos]->nodo,r_cos) ) ;

        while(nodos[i]->nodo->adj->apunt==nodos[i]->nodo || (nodos[i]->nodo->adj->apunt->adj!=NULL && nodos[i]->nodo->adj->apunt->adj->apunt==nodos[i]->nodo)){
            r_pos=rand()%(cant-1);
            nodos[i]->nodo->adj->apunt=nodos[r_pos]->nodo;
        }
        //nodos[r_pos]->nodo->add_A(new Arista(nodos[i]->nodo,r_cos));



        //MAKING SURE THEM ARISTAS DONT CONNECT THEMSELVES OR TWICE SAME NODE
        if(i%3==0){
            r_pos=rand()%(cant-1),r_cos=rand()%10+1;
            nodos[i]->nodo->adj->sig=new Arista(nodos[r_pos]->nodo,r_cos);
           // nodos[i]->nodo->add_A(new Arista(nodos[r_pos]->nodo,r_cos));

            while(nodos[i]->nodo->adj->sig->apunt==nodos[i]->nodo->adj->apunt){
                r_pos=rand()%(cant-1);
                nodos[i]->nodo->adj->sig->apunt=nodos[r_pos]->nodo;

                if(nodos[i]->nodo->adj->apunt->adj->apunt==nodos[i]->nodo){
                    r_pos=rand()%(cant-1);
                    nodos[i]->nodo->adj->sig->apunt=nodos[r_pos]->nodo;
                }

            }
            //nodos[r_pos]->nodo->add_A(new Arista(nodos[i]->nodo,r_cos));

        }
    }

    //SHOWING NODES
    for(int i=0;i<cant;i++){
        Arista* temp=nodos[i]->nodo->adj;
        cout<<"---Nodo"<<i<<"--"<<endl;
        while(temp!=NULL){
            cout<<"Peso="<<temp->peso;
            cout<<" -- A "<<temp->apunt->valor<<endl;
            temp=temp->sig;
        }
    }

}

void nodos_A(){


    nodos[0]=new Connect(new Nodo(0));
    nodos[1]=new Connect(new Nodo(1));
    nodos[2]=new Connect(new Nodo(2));
    nodos[3]=new Connect(new Nodo(3));
    nodos[4]=new Connect(new Nodo(4));
    nodos[5]=new Connect(new Nodo(5));


    nodos[0]->nodo->add_A(new Arista(nodos[2]->nodo,4));
    nodos[0]->nodo->add_A(new Arista(nodos[3]->nodo,3));
    nodos[0]->nodo->add_A(new Arista(nodos[1]->nodo,2));
    nodos[0]->nodo->add_A(new Arista(nodos[5]->nodo,5));



    nodos[1]->nodo->add_A(new Arista(nodos[0]->nodo,2));
    nodos[1]->nodo->add_A(new Arista(nodos[2]->nodo,3));
    nodos[1]->nodo->add_A(new Arista(nodos[4]->nodo,8));


    nodos[2]->nodo->add_A(new Arista(nodos[0]->nodo,4));
    nodos[2]->nodo->add_A(new Arista(nodos[1]->nodo,3));
    nodos[2]->nodo->add_A(new Arista(nodos[5]->nodo,7));
    nodos[2]->nodo->add_A(new Arista(nodos[4]->nodo,5));


    nodos[3]->nodo->add_A(new Arista(nodos[0]->nodo,3));

    nodos[4]->nodo->add_A(new Arista(nodos[1]->nodo,8));
    nodos[4]->nodo->add_A(new Arista(nodos[2]->nodo,5));

    nodos[5]->nodo->add_A(new Arista(nodos[0]->nodo,5));
    nodos[5]->nodo->add_A(new Arista(nodos[2]->nodo,7));

  /*
    nodos[0]=new Tabla(new Nodo(0));
    nodos[1]=new Tabla(new Nodo(1));
    nodos[2]=new Tabla(new Nodo(2));
    nodos[3]=new Tabla(new Nodo(3));
    nodos[4]=new Tabla(new Nodo(4));
    nodos[5]=new Tabla(new Nodo(5));

    tabla[0]->nodo->agregarArista(new Arista(tabla[1]->nodo, 5));
    tabla[0]->nodo->agregarArista(new Arista(tabla[2]->nodo, 2));
    tabla[0]->nodo->agregarArista(new Arista(tabla[5]->nodo, 4));

    tabla[1]->nodo->agregarArista(new Arista(tabla[0]->nodo, 5));
    tabla[1]->nodo->agregarArista(new Arista(tabla[3]->nodo, 6));
    tabla[1]->nodo->agregarArista(new Arista(tabla[5]->nodo, 10));

    tabla[2]->nodo->agregarArista(new Arista(tabla[0]->nodo, 2));
    tabla[2]->nodo->agregarArista(new Arista(tabla[3]->nodo, 7));

    tabla[3]->nodo->agregarArista(new Arista(tabla[1]->nodo, 6));
    tabla[3]->nodo->agregarArista(new Arista(tabla[2]->nodo, 7));
    tabla[3]->nodo->agregarArista(new Arista(tabla[4]->nodo, 3));

    tabla[4]->nodo->agregarArista(new Arista(tabla[3]->nodo, 3));

    tabla[5]->nodo->agregarArista(new Arista(tabla[0]->nodo, 4));
    tabla[5]->nodo->agregarArista(new Arista(tabla[1]->nodo, 10));
*/
}

int visitados(){
    int menor=-1;
    for(int cont=0; cont<cant; cont++){
        if(nodos[cont]->v==false){
            if(menor==-1 || nodos[cont]->c<menor)
                menor=cont;
        }
    }
    return menor;
}

void prim(int pos){
    nodos[pos]->c=0;
    while(pos!=-1){
        Arista* temp=nodos[pos]->nodo->adj;
        while(temp!=NULL){
            if(nodos[pos]->v==false){
                if(nodos[temp->apunt->valor]->c>temp->peso+nodos[pos]->c){
                    nodos[temp->apunt->valor]->c=temp->peso;
                    nodos[temp->apunt->valor]->p=nodos[pos]->nodo->valor;
                }
            }
            temp=temp->sig;
        }
        nodos[pos]->v=true;
        pos=visitados();
    }

    for(int i=0;i<cant; i++){
        cout<<nodos[i]->nodo->valor<< " || "<<nodos[i]->v<<" || "<<nodos[i]->c<< " || "<<nodos[i]->p<<endl;
    }
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int l;
    cin>>cant;
    if(cant==50){
       nodos[5];
       nodos_A();
    }
    else{
        nodos[cant];
        I_nodos(cant);
    }

    cin>>l;
    prim(l);


    return a.exec();
}
