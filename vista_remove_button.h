#ifndef VISTA_REMOVE_BUTTON_H
#define VISTA_REMOVE_BUTTON_H

#include <QObject>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTableWidgetItem>
class vista_remove_button:public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout* qvb;
    QPushButton* qpb;
public:
    vista_remove_button();
};

#endif // VISTA_REMOVE_BUTTON_H
