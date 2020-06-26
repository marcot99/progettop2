#include "carnivoro.h"

Carnivoro::Carnivoro(int id,int Pe, int A, int E, bool Ie, string S, bool ve, bool ne):
    Animale(id,Pe,A,E,Ie,S),velenoso(ve),necrofago(ne){}

std::string Carnivoro::getTipo() const
{
    return "Carnivoro";
}

/*bool Carnivoro::operator==(const Animale &a) const{
    if(typeid(const Carnivoro&) != typeid(a)) return false;
    const Carnivoro* p = dynamic_cast<const Carnivoro*>(&a);
    return Animale::operator==(a) && velenoso == p->velenoso && necrofago == p->necrofago;
}*/

bool Carnivoro::getvelenoso() const {return velenoso;}

bool Carnivoro::getnecrofago() const {return necrofago;}
