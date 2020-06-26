#include "vista_lista_options.h"
#include "controller.h"
vista_lista_options::vista_lista_options(QWidget *parent) : QWidget(parent)
{
    contr = nullptr;
    msg = new QDialog();
    QString qs = "Info";
    msg->setWindowTitle(qs);
    qhb = new QHBoxLayout();
    qvb2 = new QVBoxLayout();
    qvb3 = new QVBoxLayout();
    qvbattributi = new QVBoxLayout();
    car1 = new QLabel();
    car2 = new QLabel();
    car3 = new QLabel();
    car4 = new QLabel();
    car5 = new QLabel();
    car6 = new QLabel();
    grasso = new QLabel();
    vecchio = new QLabel();
    valore = new QLabel();
    qhb1 = new QVBoxLayout();
    qhb2 = new QVBoxLayout();
    qhb3 = new QVBoxLayout();
    qhb4 = new QVBoxLayout();
    qhb5 = new QVBoxLayout();
    qhb6 = new QVBoxLayout();
    qhb7 = new QVBoxLayout();
    qhbgrasso = new QVBoxLayout();
    qhbvecchio = new QVBoxLayout();
    qhbvalore = new QVBoxLayout();
    car1->hide();
    car2->hide();
    car3->hide();
    car4->hide();
    car5->hide();
    car6->hide();
    qpte3 = new QLabel();
    qs2 = "Caratteristiche Specie";
    qs3 = "Caratteristiche Animale";
    qs4 = "Attributi Animale";
    ql2 = new QLabel(qs2);
    ql3 = new QLabel(qs3);
    ql4 = new QLabel(qs4);
    qvb2->addWidget(ql2);
    qvb2->setAlignment(ql2,AlignTop);
    qvb3->addWidget(ql3);
    qvb3->setAlignment(ql3,AlignTop);
    qvbattributi->addWidget(ql4);
    qvbattributi->setAlignment(ql4,AlignTop);
    qhb1->addWidget(car1);
    qhb2->addWidget(car2);
    qhb3->addWidget(car3);
    qhb4->addWidget(car4);
    qhb5->addWidget(car5);
    qhb6->addWidget(car6);
    qhb7->addWidget(qpte3);
    qhbgrasso->addWidget(grasso);
    qhbvecchio->addWidget(vecchio);
    qhbvalore->addWidget(valore);
    qvb2->addLayout(qhb1);
    qvb2->addLayout(qhb2);
    qvb2->addLayout(qhb3);
    qvb2->addLayout(qhb4);
    qvb2->addLayout(qhb5);
    qvb2->addLayout(qhb6);
    qvb3->addLayout(qhb7);
    qvbattributi->addLayout(qhbgrasso);
    qvbattributi->addLayout(qhbvecchio);
    qvbattributi->addLayout(qhbvalore);
    qvb2->addStretch(0);
    qvb3->addStretch(0);
    qvbattributi->addStretch(0);
    qvb2->setAlignment(qhb1,AlignTop);
    qvb2->setAlignment(qhb2,AlignTop);
    qvb2->setAlignment(qhb3,AlignTop);
    qvb2->setAlignment(qhb4,AlignTop);
    qvb2->setAlignment(qhb5,AlignTop);
    qvb2->setAlignment(qhb6,AlignTop);
    qvb3->setAlignment(qhb7,AlignTop);
    qvbattributi->setAlignment(qhbgrasso,AlignTop);
    qvbattributi->setAlignment(qhbvecchio,AlignTop);
    qvbattributi->setAlignment(qhbvalore,AlignTop);
    qhb->addLayout(qvb2);
    qhb->addLayout(qvb3);
    qhb->addLayout(qvbattributi);
    msg->setLayout(qhb);
}

QDialog *vista_lista_options::getmsg() const
{
    return msg;
}

QLabel *vista_lista_options::getcar1() const
{
    return car1;
}

QLabel *vista_lista_options::getcar2() const
{
    return car2;
}

QLabel *vista_lista_options::getcar3() const
{
    return car3;
}

QLabel *vista_lista_options::getcar4() const
{
    return car4;
}

QLabel *vista_lista_options::getcar5() const
{
    return car5;
}

QLabel *vista_lista_options::getcar6() const
{
    return car6;
}


QLabel* vista_lista_options::getqpte3() const
{
    return qpte3;
}

QLabel *vista_lista_options::getgrasso() const
{
    return grasso;
}

QLabel *vista_lista_options::getvecchio() const
{
    return vecchio;
}

QLabel *vista_lista_options::getvalore() const
{
    return valore;
}
void vista_lista_options::setController(Controller* ctr){
    contr = ctr;
}
