#ifndef CARNIVORO_H
#define CARNIVORO_H
#include "animale.h"
class Carnivoro :virtual public Animale
{
private:
    bool velenoso;
    bool necrofago;
public:
    Carnivoro(int Pe=0,int A=0, int E=0,int Pb=0,string Cs=string() ,bool Ie=false,string S=string(),bool V=false,string Pr=string(),bool ve = false,bool ne= false);
    bool getvelenoso() const;
    bool getnecrofago() const;

};

#endif // CARNIVORO_H
