#ifndef NODO_H
#define NODO_H
#include <string>

using namespace std;


class Nodo
{
public:
    Nodo(string name);
    string nombre;
    int aristas_u,fase;
    Nodo* aristas[10];
    void add_A(Nodo* n);
    bool validar(int fase);

};

#endif // NODO_H
