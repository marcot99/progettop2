#ifndef VISTA_LISTA_OPTIONS_H
#define VISTA_LISTA_OPTIONS_H
#include <QTableWidget>
#include <QVBoxLayout>
#include <vista_add_button.h>
#include <vista_remove_button.h>
#include "model.h"
#include "QTableWidgetItem"
#include <QMessageBox>
#include <QDialog>
#include <QPlainTextEdit>
#include <QLineEdit>
#include <QLabel>
#include <QInputDialog>
#include <vista_lista_add.h>
#include <QObject>
class Controller;
class vista_lista_options : public QWidget
{
    Q_OBJECT
private:
    Controller* contr;
    QDialog* msg;
    QHBoxLayout* qhb;
    QVBoxLayout* qvb2;
    QVBoxLayout* qvb3;
    QVBoxLayout* qvbattributi;
    QLabel* qpte3;
    QString qs2;
    QString qs3;
    QString qs4;
    QLabel* ql2;
    QLabel* ql3;
    QLabel* ql4;
    QLabel* car1;
    QLabel* car2;
    QLabel* car3;
    QLabel* car4;
    QLabel* car5;
    QLabel* car6;
    QLabel* grasso;
    QLabel* vecchio;
    QLabel* valore;
    QLabel* attributititolo;
    QVBoxLayout* qhb1;
    QVBoxLayout* qhb2;
    QVBoxLayout* qhb3;
    QVBoxLayout* qhb4;
    QVBoxLayout* qhb5;
    QVBoxLayout* qhb6;
    QVBoxLayout* qhb7;
    QVBoxLayout* qhbgrasso;
    QVBoxLayout* qhbvecchio;
    QVBoxLayout* qhbvalore;

public:
    explicit vista_lista_options(QWidget *parent = nullptr);
    QDialog* getmsg() const;
    QLabel* getcar1() const;
    QLabel* getcar2() const;
    QLabel* getcar3() const;
    QLabel* getcar4() const;
    QLabel* getcar5() const;
    QLabel* getcar6() const;
    QLabel* getqpte3() const;
    QLabel* getgrasso() const;
    QLabel* getvecchio() const;
    QLabel* getvalore() const;
    void setController(Controller* ctr);

signals:

};

#endif // VISTA_LISTA_OPTIONS_H
