#include "statistikdialog.h"
#include "ui_statistikdialog.h"

#include "statistikspeicher.h"
#include "statistikeintrag.h"
#include "statistikzeile.h"
#include <QTimer>

Statistikdialog::Statistikdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Statistikdialog)
{
    ui->setupUi(this);

    foreach (Statistikeintrag *eintrag, Statistikspeicher::instance().eintraege())
    {
        ui->behaelter->addWidget(new Statistikzeile(eintrag, ui->behaelter_widget));
    }

    QTimer::singleShot(100, [=] { adjustSize(); });
}

Statistikdialog::~Statistikdialog()
{
    delete ui;
}
