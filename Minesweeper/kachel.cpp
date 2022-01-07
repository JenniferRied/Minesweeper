#include "kachel.h"
#include <QDebug>
#include <QMouseEvent>

QString Kachel::nicht_aufgedecktes_Style_Sheet =
        "Kachel"
        "{"
        "   border: 1px solid darkgray;"
        "   background: qradialgradient(cx : 0.4, cy : -0.1, fx : 0.4, fy : -0.1, radius : 1.35, stop : 0 #fff, stop : 1 #bbb);"
        "   border - radius: 1px;"
        "}";

QString Kachel::aufgedeckt_Style_Sheet =
        "Kachel"
        "{"
        "   border: 1px solid lightgray;"
        "}";

QString Kachel::aufgedeckte_Zahlen_Style_Sheet =
        "Kachel"
        "{"
        "   color: %1;"
        "   font-weight: bold;"
        "   border: 1px solid darkgray;"
        "}";

QIcon Kachel::aufgedeckt_bild()
{
    static QIcon icon = QIcon();
    return icon;
}

QIcon Kachel::flagge_bild()
{
    static QIcon icon = QIcon(QPixmap(":/new/icons/Flagge.png").scaled(QSize(20, 20)));
    return icon;
}

QIcon Kachel::mine_bild()
{
    static QIcon icon = QIcon(QPixmap(":/new/icons/Bombe.png").scaled(QSize(20, 20)));
    return icon;
}

QIcon Kachel::explosion_bild()
{
    static QIcon icon = QIcon(QPixmap(":/new/icons/explosion.png").scaled(QSize(20, 20)));
    return icon;
}

bool Kachel::ist_aufgedeckt() const
{
    return k_maschine.configuration().contains(aufgedeckter_status);
}

bool Kachel::ist_nicht_aufgedeckt() const
{
    return k_maschine.configuration().contains(nicht_aufgedeckter_status);
}

bool Kachel::ist_markiert() const
{
    return k_maschine.configuration().contains(markierter_status);
}

bool Kachel::ist_mine() const
{
    return k_ist_mine;
}

bool Kachel::hat_benachbarte_minen() const
{
    return k_benachbarte_mienen_zaehler;
}

unsigned int Kachel::benachbarte_mienen_zaehler() const
{
    return k_benachbarte_mienen_zaehler;
}

void Kachel::erhoehe_anzahl_benachbarter_minen()
{
    ++k_benachbarte_mienen_zaehler;
}

unsigned int Kachel::benachbarte_flaggen_zaehler() const
{
    return k_benachbarte_flaggen_zaehler;
}

void Kachel::erhoehe_anzahl_benachbarter_flaggen()
{
    ++k_benachbarte_flaggen_zaehler;
}

void Kachel::verringere_anzahl_benachbarter_flaggen()
{
    --k_benachbarte_flaggen_zaehler;
}

Kachel::Kachel(Kachel_Position position, QWidget* parent)
    : k_position(position)
    , QPushButton(parent)
    , k_ist_mine (false)
    , k_benachbarte_mienen_zaehler(0)
    , k_benachbarte_flaggen_zaehler(0)
{
    status_maschine_erstellen();
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    setCheckable(true);
}

void Kachel::mousePressEvent(QMouseEvent *e)
{

    if(e->buttons() == (Qt::LeftButton | Qt::RightButton))
    {
        emit beide_gleichzeitig_klick();
        k_klicks = Qt::LeftButton | Qt::RightButton;
    }
    else if (e->buttons() == Qt::LeftButton)
        k_klicks = Qt::LeftButton;
    else if (e->buttons() == Qt::RightButton)
        k_klicks = Qt::RightButton;
    else if (e->buttons() == Qt::MidButton)
        k_klicks = Qt::MidButton;
}

void Kachel::mouseReleaseEvent(QMouseEvent *e)
{
    if (k_klicks == (Qt::LeftButton | Qt::RightButton | Qt::MidButton))
        emit unClicked();
    else if (k_klicks == Qt::LeftButton)
        emit linksklick();
    else if (k_klicks == Qt::RightButton)
        emit rechtsklick();
    else if (k_klicks == Qt::MidButton)
        emit mittelklick();
}

Kachel_Position Kachel::position() const
{
    return k_position;
}

//nachbarn der Minen erstellen
void Kachel::nachbar_hinzufuegen(Kachel *kachel)
{
    k_nachbarn += kachel;
    connect(this, &Kachel::nachbarn_aufdecken, kachel, &Kachel::aufdecken, Qt::QueuedConnection);
    connect(this, &Kachel::unPreviewNeighbors, kachel, &Kachel::unPreview, Qt::QueuedConnection);
}

QSize Kachel::sizeHint() const
{
    return QSize(24,24);
}

//Die verschiedenen Status für das Spielfeld
void Kachel::status_maschine_erstellen()
{
    nicht_aufgedeckter_status = new QState;
    aufgedeckter_status = new QState;
    markierter_status = new QState;
    nachbar_status_aufdecken = new QState;
    nachbar_vorschau_status = new QState;
    vorschau_status = new QState;
    deaktiviere_status = new QFinalState;



    nicht_aufgedeckter_status -> addTransition(this, &Kachel::linksklick, aufgedeckter_status);
    nicht_aufgedeckter_status -> addTransition(this, &Kachel::rechtsklick, markierter_status);
    nicht_aufgedeckter_status -> addTransition(this, &Kachel::aufdecken, aufgedeckter_status);
    nicht_aufgedeckter_status -> addTransition(this, &Kachel::vorschau, vorschau_status);
    nicht_aufgedeckter_status -> addTransition(this, &Kachel::deaktiviert, deaktiviere_status);

    vorschau_status -> addTransition(this, &Kachel::deaktiviert, deaktiviere_status);
    vorschau_status->addTransition(this, &Kachel::aufgedeckt, aufgedeckter_status);
    vorschau_status->addTransition(this, &Kachel::unPreview, nicht_aufgedeckter_status);

    markierter_status->addTransition(this, &Kachel::mittelklick, nicht_aufgedeckter_status);

    aufgedeckter_status->addTransition(this, &Kachel::beide_gleichzeitig_klick, nachbar_vorschau_status);

    nachbar_vorschau_status -> addTransition(this, &Kachel::unClicked, nachbar_status_aufdecken);
    nachbar_vorschau_status->addTransition(this, &Kachel::unPreview, aufgedeckter_status);

    nachbar_status_aufdecken->addTransition(this, &Kachel::aufdecken, aufgedeckter_status);

    connect(nicht_aufgedeckter_status, &QState::entered, [this]()
    {
        this->setStyleSheet(nicht_aufgedecktes_Style_Sheet);
    });

    connect(vorschau_status, &QState::entered, [this]()
        {
            this->setStyleSheet(aufgedeckt_Style_Sheet);
        });

    connect(nachbar_vorschau_status, &QState::entered, [this]()
        {
            for (auto nachbar : k_nachbarn)
                nachbar->vorschau();
        });

    connect(nachbar_status_aufdecken, &QState::entered, [this]()
        {
            if (k_benachbarte_flaggen_zaehler == k_benachbarte_mienen_zaehler && k_benachbarte_mienen_zaehler)
                nachbarn_aufdecken();
            else
                unPreviewNeighbors();
            emit aufdecken();
        });

    connect(aufgedeckter_status, &QState::entered, [this]()
    {
        unPreviewNeighbors();
        this -> setIcon(aufgedeckt_bild());
        this -> setChecked(true);
        if (!ist_mine())
        {
            setText();
            if (!hat_benachbarte_minen())
                nachbarn_aufdecken();
            emit aufgedeckt();
        }
        else
        {
            emit explodiert();
            this -> setStyleSheet(aufgedeckt_Style_Sheet);
            QPushButton::setText("");
            setIcon(mine_bild());
        }
    });

    connect(markierter_status, &QState::entered, [this]()
    {
        this -> setIcon(flagge_bild());
        for (auto nachbar : k_nachbarn)
                nachbar->erhoehe_anzahl_benachbarter_flaggen();
        emit markiert(k_ist_mine);
    });

    connect(deaktiviere_status, &QState::entered, [this]()
    {

    });

    connect(markierter_status, &QState::exited, [this]()
    {
        this->setIcon(QIcon());
        for(auto nachbar : k_nachbarn)
                nachbar->verringere_anzahl_benachbarter_flaggen();
        emit nicht_markiert(k_ist_mine);
    });


    k_maschine.addState(nicht_aufgedeckter_status);
    k_maschine.addState(aufgedeckter_status);
    k_maschine.addState(markierter_status);
    k_maschine.addState(nachbar_status_aufdecken);
    k_maschine.addState(nachbar_vorschau_status);
    k_maschine.addState(deaktiviere_status);
    k_maschine.setInitialState(nicht_aufgedeckter_status);
    k_maschine.addState(vorschau_status);
    k_maschine.start();



}

//Felder mit Zahlen füllen
void Kachel::setText()
{
    QString farbe;
    switch(k_benachbarte_mienen_zaehler)
    {        
    case 1:
        farbe = "blue";
        break;
    case 2:
        farbe = "green";
        break;
    case 3:
        farbe = "red";
        break;
    case 4:
        farbe = "midnightblue";
        break;
    case 5:
        farbe = "maroon";
        break;
    case 6:
        farbe = "darkcyan";
        break;
    case 7:
        farbe = "black";
        break;
    case 8:
        farbe = "grey";
        break;
    default:
        farbe = "white";
        break;
    }

    QPushButton::setStyleSheet(aufgedeckte_Zahlen_Style_Sheet.arg(farbe));
    if(k_benachbarte_mienen_zaehler > 0)
        QPushButton::setText(QString::number(k_benachbarte_mienen_zaehler));
}

//Plazieren jeder einzelnen Mine
void Kachel::mine_plazieren(bool wert)
{
    k_ist_mine = wert;
    for (auto n : k_nachbarn)
            n->erhoehe_anzahl_benachbarter_minen();
}

