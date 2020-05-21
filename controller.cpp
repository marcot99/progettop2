#include "controller.h"
Controller::Controller(Model* a,QObject *parent) : QObject(parent),vis(nullptr),mod(a){}

void Controller::setView(Vista* v) { vis = v; }

Contenitore<Animale *> &Controller::getContenitore()
{
    return mod->getContenitore();
}
/*Lista<bagaglio*>& controller_lista_bagagli::getList(){
return bag.getList();
}*/


/*void Controller::ctrl_load_init(string path){
    mod->load(path);
}*/
