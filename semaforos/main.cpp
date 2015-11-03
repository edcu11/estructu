#include <QCoreApplication>
#include <iostream>
#include "grafo.h"

int main(int argc, char *argv[])
{
    Nodo *AB = new Nodo("AB");
    Nodo *AC = new Nodo("AC");
    Nodo *AD = new Nodo("AD");
    Nodo *BA = new Nodo("BA");
    Nodo *BC = new Nodo("BC");
    Nodo *BD = new Nodo("BD");
    Nodo *DA = new Nodo("DA");
    Nodo *DB = new Nodo("DB");
    Nodo *DC = new Nodo("DC");
    Nodo *EA = new Nodo("EA");
    Nodo *EB = new Nodo("EB");
    Nodo *EC = new Nodo("EC");
    Nodo *ED = new Nodo("ED");

    AB->add_A(BC);
    AB->add_A(BD);
    AB->add_A(DA);
    AB->add_A(EA);

    AC->add_A(BD);
    AC->add_A(DA);
    AC->add_A(DB);
    AC->add_A(EA);
    AC->add_A(EB);

    AD->add_A(EA);
    AD->add_A(EB);
    AD->add_A(EC);

    BC->add_A(AB);
    BC->add_A(DB);
    BC->add_A(EB);

    DA->add_A(AB);
    DA->add_A(AC);
    DA->add_A(BD);
    DA->add_A(EB);
    DA->add_A(EC);

    BD->add_A(AB);
    BD->add_A(AC);
    BD->add_A(DA);
    BD->add_A(EB);
    BD->add_A(EC);

    DB->add_A(AC);
    DB->add_A(BC);
    DB->add_A(EC);

    EA->add_A(AB);
    EA->add_A(AC);
    EA->add_A(AD);

    EB->add_A(AC);
    EB->add_A(AD);
    EB->add_A(BC);
    EB->add_A(BD);
    EB->add_A(DA);

    EC->add_A(AD);
    EC->add_A(BD);
    EC->add_A(DA);
    EC->add_A(DB);

    Grafo* grafo=new Grafo();

    grafo->addNodo(AB);
    grafo->addNodo(AC);
    grafo->addNodo(AD);

    grafo->addNodo(BA);
    grafo->addNodo(BC);
    grafo->addNodo(BD);

    grafo->addNodo(DA);
    grafo->addNodo(DB);
    grafo->addNodo(DC);

    grafo->addNodo(EA);
    grafo->addNodo(EB);
    grafo->addNodo(EC);
    grafo->addNodo(ED);




    grafo->resolver();
    grafo->imprimir();











    QCoreApplication a(argc, argv);

    return a.exec();
}

