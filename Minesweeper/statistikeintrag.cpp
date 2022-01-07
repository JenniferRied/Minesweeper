#include "statistikeintrag.h"

//Konstruktor der Klasse Statistikeintrag.
Statistikeintrag::Statistikeintrag(int zeilen, int spalten, int bomben, int gewonnen, int verloren, int bestzeit)
    : statistik_zeilen(zeilen), statistik_spalten(spalten),
      statistik_bomben(bomben), statistik_gewonnen(gewonnen),
      statistik_verloren(verloren), statistik_bestzeit(bestzeit)
{

}

//Anzahl der gewonnenen Spielen wird um eins erhöht und er wird geschaut,
//um die neue bestzeit kleiner als die alte wird und wenn dies er fall ist als neue  bestzeit gespeichert.
void Statistikeintrag::zunahme_gewonnen(int zeit)
{
    statistik_gewonnen++;
    if((statistik_bestzeit < 0) || (zeit > 0 && zeit < statistik_bestzeit))
    {
        statistik_bestzeit = zeit;
    }
}

//Die Anzahl der verlorenen Spiele wird um eins erhöht.
void Statistikeintrag::zunahme_verloren()
{
    statistik_verloren++;
}

//get-Funktion von zeilen.
int Statistikeintrag::zeilen()
{
    return  statistik_zeilen;
}

//get-Funktion von spalten.
int Statistikeintrag::spalten()
{
    return  statistik_spalten;
}

//get-Funktion von bomben.
int Statistikeintrag::bomben()
{
    return  statistik_bomben;
}

//get-Funktion von gewonnen.
int Statistikeintrag::gewonnen()
{
    return  statistik_gewonnen;
}

//get-Funktion von verloren.
int Statistikeintrag::verloren()
{
    return  statistik_verloren;
}

//get-Funktion von bestzeit.
int Statistikeintrag::bestzeit()
{
    return  statistik_bestzeit;
}
