#include "onnivoro.h"



Onnivoro::Onnivoro(int Pe, int A, int E, int Pb, std::string Cs, bool Ie, std::string S, bool V, std::string Pr, list<Tipo> t, bool ve, bool ne):
    Animale(Pe,A,E,Pb,Cs,Ie,S,V,Pr),Erbivoro(Pe,A,E,Pb,Cs,Ie,S,V,Pr,t),Carnivoro(Pe,A,E,Pb,Cs,Ie,S,V,Pr,ve,ne){}
