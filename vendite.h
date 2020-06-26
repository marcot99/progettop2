#ifndef VENDITE_H
#define VENDITE_H

#include <string>
using std::string;

class vendite
{
private:
    int id;
    string tipoanimale;
    int prezzove;
    string data;
public:
    vendite(int i,string t,int p,string d);
    int getId() const;
    string getTipoA() const;
    int getPrezzoV() const;
    string getData() const;
};

#endif // VENDITE_H
