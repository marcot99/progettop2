#include "dati_finanziari.h"
dati_finanziari::dati_finanziari()
{}

void dati_finanziari::addacquisto(acquisti a)
{
    va.push_back(a);
}

void dati_finanziari::addvendita(vendite v)
{
    vv.push_back(v);
}

void dati_finanziari::setAcquisti(int a)
{
    totacquisti = a;
}

void dati_finanziari::setVendite(int v)
{
    totvendite = v;
}

void dati_finanziari::setBilancio(int b)
{
    bilancio = b;
}

vector<acquisti> dati_finanziari::getVA() const
{
    return va;
}

vector<vendite> dati_finanziari::getVV() const
{
    return vv;
}

int dati_finanziari::getTotA() const
{
    return totacquisti;
}

int dati_finanziari::getTotV() const
{
    return totvendite;
}

int dati_finanziari::getBil() const
{
    return bilancio;
}

void dati_finanziari::togliacquisto(int id)
{
    for(vector<acquisti>::iterator it = va.begin(); it != va.end();it++){
        if((*it).getId()==id){
            va.erase(it);return;
        }
    }
}

void dati_finanziari::toglivendita(int id)
{
    for(vector<vendite>::iterator it = vv.begin(); it != vv.end();it++){
        if((*it).getId()==id){
            vv.erase(it);return;
        }
    }
}

