#ifndef NODO_H
#define NODO_H


class Nodo
{
public:
    Nodo();
    string nombre;
    int n_aris, fase;
    Nodo* aristas[10];

    void addArista(Nodo n);
    bool checkFase(int x);



};

#endif // NODO_H
