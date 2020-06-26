#ifndef VISTA_FINANZA_ACQUISTI_H
#define VISTA_FINANZA_ACQUISTI_H

#include <QObject>
#include <QWidget>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include "vista_add_button.h"
using std::string;
class Controller;
class vista_finanza_acquisti : public QWidget
{
    Q_OBJECT
private:
    Controller* contr;
    QVBoxLayout* qvb;
    QTableWidget* qtw;
    QLabel* ql;
public:
    explicit vista_finanza_acquisti(QWidget *parent = nullptr);
    void setController(Controller* ctr);
    void aggiungiacquisto(int id,string specie,int prezzo,QDate data);
public slots:
    void Remove(int row,int col);
signals:
    void sistemaac(int id,int prezzo);

};

#endif // VISTA_FINANZA_ACQUISTI_H
