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
Erbivoro(int Pe=0, int A=0, int E=0, int Pb=0, string Cs=string(), bool Ie= false, string S=string(), bool V=false,string Pr=string(),list<Tipo> t=list<Tipo>());
list<Tipo> getDieta() const;


};

#endif // ERBIVORO_H
