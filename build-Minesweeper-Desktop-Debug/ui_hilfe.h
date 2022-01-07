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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Hilfe
{
public:
    QDialogButtonBox *ok_button;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *links_button;
    QLabel *linksklick_label;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *rechts_button;
    QLabel *rechtsklick_label;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *Mitte_button;
    QLabel *mitte_label;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *beide_button;
    QLabel *label;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QDialog *Hilfe)
    {
        if (Hilfe->objectName().isEmpty())
            Hilfe->setObjectName(QString::fromUtf8("Hilfe"));
        Hilfe->resize(400, 300);
        Hilfe->setMaximumSize(QSize(16777215, 16777202));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/icons/Bombe.png"), QSize(), QIcon::Normal, QIcon::Off);
        Hilfe->setWindowIcon(icon);
        ok_button = new QDialogButtonBox(Hilfe);
        ok_button->setObjectName(QString::fromUtf8("ok_button"));
        ok_button->setGeometry(QRect(180, 250, 189, 25));
        verticalLayoutWidget = new QWidget(Hilfe);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 30, 341, 231));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        links_button = new QPushButton(verticalLayoutWidget);
        links_button->setObjectName(QString::fromUtf8("links_button"));

        horizontalLayout_4->addWidget(links_button);

        linksklick_label = new QLabel(verticalLayoutWidget);
        linksklick_label->setObjectName(QString::fromUtf8("linksklick_label"));

        horizontalLayout_4->addWidget(linksklick_label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        rechts_button = new QPushButton(verticalLayoutWidget);
        rechts_button->setObjectName(QString::fromUtf8("rechts_button"));

        horizontalLayout_3->addWidget(rechts_button);

        rechtsklick_label = new QLabel(verticalLayoutWidget);
        rechtsklick_label->setObjectName(QString::fromUtf8("rechtsklick_label"));

        horizontalLayout_3->addWidget(rechtsklick_label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Mitte_button = new QPushButton(verticalLayoutWidget);
        Mitte_button->setObjectName(QString::fromUtf8("Mitte_button"));

        horizontalLayout->addWidget(Mitte_button);

        mitte_label = new QLabel(verticalLayoutWidget);
        mitte_label->setObjectName(QString::fromUtf8("mitte_label"));

        horizontalLayout->addWidget(mitte_label);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        beide_button = new QPushButton(verticalLayoutWidget);
        beide_button->setObjectName(QString::fromUtf8("beide_button"));

        horizontalLayout_2->addWidget(beide_button);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setWordWrap(true);

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(Hilfe);

        QMetaObject::connectSlotsByName(Hilfe);
    } // setupUi

    void retranslateUi(QDialog *Hilfe)
    {
        Hilfe->setWindowTitle(QApplication::translate("Hilfe", "Hilfe", nullptr));
        links_button->setText(QString());
        linksklick_label->setText(QApplication::translate("Hilfe", "Linksklick: Feld aufdecken", nullptr));
        rechts_button->setText(QString());
        rechtsklick_label->setText(QApplication::translate("Hilfe", "Rechtsklick: Feld markieren", nullptr));
        Mitte_button->setText(QString());
        mitte_label->setText(QApplication::translate("Hilfe", "Mittelmausklick: Flagge entfernen", nullptr));
        beide_button->setText(QString());
        label->setText(QApplication::translate("Hilfe", "linksklick + rechtsklick: benachbarte                 Felder aufdecken", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Hilfe: public Ui_Hilfe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HILFE_H
