#ifndef MODEL_H
#define MODEL_H
#include "contenitore.h"
#include <vector>
#include "save_load.h"
#include "dati_finanziari.h"

class Model
{

private:
    Contenitore<Animale*> con;
    save_load* sl;
    dati_finanziari* df;
    void loaded();
public:
    Model();
    Contenitore<Animale*> getContenitore() const;
    void AddAnimale(Animale* an);
    void RemoveAnimale(int id);
    Animale* searchanimale(int id) const;
    bool verifyid(int id) const;
    void saved() const;
    void aggA(acquisti a) const;
    void aggV(vendite v)const;
    void sMAc(int a) const;
    void sMVe(int v) const;
    void sBil(int b) const;
    int getContenitoreSize() const;
    vector<Animale*> animalisback() const;
    dati_finanziari datifinanziarisback() const;
    void removeacquisto(int id);
    void removevendita(int id);


};

#endif // MODEL_H
