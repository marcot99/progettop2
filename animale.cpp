#include "animale.h"

Animale::Animale(int id,int Pe , int A ,int E,bool Ie,string S):
    ID(id),Peso(Pe), Altezza(A) , Eta(E) , InEstinz(Ie) , Sede(S) {}

int Animale::getID() const
{
    return ID;
}

/*bool Animale::operator==(const Animale &a) const {
    return Peso==a.Peso && Altezza==a.Altezza &&Eta == a.Eta && PrezzoBase == a.PrezzoBase &&
            CarSpec == a.CarSpec && InEstinz == a.InEstinz && Sede == a.Sede && Venduto == a.Venduto
            && Proprietario == a.Proprietario;
}*/

int Animale::getPeso() const {return Peso;}

int Animale::getAltezza() const {return Altezza;}

int Animale::getEta() const {return Eta;}



std::string Animale::getSede() const {return Sede;}

bool Animale::getInEstinz() const {return InEstinz;}

