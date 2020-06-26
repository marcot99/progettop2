#ifndef VISTA_FINANZA_BILANCIO_H
#define VISTA_FINANZA_BILANCIO_H

#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QLabel>
class Controller;

class vista_finanza_bilancio : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout* qvb;
    QTableWidget* qtw;
    QLabel* ql;
    Controller* contr;
public:
    explicit vista_finanza_bilancio(QWidget *parent = nullptr);
    void setacquisto(int acq);
    void setstart(int acq,int ven,int bil);
    void setvendita(int ven);
    void setbilancio(int bil);
    void setController(Controller* ctr);
};

#endif // VISTA_FINANZA_BILANCIO_H
