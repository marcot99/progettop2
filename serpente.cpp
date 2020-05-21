#include "serpente.h"



Serpente::Serpente(int Pe, int A, int E, int Pb, string Cs, bool Ie, string S, bool V, string Pr, bool ve, bool ne, int pe):
Animale(Pe,A,E,Pb,Cs,Ie,S,V,Pr),Carnivoro(Pe,A,E,Pb,Cs,Ie,S,V,Pr,ve,ne),Pelle(pe) {}

int Serpente::getPelle() const
{
    return Pelle;
}
bool Serpente::isGrasso() const
{
    return (getAltezza()/getPeso() > 5 ? true : false);
}

bool Serpente::isVecchio() const
{
    return (getEta() > 25 ? true : false);
}

bool Serpente::isdiValore() const
{
    return (getPelle() > 2 ? true : false);
}

int Serpente::PrezzoFinale() const
{
    return getPrezzoBase()+(isdiValore()?500:0);
}

/*bool Serpente::operator==(const Animale &a) const {
    if(typeid(const Serpente&) != typeid(a)) return false;
    const Serpente* p = dynamic_cast<const Serpente*>(&a);
    return Animale::operator==(a) && getvelenoso() == p->getvelenoso() && getnecrofago() == p->getnecrofago() && getPelle() == p->getPelle();
}*/
