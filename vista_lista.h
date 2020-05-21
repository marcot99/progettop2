#ifndef VISTA_LISTA_H
#define VISTA_LISTA_H

#include <QTableWidget>
#include "model.h"

class Controller;

class vista_lista:public QTableWidget
{
    Q_OBJECT
private:
    Controller * ctr;
public:
    vista_lista(Model* M= new Model());
    void build_view_list(Contenitore<Animale*>&);
    Controller* getCtrl() const;
};

#endif // VISTA_LISTA_H
