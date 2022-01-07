#include "statistikspeicher.h"
#include <QFile>
#include <QFileInfo>
#include <QTextStream>
#include <QMessageBox>

//Konstante Strings, die nicht veränderbar sind.
const QString Statistikspeicher::zeilen_seperator = "\n";
const QString Statistikspeicher::werte_seperator = ";";
const QString Statistikspeicher::dateiname = "Statistik.csv";

//Konstruktor der Klasse Statistikspeicher. Dabei wird wird die csv-Datein mit den Statistikdaten eingelesen
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

//Diese Funktion hat den Inhalt der Statistikdatei und Zeilen nacheinander durch, um Statistikeinträge daraus zu machen.
void Statistikspeicher::dateizeile_zu_listeneintrag(QStringList zeilen)
{
    foreach (QString zeile, zeilen)
    {
        QStringList elemente(zeile.split(werte_seperator));

        if (elemente.length() != 6)
        {
            continue;
        }

        QList<int> werte;
        bool ok = true;

        foreach (QString part, elemente)
        {
            werte.append(part.trimmed().toInt(&ok));
        }

        if (ok) {
            statistiklisteneintrag(werte);
        }
    }
}

//Die Funktion erstellt einen neuen Statistikeintrag und fügt sie der Liste aller Einträge hinzu.
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

//Statistikspeicher ist ein Singelton und hier kann man sich die instance des Statistikspeichers holen.
Statistikspeicher& Statistikspeicher::instance()
{
    static Statistikspeicher instance;
    return instance;
}

//Diese Funktion gibt die Liste aller Statistikeinträge zurück.
QList<Statistikeintrag *> Statistikspeicher::eintraege()
{
    return statistikliste;
}

//diese Funktion wird aufgerufen, wenn ein Spiel gewonnen wurde. Dabei wird geschaut,ob diese Einstellungen von zeilen, spalten und Bomben schon existieren
//und dort ein weiterer Sieg hinzugefügt werden muss, oder ein komplett neuer Statistikeintrag erstellt werden muss.
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

//diese Funktion wird aufgerufen, wenn ein Spiel verloren wurde. Dabei wird geschaut,ob diese Einstellungen von zeilen, spalten und Bomben schon existieren
//und dort nur eine weitere Niederlage hinzugefügt werden muss, oder ein komplett neuer Statistikeintrag erstellt werden muss.
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

//destruktor der Klasse Statistikspeicher. Dabei werden die vorhandenen Statistikdaten in einer csv-Datei gespeichert.
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
        fehlermeldung.critical(0, "Fehler", "Beim Speichern der Statistikdatei sind Probleme aufgetreten.");
    }
}
