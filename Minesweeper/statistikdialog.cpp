#include "statistikdialog.h"
#include "ui_statistikdialog.h"

#include "statistikspeicher.h"
#include "statistikeintrag.h"
#include "statistikzeile.h"
#include <QTimer>

//Konstruktor der Klasse Statistikdialog. Dabei wird für jeden Statisikeintrag in dem Statistikspeicher eine eigene Statistikzeile erzeugt. Und die Größe nochmal angepasst.
Statistikdialog::Statistikdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Statistikdialog)
{
    ui->setupUi(this);

    QGridLayout* behaeltnis_layout = static_cast<QGridLayout*>(ui->behaelter->layout());

    QList<Statistikeintrag *> eintraege = Statistikspeicher::instance().eintraege();
    for(int i = 0; i< eintraege.size(); i++)
    {
        Statistikeintrag* eintrag = eintraege.at(i);
        Statistikzeile* zeile = new Statistikzeile(eintrag, ui->behaelter_widget);
        behaeltnis_layout->addWidget(zeile->links(), i, 0);
        behaeltnis_layout->addWidget(zeile->mitte(), i, 1);
        behaeltnis_layout->addWidget(zeile->rechts(), i, 2);
    }

    QTimer::singleShot(100, [=] { adjustSize(); });
}

//Destruktor der Klasse Statistikdialog.
Statistikdialog::~Statistikdialog()
{
    delete ui;
}
