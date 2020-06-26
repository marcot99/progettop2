#ifndef ACQUISTI_H
#define ACQUISTI_H

#include <string>
using std::string;
class acquisti
{
private:
    int id;
    string tipoanimale;
    int prezzoac;
    string data;
public:
    acquisti(int i,string t,int p,string d);
    int getId() const;
    string getTipoA() const;
    int getPrezzoA() const;
    string getData() const;
};

#endif // ACQUISTI_H
