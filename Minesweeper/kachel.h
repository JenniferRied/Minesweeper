#ifndef KACHEL_H
#define KACHEL_H

#include <QPushButton>
#include <QState>
#include <QStateMachine>
#include <QFinalState>

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
    void mine_plazieren(bool wert);
    void minen_aufdecken();
    void klicken();

    bool ist_mine() const;
    bool ist_markiert() const;
    bool ist_aufgedeckt() const;
    bool ist_nicht_aufgedeckt() const;
    bool hat_benachbarte_minen() const;

    unsigned int benachbarte_mienen_zaehler() const;
    unsigned int benachbarte_flaggen_zaehler() const;
    unsigned int flaggen_zaehler() const;

    virtual void mousePressEvent(QMouseEvent* e) override;
    virtual void mouseReleaseEvent(QMouseEvent* e) override;

    QSize sizeHint() const override;

    static QIcon flagge_bild();
    static QIcon aufgedeckt_bild();
    static QIcon mine_bild();
    static QIcon explosion_bild();

    QList<Kachel*>& nachbarn();



public slots:

    void erhoehe_anzahl_benachbarter_flaggen();
    void erhoehe_anzahl_flaggen();
    void verringere_anzahl_benachbarter_flaggen();
    void verringere_anzahl_flaggen();
    void erhoehe_anzahl_benachbarter_minen();

signals:

    void unClicked();
    void erster_klick(Kachel*);
    void linksklick();
    void rechtsklick();
    void beide_gleichzeitig_klick();
    void mittelklick();
    void aufdecken();
    void aufgedeckt();
    void explodiert();
    void nachbarn_aufdecken();
    void unPreview();
    void unPreviewNeighbors();
    void vorschau();
    void deaktiviert();
    void markiert(bool);
    void nicht_markiert(bool);

private:
    static QString nicht_aufgedecktes_Style_Sheet;
    static QString aufgedeckt_Style_Sheet;
    static QString aufgedeckte_Zahlen_Style_Sheet;
    Qt::MouseButtons k_klicks;

    Kachel_Position k_position;

    void status_maschine_erstellen();
    void zahlen_eintragen();
    void setText();

    QList<Kachel*> k_nachbarn;

    QStateMachine k_maschine;
    QState* nicht_aufgedeckter_status;
    QState* aufgedeckter_status;
    QState* markierter_status;
    QState* nachbar_status_aufdecken;
    QState* nachbar_vorschau_status;
    QState* vorschau_status;
    QFinalState* deaktiviere_status;
    bool k_ist_mine;

    unsigned int k_benachbarte_mienen_zaehler;
    unsigned int k_benachbarte_flaggen_zaehler;
    unsigned int k_flaggen_zaehler;

};

#endif // KACHEL_H
