#ifndef STATISTIKEINTRAG_H
#define STATISTIKEINTRAG_H


class Statistikeintrag
{
public:
    Statistikeintrag(int zeilen, int spalten, int bomben, int gewonnen = 0, int verloren = 0, int bestzeit = -1);

    //getter
    int zeilen();
    int spalten();
    int bomben();
    int gewonnen();
    int verloren();
    int bestzeit();

    //aktualisierung für vorhandene spieleinstellungen
    void zunahme_gewonnen(int zeit);
    void zunahme_verloren();

private:
    int statistik_zeilen, statistik_spalten, statistik_bomben;
    int statistik_gewonnen, statistik_verloren, statistik_bestzeit;
};

#endif // STATISTIKEINTRAG_H
