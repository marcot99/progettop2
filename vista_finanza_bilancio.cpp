#include "vista_finanza_bilancio.h"
#include <QDebug>
#include "controller.h"

vista_finanza_bilancio::vista_finanza_bilancio(QWidget *parent) : QWidget(parent)
{
    contr = nullptr;
    qvb = new QVBoxLayout();
    qtw = new QTableWidget();
    QString title ("BILANCIO");
    ql = new QLabel(title);
    QStringList name_col;
    name_col<<"Costo";
    QStringList name_row;
    name_row<<"TotaleAcquisti" << "TotaleVendite" << "Bilancio";
    qtw->setColumnCount(1);
    qtw->setRowCount(3);
    qtw->setHorizontalHeaderLabels(name_col);
    qtw->setVerticalHeaderLabels(name_row);
    qtw->setColumnWidth(0,100);
    qvb->addWidget(ql);
    qvb->addWidget(qtw);
    setLayout(qvb);
}

void vista_finanza_bilancio::setacquisto(int acq)
{
    if(qtw->item(0,0))
    {
        qtw->takeItem(0,0);
    }
    QTableWidgetItem* qtwi = new QTableWidgetItem();
    qtwi->setText(QString::number(acq));
    qtw->setItem(0,0,qtwi);
    qtwi->setFlags(qtwi->flags() ^ Qt::ItemIsEditable);
    contr->sisTotAc(acq);

}

void vista_finanza_bilancio::setstart(int acq,int ven,int bil)
{

    if(qtw->item(0,0))
    {
        qtw->takeItem(0,0);
    }
    QTableWidgetItem* qtwi = new QTableWidgetItem();
    qtwi->setText(QString::number(acq));
    qtw->setItem(0,0,qtwi);
    qtwi->setFlags(qtwi->flags() ^ Qt::ItemIsEditable);

    if(qtw->item(1,0))
    {
        qtw->takeItem(1,0);
    }
    QTableWidgetItem* qtwi1 = new QTableWidgetItem();
    qtwi1->setText(QString::number(ven));
    qtw->setItem(1,0,qtwi1);
    qtwi1->setFlags(qtwi1->flags() ^ Qt::ItemIsEditable);

    if(qtw->item(2,0))
    {
        qtw->takeItem(2,0);
    }
    QTableWidgetItem* qtwi2 = new QTableWidgetItem();
    qtwi2->setText(QString::number(bil));
    qtw->setItem(2,0,qtwi2);
    qtwi2->setFlags(qtwi2->flags() ^ Qt::ItemIsEditable);
}

void vista_finanza_bilancio::setvendita(int ven)
{
    if(qtw->item(1,0))
    {
        qtw->takeItem(1,0);
    }
    QTableWidgetItem* qtwi = new QTableWidgetItem();
    qtwi->setText(QString::number(ven));
    qtw->setItem(1,0,qtwi);
    qtwi->setFlags(qtwi->flags() ^ Qt::ItemIsEditable);
    contr->sisTotVe(ven);
}


void vista_finanza_bilancio::setbilancio(int bil)
{
    if(qtw->item(2,0))
    {
        qtw->takeItem(2,0);
    }
    QTableWidgetItem* qtwi = new QTableWidgetItem();
    qtwi->setText(QString::number(bil));
    qtw->setItem(2,0,qtwi);
    qtwi->setFlags(qtwi->flags() ^ Qt::ItemIsEditable);
    contr->sisBil(bil);
}


void vista_finanza_bilancio::setController(Controller *ctr)
{
    contr = ctr;
}

