#include "kachel.h"

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
        "   color: %1"
        "   font-weight: bold;"
        "   border: 1px solid darkgray;"
        "}";


Kachel::Kachel(Kachel_Position position, QWidget* parent)
    : k_position(position)
    , QPushButton(parent)
{
    status_maschine_erstellen();
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    setCheckable(true);
}

Kachel_Position Kachel::position() const
{
    return k_position;
}

void Kachel::nachbar_hinzufuegen(Kachel *kachel)
{
    k_nachbarn += kachel;
}

QSize Kachel::sizeHint() const
{
    return QSize(20,20);
}

void Kachel::status_maschine_erstellen()
{
    nicht_aufgedeckter_status = new QState;
    aufgedeckter_status = new QState;
    markierter_status = new QState;


    connect(nicht_aufgedeckter_status, &QState::entered, [this]()
    {
        this->setStyleSheet(nicht_aufgedecktes_Style_Sheet);
    });

    connect(nicht_aufgedeckter_status, &QState::entered, [this]()
    {
        this->setStyleSheet(nicht_aufgedecktes_Style_Sheet);
    });

    k_maschine.addState(nicht_aufgedeckter_status);
    k_maschine.addState(aufgedeckter_status);
    k_maschine.addState(markierter_status);
    k_maschine.setInitialState(nicht_aufgedeckter_status);
    k_maschine.start();
}

void Kachel::zahlen_eintragen()
{
    QString farbe;

    //Funktion für zählen der benachbarten Minen fehlt noch
    /*switch(anzahl_benachbarter_minen)
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
        break;
    }*/

    QPushButton::setStyleSheet(aufgedeckte_Zahlen_Style_Sheet.arg(farbe));
}
