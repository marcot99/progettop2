#include "controller.h"
#include "vista.h"
Vista::Vista(QWidget *parent) : QWidget(parent){
    mainlayout = new QBoxLayout(QBoxLayout::TopToBottom);
    menubar = new QMenuBar(this);
    menu = new QMenu("File",menubar);
    exit = new QAction("Exit",menu);
    connect(exit,SIGNAL(triggered()),this,SLOT(close()));
    menu->addAction(exit);
    menubar->addMenu(menu);
    mainlayout->addWidget(menubar);
    tabwidget = new QTabWidget;
    i0 = new QIcon();
    q0 = new QString("Inventario");
    q1 = new QString("Finanza");
    tabvis = new vista_lista();
    //finvis = new vista_finanza();
    tabwidget->addTab(tabvis,*i0,*q0);
    //tabwidget->addTab(finvis,*i0,*q1);
    contr=tabvis->getCtrl();
    tabvis->build_view_list(contr->getContenitore());
    mainlayout->addWidget(tabwidget);
    setMinimumSize(QSize(400,400));
    setLayout(mainlayout);
}

