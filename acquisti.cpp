#include "acquisti.h"

acquisti::acquisti(int i,string t,int p,string d) : id(i),tipoanimale(t),prezzoac(p),data(d) {}

int acquisti::getId() const
{
    return id;
}

string acquisti::getTipoA() const
{
    return  tipoanimale;
}
int acquisti::getPrezzoA() const
{
    return  prezzoac;
}

string acquisti::getData() const
{
    return data;
}
