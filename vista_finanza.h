#ifndef VISTA_FINANZA_H
#define VISTA_FINANZA_H
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "vista_finanza_menu.h"
#include "vista_finanza_acquisti.h"
#include "vista_finanza_vendite.h"
#include "vista_finanza_bilancio.h"
#include "dati_finanziari.h"
class vista_finanza : public QWidget
{
    Q_OBJECT
private:
    Controller* contr;
    int totaleacquisti;
    int totalevendite;
    int bilancio;
    QVBoxLayout* qvb;
    QHBoxLayout* qhb1;
    QHBoxLayout* qhb2;
    vista_finanza_acquisti* vfa;
    vista_finanza_vendite* vfv;
    vista_finanza_bilancio* vfb;
    void updateqtw();
public:
   void setController(Controller* ctr);
   explicit vista_finanza(QWidget *parent = nullptr);
   vista_finanza_acquisti* getvfa() const;
   vista_finanza_vendite* getvfv() const;
   void addacquisto(int acq);
   void addvendita(int ven);
   vista_finanza_bilancio* getvfb() const;
   void sistemaacquisto(int prezzo);
   void sistemavendita(int prezzo);
public slots:

};

#endif // VISTA_FINANZA_H
