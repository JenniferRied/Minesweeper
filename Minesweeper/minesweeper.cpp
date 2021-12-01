#include "minesweeper.h"
#include "ui_minesweeper.h"
#include "hilfe.h"

Minesweeper::Minesweeper(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Minesweeper)
{
    ui->setupUi(this);

    connect(ui->actionHilfe, SIGNAL(triggered()), this, SLOT(hilfe_oeffnen()));
}

void Minesweeper::hilfe_oeffnen()
{
   Hilfe *hilfe = new Hilfe();
   hilfe->show();
}

Minesweeper::~Minesweeper()
{
    delete ui;
}

