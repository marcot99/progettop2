#ifndef RINOCERONTE_H
#define RINOCERONTE_H

#include "erbivoro.h"
class Rinoceronte:public Erbivoro
{
private:
    int Corno;
public:
    Rinoceronte(int id=0,int Pe=0, int A=0, int E=0, bool Ie= false,string S=string(), list<Tipo> t=list<Tipo>(), int Co=0);
    virtual bool isGrasso() const;
    virtual bool isVecchio() const;
    virtual bool isdiValore() const;
    virtual int getCorno() const;
    virtual Animale* clone() const;
    virtual string getSpecie() const;
    //virtual bool operator==(const Animale &a) const;

};

#endif // RINOCERONTE_H
