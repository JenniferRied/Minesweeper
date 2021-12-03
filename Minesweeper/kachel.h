#ifndef KACHEL_H
#define KACHEL_H

#include <QPushButton>
#include <QState>
#include <QStateMachine>

struct Kachel_Position
{
    unsigned int reihe;
    unsigned int spalte;
};

class Kachel: public QPushButton
{
    Q_OBJECT
public:
    Kachel(Kachel_Position position, QWidget* parent);

    Kachel_Position position() const;

    void nachbar_hinzufuegen(Kachel* kachel);

    bool ist_mine();
    bool ist_markiert();
    bool ist_aufgedeckt();
    bool hat_benachbarte_minen();

    QSize sizeHint() const override;

signals:

    void linksklick();
    void rechtsklick();
    void beide_gleichzeitig_klick();
    void mittelklick();
    void aufgedeckt();
    void explodiert();
    void markiert(bool);

private:
    static QString nicht_aufgedecktes_Style_Sheet;
    static QString aufgedeckt_Style_Sheet;
    static QString aufgedeckte_Zahlen_Style_Sheet;

    Kachel_Position k_position;

    void status_maschine_erstellen();
    void zahlen_eintragen();

    QList<Kachel*> k_nachbarn;

    QStateMachine k_maschine;
    QState* nicht_aufgedeckter_status;
    QState* aufgedeckter_status;
    QState* markierter_status;

};

#endif // KACHEL_H
