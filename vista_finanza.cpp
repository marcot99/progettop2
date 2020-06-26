#include "vista_finanza.h"
#include "controller.h"
vista_finanza::vista_finanza(QWidget *parent) :QWidget(parent)
{
    contr = nullptr;
    totaleacquisti = 0;
    totalevendite = 0;
    bilancio = 0;
    qvb = new QVBoxLayout();
    qhb1 = new QHBoxLayout();
    qhb2 = new QHBoxLayout();
    vfa = new vista_finanza_acquisti();
    vfv = new vista_finanza_vendite();
    vfb = new vista_finanza_bilancio();
    qhb2->addWidget(vfa);
    qhb2->addWidget(vfv);
    qhb2->addWidget(vfb);
    qvb->addLayout(qhb1);
    qvb->addLayout(qhb2);
    setLayout(qvb);
}


void vista_finanza::updateqtw()
{
    dati_finanziari d = contr->getmod()->datifinanziarisback();
    vector<acquisti> va = d.getVA();
    vector<vendite> vv = d.getVV();
    for(vector<acquisti>::iterator it = va.begin();it != va.end();it++){
        vfa->aggiungiacquisto((*it).getId(),(*it).getTipoA(),(*it).getPrezzoA(),QDate::fromString(QString::fromStdString((*it).getData())));
    }
    for(vector<vendite>::iterator it = vv.begin();it != vv.end();it++){
        vfv->aggiungivendita((*it).getId(),(*it).getTipoA(),(*it).getPrezzoV(),QDate::fromString(QString::fromStdString((*it).getData())));
    }
    vfb->setstart(d.getTotA(),d.getTotV(),d.getBil());
    totaleacquisti = d.getTotA();
    totalevendite = d.getTotV();
    bilancio = d.getBil();
}

void vista_finanza::setController(Controller* ctr){
    contr = ctr;
    updateqtw();
}


vista_finanza_acquisti* vista_finanza::getvfa() const
{
    return vfa;
}
vista_finanza_vendite* vista_finanza::getvfv() const
{
    return vfv;
}
void vista_finanza::addacquisto(int acq)
{
    totaleacquisti = totaleacquisti+acq;
    bilancio= bilancio-acq;
    vfb->setacquisto(totaleacquisti);
    vfb->setbilancio(bilancio);
}

void vista_finanza::addvendita(int ven)
{
    totalevendite = totalevendite+ven;
    bilancio = bilancio+ven;
    vfb->setvendita(totalevendite);
    vfb->setbilancio(bilancio);

}

vista_finanza_bilancio *vista_finanza::getvfb() const
{
    return vfb;

}

void vista_finanza::sistemaacquisto(int prezzo)
{
    totaleacquisti = totaleacquisti-prezzo;
    bilancio = bilancio+prezzo;
    vfb->setacquisto(totaleacquisti);
    vfb->setbilancio(bilancio);

}

void vista_finanza::sistemavendita(int prezzo)
{
    totalevendite = totalevendite-prezzo;
    bilancio = bilancio-prezzo;
    vfb->setvendita(totalevendite);
    vfb->setbilancio(bilancio);
    
}

