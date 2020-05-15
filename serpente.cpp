#include "serpente.h"



Serpente::Serpente(int Pe, int A, int E, int Pb, std::string Cs, bool Ie, std::string S, bool V, std::string Pr, bool ve, bool ne, int pe):
Carnivoro(Pe,A,E,Pb,Cs,Ie,S,V,Pr,ve,ne),Pelle(pe) {}

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
