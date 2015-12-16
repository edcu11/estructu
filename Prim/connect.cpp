#include "connect.h"
#include <limits>

Connect::Connect(Nodo* n)
{
    this->nodo=n;
    v=false;
    c=999;
    p=-1;
}

