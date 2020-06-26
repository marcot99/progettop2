#ifndef VISTA_LISTA_ADD_H
#define VISTA_LISTA_ADD_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QInputDialog>
#include <QPushButton>
#include <QCheckBox>
#include <QComboBox>
#include <QGroupBox>
#include <QDateEdit>
using std::string;
class Controller;
class vista_lista_add : public QWidget
{
    Q_OBJECT
private:
        Controller* contr;
        QVBoxLayout* qvb;
        QLineEdit* inserireid;
        QLineEdit* peso;
        QLineEdit* altezza;
        QLineEdit* eta;
        QLineEdit* prezzo;
        QComboBox* sede;
        QLineEdit* specialita;
        QComboBox* boxanimale;
        QComboBox* boxspecie;
        QCheckBox* vele;
        QCheckBox* necr;
        QGroupBox* erb;
        QLabel* inseriredati;
        QLabel* idtitolo;
        QLabel* animaletitolo;
        QLabel* pesotitolo;
        QLabel* altezzatitolo;
        QLabel* etatitolo;
        QLabel* prezzotitolo;
        QLabel* sedetitolo;
        QLabel* inestinztitolo;
        QLabel* Caratteristica1titolo;
        QLabel* Caratteristica2titolo;
        QLabel* Caratteristica3titolo;
        QLabel* Specialitatitolo;
        QLabel* Acquistatotitolo;
        QLabel* datatitolo;
        QDateEdit* data;
        QCheckBox* acquistato;
        QCheckBox* inestinz;
        QPushButton* qpb;
        QLabel* specietitolo;
        QCheckBox *frug;
        QCheckBox *foli;
        QCheckBox *gran;
        QCheckBox *netti;
public:
    explicit vista_lista_add(QWidget *parent = nullptr);
    void setController(Controller* ctr);
    QComboBox* getboxspecie() const;
    QComboBox* getboxanimale() const;
    QLineEdit* getid() const;
    QLineEdit* getpeso() const;
    QLineEdit* getaltezza() const;
    QLineEdit* geteta() const;
    QLineEdit* getprezzo() const;
    QComboBox* getsede() const;
    QLineEdit* getspecialita() const;
    QCheckBox* getinestinzione() const;
    QCheckBox* getfrug() const;
    QCheckBox* getfoli() const;
    QCheckBox* getgrani() const;
    QCheckBox* getnetti() const;
    QCheckBox* getvele() const;
    QCheckBox* getnecr() const;
    QCheckBox* getacquistato() const;
    QGroupBox* geterb() const;
    QLabel* getdatatitolo() const;
    QDateEdit* getdata() const;
    QLabel* getcar1titolo() const;
    QLabel* getcar2titolo() const;
    QLabel* getcar3titolo() const;
    QLabel* getspecialitatitolo() const;
    QLabel* getprezzotitolo() const;
signals:
    void sendsignal(bool,int,string,bool,bool,bool,bool,bool,bool,string,int,int,int,int,int,QDate,bool,string);
public slots:
    void onbuttonpressed();
    void convertitore(int a);
    void specifiche_animali(int b);
    void toglimetti(int c);
    void activateboxspecie(int z);
    void attivaacquisto(int q);

};

#endif // VISTA_LISTA_ADD_H
