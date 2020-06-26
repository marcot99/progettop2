#include "vista_remove_button.h"

vista_remove_button::vista_remove_button()
{
    qvb = new QVBoxLayout();
    qpb = new QPushButton();
    QString qs = "REMOVE";
    qpb->setText(qs);
    qvb->addWidget(qpb);
    setLayout(qvb);
}
