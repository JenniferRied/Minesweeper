#include "spielbrett.h"
#include <iostream>
#include <QGridLayout>
#include "minesweeper.h"

Spielbrett::Spielbrett(unsigned int reihen, unsigned int spalten, QWidget* parent, QGridLayout* spielbrett_gridLayout)
    : k_reihen(reihen)
    , k_spalten(spalten)
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
    layout->setSizeConstraint(QLayout::SetFixedSize);

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
        }
    }
    k_kacheln[0][0]->setDown(true);
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

