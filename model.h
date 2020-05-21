#ifndef MODEL_H
#define MODEL_H
#include "contenitore.h"
class Model
{

private:
    Contenitore<Animale*> con;

public:
    Model(Contenitore<Animale*> a = Contenitore<Animale*>());
    Contenitore<Animale *>& getContenitore();

    /*void AddAnimale(Animale* an);
    void RemoveLastAnimale();
    void RemoveAnimale(Animale* an);*/
};

#endif // MODEL_H
