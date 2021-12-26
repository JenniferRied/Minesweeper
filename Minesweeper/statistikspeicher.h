#ifndef STATISTIKSPEICHER_H
#define STATISTIKSPEICHER_H

#include <QObject>
#include <QList>
#include "statistikeintrag.h"

class Statistikspeicher : public QObject
{
    Q_OBJECT

public:

    static Statistikspeicher &instance();
    QList<Statistikeintrag*> eintraege();

    void gewonnen(int zeile, int spalte, int bomben, int zeit);
    void verloren(int zeile, int spalte, int bomben);

private:
    ~Statistikspeicher();
    Statistikspeicher(QObject* partent = NULL);
    QList<Statistikeintrag*> statistikliste;

    static const QString zeilen_seperator;
    static const QString werte_seperator;
    static const QString dateiname;

    void dateizeile_zu_listeneintrag(QStringList zeilen);
    void statistiklisteneintrag(QList<int> werte);
};

#endif // STATISTIKSPEICHER_H
