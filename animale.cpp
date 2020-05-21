#include "animale.h"

Animale::Animale(int Pe , int A ,int E,int Pb,string Cs,bool Ie,string S,bool V,string Pr):
    Peso(Pe), Altezza(A) , Eta(E) , PrezzoBase(Pb) , CarSpec(Cs) , InEstinz(Ie) , Sede(S) , Venduto(V) , Proprietario(Pr){}

/*bool Animale::operator==(const Animale &a) const {
    return Peso==a.Peso && Altezza==a.Altezza &&Eta == a.Eta && PrezzoBase == a.PrezzoBase &&
            CarSpec == a.CarSpec && InEstinz == a.InEstinz && Sede == a.Sede && Venduto == a.Venduto
            && Proprietario == a.Proprietario;
}*/

int Animale::getPeso() const {return Peso;}

int Animale::getAltezza() const {return Altezza;}

int Animale::getEta() const {return Eta;}

int Animale::getPrezzoBase() const {return PrezzoBase;}

std::string Animale::getCarSpec() const {return CarSpec;}

std::string Animale::getSede() const {return Sede;}

std::string Animale::getProprietario() const {return Proprietario;}

bool Animale::getInEstinz() const {return InEstinz;}

bool Animale::getVenduto() const {return Venduto;}