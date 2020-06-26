#include "onnivoro.h"

Onnivoro::Onnivoro(int id,int Pe, int A, int E,bool Ie, string S, list<Tipo> t, bool ve, bool ne):
    Animale(id,Pe,A,E,Ie,S),Erbivoro(id,Pe,A,E,Ie,S,t),Carnivoro(id,Pe,A,E,Ie,S,ve,ne){}

std::string Onnivoro::getTipo() const
{
    return "Onnivoro";
}

/*bool Onnivoro::operator==(const Animale &a) const {
    if(typeid(const Onnivoro&) != typeid(a)) return false;
    return Animale::operator==(a),Carnivoro::operator==(a),Erbivoro::operator==(a);
}*/
