#include "vista.h"
#include "controller.h"
#include "model.h"
#include "animale.h"
#include "erbivoro.h"
#include "carnivoro.h"
#include "onnivoro.h"
#include "carnivoro.h"
#include "erbivoro.h"
#include "rinoceronte.h"
#include <QApplication>
#include <iostream>
#include <QDebug>
#include <QWidget>
#include <QDate>
//using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Contenitore<Animale*> con;
    Rinoceronte r (23,12,20);
    Orso o (21);
    Serpente s (23);
    Serpente* s0 = &s;
    Rinoceronte* r0 = &r;
    Orso* o0 = &o;
    con.push_back(s0);
    con.push_back(r0);
    con.push_back(o0);
    Model m(con);
    Controller c(&m);
    Vista v;
    c.setView(&v);
    v.show();
    return a.exec();
}
