#include "erbivoro.h"

Erbivoro::Erbivoro(int id,int Pe , int A ,int E,bool Ie,string S,list<Tipo> t):
    Animale(id,Pe,A,E,Ie,S),Dieta(t){}

list<Tipo> Erbivoro::getDieta() const {return Dieta;}


std::string Erbivoro::getTipo() const
{
    return "Erbivoro";
}

std::string Erbivoro::getFrugivoro() const
{
    list<Tipo> l = getDieta();
    for(list<Tipo>::iterator it=l.begin();it!=l.end();it++)
    {
        if(*it==Frugivoro){
            return "Frugivoro";
        }
    }
    return "Non è Frugivoro";
}

std::string Erbivoro::getFolivoro() const
{
    list<Tipo> l = getDieta();
    for(list<Tipo>::iterator it=l.begin();it!=l.end();it++)
    {
        if(*it==Folivoro){
            return "Folivoro";
        }
    }
    return "Non è Folivoro";
}

std::string Erbivoro::getGranivoro() const
{
    list<Tipo> l = getDieta();
    for(list<Tipo>::iterator it=l.begin();it!=l.end();it++)
    {
        if(*it==Granivoro){
            return "Granivoro";
        }
    }
    return "Non è Granivoro";
}

std::string Erbivoro::getNettarivoro() const
{
    list<Tipo> l = getDieta();
    for(list<Tipo>::iterator it=l.begin();it!=l.end();it++)
    {
        if(*it==Nettarivoro){
            return "Nettarivoro";
        }
    }
    return "Non è Nettarivoro";
}

/*bool Erbivoro::operator==(const Animale &a) const {
    if(typeid(const Erbivoro&) != typeid(a)) return false;
    const Erbivoro* p = dynamic_cast<const Erbivoro*>(&a);
    return Animale::operator==(a) && Dieta == p->Dieta;
}*/
