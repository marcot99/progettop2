#ifndef VISTA_LISTA_H
#define VISTA_LISTA_H

#include <QTableWidget>
#include <QVBoxLayout>
#include <vista_add_button.h>
#include <vista_remove_button.h>
#include "model.h"
#include "QTableWidgetItem"
#include <QMessageBox>
#include <QDialog>
#include <QPlainTextEdit>
#include <QLabel>
#include <QInputDialog>
#include <vista_lista_add.h>
#include "vista_lista_options.h"
#include "vista_lista_vendita.h"
class Controller;
class vista_lista:public QWidget
{
    Q_OBJECT
private:
    Controller * contr;
    QTableWidget* qtw;
    QVBoxLayout* qvb;
    QTableWidget* qtw1;
    vista_add_button* vab;
    QPushButton* qpb;
    vista_lista_add* vla;
    vista_lista_options* vlo;
    vista_lista_vendita* vlv;
    QTableWidgetItem *qtu;
    void updateqtw();
public:
    vista_lista();
    Controller* getCtrl() const;
    void setController(Controller* ctr);
    QTableWidget* getqtw() const;
    vista_lista_add* getvla() const;
    vista_lista_options* getvlo() const;
    vista_lista_vendita* getvlv() const;
    void aggiungianimale(int id,string an,string specie,int a,int b,int c,bool h,string g);
signals:
    void deletestuff(int,int);
public slots:
     void SuccedonoCose(int row,int col);
     void aprivla() const;
};

#endif // VISTA_LISTA_H
