#ifndef RINOCERONTE_H
#define RINOCERONTE_H

#include "erbivoro.h"
class Rinoceronte:public Erbivoro
{
private:
    int Corno;
public:
    Rinoceronte(int Pe=0, int A=0, int E=0, int Pb=0, string Cs=string(), bool Ie= false,string S=string(), bool V=false, string Pr=string(), list<Tipo> t=list<Tipo>(), int Co=0);
    virtual bool isGrasso() const;
    virtual bool isVecchio() const;
    virtual bool isdiValore() const;
    virtual int PrezzoFinale() const;
    virtual int getCorno() const;
    //virtual bool operator==(const Animale &a) const;

};

#endif // RINOCERONTE_H
