#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "vista.h"
#include "model.h"
class Controller : public QObject
{
    Q_OBJECT
private:
    Vista* vis;
    Model* mod;
public:
    Controller();
    explicit Controller(Model* a,QObject *parent = nullptr);
    void setView(Vista* v);
    Contenitore<Animale*>& getContenitore();
public slots:


};

#endif // CONTROLLER_H
