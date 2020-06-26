#ifndef SERPENTE_H
#define SERPENTE_H

#include "carnivoro.h"
class Serpente:public Carnivoro
{
private:
    int Pelle;
public:
    Serpente(int id=0,int Pe=0,int A=0, int E=0,bool Ie=false,string S=string(),bool ve = false,bool ne= false,int pe = 0);
    int getPelle() const;
    virtual bool isGrasso() const;
    virtual bool isVecchio() const;
    virtual bool isdiValore() const;
    virtual Animale* clone() const;
    virtual string getSpecie() const;
    //virtual bool operator==(const Animale &a) const;
};

#endif // SERPENTE_H
