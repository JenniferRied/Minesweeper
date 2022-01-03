#include "kachel.h"
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
        "   color: %1"
        "   font-weight: bold;"
        "   border: 1px solid darkgray;"
        "}";


Kachel::Kachel(Kachel_Position position, QWidget* parent)
    : k_position(position)
    , QPushButton(parent)
    , k_ist_mine (false)
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
    if (k_klicks == Qt::LeftButton)
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

void Kachel::nachbar_hinzufuegen(Kachel *kachel)
{
    k_nachbarn += kachel;
}

QSize Kachel::sizeHint() const
{
    return QSize(24,24);
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

void Kachel::minen_verteiler(bool val)
{
    k_ist_mine = val;
}

void Kachel::minen_aufdecken()
{
    //aufdecken aller Minen wenn verloren
}
