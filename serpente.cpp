#include "serpente.h"



Serpente::Serpente(int id,int Pe, int A, int E, bool Ie, string S, bool ve, bool ne, int pe):
Animale(id,Pe,A,E,Ie,S),Carnivoro(id,Pe,A,E,Ie,S,ve,ne),Pelle(pe) {}

int Serpente::getPelle() const
{
    return Pelle;
}
bool Serpente::isGrasso() const
{
    return getAltezza()/getPeso() > 5;
}

bool Serpente::isVecchio() const
{
    return getEta() > 25;
}

bool Serpente::isdiValore() const
{
    return getPelle() > 2;
}


Animale* Serpente::clone() const
{
    return new Serpente(*this);
}

std::string Serpente::getSpecie() const
{
    return "Serpente";
}
/*bool Serpente::operator==(const Animale &a) const {
    if(typeid(const Serpente&) != typeid(a)) return false;
    const Serpente* p = dynamic_cast<const Serpente*>(&a);
    return Animale::operator==(a) && getvelenoso() == p->getvelenoso() && getnecrofago() == p->getnecrofago() && getPelle() == p->getPelle();
}*/
