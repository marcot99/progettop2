#ifndef VISTA_H
#define VISTA_H

#include "vista_lista.h"
#include "vista_finanza.h"
#include <QBoxLayout>
#include <QMenuBar>

class Controller;

class Vista:public QWidget
{
    Q_OBJECT
private:
    Controller* contr;
    QBoxLayout* mainlayout;
    QMenuBar* menubar;
    QMenu* menu;
    QAction* exit;
    QAction* reset;
    QTabWidget* tabwidget;
    QIcon* i0;
    QString* q0;
    QString* q1;
    vista_lista* tabvis;
    vista_finanza* finvis;
    vista_finanza A();
public:
    Vista(QWidget *parent = nullptr);
public slots:
// slot che chimano metodi che ci sono nei widget dentro alla vista principale e metodi nel controller
};

#endif // VISTA_H
