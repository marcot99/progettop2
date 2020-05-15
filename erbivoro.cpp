#include "erbivoro.h"

Erbivoro::Erbivoro(int Pe , int A ,int E,int Pb,string Cs,bool Ie,string S,bool V,string Pr,list<Tipo> t):
    Animale(Pe,A,E,Pb,Cs,Ie,S,V,Pr),Dieta(t){}

list<Tipo> Erbivoro::getDieta() const {return Dieta;}
