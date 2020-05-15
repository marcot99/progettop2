#include "orso.h"

Orso::Orso(int Pe, int A, int E, int Pb, std::string Cs, bool Ie, std::string S, bool V, std::string Pr, list<Tipo> t, bool ve, bool ne,int pe):
Onnivoro(Pe,A,E,Pb,Cs,Ie,S,V,Pr,t,ve,ne),Pelliccia(pe){}

int Orso::getPelliccia() const
{
    return Pelliccia;
}

bool Orso::isGrasso() const
{
    return (getAltezza()/getPeso() > 5 ? true : false);
}

bool Orso::isVecchio() const
{
    return (getEta() > 25 ? true : false);
}

bool Orso::isdiValore() const
{
    return (getPelliccia() > 2 ? true : false);
}

int Orso::PrezzoFinale() const
{
    return getPrezzoBase()+(isdiValore()?500:0);
}
