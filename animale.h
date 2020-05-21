#ifndef ANIMALE_H
#define ANIMALE_H
#include <string>
using std::string;
class Animale
{
private:
    int Peso;
    int Altezza;
    int Eta;
    int PrezzoBase;
    string CarSpec;
    bool InEstinz;
    string Sede;
    bool Venduto;
    string Proprietario;
protected:
    int getPrezzoBase() const;
public:
    Animale(int Pe=0,int A=0, int E=0,int Pb=0,string Cs=string(),bool Ie=false,string S=string(),bool V=false,string Pr=string());
    virtual ~Animale() {}
    virtual bool isGrasso() const = 0;
    virtual bool isVecchio() const = 0;
    virtual bool isdiValore() const = 0;
    virtual int PrezzoFinale() const = 0;
    //virtual bool operator==(const Animale& a) const;
    int getPeso() const;
    int getAltezza() const;
    int getEta() const;
    string getCarSpec() const;
    string getSede() const;
    string getProprietario() const;
    bool getInEstinz() const;
    bool getVenduto() const;
};

#endif // ANIMALE_H
