#include "vista_lista_vendita.h"
#include "controller.h"

QDialog *vista_lista_vendita::getdialog() const
{
    return d;
}

vista_lista_vendita::vista_lista_vendita(QWidget *parent) : QWidget(parent)
{
    contr = nullptr;
    d = new QDialog();
    d->setWindowTitle("Vendita Animale");
    d->setMinimumWidth(300);
    qpb = new QPushButton();
    qpb->setText("Ok");
    qvb = new QVBoxLayout();
    dativendita = new QLabel();
    dativendita->setText("Dati Vendita");
    prezzotitolo = new QLabel();
    prezzotitolo->setText("Prezzo Vendita");
    datatitolo = new QLabel();
    datatitolo->setText("Data vendita");
    prezzo = new QLineEdit();
    data = new QDateEdit();
    qvb->addWidget(dativendita);
    qvb->addWidget(prezzotitolo);
    qvb->addWidget(prezzo);
    qvb->addWidget(datatitolo);
    qvb->addWidget(data);
    qvb->addWidget(qpb);
    qvb->addStretch(0);
    d->setLayout(qvb);
    connect(qpb,SIGNAL(clicked()),this,SLOT(inviadati()));
    connect(qpb,SIGNAL(clicked()),d,SLOT(close()));
}

void vista_lista_vendita::setController(Controller *ctr)
{
    contr = ctr;
}

void vista_lista_vendita::assignrow(int row)
{
    riga = row;
}

QDateEdit* vista_lista_vendita::getdata() const
{
    return data;
}

QLineEdit* vista_lista_vendita::getprezzo() const
{
    return prezzo;
}

void vista_lista_vendita::inviadati()
{
    QTableWidgetItem* dap=contr->getvis()->getvl()->getqtw()->takeItem(riga,0);
    QString fad = dap->text();
    contr->getvis()->getvl()->getqtw()->setItem(riga,0,dap);
    string xx = fad.toStdString();
    int aabb = std::stoi(xx);
    QTableWidgetItem* dap1=contr->getvis()->getvl()->getqtw()->takeItem(riga,2);
    QString fad1 = dap1->text();
    string yy = fad1.toStdString();
    emit selldata(aabb,yy,prezzo->text().toInt(),data->date());
}
