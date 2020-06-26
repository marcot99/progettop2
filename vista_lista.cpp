#include "controller.h"
#include <QDebug>
#include <typeinfo>
#include "erbivoro.h"
using std::string;


void vista_lista::updateqtw()
{
    int riga = -1;
    vector<Animale*> v = contr->getmod()->animalisback();
    for(vector<Animale*>::iterator it = v.begin(); it != v.end();it++){
        riga++;
        qtw->setRowCount(qtw->rowCount()+1);
        QTableWidgetItem* qtw0 = new QTableWidgetItem();
        qtw0->setText(QString::number((*it)->getID()));
        qtw0->setFlags(qtw0->flags() ^ Qt::ItemIsEditable);
        qtw->setItem(riga,0,qtw0);
        QTableWidgetItem* qtw1 = new QTableWidgetItem();
        qtw1->setText(QString::fromStdString((*it)->getTipo()));
        qtw1->setFlags(qtw1->flags() ^ Qt::ItemIsEditable);
        qtw->setItem(riga,1,qtw1);
        QTableWidgetItem* qtw2 = new QTableWidgetItem();
        qtw2->setText(QString::fromStdString((*it)->getSpecie()));
        qtw2->setFlags(qtw2->flags() ^ Qt::ItemIsEditable);
        qtw->setItem(riga,2,qtw2);
        QTableWidgetItem* qtw3 = new QTableWidgetItem();
        qtw3->setText(QString::number((*it)->getPeso()));
        qtw3->setFlags(qtw3->flags() ^ Qt::ItemIsEditable);
        qtw->setItem(riga,3,qtw3);
        QTableWidgetItem* qtw4 = new QTableWidgetItem();
        qtw4->setText(QString::number((*it)->getAltezza()));
        qtw4->setFlags(qtw4->flags() ^ Qt::ItemIsEditable);
        qtw->setItem(riga,4,qtw4);
        QTableWidgetItem* qtw5 = new QTableWidgetItem();
        qtw5->setText(QString::number((*it)->getEta()));
        qtw5->setFlags(qtw5->flags() ^ Qt::ItemIsEditable);
        qtw->setItem(riga,5,qtw5);
        QTableWidgetItem* qtw6 = new QTableWidgetItem();
        QString s1 = (((*it)->getInEstinz()) ? "si" : "no");
        qtw6->setText(s1);
        qtw6->setFlags(qtw6->flags() ^ Qt::ItemIsEditable);
        qtw->setItem(riga,6,qtw6);
        QTableWidgetItem* qtw7 = new QTableWidgetItem();
        qtw7->setText(QString::fromStdString((*it)->getSede()));
        qtw7->setFlags(qtw7->flags() ^ Qt::ItemIsEditable);
        qtw->setItem(riga,7,qtw7);
        QTableWidgetItem* qtw8 = new QTableWidgetItem();
        qtw8->setFlags(qtw8->flags() ^ Qt::ItemIsEditable);
        qtw->setItem(riga,8,qtw8);
        QTableWidgetItem* qtw9 = new QTableWidgetItem();
        qtw9->setFlags(qtw9->flags() ^ Qt::ItemIsEditable);
        qtw->setItem(riga,9,qtw0);
    }
}

vista_lista::vista_lista()
{
    contr = nullptr;
    qvb = new QVBoxLayout();
    qtw = new QTableWidget();
    vab = new vista_add_button();
    vla= new vista_lista_add();
    vlv = new vista_lista_vendita();
    vla->setMinimumHeight(900);
    vlo = new vista_lista_options();
    qpb = vab->getqpb();
    qvb->addWidget(qtw);
    qvb->addWidget(vab);
    QStringList name_col;
    name_col<<"ID"<<"Tipo"<<"Specie"<<"Peso"<<"Altezza"<<"Età"<<
              "InEstinzione"<<"Sede"<<"Info"<<"Delete";
    qtw->setColumnCount(10);
    qtw->setHorizontalHeaderLabels(name_col);
    qtw->setColumnWidth(0,100);qtw->setColumnWidth(1,100);qtw->setColumnWidth(2,100);
    qtw->setColumnWidth(3,100);
    qtw->setColumnWidth(4,100);qtw->setColumnWidth(5,200);qtw->setColumnWidth(6,100);
    qtw->setColumnWidth(7,100);qtw->setColumnWidth(8,100);
    connect(qpb, SIGNAL(clicked()),this,SLOT(aprivla()));
    setLayout(qvb);
}

void vista_lista::setController(Controller* ctr){
    contr = ctr;
    updateqtw();
    connect(qtw,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(SuccedonoCose(int,int)));
}

QTableWidget *vista_lista::getqtw() const
{
    return qtw;
}

void vista_lista::aprivla() const
{
    vla->getboxspecie()->setEnabled(false);
    vla->getboxanimale()->setCurrentIndex(0);
    vla->getboxspecie()->setCurrentIndex(0);
    vla->getid()->setText("");
    vla->getpeso()->setText("");
    vla->getaltezza()->setText("");
    vla->geteta()->setText("");
    vla->getprezzo()->setText("0");
    vla->getprezzo()->hide();
    vla->getprezzotitolo()->hide();
    vla->getdatatitolo()->hide();
    vla->getdata()->hide();
    vla->getsede()->setCurrentIndex(0);
    vla->getspecialita()->setText("");
    vla->getinestinzione()->setCheckState(Qt::CheckState::Unchecked);
    vla->getfrug()->setCheckState(Qt::CheckState::Unchecked);
    vla->getfoli()->setCheckState(Qt::CheckState::Unchecked);
    vla->getgrani()->setCheckState(Qt::CheckState::Unchecked);
    vla->getnetti()->setCheckState(Qt::CheckState::Unchecked);
    vla->getvele()->setCheckState(Qt::CheckState::Unchecked);
    vla->getnecr()->setCheckState(Qt::CheckState::Unchecked);
    vla->getacquistato()->setCheckState(Qt::CheckState::Unchecked);
    QDate* qd = new QDate(2020,1,1);
    vla->getdata()->setDate(*qd);
    vla->geterb()->hide();
    vla->getfrug()->hide();
    vla->getfoli()->hide();
    vla->getgrani()->hide();
    vla->getnetti()->hide();
    vla->getvele()->hide();
    vla->getnecr()->hide();
    vla->getcar1titolo()->hide();
    vla->getcar2titolo()->hide();
    vla->getcar3titolo()->hide();
    vla->getspecialitatitolo()->hide();
    vla->getspecialita()->hide();
    vla->show();
}



vista_lista_add *vista_lista::getvla() const
{
    return vla;
}

vista_lista_options *vista_lista::getvlo() const
{
    return vlo;
}

vista_lista_vendita *vista_lista::getvlv() const
{
    return vlv;
}
void vista_lista::aggiungianimale(int id, string an,string specie, int a, int b, int c, bool h, string i)
{
    qtw->setRowCount(qtw->rowCount()+1);
    int riga = qtw->rowCount()-1;
    QTableWidgetItem* qtwi = new QTableWidgetItem();
    qtwi->setText(QString::number(id));
    qtwi->setFlags(qtwi->flags() ^ Qt::ItemIsEditable);
    qtw->setItem(riga,0,qtwi);
    QTableWidgetItem* qtwi0 = new QTableWidgetItem();
    qtwi0->setText(QString::fromStdString(an));
    qtwi0->setFlags(qtwi0->flags() ^ Qt::ItemIsEditable);
    qtw->setItem(riga,1,qtwi0);
    QTableWidgetItem* qtwif = new QTableWidgetItem();
    qtwif->setText(QString::fromStdString(specie));
    qtwif->setFlags(qtwif->flags() ^ Qt::ItemIsEditable);
    qtw->setItem(riga,2,qtwif);
    QTableWidgetItem* qtwi1 = new QTableWidgetItem();
    qtwi1->setText(QString::number(a));
    qtw->setItem(riga,3,qtwi1);
    QTableWidgetItem* qtwi2 = new QTableWidgetItem();
    qtwi2->setText(QString::number(b));
    qtw->setItem(riga,4,qtwi2);
    QTableWidgetItem* qtwi3 = new QTableWidgetItem();
    qtwi3->setText(QString::number(c));
    qtw->setItem(riga,5,qtwi3);
    QTableWidgetItem* qtwi5 = new QTableWidgetItem();
    QString s1 = (h ? "si" : "no");
    qtwi5->setText(s1);
    qtw->setItem(riga,6,qtwi5);
    QTableWidgetItem* qtwi4 = new QTableWidgetItem();
    qtwi4->setText(QString::fromStdString(i));
    qtw->setItem(riga,7,qtwi4);
    QTableWidgetItem* qtwidel = new QTableWidgetItem();
    qtwidel->setFlags(qtwidel->flags() ^ Qt::ItemIsEditable);
    qtw->setItem(riga,9,qtwidel);
    QTableWidgetItem* qtwiinf = new QTableWidgetItem();
    qtwiinf->setFlags(qtwiinf->flags() ^ Qt::ItemIsEditable);
    qtw->setItem(riga,8,qtwiinf);

}

void vista_lista::SuccedonoCose(int row,int col)
{
    if(col==9){
    QMessageBox* msg = new QMessageBox();
    msg->setWindowTitle("Rimuovi Animale");
    QMessageBox* vendita = new QMessageBox();
    vendita->setWindowTitle("Vendita Animale");
    msg->setIcon(QMessageBox::Question);
    msg->setText("Eliminare in modo permanente questo animale?");
    msg->setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
    msg->setDefaultButton(QMessageBox::Cancel);
    int ch=msg->exec();
    if(ch==QMessageBox::Yes){
        vendita->setIcon(QMessageBox::Question);
        vendita->setText("Aggiungere l'animale alla lista vendite?");
        vendita->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        vendita->setDefaultButton(QMessageBox::No);
        int ch2 = vendita->exec();
        if (ch2 == QMessageBox::Yes){
            vlv->getprezzo()->setText("0");
            QDate* qd = new QDate(2020,1,1);
            vlv->getdata()->setDate(*qd);
            vlv->assignrow(row);
            vlv->getdialog()->exec();
        }
        QTableWidgetItem* dap=qtw->takeItem(row,0);
        QString fad = dap->text();
        qtw->setItem(row,0,dap);
        string xx = fad.toStdString();
        int aabb = std::stoi(xx);
        emit deletestuff(aabb,row);
    }
    }
    else if (col==8){
        QTableWidgetItem* dap = qtw->takeItem(row,0);
        QString fad = dap->text();
        qtw->setItem(row,0,dap);
        string xx = fad.toStdString();
        int i = std::stoi(xx);
        Animale* an = contr->getmod()->searchanimale(i);
        list<Tipo> Dieta;
        bool velenoso;
        bool necrofago;
        int corno;
        int pelle;
        int pelliccia;
        bool grasso = an->isGrasso();
        bool vecchio = an->isVecchio();
        bool valore = an->isdiValore();
        Erbivoro* erb = dynamic_cast<Erbivoro*>(an);
        Carnivoro* car = dynamic_cast<Carnivoro*>(an);
        Onnivoro* onn = dynamic_cast<Onnivoro*>(an);
        vlo->getcar1()->hide();
        vlo->getcar2()->hide();
        vlo->getcar3()->hide();
        vlo->getcar4()->hide();
        vlo->getcar5()->hide();
        vlo->getcar6()->hide();
        if(erb){
            Dieta = erb->getDieta();
            bool frugivoro=false,folivoro=false,granivoro=false,nettarivoro=false;
            vlo->getcar1()->setText("Non è frugivoro");
            vlo->getcar2()->setText("Non è folivoro");
            vlo->getcar3()->setText("Non è granivoro");
            vlo->getcar4()->setText("Non è nettarivoro");
            vlo->getcar1()->setVisible(true);
            vlo->getcar2()->setVisible(true);
            vlo->getcar3()->setVisible(true);
            vlo->getcar4()->setVisible(true);
            for(list<Tipo>::const_iterator it = Dieta.begin();it!=Dieta.end();++it){
                if(*it==Frugivoro)
                {
                    frugivoro=true;
                    vlo->getcar1()->setVisible(true);
                    vlo->getcar1()->setText("E' frugivoro");
                }
                if(*it==Folivoro)
                {
                    folivoro=true;
                    vlo->getcar2()->setVisible(true);
                    vlo->getcar2()->setText("E' folivoro");
                }
                if(*it==Granivoro)
                {
                    granivoro=true;
                    vlo->getcar3()->setVisible(true);
                    vlo->getcar3()->setText("E' granivoro");
                }
                if(*it==Nettarivoro)
                {
                    nettarivoro=true;
                    vlo->getcar4()->setVisible(true);
                    vlo->getcar4()->setText("E' nettarivoro");
                }
            }
            Rinoceronte* rino = dynamic_cast<Rinoceronte*>(an);
            if (rino){
                corno = rino->getCorno();
                vlo->getqpte3()->setText("Questo rinoceronte ha " + QString::number(corno) + " kg di corna");
                QString strgrasso = (grasso ? "Questo rinoceronte è grasso" : "Questo rinoceronte è grasso");
                QString strvecchio = (vecchio ? "Questo rinoceronte è vecchio" : "Questo rinoceronte non è vecchio");
                QString strvalore = (valore ? "Questo rinoceronte è di valore" : "Questo rinoceronte non è di valore");
                vlo->getgrasso()->setText(strgrasso);
                vlo->getvecchio()->setText(strvecchio);
                vlo->getvalore()->setText(strvalore);
            }
        }
        if(car){
            velenoso = car->getvelenoso();
            necrofago = car->getnecrofago();
            vlo->getcar1()->setVisible(true);
            vlo->getcar2()->setVisible(true);
            if (velenoso)
            {
                vlo->getcar1()->setText("E' velenoso");
            }
            else
            {
                vlo->getcar1()->setText("Non è velenoso");
            }
            if (necrofago)
            {
                vlo->getcar2()->setText("E' necrofago");
            }
            else
            {
                vlo->getcar2()->setText("Non è necrofago");
            }
            Serpente* serpy = dynamic_cast<Serpente*>(an);
            if (serpy){
                pelle = serpy->getPelle();
                vlo->getqpte3()->setText("Questo serpente ha " + QString::number(pelle) + " kg di pelle");
                QString strgrasso = (grasso ? "Questo serpente è grasso" : "Questo serpente è grasso");
                QString strvecchio = (vecchio ? "Questo serpente è vecchio" : "Questo serpente non è vecchio");
                QString strvalore = (valore ? "Questo serpente è di valore" : "Questo serpente non è di valore");
                vlo->getgrasso()->setText(strgrasso);
                vlo->getvecchio()->setText(strvecchio);
                vlo->getvalore()->setText(strvalore);
            }
        }
        if (onn)
        {
            Dieta = erb->getDieta();
            bool frugivoro=false,folivoro=false,granivoro=false,nettarivoro=false;
            vlo->getcar3()->setText("Non è frugivoro");
            vlo->getcar4()->setText("Non è folivoro");
            vlo->getcar5()->setText("Non è granivoro");
            vlo->getcar6()->setText("Non è nettarivoro");
            vlo->getcar3()->setVisible(true);
            vlo->getcar4()->setVisible(true);
            vlo->getcar5()->setVisible(true);
            vlo->getcar6()->setVisible(true);
            for(list<Tipo>::const_iterator it = Dieta.begin();it!=Dieta.end();++it){
                if(*it==Frugivoro)
                {
                    frugivoro=true;
                    vlo->getcar3()->setText("E' frugivoro");
                }
                if(*it==Folivoro)
                {
                    folivoro=true;
                    vlo->getcar4()->setText("E' folivoro");
                }
                if(*it==Granivoro)
                {
                    granivoro=true;
                    vlo->getcar5()->setText("E' granivoro");
                }
                if(*it==Nettarivoro)
                {
                    nettarivoro=true;
                    vlo->getcar6()->setText("E' nettarivoro");
                }
            }
            velenoso = car->getvelenoso();
            necrofago = car->getnecrofago();
            vlo->getcar1()->setVisible(true);
            vlo->getcar2()->setVisible(true);
            if (velenoso)
            {
                vlo->getcar1()->setText("E' velenoso");
            }
            else
            {
                vlo->getcar1()->setText("Non è velenoso");
            }
            if (necrofago)
            {
                vlo->getcar2()->setText("E' necrofago");
            }
            else
            {
                vlo->getcar2()->setText("Non è necrofago");
            }
            Orso* boog = dynamic_cast<Orso*>(an);
            if (boog){
                pelliccia = boog->getPelliccia();
                vlo->getqpte3()->setText("Questo orso ha " + QString::number(pelliccia) + " kg di pelliccia");
                QString strgrasso = (grasso ? "Questo orso è grasso" : "Questo orso è grasso");
                QString strvecchio = (vecchio ? "Questo orso è vecchio" : "Questo orso non è vecchio");
                QString strvalore = (valore ? "Questo orso è di valore" : "Questo orso non è di valore");
                vlo->getgrasso()->setText(strgrasso);
                vlo->getvecchio()->setText(strvecchio);
                vlo->getvalore()->setText(strvalore);
            }
        }
        vlo->getmsg()->exec();
    }
}

