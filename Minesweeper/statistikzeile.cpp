#include "statistikzeile.h"
#include "ui_statistikzeile.h"

//Konstruktor der Klasse Statistikzeile, bei der alle Felder der ui mit den Einträgen des Statistikeintrags gefüllt werden.
//Dabei gibt es auch einen default-Wert für alles, falls der Statistikeintrag leer ist.
Statistikzeile::Statistikzeile(Statistikeintrag *inhalt, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Statistikzeile)
{
    ui->setupUi(this);

    if(inhalt)
    {
        ui->zeile->setText(QString::number(inhalt->zeilen()));
        ui->spalte->setText(QString::number(inhalt->spalten()));
        ui->bomben->setText(QString::number(inhalt->bomben()));

        if (inhalt->gewonnen() > 0)
        {
            ui->gewonnen->setText(QString::number(inhalt->gewonnen()));
        }else{
            ui->gewonnen->setText("");
        }

        if (inhalt->verloren() > 0)
        {
            ui->verloren->setText(QString::number(inhalt->verloren()));
        }else{
            ui->verloren->setText("");
        }

        ui->verhaeltnis->setStretch(0, inhalt->gewonnen());
        ui->verhaeltnis->setStretch(1, inhalt->verloren());
        ui->anzahl->setText(QString::number(inhalt->gewonnen() + inhalt->verloren()));

        if (inhalt->bestzeit() > 0)
        {
            ui->bestzeit->setText(QString::number(inhalt->bestzeit()));
            ui->bestzeit->setToolTip("");
        }else{
            ui->bestzeit->setText("//");
            ui->bestzeit->setToolTip("Es gibt noch keine Bestzeit.");
        }
    }else{
        ui->zeile->setText(0);
        ui->spalte->setText(0);
        ui->bomben->setText(0);
        ui->gewonnen->setText(0);
        ui->verloren->setText(0);
        ui->verhaeltnis->setStretch(0, 1);
        ui->verhaeltnis->setStretch(1, 1);
        ui->anzahl->setText(0);
        ui->bestzeit->setText(0);
    }
}

//Weitergabe des linken Teils der ui
QWidget *Statistikzeile::links()
{
    return ui->links;
}

//Weitergabe des mittleren Teils der ui
QWidget *Statistikzeile::mitte()
{
    return ui->mitte;
}

//Weitergabe des rechten Teils der ui
QWidget *Statistikzeile::rechts()
{
    return ui->rechts;
}

//Destruktor der Klasse Statistikzeile
Statistikzeile::~Statistikzeile()
{
    delete ui;
}
