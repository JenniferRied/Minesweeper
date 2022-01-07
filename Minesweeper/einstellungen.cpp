#include "einstellungen.h"
#include "ui_einstellungen.h"
#include "minesweeper.h"


//Konstruktor der Klasse Einstellungen.
Einstellungen::Einstellungen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Einstellungen)
{
    ui->setupUi(this);
    connect(ui->akzeptieren_button, SIGNAL(clicked()), this, SLOT(uebernehmen()));
    connect(ui->akzeptieren_button, SIGNAL(clicked()), this, SLOT(bestaetigung()));
    connect(ui->abbrechen_button, SIGNAL(clicked()), this, SLOT(abbrechen()));
    connect(ui->abbrechen_button, SIGNAL(clicked()), this, SLOT(abbruch()));
}

//Die Funktion wird bei Betätigen des Abbrechen-Buttons ausgeführt.
void Einstellungen::abbrechen()
{
    QDialog::close();
}

//Die Funktion soll wiedergeben, ob die eingegebenen Werte/der ausgewählte Schwierigkeitsgrad angewendet werden soll.
bool Einstellungen::bestaetigung()
{
    bestaetigen = true;
    return bestaetigen;
}

//Die Funktion soll wiedergeben, ob die eingegebenen Werte/der ausgewählte Schwierigkeitsgrad angewendet werden soll.
bool Einstellungen::abbruch()
{
    bestaetigen = false;
    return bestaetigen;
}

//Die Funktion soll wiedergeben, ob die eingegebenen Werte/der ausgewählte Schwierigkeitsgrad angewendet werden soll.
bool Einstellungen::abschluss()
{
    return bestaetigen;
}

void Einstellungen::closeEvent(QCloseEvent *event)
{
    emit einstellungen_geschlossen();
    event->accept();
}

//Die Funktion gibt die eingetragene Spaltenanzahl wieder.
unsigned int Einstellungen::get_spaltenanzahl()
{
    return ui->spaltenanzahl_edit->text().toInt();
}

//Die Funktion gibt die eingetragene Reihenanzahl wieder.
unsigned int Einstellungen::get_reihenanzahl()
{
    return ui->reihenanzahl_edit->text().toInt();
}

//Die Funktion gibt die eingetragene Minenanzahl wieder.
unsigned int Einstellungen::get_minenanzahl()
{
    return ui->minenanzahl_edit->text().toInt();
}


//Die Funktion liest den Schwierigkeitsgrad der Combobox aus und weißt ihr einen Integerwert zu, welcher in Minesweeper.cpp in einem Switch weiter verwendet wird.
unsigned int Einstellungen::get_schwierigkeit()
{
    unsigned int schwierigkeit;

    if(ui->schwierigkeit_comboBox->currentText() == "Leicht")
    {
        schwierigkeit = 0;
    }
    if(ui->schwierigkeit_comboBox->currentText() == "Mittel")
    {
        schwierigkeit = 1;
    }
    if(ui->schwierigkeit_comboBox->currentText() == "Schwer")
    {
        schwierigkeit = 2;
    }
    if(ui->schwierigkeit_comboBox->currentText() == "Benutzerdefiniert")
    {
        schwierigkeit = 3;
    }
    return schwierigkeit;
}

//Die Funktion soll die angegebenen Funktionen nach Betätigen des Akzeptieren-Buttons ausführen.
void Einstellungen::uebernehmen()
{
    get_minenanzahl();
    get_reihenanzahl();
    get_spaltenanzahl();
    get_schwierigkeit();
    QDialog::close();
}

//Destruktor der Klasse Einstellungen.
Einstellungen::~Einstellungen()
{
    delete ui;
}
