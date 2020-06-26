#include "save_load.h"
#include "model.h"
QString save_load::file_data="C:/Users/marco/OneDrive/Desktop/verifyanimals/data.xml";

save_load::save_load(){

}


void save_load::save(const Contenitore<Animale*>& c,dati_finanziari d)
{
    int size=file_data.size();
    if(size<4 || file_data.at(size-1)!='l' || file_data.at(size-2)!='m' || file_data.at(size-3)!='x' || file_data.at(size-4)!='.') file_data+=".xml";
    QFile file(file_data);
    file.open(QIODevice::WriteOnly);
    QXmlStreamWriter xmlStreamWriter(&file);
    xmlStreamWriter.setAutoFormatting(true);
    xmlStreamWriter.writeStartDocument();
    xmlStreamWriter.writeStartElement("animali");
    for(Contenitore<Animale*>::iteratore it=c.begin();it!=c.end() && !c.isEmpty();++it){
        xmlStreamWriter.writeStartElement("animale");
        xmlStreamWriter.writeTextElement("Tipo",QString::fromStdString(c[it].b->getTipo()));
        xmlStreamWriter.writeTextElement("Specie",QString::fromStdString(c[it].b->getSpecie()));
        xmlStreamWriter.writeTextElement("Peso",QString::number(c[it].b->getPeso()));
        xmlStreamWriter.writeTextElement("Altezza",QString::number(c[it].b->getAltezza()));
        xmlStreamWriter.writeTextElement("Eta",QString::number(c[it].b->getEta()));
        if(c[it].b->getInEstinz()) xmlStreamWriter.writeTextElement("InEstinzione","si");
        xmlStreamWriter.writeTextElement("Sede",QString::fromStdString(c[it].b->getSede()));
        if(c[it].b->getTipo() == "Erbivoro"){
               Erbivoro* erb = dynamic_cast<Erbivoro*>(c[it].b);
               list<Tipo> l = erb->getDieta();
               for(list<Tipo>::iterator it  = l.begin();it != l.end();it++){
                    if((*it)==Frugivoro){
                        xmlStreamWriter.writeTextElement("Frugivoro",QString::fromStdString(erb->getFrugivoro()));
                    }
                    if((*it)==Folivoro){
                        xmlStreamWriter.writeTextElement("Folivoro",QString::fromStdString(erb->getFolivoro()));
                    }
                    if((*it)==Granivoro){
                        xmlStreamWriter.writeTextElement("Granivoro",QString::fromStdString(erb->getGranivoro()));
                    }
                    if((*it)==Nettarivoro){
                        xmlStreamWriter.writeTextElement("Nettarivoro",QString::fromStdString(erb->getNettarivoro()));
                    }
               }
        }
        if(c[it].b->getTipo() == "Carnivoro"){
            Carnivoro* car = dynamic_cast<Carnivoro*>(c[it].b);
            if (car->getvelenoso()) xmlStreamWriter.writeTextElement("Velenoso","E' velenoso");
            if (car->getnecrofago()) xmlStreamWriter.writeTextElement("Necrofago","E' necrofago");
        }
        if(c[it].b->getTipo() == "Onnivoro"){
               Onnivoro* onn = dynamic_cast<Onnivoro*>(c[it].b);
               list<Tipo> l = onn->getDieta();
               for(list<Tipo>::iterator it  = l.begin();it != l.end();it++){
                    if((*it)==Frugivoro){
                        xmlStreamWriter.writeTextElement("Frugivoro",QString::fromStdString(onn->getFrugivoro()));
                    }
                    if((*it)==Folivoro){
                        xmlStreamWriter.writeTextElement("Folivoro",QString::fromStdString(onn->getFolivoro()));
                    }
                    if((*it)==Granivoro){
                        xmlStreamWriter.writeTextElement("Granivoro",QString::fromStdString(onn->getGranivoro()));
                    }
                    if((*it)==Nettarivoro){
                        xmlStreamWriter.writeTextElement("Nettarivoro",QString::fromStdString(onn->getNettarivoro()));
                    }
               }
               if (onn->getvelenoso()) xmlStreamWriter.writeTextElement("Velenoso","E' velenoso");
               if (onn->getnecrofago()) xmlStreamWriter.writeTextElement("Necrofago","E' necrofago");
        }
        if(c[it].b->getSpecie() == "Rinoceronte"){
            Rinoceronte* rin = dynamic_cast<Rinoceronte*>(c[it].b);
            xmlStreamWriter.writeTextElement("Corno",QString::number(rin->getCorno()));
            if (rin->isGrasso()) xmlStreamWriter.writeTextElement("Grasso","Questo rinoceronte è grasso");
            if (rin->isVecchio()) xmlStreamWriter.writeTextElement("Vecchio","Questo rinoceronte è vecchio");
            if (rin->isdiValore()) xmlStreamWriter.writeTextElement("Divalore","Questo rinoceronte è di valore");
        }
        if(c[it].b->getSpecie() == "Serpente"){
            Serpente* ser = dynamic_cast<Serpente*>(c[it].b);
            xmlStreamWriter.writeTextElement("Pelle",QString::number(ser->getPelle()));
            if (ser->isGrasso()) xmlStreamWriter.writeTextElement("Grasso","Questo serpente è grasso");
            if (ser->isVecchio()) xmlStreamWriter.writeTextElement("Vecchio","Questo serpente è vecchio");
            if (ser->isdiValore()) xmlStreamWriter.writeTextElement("Divalore","Questo serpente è di valore");
        }
        if(c[it].b->getSpecie() == "Orso"){
            Orso* ors = dynamic_cast<Orso*>(c[it].b);
            xmlStreamWriter.writeTextElement("Pelliccia",QString::number(ors->getPelliccia()));
            if (ors->isGrasso()) xmlStreamWriter.writeTextElement("Grasso","Questo orso è grasso");
            if (ors->isVecchio()) xmlStreamWriter.writeTextElement("Vecchio","Questo orso è vecchio");
            if (ors->isdiValore()) xmlStreamWriter.writeTextElement("Divalore","Questo orso è di valore");
        }
        xmlStreamWriter.writeTextElement("ID",QString::number(c[it].b->getID()));

        xmlStreamWriter.writeEndElement();
    }
    xmlStreamWriter.writeStartElement("DatiFinanziari");
    vector<acquisti> va = d.getVA();
    for(vector<acquisti>::iterator it=va.begin();it!=va.end() && !va.empty();++it) {
        xmlStreamWriter.writeStartElement("acquisto");
        xmlStreamWriter.writeTextElement("IDAC",QString::number((*it).getId()));
        xmlStreamWriter.writeTextElement("SpecieAC",QString::fromStdString((*it).getTipoA()));
        xmlStreamWriter.writeTextElement("PrezzoAC",QString::number((*it).getPrezzoA()));
        xmlStreamWriter.writeTextElement("DataAC",QString::fromStdString((*it).getData()));
        xmlStreamWriter.writeEndElement();
    }
    vector<vendite> vv = d.getVV();
    for(vector<vendite>::iterator it=vv.begin();it!=vv.end() && !vv.empty();++it) {
        xmlStreamWriter.writeStartElement("vendite");
        xmlStreamWriter.writeTextElement("IDVE",QString::number((*it).getId()));
        xmlStreamWriter.writeTextElement("SpecieVE",QString::fromStdString((*it).getTipoA()));
        xmlStreamWriter.writeTextElement("PrezzoVE",QString::number((*it).getPrezzoV()));
        xmlStreamWriter.writeTextElement("DataVE",QString::fromStdString((*it).getData()));
        xmlStreamWriter.writeEndElement();
    }
    xmlStreamWriter.writeStartElement("TotaleAcquisti");
    xmlStreamWriter.writeTextElement("TotAcquisti",(QString::number(d.getTotA())));
    xmlStreamWriter.writeEndElement();
    xmlStreamWriter.writeStartElement("TotaleVendite");
    xmlStreamWriter.writeTextElement("TotVendite",(QString::number(d.getTotV())));
    xmlStreamWriter.writeEndElement();
    xmlStreamWriter.writeStartElement("Bilancio");
    xmlStreamWriter.writeTextElement("Bilanciodato",(QString::number(d.getBil())));
    xmlStreamWriter.writeEndElement();
    xmlStreamWriter.writeEndDocument();
    file.close();
}

void save_load::load(Contenitore<Animale*>& c,dati_finanziari& d)
{
    int id,peso,altezza,eta,corno,pelliccia,pelle,totacquisti = 0,totvendite = 0,bilancio = 0,idac,prac,idve,prve;
    string tipo = "", specie = "",sede,spac,daac,spve,dave;
    bool inEst = false,velenoso = false,necrofago = false;
    Tipo frugivoro, nettarivoro, folivoro, granivoro;
    QFile file(file_data);
    Animale* a= 0;
    acquisti* acq = 0;
    vendite* ven = 0;
    list<Tipo> l;
    if(file.open(QFile::ReadOnly)){
        QXmlStreamReader xmlStreamReader(&file);
        xmlStreamReader.readNext();
        while(!xmlStreamReader.atEnd()){
            if(xmlStreamReader.isStartElement()){
                if(xmlStreamReader.name()=="animali" || xmlStreamReader.name()=="animale" || xmlStreamReader.name()=="DatiFinanziari"||
                   xmlStreamReader.name()=="TotaleAcquisti"|| xmlStreamReader.name()=="TotaleVendite"|| xmlStreamReader.name()=="Bilancio" ){
                                xmlStreamReader.readNext();}
                if(xmlStreamReader.name()=="Tipo") tipo=xmlStreamReader.readElementText().toStdString();
                if(xmlStreamReader.name()=="Specie") specie=xmlStreamReader.readElementText().toStdString();
                if(xmlStreamReader.name()=="Peso") peso=xmlStreamReader.readElementText().toInt();
                if(xmlStreamReader.name()=="Altezza") altezza=xmlStreamReader.readElementText().toInt();
                if(xmlStreamReader.name()=="Eta") eta=xmlStreamReader.readElementText().toInt();
                if(xmlStreamReader.name()=="InEstinzione") {
                    inEst = true;
                 }
                if(xmlStreamReader.name()=="Sede") sede=xmlStreamReader.readElementText().toStdString();
                if(xmlStreamReader.name()=="Frugivoro") l.push_back(frugivoro);
                if(xmlStreamReader.name()=="Folivoro") l.push_back(folivoro);
                if(xmlStreamReader.name()=="Granivoro") l.push_back(granivoro);
                if(xmlStreamReader.name()=="Nettarivoro") l.push_back(nettarivoro);
                if(xmlStreamReader.name()=="Velenoso") {
                    velenoso = true;
                }
                if(xmlStreamReader.name()=="Necrofago") {
                    necrofago = true;
                }
                if(xmlStreamReader.name()=="Corno") corno=xmlStreamReader.readElementText().toInt();
                if(xmlStreamReader.name()=="Pelle") pelle=xmlStreamReader.readElementText().toInt();
                if(xmlStreamReader.name()=="Pelliccia") pelliccia=xmlStreamReader.readElementText().toInt();
                if(xmlStreamReader.name()=="ID") {
                    id=xmlStreamReader.readElementText().toInt();
                    if (a) delete a;
                    if(specie == "Rinoceronte"){
                        a = new Rinoceronte(id,peso,altezza,eta,inEst,sede,l,corno);
                    }
                    if(specie == "Serpente"){
                        a = new Serpente(id,peso,altezza,eta,inEst,sede,velenoso,necrofago,pelle);
                    }
                    if(specie == "Orso"){
                        a = new Orso(id,peso,altezza,eta,inEst,sede,l,velenoso,necrofago,pelliccia);
                    }
                    if(a){
                        c.push_back(a);
                        a = 0;
                    }
                }
                if(xmlStreamReader.name()=="IDAC") idac = xmlStreamReader.readElementText().toInt();
                if(xmlStreamReader.name()=="SpecieAC") spac = xmlStreamReader.readElementText().toStdString();
                if(xmlStreamReader.name()=="PrezzoAC") prac = xmlStreamReader.readElementText().toInt();
                if(xmlStreamReader.name()=="DataAC"){
                    daac = xmlStreamReader.readElementText().toStdString();
                    if (acq) delete acq;
                    acq = new acquisti(idac,spac,prac,daac);
                    if (acq){
                        d.addacquisto(*acq);
                        acq = 0;
                    }
                }
                if(xmlStreamReader.name()=="IDVE") idve = xmlStreamReader.readElementText().toInt();
                if(xmlStreamReader.name()=="SpecieVE") spve = xmlStreamReader.readElementText().toStdString();
                if(xmlStreamReader.name()=="PrezzoVE") prve = xmlStreamReader.readElementText().toInt();
                if(xmlStreamReader.name()=="DataVE"){
                    dave = xmlStreamReader.readElementText().toStdString();
                    if (ven) delete ven;
                    ven = new vendite(idve,spve,prve,dave);
                    if (ven){
                        d.addvendita(*ven);
                        ven = 0;
                    }
                }
                if(xmlStreamReader.name()=="TotAcquisti"){
                    totacquisti = xmlStreamReader.readElementText().toInt();
                }
                if(xmlStreamReader.name()=="TotVendite"){
                    totvendite = xmlStreamReader.readElementText().toInt();
                }
                if(xmlStreamReader.name()=="Bilanciodato"){
                    bilancio = xmlStreamReader.readElementText().toInt();
                }
            }
            xmlStreamReader.readNext();
     }
     d.setAcquisti(totacquisti);
     d.setVendite(totvendite);
     d.setBilancio(bilancio);
     file.close();
   }
}
