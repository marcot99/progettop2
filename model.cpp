#include "model.h"
#include <vector>
#include "animale.h"
using std::vector;

Model::Model(){
    sl = new save_load();
    df = new dati_finanziari();
    loaded();
}

Contenitore<Animale*> Model::getContenitore() const
{
    return con;
}

void Model::AddAnimale(Animale *an) {
    con.push_back(an);
}

void Model::RemoveAnimale(int id)
{
    for(Contenitore<Animale*>::iteratore it = con.begin();it!=con.end();++it){
        if((*it).b->getID()==id)
        {
            con.pop(it);return;
        }
    }
}
Animale *Model::searchanimale(int id) const
{
    Animale* an = nullptr;
    for(Contenitore<Animale*>::iteratore it = con.begin();it!=con.end();++it){
        if((*it).b->getID()==id)
        {
            an = (*it).b->clone();
        }
    }
    return an;
}

bool Model::verifyid(int id) const
{
    bool verify = true;
    for(Contenitore<Animale*>::iteratore it = con.begin();it!=con.end();++it){
        if((*it).b->getID()==id)
        {
            verify = false;
        }
    }
    return verify;
}

void Model::loaded()
{
    sl->load(con,*df);
}

void Model::saved() const
{
    sl->save(con,*df);
}

void Model::aggA(acquisti a) const
{
    df->addacquisto(a);
}

void Model::aggV(vendite v) const
{
    df->addvendita(v);
}

void Model::sMAc(int a) const
{
    df->setAcquisti(a);
}

void Model::sMVe(int v) const
{
    df->setVendite(v);
}

void Model::sBil(int b) const
{
    df->setBilancio(b);
}

int Model::getContenitoreSize() const
{
    return con.size();
}

vector<Animale*> Model::animalisback() const
{
    vector<Animale*> v;
    for(Contenitore<Animale*>::iteratore it = con.begin();it!=con.end();++it){
            v.push_back((*it).b->clone());
    }
    return v;
}

dati_finanziari Model::datifinanziarisback() const
{
    return *df;
}

void Model::removeacquisto(int id)
{
    df->togliacquisto(id);
}

void Model::removevendita(int id)
{
    df->toglivendita(id);
}




