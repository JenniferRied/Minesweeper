#include "spielbrett.h"
#include <QGridLayout>
#include <random>
#include <QMessageBox>
#include "minesweeper.h"
#include "statistikspeicher.h"


Spielbrett::Spielbrett(unsigned int reihen, unsigned int spalten, unsigned int minen_anzahl, QGridLayout* spielbrett_gridLayout)
    : QFrame(nullptr)
    , k_reihen(reihen)
    , k_spalten(spalten)
    , k_minen_anzahl(minen_anzahl)
    , explosion_timer(new QTimer(this))
{

    kacheln_erstellen(spielbrett_gridLayout);
    layout_erstellen();
    nachbarn_hinzufuegen();
    minen_verteilen();

    connect(this, &Spielbrett::sieg, [this]()
        {
            explosion_timer->setProperty("sieg", true);
        });
        connect(this, &Spielbrett::verloren, [this]()
        {
            ende(true);
            explosion_timer->setProperty("sieg", false);
        });

    connect(explosion_timer, &QTimer::timeout, [this]()
            {
                if (k_minen.isEmpty())
                {
                    explosion_timer->stop();
                    return;
                }

                Kachel* mine = k_minen.values().front();
                k_minen.remove(mine);

                if (explosion_timer->property("sieg").toBool())
                    mine->setIcon(mine->flagge_bild());
                else
                {
                        mine->setIcon(mine->explosion_bild());                        
                }
            });


}

Spielbrett::~Spielbrett()
{
    for (QList<Kachel*> kacheln : k_kacheln) {
        for (Kachel* k : kacheln) {
            delete k;
        }
        kacheln.clear();
    }
    k_kacheln.clear();
}

//erstellen des Layouts
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

//erstellen jeder einzelnen Kachel
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
            connect(k_kacheln[r][s], &Kachel::explodiert, this, &Spielbrett::verloren_animation);
            connect(this, &Spielbrett::verloren, k_kacheln[r][s], &Kachel::deaktiviert);
            connect(this, &Spielbrett::sieg, k_kacheln[r][s], &Kachel::deaktiviert);
        }
    }
    k_kacheln[0][0]->setDown(true);
}

//explodieren der Bomben nacheinander
void Spielbrett::verloren_animation()
{
    Kachel* sender = dynamic_cast<Kachel*>(this->sender());
    QTimer::singleShot(350, this, [sender]()
    {
        sender->setIcon(sender->explosion_bild());
    });
    QTimer::singleShot(500, this, [this]()
    {
        for (auto mine : k_minen)
        {
            disconnect(mine, &Kachel::explodiert, this, &Spielbrett::verloren_animation);
            //if (!mine->ist_markiert())
                mine->aufdecken();
        }
        emit verloren();

    });

    QTimer::singleShot(1000, explosion_timer, [this]()
    {
        explosion_timer->start(25);
    });
}

void Spielbrett::ende(bool spiel_verloren)
{
    if (spiel_verloren)
    {
        QMessageBox runde_verloren;
        runde_verloren.setText("Du hast leider Verloren!");
        runde_verloren.exec();
        Statistikspeicher::instance().verloren(k_reihen,k_spalten,k_minen_anzahl);
    }
}

//Wenn die Funktion geklickt aufgerufen wird, wird das Signal klickt abgegeben.
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

//Minen in einer QList generieren
void Spielbrett::minen_verteilen()
{

    QList<Kachel*> kacheln;
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

    std::random_device zufall;
    std::mt19937 g(zufall());

    std::shuffle(kacheln.begin(),kacheln.end(),g);

    for (unsigned int i = 0; i < k_minen_anzahl; ++i)
    {
        kacheln[i] -> mine_plazieren(true);
        k_minen.insert(kacheln[i]);
    }
    emit initialisiert();
}

