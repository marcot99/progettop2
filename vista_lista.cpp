#include "controller.h"
vista_lista::vista_lista(Model* M):QTableWidget(12,12)
{
    ctr = new Controller(M);
}

void vista_lista::build_view_list(Contenitore<Animale *> &)
{
    QStringList name_col;
    name_col<<"Del"<<"Peso"<<"Altezza"<<"Età"<<"Prezzo"<<"CarSpeciali"<<"Inestinz"<<"Sede"<<"Venduto"<<"Proprietario"<<"CarSpecie"<<"CarAnimale";
    setColumnCount(12);
    setHorizontalHeaderLabels(name_col);
    setColumnWidth(0,100);setColumnWidth(1,100);setColumnWidth(2,100);setColumnWidth(3,100);setColumnWidth(4,100);setColumnWidth(5,100);
    setColumnWidth(6,100);setColumnWidth(7,100);setColumnWidth(8,100);setColumnWidth(9,100);setColumnWidth(10,100);setColumnWidth(11,100);
}
Controller* vista_lista::getCtrl() const{return ctr;}
