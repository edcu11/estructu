#ifndef NODO_H
#define NODO_H
#include <iostream>
class Arista;
using namespace std;

class Nodo
{
public:
    Nodo(int v);
    int valor;
    Arista* adj;
    void add_A(Arista* arista);
};

#endif // NODO_H
