#include "minesweeper.h"
#include "ui_minesweeper.h"
#include "hilfe.h"
#include "spielbrett.h"
#include <QVBoxLayout>

Minesweeper::Minesweeper(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Minesweeper)
    , mainFrame(nullptr)
{
    ui->setupUi(this);
    reihen = 15;
    spalten = 15;

    initialisieren();

    connect(ui->actionHilfe, SIGNAL(triggered()), this, SLOT(hilfe_oeffnen()));
}

void Minesweeper::hilfe_oeffnen()
{
   Hilfe *hilfe = new Hilfe();
   hilfe->show();
}

void Minesweeper::initialisieren()
{


    spielbrett = new Spielbrett(reihen,spalten, ui->haupt_frame, ui->spielbrett_gridLayout);
    auto haupt_Frame_Layout = new QVBoxLayout;

    connect(spielbrett, &Spielbrett::initialisiert, this, &Minesweeper::starte_spiel, Qt::UniqueConnection);

    haupt_Frame_Layout->addWidget(spielbrett);


    haupt_Frame_Layout->setSizeConstraint(QLayout::SetNoConstraint);



}

Minesweeper::~Minesweeper()
{
    delete ui;
}

