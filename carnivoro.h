#ifndef CARNIVORO_H
#define CARNIVORO_H
#include "animale.h"
class Carnivoro :virtual public Animale
{
private:
    bool velenoso;
    bool necrofago;
public:
    //Carnivoro(int Pe,int A, int E,int Pb,string Cs,bool Ie,string S,bool V,string Pr,bool ve,bool ne);
    Carnivoro(int Pe=0,int A=0, int E=0,int Pb=0,string Cs=string() ,bool Ie=false,string S=string(),bool V=false,string Pr=string(),bool ve = false,bool ne= false);
    //virtual bool operator==(const Animale& a) const;

    bool getvelenoso() const;
    bool getnecrofago() const;

};

#endif // CARNIVORO_H
