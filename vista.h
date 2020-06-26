#ifndef VISTA_H
#define VISTA_H

#include "vista_lista.h"
#include "vista_finanza.h"
#include <QBoxLayout>
#include <QMenuBar>
#include <QMessageBox>

class Controller;

class Vista:public QWidget
{
    Q_OBJECT
private:
    Controller* contr;
    QVBoxLayout* mainlayout;
    QTabWidget* tabwidget;
    QIcon* i0;
    QString* q0;
    QString* q1;
    QMenuBar* menubar;
    QMenu* menu;
    QAction* exit;
    QAction* save;
    QMessageBox* errormsg;
    vista_finanza* finvis;
    vista_lista* tabvis;
    void addMenu();
public:
    Vista(QWidget *parent = nullptr);
    void VistaAddAnimale(int id, string an, string specie, int a, int b, int c, bool h, string g);
    void VistaAddAcquisto(int id,string specie,int prezzo,QDate data);
    void VistaAddVendita(int id,string animale,int prezzo,QDate data);
    vista_lista* getvl() const;
    vista_lista_add *getvla() const;
    vista_lista_vendita* getvlv() const;
    vista_finanza* getfinvis() const;
    void setController(Controller* ctr);
public slots:
    void message();
    void iddouble();
};

#endif // VISTA_H
