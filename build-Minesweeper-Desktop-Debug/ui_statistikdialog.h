/********************************************************************************
** Form generated from reading UI file 'statistikdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTIKDIALOG_H
#define UI_STATISTIKDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Statistikdialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QScrollArea *behaelter_widget;
    QWidget *behaelter;
    QGridLayout *gridLayout;

    void setupUi(QDialog *Statistikdialog)
    {
        if (Statistikdialog->objectName().isEmpty())
            Statistikdialog->setObjectName(QString::fromUtf8("Statistikdialog"));
        Statistikdialog->resize(600, 115);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Statistikdialog->sizePolicy().hasHeightForWidth());
        Statistikdialog->setSizePolicy(sizePolicy);
        Statistikdialog->setMinimumSize(QSize(600, 0));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/icons/Bombe.png"), QSize(), QIcon::Normal, QIcon::Off);
        Statistikdialog->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(Statistikdialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(Statistikdialog);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(label);

        behaelter_widget = new QScrollArea(Statistikdialog);
        behaelter_widget->setObjectName(QString::fromUtf8("behaelter_widget"));
        behaelter_widget->setWidgetResizable(true);
        behaelter = new QWidget();
        behaelter->setObjectName(QString::fromUtf8("behaelter"));
        behaelter->setGeometry(QRect(0, 0, 580, 72));
        gridLayout = new QGridLayout(behaelter);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        behaelter_widget->setWidget(behaelter);

        verticalLayout->addWidget(behaelter_widget);


        retranslateUi(Statistikdialog);

        QMetaObject::connectSlotsByName(Statistikdialog);
    } // setupUi

    void retranslateUi(QDialog *Statistikdialog)
    {
        Statistikdialog->setWindowTitle(QApplication::translate("Statistikdialog", "Statistik", nullptr));
        label->setText(QApplication::translate("Statistikdialog", "Statistik:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Statistikdialog: public Ui_Statistikdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTIKDIALOG_H
