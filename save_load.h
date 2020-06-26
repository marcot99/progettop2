#ifndef SAVE_LOAD_H
#define SAVE_LOAD_H

#include "contenitore.h"
#include <QObject>
#include <QWidget>
#include <QFile>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include "dati_finanziari.h"
class save_load : public QWidget
{
    Q_OBJECT
public:
    save_load();
    void save(const Contenitore<Animale*>& c,dati_finanziari d);
    void load(Contenitore<Animale*> & c,dati_finanziari& d);
private:
    static QString file_data; // path del file in uso
};

#endif // SAVE_LOAD_H
