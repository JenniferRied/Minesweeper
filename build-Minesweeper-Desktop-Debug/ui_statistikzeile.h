/********************************************************************************
** Form generated from reading UI file 'statistikzeile.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTIKZEILE_H
#define UI_STATISTIKZEILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Statistikzeile
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *links;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLabel *zeile;
    QLabel *label_2;
    QLabel *spalte;
    QLabel *label_3;
    QLabel *bomben;
    QWidget *mitte;
    QHBoxLayout *verhaeltnis;
    QLabel *gewonnen;
    QLabel *verloren;
    QWidget *rechts;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLabel *anzahl;
    QLabel *label_6;
    QLabel *bestzeit;

    void setupUi(QWidget *Statistikzeile)
    {
        if (Statistikzeile->objectName().isEmpty())
            Statistikzeile->setObjectName(QString::fromUtf8("Statistikzeile"));
        Statistikzeile->resize(600, 40);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Statistikzeile->sizePolicy().hasHeightForWidth());
        Statistikzeile->setSizePolicy(sizePolicy);
        Statistikzeile->setMinimumSize(QSize(600, 0));
        horizontalLayout = new QHBoxLayout(Statistikzeile);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(2, 0, 2, 0);
        links = new QWidget(Statistikzeile);
        links->setObjectName(QString::fromUtf8("links"));
        horizontalLayout_3 = new QHBoxLayout(links);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(links);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        zeile = new QLabel(links);
        zeile->setObjectName(QString::fromUtf8("zeile"));

        horizontalLayout_3->addWidget(zeile);

        label_2 = new QLabel(links);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        spalte = new QLabel(links);
        spalte->setObjectName(QString::fromUtf8("spalte"));

        horizontalLayout_3->addWidget(spalte);

        label_3 = new QLabel(links);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        bomben = new QLabel(links);
        bomben->setObjectName(QString::fromUtf8("bomben"));

        horizontalLayout_3->addWidget(bomben);


        horizontalLayout->addWidget(links);

        mitte = new QWidget(Statistikzeile);
        mitte->setObjectName(QString::fromUtf8("mitte"));
        verhaeltnis = new QHBoxLayout(mitte);
        verhaeltnis->setSpacing(0);
        verhaeltnis->setObjectName(QString::fromUtf8("verhaeltnis"));
        verhaeltnis->setSizeConstraint(QLayout::SetMaximumSize);
        verhaeltnis->setContentsMargins(5, -1, 5, -1);
        gewonnen = new QLabel(mitte);
        gewonnen->setObjectName(QString::fromUtf8("gewonnen"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(gewonnen->sizePolicy().hasHeightForWidth());
        gewonnen->setSizePolicy(sizePolicy1);
        gewonnen->setStyleSheet(QString::fromUtf8("background-color: #99ff99;\n"
"color: black;\n"
""));

        verhaeltnis->addWidget(gewonnen);

        verloren = new QLabel(mitte);
        verloren->setObjectName(QString::fromUtf8("verloren"));
        sizePolicy1.setHeightForWidth(verloren->sizePolicy().hasHeightForWidth());
        verloren->setSizePolicy(sizePolicy1);
        verloren->setStyleSheet(QString::fromUtf8("background-color: #990000;\n"
"color: white;"));
        verloren->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verhaeltnis->addWidget(verloren);

        verhaeltnis->setStretch(0, 4);
        verhaeltnis->setStretch(1, 5);

        horizontalLayout->addWidget(mitte);

        rechts = new QWidget(Statistikzeile);
        rechts->setObjectName(QString::fromUtf8("rechts"));
        horizontalLayout_2 = new QHBoxLayout(rechts);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(rechts);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        anzahl = new QLabel(rechts);
        anzahl->setObjectName(QString::fromUtf8("anzahl"));

        horizontalLayout_2->addWidget(anzahl);

        label_6 = new QLabel(rechts);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_2->addWidget(label_6);

        bestzeit = new QLabel(rechts);
        bestzeit->setObjectName(QString::fromUtf8("bestzeit"));

        horizontalLayout_2->addWidget(bestzeit);


        horizontalLayout->addWidget(rechts);


        retranslateUi(Statistikzeile);

        QMetaObject::connectSlotsByName(Statistikzeile);
    } // setupUi

    void retranslateUi(QWidget *Statistikzeile)
    {
        Statistikzeile->setWindowTitle(QApplication::translate("Statistikzeile", "Form", nullptr));
        label->setText(QApplication::translate("Statistikzeile", "L\303\244nge: ", nullptr));
        zeile->setText(QApplication::translate("Statistikzeile", "1", nullptr));
        label_2->setText(QApplication::translate("Statistikzeile", ", Breite: ", nullptr));
        spalte->setText(QApplication::translate("Statistikzeile", "2", nullptr));
        label_3->setText(QApplication::translate("Statistikzeile", ", Bomben: ", nullptr));
        bomben->setText(QApplication::translate("Statistikzeile", "3", nullptr));
        gewonnen->setText(QApplication::translate("Statistikzeile", "4", nullptr));
        verloren->setText(QApplication::translate("Statistikzeile", "5", nullptr));
        label_4->setText(QApplication::translate("Statistikzeile", "von ", nullptr));
        anzahl->setText(QApplication::translate("Statistikzeile", "6", nullptr));
        label_6->setText(QApplication::translate("Statistikzeile", ", Bestzeit: ", nullptr));
        bestzeit->setText(QApplication::translate("Statistikzeile", "7:25", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Statistikzeile: public Ui_Statistikzeile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTIKZEILE_H
