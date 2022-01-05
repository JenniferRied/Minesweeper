#include "einstellungen.h"
#include "ui_einstellungen.h"

Einstellungen::Einstellungen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Einstellungen)
{
    ui->setupUi(this);
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

void Einstellungen::abgebrochen()
{
    QDialog::close();
    emit closed();
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
    emit closed();
}

Einstellungen::~Einstellungen()
{
    delete ui;
}

void Einstellungen::on_abbrechen_button_clicked()
{
    abgebrochen();
}

void Einstellungen::on_akzeptieren_button_clicked()
{
    uebernehmen();
}
