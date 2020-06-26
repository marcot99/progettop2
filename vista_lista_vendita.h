#ifndef VISTA_LISTA_VENDITA_H
#define VISTA_LISTA_VENDITA_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QDateEdit>
#include <QDialog>
#include <QPushButton>
using std::string;
class Controller;
class vista_lista_vendita : public QWidget
{
    Q_OBJECT
private:
    Controller* contr;
    QPushButton* qpb;
    QVBoxLayout* qvb;
    QLabel* dativendita;
    QLabel* prezzotitolo;
    QLabel* datatitolo;
    QLineEdit* prezzo;
    QDateEdit* data;
    QDialog* d;
    int riga;
public:
    QDialog* getdialog() const;
    explicit vista_lista_vendita(QWidget *parent = nullptr);
    void setController(Controller* ctr);
    void assignrow(int row);
    QDateEdit* getdata() const;
    QLineEdit* getprezzo() const;
signals:
    void selldata(int,string,int,QDate);

public slots:
void inviadati();

};

#endif // VISTA_LISTA_VENDITA_H
