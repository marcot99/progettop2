#ifndef DATI_FINANZIARI_H
#define DATI_FINANZIARI_H

#include "acquisti.h"
#include "vendite.h"
//#include "contenitore.h"
#include <vector>
using std::vector;

class dati_finanziari
{
private:
    vector<acquisti> va;
    vector<vendite> vv;
    int totacquisti;
    int totvendite;
    int bilancio;
public:
    dati_finanziari();
    void addacquisto(acquisti a);
    void addvendita(vendite v);
    void setAcquisti(int a);
    void setVendite(int v);
    void setBilancio(int b);
    vector<acquisti> getVA() const;
    vector<vendite> getVV() const;
    int getTotA() const;
    int getTotV() const;
    int getBil() const;
    void togliacquisto(int id);
    void toglivendita(int id);
};

#endif // DATI_FINANZIARI_H
