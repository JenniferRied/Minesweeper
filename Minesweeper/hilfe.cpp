#include "hilfe.h"
#include "ui_hilfe.h"

Hilfe::Hilfe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Hilfe)
{
    ui->setupUi(this);
}

Hilfe::~Hilfe()
{
    delete ui;
}
