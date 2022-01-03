#include "minesweeper.h"
#include "ui_minesweeper.h"
#include "hilfe.h"
#include "spielbrett.h"
#include <QVBoxLayout>
#include "statistikdialog.h"
#include "statistikspeicher.h"
#include <iostream>

Minesweeper::Minesweeper(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Minesweeper)
    , mainFrame(nullptr)
{
    ui->setupUi(this);
    reihen = 20;
    spalten = 20;
    minen_anzahl = 100;

    initialisieren();
    Minesweeper::adjustSize();

    connect(ui->actionHilfe, SIGNAL(triggered()), this, SLOT(hilfe_oeffnen()));
    connect(ui->neu_button, SIGNAL(clicked()), this, SLOT(neu()));
    connect(ui->pause_button, SIGNAL(clicked()), this, SLOT(pausieren()));
    connect(ui->beenden_button, SIGNAL(clicked()), this, SLOT(beenden()));
    connect(ui->actionStatistik, SIGNAL(triggered()), this, SLOT(statistik_oeffnen()));
}

void Minesweeper::neu()
{
    timer_pausieren();
    pausiert = false;
    erster_klick = true;
    ui->Zeitanzeige->display(0);
    initialisieren();
}

void Minesweeper::hilfe_oeffnen()
{
   Hilfe *hilfe = new Hilfe();
   hilfe->show();
}

void Minesweeper::initialisieren()
{
    spielbrett = new Spielbrett(reihen,spalten, minen_anzahl, ui->haupt_frame, ui->spielbrett_gridLayout);
    auto haupt_Frame_Layout = new QVBoxLayout;

    connect(spielbrett, &Spielbrett::initialisiert, this, &Minesweeper::starte_spiel, Qt::UniqueConnection);
    connect(spielbrett, SIGNAL(klickt()), this, SLOT(kachel_geklickt()));

    haupt_Frame_Layout->addWidget(spielbrett);

    haupt_Frame_Layout->setSizeConstraint(QLayout::SetNoConstraint);
}

void Minesweeper::kachel_geklickt()
{
    if(erster_klick)
    {
        timer_starten();
        erster_klick = false;
    }
}

void Minesweeper::pausieren()
{
    if (pausiert)
    {
        timer_fortsetzen();
        ui->spielbrett_widget->show();
        ui->pause_button->setText("Pause");
    }else{
        ui->spielbrett_widget->hide();
        timer_pausieren();
        ui->pause_button->setText("Weiter");
    }
}

void Minesweeper::beenden()
{
    ui->Zeitanzeige->display(0);
    //alle felder aufdecken
    //spiel zählt als verloren: Statistikspeicher::instance().verloren(5,5,3);
}

void Minesweeper::statistik_oeffnen()
{
    timer_pausieren();
    ui->spielbrett_widget->hide();
    Statistikdialog statistik;
    statistik.exec();
    ui->spielbrett_widget->show();
    timer_fortsetzen();
}

void Minesweeper::timer_starten()
{
    if(timer != NULL)
    {
        delete timer;
        timer = NULL;
    }
    zeit = 0;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timer_timeout()));
    timer->start(1000);
}

void Minesweeper::timer_pausieren()
{
    if(timer && !pausiert)
    {
        timer->stop();
        pausiert = true;
    }
}

void Minesweeper::timer_fortsetzen()
{
    if(timer && pausiert)
    {
        timer->start();
        pausiert = false;
    }
}

void Minesweeper::timer_timeout()
{
    zeit++;
    ui->Zeitanzeige->display(zeit);
}

Minesweeper::~Minesweeper()
{
    delete ui;
}

