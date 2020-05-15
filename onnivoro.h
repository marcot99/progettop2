#ifndef ONNIVORO_H
#define ONNIVORO_H

#include "erbivoro.h"
#include "carnivoro.h"
class Onnivoro:public Erbivoro ,public Carnivoro
{
public:
    Onnivoro(int Pe=0,int A=0 , int E=0,int Pb=0,string Cs=string(),bool Ie=false,string S=string(),bool V=false,string Pr=string(),list<Tipo> t = list<Tipo>(),bool ve = false,bool ne= false);
};

#endif // ONNIVORO_H
