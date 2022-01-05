/********************************************************************************
** Form generated from reading UI file 'einstellungen.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EINSTELLUNGEN_H
#define UI_EINSTELLUNGEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Einstellungen
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QSpacerItem *verticalSpacer_4;
    QComboBox *schwierigkeit_comboBox;
    QSpacerItem *horizontalSpacer;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_3;
    QLineEdit *reihenanzahl_edit;
    QSpacerItem *horizontalSpacer_2;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QSpacerItem *verticalSpacer;
    QLineEdit *spaltenanzahl_edit;
    QSpacerItem *horizontalSpacer_3;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_4;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *minenanzahl_edit;
    QSpacerItem *horizontalSpacer_4;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *abbrechen_button;
    QPushButton *akzeptieren_button;

    void setupUi(QDialog *Einstellungen)
    {
        if (Einstellungen->objectName().isEmpty())
            Einstellungen->setObjectName(QString::fromUtf8("Einstellungen"));
        Einstellungen->resize(400, 363);
        layoutWidget = new QWidget(Einstellungen);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 30, 278, 41));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_4->addWidget(label);

        verticalSpacer_4 = new QSpacerItem(5, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_4->addItem(verticalSpacer_4);

        schwierigkeit_comboBox = new QComboBox(layoutWidget);
        schwierigkeit_comboBox->addItem(QString());
        schwierigkeit_comboBox->addItem(QString());
        schwierigkeit_comboBox->addItem(QString());
        schwierigkeit_comboBox->addItem(QString());
        schwierigkeit_comboBox->setObjectName(QString::fromUtf8("schwierigkeit_comboBox"));
        schwierigkeit_comboBox->setEnabled(true);

        horizontalLayout_4->addWidget(schwierigkeit_comboBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        layoutWidget_2 = new QWidget(Einstellungen);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(50, 90, 278, 41));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_5->addWidget(label_2);

        verticalSpacer_3 = new QSpacerItem(5, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_5->addItem(verticalSpacer_3);

        reihenanzahl_edit = new QLineEdit(layoutWidget_2);
        reihenanzahl_edit->setObjectName(QString::fromUtf8("reihenanzahl_edit"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(reihenanzahl_edit->sizePolicy().hasHeightForWidth());
        reihenanzahl_edit->setSizePolicy(sizePolicy1);
        reihenanzahl_edit->setMaximumSize(QSize(86, 16777215));

        horizontalLayout_5->addWidget(reihenanzahl_edit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        layoutWidget_3 = new QWidget(Einstellungen);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(50, 150, 278, 41));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_6->addWidget(label_3);

        verticalSpacer = new QSpacerItem(0, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_6->addItem(verticalSpacer);

        spaltenanzahl_edit = new QLineEdit(layoutWidget_3);
        spaltenanzahl_edit->setObjectName(QString::fromUtf8("spaltenanzahl_edit"));
        sizePolicy1.setHeightForWidth(spaltenanzahl_edit->sizePolicy().hasHeightForWidth());
        spaltenanzahl_edit->setSizePolicy(sizePolicy1);
        spaltenanzahl_edit->setMaximumSize(QSize(86, 16777215));

        horizontalLayout_6->addWidget(spaltenanzahl_edit);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        layoutWidget_4 = new QWidget(Einstellungen);
        layoutWidget_4->setObjectName(QString::fromUtf8("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(50, 210, 278, 41));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);
        label_4->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_7->addWidget(label_4);

        verticalSpacer_2 = new QSpacerItem(9, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_7->addItem(verticalSpacer_2);

        minenanzahl_edit = new QLineEdit(layoutWidget_4);
        minenanzahl_edit->setObjectName(QString::fromUtf8("minenanzahl_edit"));
        sizePolicy1.setHeightForWidth(minenanzahl_edit->sizePolicy().hasHeightForWidth());
        minenanzahl_edit->setSizePolicy(sizePolicy1);
        minenanzahl_edit->setMaximumSize(QSize(86, 16777215));

        horizontalLayout_7->addWidget(minenanzahl_edit);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);

        horizontalLayoutWidget = new QWidget(Einstellungen);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(200, 290, 188, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        abbrechen_button = new QPushButton(horizontalLayoutWidget);
        abbrechen_button->setObjectName(QString::fromUtf8("abbrechen_button"));

        horizontalLayout->addWidget(abbrechen_button);

        akzeptieren_button = new QPushButton(horizontalLayoutWidget);
        akzeptieren_button->setObjectName(QString::fromUtf8("akzeptieren_button"));

        horizontalLayout->addWidget(akzeptieren_button);


        retranslateUi(Einstellungen);

        QMetaObject::connectSlotsByName(Einstellungen);
    } // setupUi

    void retranslateUi(QDialog *Einstellungen)
    {
        Einstellungen->setWindowTitle(QApplication::translate("Einstellungen", "Dialog", nullptr));
        label->setText(QApplication::translate("Einstellungen", "Schwierigkeit:", nullptr));
        schwierigkeit_comboBox->setItemText(0, QApplication::translate("Einstellungen", "Leicht", nullptr));
        schwierigkeit_comboBox->setItemText(1, QApplication::translate("Einstellungen", "Mittel", nullptr));
        schwierigkeit_comboBox->setItemText(2, QApplication::translate("Einstellungen", "Schwer", nullptr));
        schwierigkeit_comboBox->setItemText(3, QApplication::translate("Einstellungen", "Benutzerdefiniert", nullptr));

        label_2->setText(QApplication::translate("Einstellungen", "Reihenanzahl:", nullptr));
        label_3->setText(QApplication::translate("Einstellungen", "Spaltenanzahl:", nullptr));
        label_4->setText(QApplication::translate("Einstellungen", "Minenanzahl:", nullptr));
        abbrechen_button->setText(QApplication::translate("Einstellungen", "Abbrechen", nullptr));
        akzeptieren_button->setText(QApplication::translate("Einstellungen", "Akzeptieren", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Einstellungen: public Ui_Einstellungen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EINSTELLUNGEN_H
