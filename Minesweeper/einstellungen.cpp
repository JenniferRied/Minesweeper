#include "einstellungen.h"
#include "ui_einstellungen.h"
#include "minesweeper.h"

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

void Einstellungen::abbrechen()
{
    QDialog::close();
}

bool Einstellungen::bestaetigung()
{
    bestaetigen = true;
    return bestaetigen;
}

bool Einstellungen::abbruch()
{
    bestaetigen = false;
    return bestaetigen;
}

bool Einstellungen::abschluss()
{
    return bestaetigen;
}

void Einstellungen::closeEvent(QCloseEvent *event)
{
    emit einstellungen_geschlossen();
    event->accept();
}

unsigned int Einstellungen::get_spaltenanzahl()
{
    return ui->spaltenanzahl_edit->text().toInt();
}

unsigned int Einstellungen::get_reihenanzahl()
{
    return ui->reihenanzahl_edit->text().toInt();
}

unsigned int Einstellungen::get_minenanzahl()
{
    return ui->minenanzahl_edit->text().toInt();
}

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

void Einstellungen::uebernehmen()
{
    get_minenanzahl();
    get_reihenanzahl();
    get_spaltenanzahl();
    get_schwierigkeit();
    QDialog::close();
}

Einstellungen::~Einstellungen()
{
    delete ui;
}
