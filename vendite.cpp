#include "vendite.h"

vendite::vendite(int i,string t,int p,string d) : id(i),tipoanimale(t),prezzove(p),data(d) {}

int vendite::getId() const
{
    return id;
}

string vendite::getTipoA() const
{
    return  tipoanimale;
}
int vendite::getPrezzoV() const
{
    return  prezzove;
}

string vendite::getData() const
{
    return data;
}
