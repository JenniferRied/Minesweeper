#include "spielbrett.h"
#include <iostream>
#include <QGridLayout>
#include <random>
#include "minesweeper.h"


Spielbrett::Spielbrett(unsigned int reihen, unsigned int spalten, unsigned int minen_anzahl, QWidget* parent, QGridLayout* spielbrett_gridLayout)
    : k_reihen(reihen)
    , k_spalten(spalten)
    , k_minen_anzahl(minen_anzahl)
    , QFrame(parent)
{

    kacheln_erstellen(spielbrett_gridLayout);
    layout_erstellen();
    nachbarn_hinzufuegen();
}

void Spielbrett::layout_erstellen()
{
    this->setAttribute(Qt::WA_LayoutUsesWidgetRect);
    this->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    auto layout = new QGridLayout;

    layout->setSpacing(0);
    layout->setMargin(0);
    layout->setContentsMargins(0, 0, 0, 0);

    this->setLayout(layout);
}

void Spielbrett::kacheln_erstellen(QGridLayout* spielbrett_gridLayout)
{
    for (unsigned int r = 0; r < k_reihen; r++)
    {
        k_kacheln += QList<Kachel*>{};

        for (unsigned int s = 0; s < k_spalten; s++)
        {
            k_kacheln[r] += new Kachel({r, s}, this);
            spielbrett_gridLayout->addWidget(k_kacheln[r][s], r, s);
            connect(k_kacheln[r][s],SIGNAL(linksklick()),this,SLOT(geklickt()));
            connect(k_kacheln[r][s],SIGNAL(rechtsklick()),this,SLOT(geklickt()));
            connect(k_kacheln[r][s],SIGNAL(beide_gleichzeitig_klick()),this,SLOT(geklickt()));
            connect(k_kacheln[r][s],SIGNAL(mittelklick()),this,SLOT(geklickt()));
        }
    }
    k_kacheln[0][0]->setDown(true);
}

void Spielbrett::geklickt()
{
    emit klickt();
}

void Spielbrett::nachbarn_hinzufuegen()
{
    for (unsigned int r = 0; r < k_reihen; r++)
    {
        for (unsigned int s = 0; s < k_spalten; s++)
        {
            auto* kachel = k_kacheln[r][s];
            auto letzte_reihe = k_reihen - 1;
            auto letzte_spalte = k_spalten - 1;

            if (r && s)
                kachel->nachbar_hinzufuegen(k_kacheln[r - 1][s - 1]);
            if (r)
                kachel->nachbar_hinzufuegen(k_kacheln[r - 1][s]);
            if (r && s < letzte_spalte)
                kachel->nachbar_hinzufuegen(k_kacheln[r - 1][s + 1]);
            if (s < letzte_spalte)
                kachel->nachbar_hinzufuegen(k_kacheln[r][s + 1]);
            if (r < letzte_reihe && s < letzte_spalte)
                kachel->nachbar_hinzufuegen(k_kacheln[r + 1][s + 1]);
            if (r < letzte_reihe)
                kachel->nachbar_hinzufuegen(k_kacheln[r + 1][s]);
            if (r < letzte_reihe && s)
                kachel->nachbar_hinzufuegen(k_kacheln[r + 1][s - 1]);
            if (s)
                kachel->nachbar_hinzufuegen(k_kacheln[r][s - 1]);
        }
    }
}

void Spielbrett::minen_verteilen()
{

    QSet <Kachel*> fertig;

    for (unsigned int reihe = 0; reihe < k_reihen; ++reihe)
    {
        k_kacheln += QList<Kachel*>{};
        for (unsigned int spalte = 0; spalte < k_spalten; ++spalte)
        {
            if (auto kachel = k_kacheln [reihe] [spalte]; !fertig.contains(kachel))
                kacheln += kachel;
        }
    }

    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(kacheln.begin(),kacheln.end(),g);

    for (unsigned int i = 0; i < k_minen_anzahl; ++i)
    {
        kacheln[i] -> minen_verteiler(true);
        k_minen.insert(kacheln[i]);
    }
}

