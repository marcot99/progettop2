#ifndef VISTA_FINANZA_H
#define VISTA_FINANZA_H
#include <QComboBox>

class vista_finanza : public QWidget
{
    Q_OBJECT
private:
    //vista_acquisti*;
    //vista_vendite*;
    //vista_bilancio*;
    QComboBox* qcby;
    QComboBox* qcbm;
public:
   explicit vista_finanza(QWidget *parent = nullptr);

signals:

};

#endif // VISTA_FINANZA_H
