#ifndef SPIELBRETT_H
#define SPIELBRETT_H

#include <QFrame>
#include "kachel.h"
#include <QGridLayout>

class Spielbrett : public QFrame
{
    Q_OBJECT
public:
    Spielbrett(unsigned int reihen, unsigned int spalten, QWidget* parent, QGridLayout* spielbrett_gridLayout);

    unsigned int reihen() const{return k_reihen; };
    unsigned int spalten() const{return k_spalten; };

public slots:
    void geklickt();

signals:
    void initialisiert();
    void klickt();

private:
    unsigned int k_reihen;
    unsigned int k_spalten;

    QList<QList<Kachel*>> k_kacheln;

    void kacheln_erstellen(QGridLayout*);
    void nachbarn_hinzufuegen();
    void layout_erstellen();
};

#endif // SPIELBRETT_H
