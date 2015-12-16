#include <QCoreApplication>
#include <nodo.h>
#include <arista.h>


Nodo* nodos[20];
int cant;
int c[20][20],p[20][20];

void I_nodos(int cant){

    for(int i=0;i<cant;i++){
        nodos[i]=new Nodo(i);
    }

    int r_pos,r_cos;
    //MAKING ARISTAS

    for(int i=0; i<cant;i++){
        r_pos=rand()%(cant-1),r_cos=rand()%10+1;

        nodos[i]->add_A( new Arista(nodos[r_pos],r_cos) ) ;

        while(nodos[i]->adj->apunt==nodos[i] || (nodos[i]->adj->apunt->adj!=NULL && nodos[i]->adj->apunt->adj->apunt==nodos[i])){
            r_pos=rand()%(cant-1);
            nodos[i]->adj->apunt=nodos[r_pos];
        }
        //nodos[r_pos]->nodo->add_A(new Arista(nodos[i]->nodo,r_cos));

        //MAKING SURE THEM ARISTAS DONT CONNECT THEMSELVES OR TWICE SAME NODE
        if(i%3==0){
            r_pos=rand()%(cant-1),r_cos=rand()%10+1;
            nodos[i]->adj->sig=new Arista(nodos[r_pos],r_cos);
           // nodos[i]->nodo->add_A(new Arista(nodos[r_pos]->nodo,r_cos));

            while(nodos[i]->adj->sig->apunt==nodos[i]->adj->apunt){
                r_pos=rand()%(cant-1);
                nodos[i]->adj->sig->apunt=nodos[r_pos];

                if(nodos[i]->adj->apunt->adj->apunt==nodos[i]){
                    r_pos=rand()%(cant-1);
                    nodos[i]->adj->sig->apunt=nodos[r_pos];
                }

            }
            //nodos[r_pos]->nodo->add_A(new Arista(nodos[i]->nodo,r_cos));
        }
    }

    //SHOWING NODES
    for(int i=0;i<cant;i++){
        Arista* temp=nodos[i]->adj;
        cout<<"---Nodo"<<i<<"--"<<endl;
        while(temp!=NULL){
            cout<<"Peso="<<temp->peso;
            cout<<" -- A "<<temp->apunt->valor<<endl;
            temp=temp->sig;
        }
    }

    for(int x=0; x<cant; x++){
        for(int y=0; y<cant; y++){
              c[x][y]=999;
              p[x][y]=-1;
        }
    }

    for(int x=0; x<cant; x++){
        Arista* temp=nodos[x]->adj;
        while(temp!=NULL){
            c[x][temp->apunt->valor]=temp->peso;
            p[x][temp->apunt->valor]=nodos[x]->valor;
            temp=temp->sig;
        }
    }


}




void floyd(){

    for(int k=0; k<cant; k++){
        for(int i=0; i<cant; i++){
            for(int j=0; j<cant; j++){
                if(c[i][k]+c[k][j] < c[i][j]){
                    c[i][j]= c[i][k]+c[k][j];
                    p[i][j]=k;
                }
            }
        }
    }

    for(int x=0; x<cant; x++){
        c[x][x]=0;
        p[x][x]=-1;
    }

    for(int x=0; x<cant; x++){
        for(int y=0; y<cant; y++){
              cout<<c[x][y]<< " \t ";
        }
        cout<<endl;
    }

    cout<<endl;

    for(int x=0; x<cant; x++){
        for(int y=0; y<cant; y++){
              cout<<p[x][y]<< " \t ";
        }
        cout<<endl;
    }

}





int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cin>>cant;
    nodos[cant];
    c[cant][cant],p[cant][cant];
    I_nodos(cant);
    floyd();

    return a.exec();
}

