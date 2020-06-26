#ifndef ORSO_H
#define ORSO_H

#include "onnivoro.h"
class Orso:public Onnivoro
{
private:
    int Pelliccia;
public:
    Orso(int id = 0,int Pe=0, int A=0, int E=0, bool Ie= false,string S=string(), list<Tipo> t=list<Tipo>(),bool ve = false,bool ne= false,int pe=0);
    int getPelliccia() const;
    virtual bool isGrasso() const;
    virtual bool isVecchio() const;
    virtual bool isdiValore() const;
    virtual Animale* clone() const;
    virtual string getSpecie() const;
    //virtual bool operator==(const Animale &a) const;
};

#endif // ORSO_H

