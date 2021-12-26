#ifndef STATISTIKZEILE_H
#define STATISTIKZEILE_H

#include "statistikeintrag.h"
#include <QWidget>

namespace Ui {
class Statistikzeile;
}

class Statistikzeile : public QWidget
{
    Q_OBJECT

public:
    explicit Statistikzeile(Statistikeintrag* inhalt , QWidget *parent = 0);
    ~Statistikzeile();

private:
    Ui::Statistikzeile *ui;
};

#endif // STATISTIKZEILE_H
