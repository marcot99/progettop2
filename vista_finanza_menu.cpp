#include "vista_finanza_menu.h"
#include <QSizePolicy>
vista_finanza_menu::vista_finanza_menu(QWidget *parent) : QWidget(parent)
{
    qcby = new QComboBox();
    qcbm = new QComboBox();
    QStringList qsm;
    QStringList qsy;
    qsm << "January" << "February" << "March" << "April" << "May" << "June" <<
           "July" << "August" << "September" << "October" << "November"
        << "December";
    qsy << "2020" << "2021" << "2022" << "2023" << "2024" << "2025" <<
           "2026" << "2027" << "2028" << "2029" << "2030";
    qcbm->insertItems(1,qsm);
    qcby->insertItems(1,qsy);
    qcby->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    qcbm->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    qhb = new QHBoxLayout();
    qvb1 = new QVBoxLayout();
    qvb2 = new QVBoxLayout();
    qvb1->addWidget(qcby);
    qvb2->addWidget(qcbm);
    qhb->addLayout(qvb1);
    qhb->addLayout(qvb2);
    qhb->setAlignment(qvb1,AlignLeft);
    qhb->setAlignment(qvb2,AlignLeft);
    qvb1->setAlignment(qcby,AlignTop);
    qvb2->setAlignment(qcbm,AlignTop);
    qhb->addStretch(0);
    setLayout(qhb);
}
