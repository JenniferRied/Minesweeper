#ifndef SPIELBRETT_H
#define SPIELBRETT_H

#include <QFrame>
#include "kachel.h"
#include <QGridLayout>

class Spielbrett : public QFrame
{
    Q_OBJECT
public:
    Spielbrett(unsigned int reihen, unsigned int spalten, unsigned int minen_anzahl, QGridLayout* spielbrett_gridLayout);
    virtual ~Spielbrett();

    unsigned int reihen() const{return k_reihen; };
    unsigned int spalten() const{return k_spalten; };
    unsigned int minen_anzahl() const {return k_minen_anzahl; };

    void verloren_animation();
    void ende(bool);

public slots:
    void geklickt();
    void minen_verteilen();
    void alle_aufdecken();

signals:
    void initialisiert();
    void klickt();
    void sieg();
    void verloren();
    void timer_anhalten();

private:
    unsigned int k_reihen;
    unsigned int k_spalten;
    unsigned int k_minen_anzahl;

    QList<QList<Kachel*>> k_kacheln;
    QSet<Kachel*> k_minen;
    QSet<Kachel*> k_richtige_flaggen;
    QSet<Kachel*> k_falsche_flaggen;
    QSet<Kachel*> k_aufgedeckte_felder;
    QList <Kachel*> kacheln;

    void kacheln_erstellen(QGridLayout*);
    void nachbarn_hinzufuegen();
    void layout_erstellen();

    QTimer* explosion_timer;
};

#endif // SPIELBRETT_H
