#include "controller.h"
#include "vista.h"
#include <QDebug>
#include <fstream>
#include <iostream>

Vista::Vista(QWidget *parent) : QWidget(parent){
    contr = nullptr;
    mainlayout = new QVBoxLayout();
    tabwidget = new QTabWidget;
    errormsg = new QMessageBox();
    i0 = new QIcon();
    q0 = new QString("INVENTARIO");
    q1 = new QString("FINANZA");
    tabvis = new vista_lista();
    finvis = new vista_finanza();
    tabwidget->addTab(tabvis,*i0,*q0);
    tabwidget->addTab(finvis,*i0,*q1);
    addMenu();
    mainlayout->addWidget(tabwidget);
    setLayout(mainlayout);
}

void Vista::VistaAddAnimale(int id,string an,string specie, int a, int b, int c, bool h,string i)
{
    tabvis->aggiungianimale(id,an,specie,a,b,c,h,i);
}


void Vista::VistaAddAcquisto(int id,string specie,int prezzo,QDate data)
{
    finvis->getvfa()->aggiungiacquisto(id,specie,prezzo,data);
    finvis->addacquisto(prezzo);
}

void Vista::VistaAddVendita(int id,string animale,int prezzo,QDate data)
{
    finvis->getvfv()->aggiungivendita(id,animale,prezzo,data);
    finvis->addvendita(prezzo);
}

vista_lista *Vista::getvl() const
{
    return tabvis;
}

void Vista::addMenu(){
    menubar = new QMenuBar();
    menu = new QMenu("MENU",menubar);
    exit = new QAction("CHIUDI",menu);
    save = new QAction("SALVA",menu);
    menu->addAction(exit);
    menu->addAction(save);
    menubar->addMenu(menu);
    mainlayout->addWidget(menubar);
}




void Vista::setController(Controller * ctr)
{
    contr = ctr;
    tabvis->setController(ctr);
    tabvis->getvla()->setController(ctr);
    tabvis->getvlo()->setController(ctr);
    tabvis->getvlv()->setController(ctr);
    finvis->setController(ctr);
    finvis->getvfa()->setController(ctr);
    finvis->getvfv()->setController(ctr);
    finvis->getvfb()->setController(ctr);
    connect(save,SIGNAL(triggered()),contr,SLOT(salvataggio()));
    connect(exit,SIGNAL(triggered()),this,SLOT(close()));
    connect(contr,SIGNAL(errsignal()),this,SLOT(message()));
    connect(contr,SIGNAL(erriddoppio()),this,SLOT(iddouble()));
}

void Vista::message()
{
    errormsg->setIcon(QMessageBox::Warning);
    errormsg->setText("I valori inseriti non sono accettabili");
    errormsg->setEscapeButton(QMessageBox::Ok);
    errormsg->exec();
}

void Vista::iddouble()
{
    errormsg->setIcon(QMessageBox::Warning);
    errormsg->setText("E' già presente un animale con questo ID");
    errormsg->setEscapeButton(QMessageBox::Ok);
    errormsg->exec();
}

vista_lista_add *Vista::getvla() const
{
    return tabvis->getvla();
}

vista_lista_vendita *Vista::getvlv() const
{
    return tabvis->getvlv();
}

vista_finanza *Vista::getfinvis() const
{
    return finvis;
}

