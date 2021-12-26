#include "statistikeintrag.h"

Statistikeintrag::Statistikeintrag(int zeilen, int spalten, int bomben, int gewonnen, int verloren, int bestzeit)
    : statistik_zeilen(zeilen), statistik_spalten(spalten),
      statistik_bomben(bomben), statistik_gewonnen(gewonnen),
      statistik_verloren(verloren), statistik_bestzeit(bestzeit)
{

}

void Statistikeintrag::zunahme_gewonnen(int zeit)
{
    statistik_gewonnen++;
    if((statistik_bestzeit < 0) || (zeit > 0 && zeit < statistik_bestzeit))
    {
        statistik_bestzeit = zeit;
    }
}

void Statistikeintrag::zunahme_verloren()
{
    statistik_verloren++;
}

int Statistikeintrag::zeilen()
{
    return  statistik_zeilen;
}

int Statistikeintrag::spalten()
{
    return  statistik_spalten;
}

int Statistikeintrag::bomben()
{
    return  statistik_bomben;
}

int Statistikeintrag::gewonnen()
{
    return  statistik_gewonnen;
}

int Statistikeintrag::verloren()
{
    return  statistik_verloren;
}

int Statistikeintrag::bestzeit()
{
    return  statistik_bestzeit;
}
