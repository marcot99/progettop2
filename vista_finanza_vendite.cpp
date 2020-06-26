#include "vista_finanza_vendite.h"
#include "controller.h"


vista_finanza_vendite::vista_finanza_vendite(QWidget *parent) : QWidget(parent)
{
    qvb = new QVBoxLayout();
    qtw = new QTableWidget();
    QString title ("VENDITE");
    ql = new QLabel(title);
    QStringList name_col;
    name_col<<"ID"<<"TipoAnimale"<<"PrezzoVendita"<<"Data"<<"Delete";
    qtw->setColumnCount(5);
    qtw->setHorizontalHeaderLabels(name_col);
    qtw->setColumnWidth(0,70);qtw->setColumnWidth(1,150);qtw->setColumnWidth(2,130);qtw->setColumnWidth(3,150);qtw->setColumnWidth(4,70);
    qvb->addWidget(ql);
    qvb->addWidget(qtw);
    setLayout(qvb);
}

void vista_finanza_vendite::setController(Controller* ctr){
    contr = ctr;
    connect(qtw,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(Remove(int,int)));
}

void vista_finanza_vendite::aggiungivendita(int id, std::string animale, int prezzo, QDate data)
{
    qtw->setRowCount(qtw->rowCount()+1);
    int riga = qtw->rowCount()-1;
    QTableWidgetItem* qtwi = new QTableWidgetItem();
    qtwi->setText(QString::number(id));
    qtw->setItem(riga,0,qtwi);
    qtwi->setFlags(qtwi->flags() ^ Qt::ItemIsEditable);
    QTableWidgetItem* qtwi0 = new QTableWidgetItem();
    qtwi0->setText(QString::fromStdString(animale));
    qtw->setItem(riga,1,qtwi0);
    qtwi0->setFlags(qtwi0->flags() ^ Qt::ItemIsEditable);
    QTableWidgetItem* qtwi1 = new QTableWidgetItem();
    qtwi1->setText(QString::number(prezzo));
    qtwi1->setFlags(qtwi1->flags() ^ Qt::ItemIsEditable);
    qtw->setItem(riga,2,qtwi1);
    QTableWidgetItem* qtwi2 = new QTableWidgetItem();
    qtwi2->setText(data.toString());
    qtwi2->setFlags(qtwi2->flags() ^ Qt::ItemIsEditable);
    qtw->setItem(riga,3,qtwi2);
    QTableWidgetItem* qtwd = new QTableWidgetItem();
    qtw->setItem(riga,4,qtwd);
    qtwd->setFlags(qtwd->flags() ^ Qt::ItemIsEditable);
}

void vista_finanza_vendite::Remove(int row, int col)
{
    if(col==4){
    QMessageBox* msg = new QMessageBox();
    msg->setWindowTitle("Elimina vendita");
    msg->setIcon(QMessageBox::Question);
    msg->setText("Rimuovere Vendita?");
    msg->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msg->setDefaultButton(QMessageBox::No);
    int ch=msg->exec();
    if(ch==QMessageBox::Yes){
        QTableWidgetItem* dap=qtw->takeItem(row,2);
        QString fad = dap->text();
        string xx = fad.toStdString();
        int aabb = std::stoi(xx);
        QTableWidgetItem* dap1=qtw->takeItem(row,0);
        QString fad1 = dap1->text();
        string xxx = fad1.toStdString();
        int aabb2 = std::stoi(xxx);
        emit sistemaven(aabb2,aabb);
        qtw->removeRow(row);
        }
    }
}


