#ifndef EINSTELLUNGEN_H
#define EINSTELLUNGEN_H

#include <QDialog>
#include <QObject>
#include <QCloseEvent>

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

    //void uebernehmen();

public slots:

    void uebernehmen();
    void abbrechen();
    bool bestaetigung();
    bool abbruch();
    bool abschluss();

signals:
    void einstellungen_geschlossen();

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::Einstellungen *ui;

    bool bestaetigen;
};
#endif // EINSTELLUNGEN_H
