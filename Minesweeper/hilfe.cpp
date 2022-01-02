#include "hilfe.h"
#include "ui_hilfe.h"

Hilfe::Hilfe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Hilfe)
{
    ui->setupUi(this);

    QString button_stylesheet = "border: none";

    QIcon* links = new QIcon(":/new/icons/links.png");
    QIcon* rechts = new QIcon(":/new/icons/Rechts.png");
    QIcon* mitte = new QIcon(":/new/icons/Mitte.png");
    QIcon* beides = new QIcon(":/new/icons/Beides.png");

    QSize icon_size;
    icon_size.setWidth(50);
    icon_size.setHeight(50);

    ui->links_button->setIcon(*links);
    ui->links_button->setIconSize(icon_size);
    ui->links_button->setStyleSheet(button_stylesheet);

    ui->rechts_button->setIcon(*rechts);
    ui->rechts_button->setIconSize(icon_size);
    ui->rechts_button->setStyleSheet(button_stylesheet);

    ui->Mitte_button->setIcon(*mitte);
    ui->Mitte_button->setIconSize(icon_size);
    ui->Mitte_button->setStyleSheet(button_stylesheet);

    ui->beide_button->setIcon(*beides);
    ui->beide_button->setIconSize(icon_size);
    ui->beide_button->setStyleSheet(button_stylesheet);
}

Hilfe::~Hilfe()
{
    delete ui;
}
