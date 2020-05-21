#include "model.h"



Model::Model(Contenitore<Animale*> a):con(a) {}

Contenitore<Animale *> &Model::getContenitore()
{
    return con;
};

/*void Model::AddAnimale(Animale *an) {
    con.push_back(an);
}

void Model::RemoveLastAnimale() {
    con.pop_back();
}*/

/*void Model::RemoveAnimale(Animale *an){
    for(Contenitore<Animale*>::iteratore it = con.begin();it!=con.end();++it){
        if(*an == *(*it))
            con.pop_back();
    }*/
//}}

