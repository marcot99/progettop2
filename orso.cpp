#include "orso.h"

Orso::Orso(int id,int Pe, int A, int E, bool Ie, string S, list<Tipo> t, bool ve, bool ne,int pe):
Animale(id,Pe,A,E,Ie,S),Onnivoro(id,Pe,A,E,Ie,S,t,ve,ne),Pelliccia(pe){}

int Orso::getPelliccia() const
{
    return Pelliccia;
}

bool Orso::isGrasso() const
{
    return getAltezza()/getPeso() > 5;
}

bool Orso::isVecchio() const
{
    return getEta() > 25;
}

bool Orso::isdiValore() const
{
    return getPelliccia() > 2;
}

/*bool Orso::operator==(const Animale &a) const {
    if(typeid(const Orso&) != typeid(a)) return false;
    const Orso* p = dynamic_cast<const Orso*>(&a);
    return Animale::operator==(a) && getDieta() == p->getDieta() && getvelenoso() == p->getvelenoso() && getnecrofago() == p->getnecrofago() && getPelliccia() == p->getPelliccia();
}*/
Animale *Orso::clone() const
{
    return new Orso(*this);
}

std::string Orso::getSpecie() const
{
    return "Orso";
}
