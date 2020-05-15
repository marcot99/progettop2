#ifndef SERPENTE_H
#define SERPENTE_H

#include "carnivoro.h"
class Serpente:public Carnivoro
{
private:
    int Pelle;
public:
    Serpente(int Pe=0,int A=0, int E=0,int Pb=0,string Cs=string() ,bool Ie=false,string S=string(),bool V=false,string Pr=string(),bool ve = false,bool ne= false,int pe = 0);
    int getPelle() const;
    virtual bool isGrasso() const;
    virtual bool isVecchio() const;
    virtual bool isdiValore() const;
    virtual int PrezzoFinale() const;
};

#endif // SERPENTE_H
