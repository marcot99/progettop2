#include "carnivoro.h"

Carnivoro::Carnivoro(int Pe, int A, int E, int Pb, std::string Cs, bool Ie, std::string S, bool V, std::string Pr, bool ve, bool ne):
    Animale(Pe,A,E,Pb,Cs,Ie,S,V,Pr),velenoso(ve),necrofago(ne){}

bool Carnivoro::getvelenoso() const {return velenoso;}

bool Carnivoro::getnecrofago() const {return necrofago;}
