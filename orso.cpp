#include "orso.h"

Orso::Orso(int Pe, int A, int E, int Pb, string Cs, bool Ie, string S, bool V, string Pr, list<Tipo> t, bool ve, bool ne,int pe):
Animale(Pe,A,E,Pb,Cs,Ie,S,V,Pr),Onnivoro(Pe,A,E,Pb,Cs,Ie,S,V,Pr,t,ve,ne),Pelliccia(pe){}

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
/*bool Orso::operator==(const Animale &a) const {
    if(typeid(const Orso&) != typeid(a)) return false;
    const Orso* p = dynamic_cast<const Orso*>(&a);
    return Animale::operator==(a) && getDieta() == p->getDieta() && getvelenoso() == p->getvelenoso() && getnecrofago() == p->getnecrofago() && getPelliccia() == p->getPelliccia();
}*/
