/********************************************************************************
** Form generated from reading UI file 'hilfe.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HILFE_H
#define UI_HILFE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Hilfe
{
public:
    QLabel *linksklick_label;
    QLabel *rechtsklick_label;
    QLabel *mitte_label;
    QDialogButtonBox *ok_button;

    void setupUi(QDialog *Hilfe)
    {
        if (Hilfe->objectName().isEmpty())
            Hilfe->setObjectName(QString::fromUtf8("Hilfe"));
        Hilfe->resize(400, 300);
        linksklick_label = new QLabel(Hilfe);
        linksklick_label->setObjectName(QString::fromUtf8("linksklick_label"));
        linksklick_label->setGeometry(QRect(90, 40, 281, 17));
        rechtsklick_label = new QLabel(Hilfe);
        rechtsklick_label->setObjectName(QString::fromUtf8("rechtsklick_label"));
        rechtsklick_label->setGeometry(QRect(90, 90, 191, 17));
        mitte_label = new QLabel(Hilfe);
        mitte_label->setObjectName(QString::fromUtf8("mitte_label"));
        mitte_label->setGeometry(QRect(90, 150, 251, 17));
        ok_button = new QDialogButtonBox(Hilfe);
        ok_button->setObjectName(QString::fromUtf8("ok_button"));
        ok_button->setGeometry(QRect(180, 250, 189, 25));

        retranslateUi(Hilfe);

        QMetaObject::connectSlotsByName(Hilfe);
    } // setupUi

    void retranslateUi(QDialog *Hilfe)
    {
        Hilfe->setWindowTitle(QApplication::translate("Hilfe", "Dialog", nullptr));
        linksklick_label->setText(QApplication::translate("Hilfe", "Linksklick: Feld aufdecken", nullptr));
        rechtsklick_label->setText(QApplication::translate("Hilfe", "Rechtsklick: Feld markieren", nullptr));
        mitte_label->setText(QApplication::translate("Hilfe", "Mittelmausklick: Flagge entfernen", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Hilfe: public Ui_Hilfe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HILFE_H
