#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include <QMainWindow>
#include "spielbrett.h"
#include <QGridLayout>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Minesweeper; }
QT_END_NAMESPACE

class Minesweeper : public QMainWindow
{
    Q_OBJECT

public:
    Minesweeper(QWidget *parent = nullptr);
    ~Minesweeper();
    QGridLayout spielbrett_gridLayout;
    Ui::Minesweeper *ui;

public slots:
    void neu();
    void hilfe_oeffnen();
    void einstellungen_oeffnen();
    void initialisieren();
    void pausieren();
    void beenden();
    void statistik_oeffnen();
    void timer_timeout();
    void kachel_geklickt();
    void setze_schwierigkeit();
    void flaggen_zaehler(int);

signals:
    void starte_spiel();

private:

    QFrame* mainFrame;
    Spielbrett* spielbrett = nullptr;

    unsigned int reihen;
    unsigned int spalten;
    unsigned int minen_anzahl;

    int zeit = 0;
    QTimer* timer = NULL;
    bool pausiert = false;

    bool erster_klick = true;

    void timer_starten();
    void timer_pausieren();
    void timer_fortsetzen();

    unsigned int schwierigkeit;
};
#endif // MINESWEEPER_H
