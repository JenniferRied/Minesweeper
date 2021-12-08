#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include <QMainWindow>
#include "spielbrett.h"
#include <QGridLayout>

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

public slots:
    void hilfe_oeffnen();
    void initialisieren();

signals:
    void starte_spiel();

private:
    Ui::Minesweeper *ui;
    QFrame* mainFrame;
    Spielbrett* spielbrett;



    unsigned int reihen;
    unsigned int spalten;
};
#endif // MINESWEEPER_H
