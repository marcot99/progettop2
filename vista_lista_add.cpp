#include "vista_lista_add.h"
#include "controller.h"
vista_lista_add::vista_lista_add(QWidget *parent) : QWidget(parent)
{
    contr = nullptr;
    setMinimumSize(400,400);
    setWindowTitle("Aggiungi Animale");
    qvb = new QVBoxLayout();
    inserireid = new QLineEdit();
    peso = new QLineEdit();
    altezza = new QLineEdit();
    eta = new QLineEdit();
    prezzo = new QLineEdit();
    sede = new QComboBox();
    specialita = new QLineEdit();
    boxanimale = new QComboBox();
    boxspecie = new QComboBox();
    vele = new QCheckBox();
    necr = new QCheckBox();
    erb = new QGroupBox();
    specialita->hide();
    vele->hide();
    necr->hide();
    frug = new QCheckBox(tr("Frugivoro"));
    foli = new QCheckBox(tr("Folivoro"));
    gran = new QCheckBox(tr("Granivoro"));
    netti = new QCheckBox(tr("Nettarivoro"));
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(frug);
    vbox->addWidget(foli);
    vbox->addWidget(gran);
    vbox->addWidget(netti);
    erb->setLayout(vbox);
    erb->hide();
    QStringList qs1;
    qs1 << "--select--" <<" Erbivoro" << "Carnivoro" << "Onnivoro";
    boxanimale->addItems(qs1);
    QStringList qs2;
    qs2 << "--select--" << "Rinoceronte" << "Serpente" << "Orso";
    boxspecie->addItems(qs2);
    QStringList qs3;
    qs3 << "--select--" <<"Nairobi" << "Pretoria" << "Luanda";
    sede->addItems(qs3);
    inestinz = new QCheckBox();
    qpb = new QPushButton();
    animaletitolo = new QLabel("Tipo Animale");
    specietitolo = new QLabel("Specie");
    inseriredati = new QLabel();
    Caratteristica1titolo = new QLabel();
    Caratteristica2titolo = new QLabel();
    Caratteristica3titolo = new QLabel();
    Specialitatitolo = new QLabel();
    inseriredati->setText("Inserire i dati");
    Acquistatotitolo = new QLabel();
    Acquistatotitolo->setText("L'animale è stato acquistato?");
    datatitolo = new QLabel();
    datatitolo->setText("Data acquisto");
    data = new QDateEdit();
    acquistato = new QCheckBox();
    idtitolo = new QLabel("ID");
    pesotitolo = new QLabel("Peso");
    altezzatitolo = new QLabel("Altezza");
    etatitolo = new QLabel("Eta");
    prezzotitolo = new QLabel("Prezzo");
    sedetitolo = new QLabel("Sede");
    inestinztitolo = new QLabel("Inestinzione");
    Caratteristica1titolo->hide();
    Caratteristica2titolo->hide();
    Caratteristica3titolo->hide();
    Specialitatitolo->hide();
    qpb->setText("OK");
    qpb->setVisible(true);
    qvb->addWidget(inseriredati);
    qvb->addWidget(Acquistatotitolo);
    qvb->addWidget(acquistato);
    qvb->addWidget(prezzotitolo);
    qvb->addWidget(prezzo);
    qvb->addWidget(datatitolo);
    qvb->addWidget(data);
    qvb->addWidget(idtitolo);
    qvb->addWidget(inserireid);
    qvb->addWidget(animaletitolo);
    qvb->addWidget(boxanimale);
    qvb->addWidget(Caratteristica1titolo);
    qvb->addWidget(erb);
    qvb->addWidget(Caratteristica2titolo);
    qvb->addWidget(vele);
    qvb->addWidget(Caratteristica3titolo);
    qvb->addWidget(necr);
    qvb->addWidget(specietitolo);
    qvb->addWidget(boxspecie);
    qvb->addWidget(Specialitatitolo);
    qvb->addWidget(specialita);
    qvb->addWidget(pesotitolo);
    qvb->addWidget(peso);
    qvb->addWidget(altezzatitolo);
    qvb->addWidget(altezza);
    qvb->addWidget(etatitolo);
    qvb->addWidget(eta);
    qvb->addWidget(inestinztitolo);
    qvb->addWidget(inestinz);
    qvb->addWidget(sedetitolo);
    qvb->addWidget(sede);
    qvb->addWidget(qpb);
    setLayout(qvb);
    connect(qpb,SIGNAL(clicked()),this,SLOT(onbuttonpressed()));
    connect(qpb,SIGNAL(clicked()),this,SLOT(close()));
    connect(boxanimale,SIGNAL(activated(int)),this,SLOT(convertitore(int)));
    connect(boxspecie,SIGNAL(activated(int)),this,SLOT(specifiche_animali(int)));
    connect(boxanimale,SIGNAL(activated(int)),this,SLOT(toglimetti(int)));
    connect(boxanimale,SIGNAL(activated(int)),this,SLOT(activateboxspecie(int)));
    connect(acquistato,SIGNAL(stateChanged(int)),this,SLOT(attivaacquisto(int)));
}


void vista_lista_add::onbuttonpressed()
{
    emit sendsignal(acquistato->isChecked(),inserireid->text().toInt(),boxanimale->currentText().toStdString(),vele->isChecked(),necr->isChecked(),
                    frug->isChecked(),foli->isChecked(),gran->isChecked(),netti->isChecked(),boxspecie->currentText().toStdString(),
                    specialita->text().toInt(),peso->text().toInt(),altezza->text().toInt(),eta->text().toInt(),
                    prezzo->text().toInt(),data->date(),inestinz->isChecked(),sede->currentText().toStdString());
}

void vista_lista_add::convertitore(int a)
{
    erb->hide();
    vele->hide();
    necr->hide();
    Caratteristica1titolo->hide();
    Caratteristica2titolo->hide();
    Caratteristica3titolo->hide();
    frug->setCheckState(Qt::CheckState::Unchecked);
    foli->setCheckState(Qt::CheckState::Unchecked);
    gran->setCheckState(Qt::CheckState::Unchecked);
    netti->setCheckState(Qt::CheckState::Unchecked);
    vele->setCheckState(Qt::CheckState::Unchecked);
    necr->setCheckState(Qt::CheckState::Unchecked);
    if(a==1)
    {

        Caratteristica1titolo->setVisible(true);
        Caratteristica1titolo->setText("Dieta");
        erb->setVisible(true);
        frug->setVisible(true);
        foli->setVisible(true);
        gran->setVisible(true);
        netti->setVisible(true);
    }
    if(a==2)
    {
        Caratteristica2titolo->setVisible(true);
        Caratteristica2titolo->setText("Velenoso");
        vele->setVisible(true);
        Caratteristica3titolo->setVisible(true);
        Caratteristica3titolo->setText("Necrofago");
        necr->setVisible(true);
    }
    if(a==3)
    {
        Caratteristica1titolo->setVisible(true);
        Caratteristica1titolo->setText("Dieta");
        erb->setVisible(true);
        frug->setVisible(true);
        foli->setVisible(true);
        gran->setVisible(true);
        netti->setVisible(true);
        Caratteristica2titolo->setVisible(true);
        Caratteristica2titolo->setText("Velenoso");
        vele->setVisible(true);
        Caratteristica3titolo->setVisible(true);
        Caratteristica3titolo->setText("Necrofago");
        necr->setVisible(true);
    }
}

void vista_lista_add::specifiche_animali(int b)
{
        QString qs = boxspecie->itemText(b);
        if (qs == "--select--"){
            Specialitatitolo->hide();
            specialita->hide();
        }
        if (qs == "Rinoceronte"){
            Specialitatitolo->setText("Corno");
            Specialitatitolo->setVisible(true);
            specialita->setVisible(true);
        }
        if (qs == "Serpente"){
            Specialitatitolo->setText("Pelle");
            Specialitatitolo->setVisible(true);
            specialita->setVisible(true);
        }
        if (qs == "Orso") {
            Specialitatitolo->setText("Pelliccia");
            Specialitatitolo->setVisible(true);
            specialita->setVisible(true);
        }
}

void vista_lista_add::toglimetti(int c)
{
    for (int i=0;i<4;i++){
        boxspecie->removeItem(0);
    }
    if(c==1){
        QStringList qs;
        qs << "--select--"<< "Rinoceronte";
        boxspecie->addItems(qs);
        Specialitatitolo->hide();
        specialita->hide();
    }
    if(c==2){
        QStringList qs;
        qs << "--select--"<< "Serpente";
        boxspecie->addItems(qs);
        Specialitatitolo->hide();
        specialita->hide();
    }
    if(c==3){
        QStringList qs;
        qs << "--select--"<< "Orso";
        boxspecie->addItems(qs);
        Specialitatitolo->hide();
        specialita->hide();
    }

}

void vista_lista_add::activateboxspecie(int z)
{
    boxspecie->setEnabled(true);
}

void vista_lista_add::attivaacquisto(int q)
{
    prezzo->setText("0");
    QDate qa (2020,1,1);
    data->setDate(qa);
    if(q==2){
        prezzotitolo->setVisible(true);
        prezzo->setVisible(true);
        datatitolo->setVisible(true);
        data->setVisible(true);
    }
    if(q==0){
        prezzotitolo->hide();
        prezzo->hide();
        datatitolo->hide();
        data->hide();
    }

}

void vista_lista_add::setController(Controller* ctr){
    contr = ctr;
}

QComboBox *vista_lista_add::getboxspecie() const
{
    return boxspecie;
}

QComboBox *vista_lista_add::getboxanimale() const
{
    return boxanimale;
}

QLineEdit *vista_lista_add::getid() const
{
    return inserireid;
}

QLineEdit *vista_lista_add::getpeso() const
{
    return peso;
}

QLineEdit *vista_lista_add::getaltezza() const
{
    return altezza;
}

QLineEdit *vista_lista_add::geteta() const
{
    return eta;
}

QLineEdit *vista_lista_add::getprezzo() const
{
    return prezzo;
}


QComboBox *vista_lista_add::getsede() const
{
    return sede;
}

QLineEdit *vista_lista_add::getspecialita() const
{
    return specialita;
}


QCheckBox *vista_lista_add::getinestinzione() const
{
    return inestinz;
}

QCheckBox *vista_lista_add::getfrug() const
{
    return frug;
}

QCheckBox *vista_lista_add::getfoli() const
{
    return foli;
}

QCheckBox *vista_lista_add::getgrani() const
{
    return gran;
}

QCheckBox *vista_lista_add::getnetti() const
{
    return netti;
}

QCheckBox *vista_lista_add::getvele() const
{
    return vele;
}

QCheckBox *vista_lista_add::getnecr() const
{
    return necr;
}

QCheckBox *vista_lista_add::getacquistato() const
{
    return acquistato;
}

QGroupBox *vista_lista_add::geterb() const
{
    return erb;
}

QLabel *vista_lista_add::getdatatitolo() const
{
    return datatitolo;
}

QDateEdit *vista_lista_add::getdata() const
{
    return data;
}

QLabel *vista_lista_add::getcar1titolo() const
{
    return Caratteristica1titolo;
}

QLabel *vista_lista_add::getcar2titolo() const
{
    return Caratteristica2titolo;
}

QLabel *vista_lista_add::getcar3titolo() const
{
    return Caratteristica3titolo;
}

QLabel *vista_lista_add::getspecialitatitolo() const
{
    return Specialitatitolo;
}

QLabel *vista_lista_add::getprezzotitolo() const
{
    return prezzotitolo;
}

