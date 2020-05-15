#ifndef ORSO_H
#define ORSO_H

#include "onnivoro.h"
class Orso:public Onnivoro
{
private:
    int Pelliccia;
public:
    Orso(int Pe=0,int A=0 , int E=0,int Pb=0,string Cs=string(),bool Ie=false,string S=string(),bool V=false,string Pr=string(),list<Tipo> t = list<Tipo>(),bool ve = false,bool ne= false,int pe = 0);
    int getPelliccia() const;
    virtual bool isGrasso() const;
    virtual bool isVecchio() const;
    virtual bool isdiValore() const;
    virtual int PrezzoFinale() const;
};

#endif // ORSO_H
