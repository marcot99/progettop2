#ifndef ANIMALE_H
#define ANIMALE_H
#include <string>
using std::string;
class Animale
{
private:
    int ID;
    int Peso;
    int Altezza;
    int Eta;
    bool InEstinz;
    string Sede;
    //int prezzoacquisto;
    //string datacquisto;
    //int prezzovendita;
    //string prezzovendita;

public:
    Animale(int id=0,int Pe=0,int A=0, int E=0,bool Ie=false,string S=string());
    virtual ~Animale() {}
    virtual bool isGrasso() const = 0;
    virtual bool isVecchio() const = 0;
    virtual bool isdiValore() const = 0;
    //virtual bool operator==(const Animale& a) const;
    int getID() const;
    int getPeso() const;
    int getAltezza() const;
    int getEta() const;
    string getSede() const;
    bool getInEstinz() const;
    virtual string getTipo() const = 0; //erb,car,onn
    virtual string getSpecie() const = 0; //rino,orso,serpy
    virtual Animale* clone() const = 0;

};

#endif // ANIMALE_H
