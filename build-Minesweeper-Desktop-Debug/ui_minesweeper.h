/********************************************************************************
** Form generated from reading UI file 'minesweeper.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MINESWEEPER_H
#define UI_MINESWEEPER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Minesweeper
{
public:
    QAction *actionEinstellungen;
    QAction *actionStatistik;
    QAction *actionHilfe;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuMen;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Minesweeper)
    {
        if (Minesweeper->objectName().isEmpty())
            Minesweeper->setObjectName(QString::fromUtf8("Minesweeper"));
        Minesweeper->resize(800, 600);
        actionEinstellungen = new QAction(Minesweeper);
        actionEinstellungen->setObjectName(QString::fromUtf8("actionEinstellungen"));
        actionStatistik = new QAction(Minesweeper);
        actionStatistik->setObjectName(QString::fromUtf8("actionStatistik"));
        actionHilfe = new QAction(Minesweeper);
        actionHilfe->setObjectName(QString::fromUtf8("actionHilfe"));
        centralwidget = new QWidget(Minesweeper);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Minesweeper->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Minesweeper);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuMen = new QMenu(menubar);
        menuMen->setObjectName(QString::fromUtf8("menuMen"));
        Minesweeper->setMenuBar(menubar);
        statusbar = new QStatusBar(Minesweeper);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Minesweeper->setStatusBar(statusbar);

        menubar->addAction(menuMen->menuAction());
        menuMen->addAction(actionEinstellungen);
        menuMen->addAction(actionStatistik);
        menuMen->addAction(actionHilfe);

        retranslateUi(Minesweeper);

        QMetaObject::connectSlotsByName(Minesweeper);
    } // setupUi

    void retranslateUi(QMainWindow *Minesweeper)
    {
        Minesweeper->setWindowTitle(QApplication::translate("Minesweeper", "Minesweeper", nullptr));
        actionEinstellungen->setText(QApplication::translate("Minesweeper", "Einstellungen", nullptr));
        actionStatistik->setText(QApplication::translate("Minesweeper", "Statistik", nullptr));
        actionHilfe->setText(QApplication::translate("Minesweeper", "Hilfe", nullptr));
        menuMen->setTitle(QApplication::translate("Minesweeper", "Men\303\274", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Minesweeper: public Ui_Minesweeper {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MINESWEEPER_H
