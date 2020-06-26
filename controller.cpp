#include "controller.h"
#include <typeinfo>
#include "animale.h"
#include "erbivoro.h"
#include "carnivoro.h"
#include "onnivoro.h"
#include "rinoceronte.h"
#include "serpente.h"
#include "orso.h"
#include "acquisti.h"
#include "vendite.h"
#include "exceptions.h"
using std::string;
#include <list>
using std::list;



Controller::Controller(Model* a,QObject *parent) : QObject(parent),mod(a)
{
    vis = nullptr;
    errormsg=new QMessageBox();
}

void Controller::setView(Vista* v) {
    vis =v;
    vl = v->getvl();
    vla = v->getvla();
    vlv = v->getvlv();
    vfa = v->getfinvis()->getvfa();
    vfv = v->getfinvis()->getvfv();
    connect(vla,SIGNAL(sendsignal(bool,int,string,bool,bool,bool,bool,bool,bool,string,int,int,int,int,int,QDate,bool,string)),
            this,SLOT(verificanimale(bool,int,string,bool,bool,bool,bool,bool,bool,string,int,int,int,int,int,QDate,bool,string)));
    connect(vlv,SIGNAL(selldata(int,string,int,QDate)),this,SLOT(vendita(int,string,int,QDate)));
    connect(vl,SIGNAL(deletestuff(int,int)),this,SLOT(deletedata(int,int)));
    connect(vfa,SIGNAL(sistemaac(int,int)),this,SLOT(sistemacontrac(int,int)));
    connect(vfv,SIGNAL(sistemaven(int,int)),this,SLOT(sistemacontrven(int,int)));
    
}

void Controller::salvataggio()
{
    mod->saved();
}

void Controller::inputok(int id,string specie,int ra, int peso, int altezza, int eta, int prezzobase, bool inestinz, string sede)
{
    if (specie == "--select--") throw exceptions::Err1();
    else if (sede == "--select--") throw exceptions::Err1();
    else if (typeid(id)!=typeid(int) || id <= 0) throw exceptions::Err1();
    else if (typeid(ra)!=typeid(int) || ra <= 0) throw exceptions::Err1();
    else if (typeid(peso)!=typeid(int) || peso <= 0) throw exceptions::Err1();
    else if (typeid(altezza)!=typeid(int) || altezza <= 0) throw exceptions::Err1();
    else if (typeid(eta)!=typeid(int) || eta <= 0) throw exceptions::Err1();
    else if (typeid(prezzobase)!=typeid(int) || prezzobase < 0) throw exceptions::Err1();
    else if (typeid(inestinz)!=typeid(bool)) throw exceptions::Err1();
    else if (typeid(sede)!=typeid(string)) throw exceptions::Err1();
}


Animale* Controller::prendicose(int id) const
{

    return mod->searchanimale(id);
}

Model* Controller::getmod() const
{
    return mod;
}

Vista *Controller::getvis() const
{
    return vis;
}

void Controller::doubledid(int id) const
{
    if (!mod->verifyid(id)){
        throw(exceptions::iddoppio());
    }
}

void Controller::sisTotAc(int a) const
{
    mod->sMAc(a);
}

void Controller::sisTotVe(int v) const
{
    mod->sMVe(v);
}

void Controller::sisBil(int b) const
{
    mod->sBil(b);
}


void Controller::verificanimale(bool acquisto,int id, string an,bool vele,bool necr,bool frug,bool foli,bool gran,bool netti,string specie,int corno, int pe, int al, int et, int prez,QDate data, bool ines, string sede)
{
    try{inputok(id,specie,corno,pe,al,et,prez,ines,sede);}
    catch(exceptions::Err1) {
        emit errsignal();
        return;
    };
    try{doubledid(id);}
    catch(exceptions::iddoppio) {
        emit erriddoppio();
        return;
    };
    Animale* animal = nullptr;
    if (specie == "Rinoceronte")
    {
        list<Tipo> Dieta;
        if(frug == true){
            Dieta.push_back(Frugivoro);
        }
        if(foli == true){
            Dieta.push_back(Folivoro);
        }
        if(gran == true){
            Dieta.push_back(Granivoro);
        }
        if(netti == true){
            Dieta.push_back(Nettarivoro);
        }
        animal =  new Rinoceronte(id,pe,al,et,ines,sede,Dieta,corno);
    }
    else if (specie == "Serpente")
    {
        animal = new Serpente(id,pe,al,et,ines,sede,vele,necr,corno);
    }
    else
    {
        list<Tipo> Dieta;
        if(frug == true){
            Dieta.push_back(Frugivoro);
        }
        if(foli == true){
            Dieta.push_back(Folivoro);
        }
        if(gran == true){
            Dieta.push_back(Granivoro);
        }
        if(netti == true){
            Dieta.push_back(Nettarivoro);
        }
        animal = new Orso(id,pe,al,et,ines,sede,Dieta,vele,necr,corno);
    }
    mod->AddAnimale(animal);
    vis->VistaAddAnimale(id,an,specie,pe,al,et,ines,sede);
    if (acquisto == true)
    {
        vis->VistaAddAcquisto(id,specie,prez,data);
        QString dd= data.toString();
        string da = dd.toStdString();
        acquisti* a= new acquisti(id,specie,prez,da);
        mod->aggA(*a);
    }
}

void Controller::vendita(int id, std::string animale, int prezzo, QDate data)
{
    vis->VistaAddVendita(id,animale,prezzo,data);
    QString dd= data.toString();
    string da = dd.toStdString();
    vendite* v= new vendite(id,animale,prezzo,da);
    mod->aggV(*v);

}

void Controller::deletedata(int id,int row)
{
    vis->getvl()->getqtw()->removeRow(row);
    mod->RemoveAnimale(id);
}

void Controller::sistemacontrac(int id,int prezzo)
{
    vis->getfinvis()->sistemaacquisto(prezzo);
    mod->removeacquisto(id);
}

void Controller::sistemacontrven(int id,int prezzo)
{
    vis->getfinvis()->sistemavendita(prezzo);
    mod->removevendita(id);
}


