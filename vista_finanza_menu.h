#ifndef VISTA_FINANZA_MENU_H
#define VISTA_FINANZA_MENU_H

#include <QObject>
#include <QWidget>
#include <QComboBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
using namespace Qt;
class vista_finanza_menu : public QWidget
{
    Q_OBJECT
private:
    QHBoxLayout * qhb;
    QVBoxLayout* qvb1;
    QVBoxLayout* qvb2;
    QComboBox* qcby;
    QComboBox* qcbm;
public:
    explicit vista_finanza_menu(QWidget *parent = nullptr);

signals:

};

#endif // VISTA_FINANZA_MENU_H
