#include "rinoceronte.h"

Rinoceronte::Rinoceronte(int Pe, int A, int E, int Pb,string Cs, bool Ie,string S, bool V, string Pr, list<Tipo> t, int Co):
Animale(Pe,A,E,Pb,Cs,Ie,S,V,Pr),Erbivoro(Pe,A,E,Pb,Cs,Ie,S,V,Pr,t),Corno(Co){}

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

/*bool Rinoceronte::operator==(const Animale &a) const {
    if(typeid(const Rinoceronte&) != typeid(a)) return false;
    const Rinoceronte* p = dynamic_cast<const Rinoceronte*>(&a);
    return Animale::operator==(a) && getDieta() == p->getDieta() && Corno == p->Corno;
}*/


