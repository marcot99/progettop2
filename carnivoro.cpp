#include "carnivoro.h"

Carnivoro::Carnivoro(int Pe, int A, int E, int Pb, string Cs, bool Ie, string S, bool V, string Pr, bool ve, bool ne):
    Animale(Pe,A,E,Pb,Cs,Ie,S,V,Pr),velenoso(ve),necrofago(ne){}

/*bool Carnivoro::operator==(const Animale &a) const{
    if(typeid(const Carnivoro&) != typeid(a)) return false;
    const Carnivoro* p = dynamic_cast<const Carnivoro*>(&a);
    return Animale::operator==(a) && velenoso == p->velenoso && necrofago == p->necrofago;
}*/

bool Carnivoro::getvelenoso() const {return velenoso;}

bool Carnivoro::getnecrofago() const {return necrofago;}
