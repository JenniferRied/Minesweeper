#include "statistikspeicher.h"
#include <QFile>
#include <QFileInfo>
#include <QTextStream>
#include <QMessageBox>

const QString Statistikspeicher::zeilen_seperator = "\n";
const QString Statistikspeicher::werte_seperator = ";";
const QString Statistikspeicher::dateiname = "Statistik.csv";

Statistikspeicher::Statistikspeicher(QObject *parent)
    : QObject(parent)
{
    QFileInfo datei(dateiname);

    if (datei.exists())
    {
        QFile statistik_datei(dateiname);

        if (statistik_datei.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QString dateiinhalt(QTextStream(&statistik_datei).readAll());
            QStringList zeilen(dateiinhalt.split(zeilen_seperator));

            dateizeile_zu_listeneintrag(zeilen);
        }
    }
}

void Statistikspeicher::dateizeile_zu_listeneintrag(QStringList zeilen)
{
    foreach (QString zeile, zeilen)
    {
        QStringList elemente(zeile.split(werte_seperator));

        if (elemente.length() != 6)
        {
            //warnung, dass zu viele werte drin sind
            continue;
        }

        QList<int> werte;
        bool ok = true;

        foreach (QString part, elemente)
        {
            werte.append(part.trimmed().toInt(&ok));
            if (!ok) {
                //probleme bei konvertiertung in ints
                break;
            }
        }

        if (ok) {
            statistiklisteneintrag(werte);
        }
    }
}

void Statistikspeicher::statistiklisteneintrag(QList<int> werte)
{
    int zeilen = werte[0];
    int spalten = werte[1];
    int bomben = werte[2];
    int gewonnen = werte[3];
    int verloren = werte[4];
    int bestzeit = werte[5];
    statistikliste.append(new Statistikeintrag(zeilen, spalten, bomben, gewonnen, verloren, bestzeit));
}

Statistikspeicher& Statistikspeicher::instance()
{
    static Statistikspeicher instance;
    return instance;
}

QList<Statistikeintrag *> Statistikspeicher::eintraege()
{
    return statistikliste;
}

void Statistikspeicher::gewonnen(int zeile, int spalte, int bomben, int zeit)
{
    foreach(Statistikeintrag* eintrag, statistikliste)
    {
        if (eintrag->zeilen() == zeile && eintrag->spalten() == spalte && eintrag->bomben() == bomben)
        {
            eintrag->zunahme_gewonnen(zeit);
            return;
        }else{
            continue;
        }
    }

    statistikliste.append(new Statistikeintrag(zeile, spalte, bomben, 1, 0, zeit));
}

void Statistikspeicher::verloren(int zeile, int spalte, int bomben)
{
    foreach(Statistikeintrag* eintrag, statistikliste)
    {
        if (eintrag->zeilen() == zeile && eintrag->spalten() == spalte && eintrag->bomben() == bomben)
        {
            eintrag->zunahme_verloren();
            return;
        }else{
            continue;
        }
    }

    statistikliste.append(new Statistikeintrag(zeile, spalte, bomben, 0, 1));
}

Statistikspeicher::~Statistikspeicher()
{
    QStringList ausgabe;
    while (!statistikliste.empty())
    {
        Statistikeintrag* element = statistikliste.takeFirst();
        QStringList zeile;
        zeile << QString::number(element->zeilen());
        zeile << QString::number(element->spalten());
        zeile << QString::number(element->bomben());
        zeile << QString::number(element->gewonnen());
        zeile << QString::number(element->verloren());
        zeile << QString::number(element->bestzeit());
        ausgabe << zeile.join(werte_seperator);
    }

    QFile datei(dateiname);
    if (datei.open(QIODevice::WriteOnly))
    {
        QTextStream output(&datei);
        output << ausgabe.join(zeilen_seperator) << "\n";
    } else {
        QMessageBox fehlermeldung;
        fehlermeldung.critical(0, "Fehler", "Ein Fehler beim Öffnen der Datei ist aufgetreten.");
    }
}
