#include "onnivoro.h"

Onnivoro::Onnivoro(int Pe, int A, int E, int Pb, string Cs, bool Ie, string S, bool V, string Pr, list<Tipo> t, bool ve, bool ne):
    Animale(Pe,A,E,Pb,Cs,Ie,S,V,Pr),Erbivoro(Pe,A,E,Pb,Cs,Ie,S,V,Pr,t),Carnivoro(Pe,A,E,Pb,Cs,Ie,S,V,Pr,ve,ne){}

/*bool Onnivoro::operator==(const Animale &a) const {
    if(typeid(const Onnivoro&) != typeid(a)) return false;
    return Animale::operator==(a),Carnivoro::operator==(a),Erbivoro::operator==(a);
}*/
