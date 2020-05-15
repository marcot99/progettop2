#include "rinoceronte.h"

Rinoceronte::Rinoceronte(int Pe, int A, int E, int Pb,string Cs, bool Ie,string S, bool V, string Pr, list<Tipo> t, int Co):
    Erbivoro(Pe,A,E,Pb,Cs,Ie,S,V,Pr,t),Corno(Co){}//Erbivoro(Pe,A,E,Pb,Cs,Ie,S,V,Pr,t)

bool Rinoceronte::isGrasso() const
{
    return getAltezza()/getPeso() > 5;
}

bool Rinoceronte::isVecchio() const
{
    return getEta() > 25;
}

bool Rinoceronte::isdiValore() const
{
    return getCorno() > 2;
}

int Rinoceronte::PrezzoFinale() const
{
    return getPrezzoBase()+(isdiValore()?500:0);
}

int Rinoceronte::getCorno() const
{
    return Corno;
}


