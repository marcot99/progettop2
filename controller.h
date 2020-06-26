#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "vista.h"
#include "model.h"
#include <QMessageBox>
class Controller : public QObject
{
    Q_OBJECT
private:
    Vista* vis;
    Model* mod;
    vista_lista* vl;
    vista_lista_add* vla;
    vista_lista_vendita* vlv;
    vista_finanza_acquisti* vfa;
    vista_finanza_vendite* vfv;
    QMessageBox* errormsg;
public:
    Controller();
    explicit Controller(Model* a,QObject *parent = nullptr);
    void setView(Vista* v);
    void inputok(int id,string specie,int ra,int peso,int altezza,int eta ,int prezzobase,bool inestinz,string sede);
    Animale* prendicose(int id) const;
    Model* getmod() const;
    Vista* getvis() const;
    void doubledid(int id) const;
    void sisTotAc(int a) const;
    void sisTotVe(int v) const;
    void sisBil(int b) const;
public slots:
     void verificanimale(bool,int,string,bool,bool,bool,bool,bool,bool,string,int,int,int,int,int,QDate,bool,string);
     void vendita(int,string,int,QDate);
     void deletedata (int id,int row);
     void sistemacontrac(int id,int prezzo);
     void sistemacontrven(int id,int prezzo);
     void salvataggio();
signals:
    void errsignal();
    void erriddoppio();

};

#endif // CONTROLLER_H
