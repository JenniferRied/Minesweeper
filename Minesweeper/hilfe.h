#ifndef HILFE_H
#define HILFE_H

#include <QDialog>

namespace Ui {
class Hilfe;
}

class Hilfe : public QDialog
{
    Q_OBJECT

public:
    explicit Hilfe(QWidget *parent = nullptr);
    ~Hilfe();

private:
    Ui::Hilfe *ui;
};

#endif // HILFE_H
