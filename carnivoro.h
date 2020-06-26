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
    Carnivoro(int id=0,int Pe=0,int A=0, int E=0,bool Ie=false,string S=string(),bool ve = false,bool ne= false);
    //virtual bool operator==(const Animale& a) const;
    virtual string getTipo() const;
    bool getvelenoso() const;
    bool getnecrofago() const;
    virtual Animale* clone() const = 0;

};

#endif // CARNIVORO_H
