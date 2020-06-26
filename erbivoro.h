#ifndef ERBIVORO_H
#define ERBIVORO_H
#include "animale.h"
#include <list>
using std::list;
enum Tipo{Frugivoro,Folivoro,Granivoro,Nettarivoro};
class Erbivoro : virtual public Animale
{
private:
      list<Tipo> Dieta;
public:
//Erbivoro(int Pe, int A, int E, int Pb, string Cs, bool Ie, string S, bool V,string Pr,list<Tipo> t);
    Erbivoro(int id,int Pe=0, int A=0, int E=0,  bool Ie= false, string S=string(),list<Tipo> t=list<Tipo>());
    list<Tipo> getDieta() const;
//virtual bool operator==(const Animale &a) const;
    virtual Animale* clone() const = 0;
    virtual string getTipo() const;
    string getFrugivoro() const;
    string getFolivoro() const;
    string getGranivoro() const;
    string getNettarivoro() const;

};

#endif // ERBIVORO_H
