#include "rinoceronte.h"

Rinoceronte::Rinoceronte(int id,int Pe, int A, int E, bool Ie,string S, list<Tipo> t, int Co):
Animale(id,Pe,A,E,Ie,S),Erbivoro(id,Pe,A,E,Ie,S,t),Corno(Co){}

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


int Rinoceronte::getCorno() const
{
    return Corno;
}

Animale *Rinoceronte::clone() const
{
    return new Rinoceronte(*this);
}

std::string Rinoceronte::getSpecie() const
{
    return "Rinoceronte";
}

/*bool Rinoceronte::operator==(const Animale &a) const {
    if(typeid(const Rinoceronte&) != typeid(a)) return false;
    const Rinoceronte* p = dynamic_cast<const Rinoceronte*>(&a);
    return Animale::operator==(a) && getDieta() == p->getDieta() && Corno == p->Corno;
}*/


