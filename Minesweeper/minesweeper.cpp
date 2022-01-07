#include "minesweeper.h"
#include "kachel.h"
#include "ui_minesweeper.h"
#include "hilfe.h"
#include "einstellungen.h"
#include "spielbrett.h"
#include <QVBoxLayout>
#include "statistikdialog.h"
#include "statistikspeicher.h"
#include <iostream>
#include <QAction>

//Konstruktor der Klasse Minesweeper.
Minesweeper::Minesweeper(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Minesweeper)
    , mainFrame(nullptr)
{
    ui->setupUi(this);
    reihen = 20;
    spalten = 20;
    minen_anzahl = 50;

    initialisieren();
    Minesweeper::adjustSize();


    connect(ui->actionHilfe, SIGNAL(triggered()), this, SLOT(hilfe_oeffnen()));
    connect(ui->neu_button, SIGNAL(clicked()), this, SLOT(neu()));
    connect(ui->pause_button, SIGNAL(clicked()), this, SLOT(pausieren()));
    connect(ui->beenden_button, SIGNAL(clicked()), this, SLOT(beenden()));
    connect(ui->actionStatistik, SIGNAL(triggered()), this, SLOT(statistik_oeffnen()));
    connect(ui->actionEinstellungen, SIGNAL(triggered()), this, SLOT(einstellungen_oeffnen()));
}

//Hier wird die Flaggenanzahl auf der Ui angezeigt

void Minesweeper::flaggen_zaehler(int anzahl)
{
    ui->flaggen_anzahl->display(anzahl);
}

//Wenn der Button neu geklickt wird, wird der timer angehalten und auf null gesetzt, zwei boolean-Werte auf den Anfangszustand gesetzt und das neue Spiel initialisiert.
void Minesweeper::neu()
{
    timer_pausieren();
    pausiert = false;
    erster_klick = true;
    ui->Zeitanzeige->display(0);
    ui->pause_button->setText("Pause");
    initialisieren();
}

//Hier wird das Hilfefenster geöffnet

void Minesweeper::hilfe_oeffnen()
{
    timer_pausieren();
    ui->spielbrett_widget->hide();
    Hilfe *hilfe = new Hilfe();
    hilfe->show();
    ui->spielbrett_widget->show();
    timer_fortsetzen();
}

//Hier wird das Einstellungsfenster geöffnet

void Minesweeper::einstellungen_oeffnen()
{
    Einstellungen *einstellungen = new Einstellungen();
    einstellungen->exec();
    if(einstellungen->abschluss() == true)
    {
    unsigned int schwierigkeit = einstellungen->get_schwierigkeit();
    unsigned int custom_reihen = einstellungen->get_reihenanzahl();
    unsigned int custom_spalten = einstellungen->get_spaltenanzahl();
    unsigned int custom_minen = einstellungen->get_minenanzahl();

    switch(schwierigkeit)
    {
    case 0:
        reihen = 9;
        spalten = 9;
        minen_anzahl = 10;
        break;
    case 1:
        reihen = 16;
        spalten = 16;
        minen_anzahl = 40;
        break;
    case 2:
        reihen = 16;
        spalten = 30;
        minen_anzahl = 99;
        break;
    case 3:
        reihen = custom_reihen;
        spalten = custom_spalten;
        minen_anzahl = custom_minen;
    default:
        break;
    }

    initialisieren();
    adjustSize();
    }
}

//Hier wird das Spielbrett initialisiert

void Minesweeper::initialisieren()
{
    if(spielbrett != nullptr)
    {
        delete spielbrett;
        spielbrett = nullptr;
    }

    spielbrett = new Spielbrett(reihen,spalten, minen_anzahl, ui->spielbrett_gridLayout);
    auto haupt_Frame_Layout = new QVBoxLayout;

    connect(spielbrett, &Spielbrett::initialisiert, this, &Minesweeper::starte_spiel, Qt::UniqueConnection);
    connect(spielbrett, SIGNAL(klickt()), this, SLOT(kachel_geklickt()));
    connect(spielbrett, SIGNAL(timer_anhalten()),this, SLOT(timer_pausieren()));

    haupt_Frame_Layout->addWidget(spielbrett);

    haupt_Frame_Layout->setSizeConstraint(QLayout::SetNoConstraint);
}

//Diese Funktion wird bei jeden Klick auf eine Kachel aufgerufen und wenn dieser Klick der erste war, wird der Timer gestartet.
void Minesweeper::kachel_geklickt()
{
    if(erster_klick)
    {
        timer_starten();
        erster_klick = false;
    }
}

//Bei Klick auf den Butteon pause, wird der Timer angehalten, das Spielfeld versteckt und der Text des Button auf weiter gesetzt.
//Bei erneuten Klick wird alles wieder auf den vorherigen Zustand gestellt.
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

//Wird der Button beenden geklickt, so wird der Timer pausiert und auf null gestellt, das Spielfeld aufgedeckt und das Spiel als verloren gewertet.
void Minesweeper::beenden()
{
    ui->Zeitanzeige->display(0);
    timer_pausieren();
    ui->pause_button->setText("Pause");
    //spielbrett->ende(true);
     spielbrett->verloren_animation();
}

//Bei dieser Funktion wird vor dem anzeigen des Statistikfensters der timer pausiert und das Spielfeld versteckt.
//Nach dem schließen des Fensters, wird das Spielbrett wieder gezeigt und der Timer läuft weiter.
void Minesweeper::statistik_oeffnen()
{
    timer_pausieren();
    ui->spielbrett_widget->hide();
    Statistikdialog statistik;
    statistik.exec();
    ui->spielbrett_widget->show();
    timer_fortsetzen();
}

//Diese Funktion erstellt einen neuen Timer und dieser sendet jede sekunde ein Signal, dass eine sekunde vergangen ist.
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

//Disee Funktion pausiert den Timer, wenn er noch nicht pausiert ist.
void Minesweeper::timer_pausieren()
{
    if(timer && !pausiert)
    {
        timer->stop();
        pausiert = true;
    }
}

//Diese Funktion setzt den timer fort, wennn er pausiert ist.
void Minesweeper::timer_fortsetzen()
{
    if(timer && pausiert)
    {
        timer->start();
        pausiert = false;
    }
}

//Diese Funktion wird jede Sekunde durch den Timer aufgerufen und setzt sie Zeit eins hoch und diese neue Zahl wird auf der Zeitanzeige gezeigt.
void Minesweeper::timer_timeout()
{
    zeit++;
    ui->Zeitanzeige->display(zeit);
}


//Destruktor der Klasse Minesweeper.
Minesweeper::~Minesweeper()
{
    delete ui;
}

