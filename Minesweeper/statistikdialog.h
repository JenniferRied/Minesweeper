#ifndef STATISTIKDIALOG_H
#define STATISTIKDIALOG_H

#include <QDialog>

namespace Ui {
class Statistikdialog;
}

class Statistikdialog : public QDialog
{
    Q_OBJECT

public:
    explicit Statistikdialog(QWidget *parent = nullptr);
    ~Statistikdialog();

private:
    Ui::Statistikdialog *ui;
};

#endif // STATISTIKDIALOG_H
