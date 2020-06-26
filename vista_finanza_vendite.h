#ifndef VISTA_FINANZA_VENDITE_H
#define VISTA_FINANZA_VENDITE_H

#include <QObject>
#include <QWidget>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include "vista_add_button.h"
using std::string;
class Controller;
class vista_finanza_vendite : public QWidget
{
    Q_OBJECT
private:
    Controller * contr;
    QVBoxLayout* qvb;
    QTableWidget* qtw;
    QLabel* ql;
public:
    explicit vista_finanza_vendite(QWidget *parent = nullptr);
    void setController(Controller* ctr);
    void aggiungivendita(int id,string animale,int prezzo,QDate data);

public slots:
    void Remove(int row,int col);
signals:
    void sistemaven(int id, int prezzo);
};

#endif // VISTA_FINANZA_VENDITE_H
