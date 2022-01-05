#ifndef EINSTELLUNGEN_H
#define EINSTELLUNGEN_H

#include <QDialog>
#include <QObject>

namespace Ui {
class Einstellungen;
}

class Einstellungen : public QDialog
{
    Q_OBJECT

public:

    explicit Einstellungen(QWidget *parent = nullptr);
    ~Einstellungen();

    unsigned int get_spaltenanzahl();
    unsigned int get_reihenanzahl();
    unsigned int get_minenanzahl();
    unsigned int get_schwierigkeit();

    void abgebrochen();
    void uebernehmen();

signals:
    void closed();

private slots:
    void on_abbrechen_button_clicked();

    void on_akzeptieren_button_clicked();

private:
    Ui::Einstellungen *ui;
};
#endif // EINSTELLUNGEN_H
