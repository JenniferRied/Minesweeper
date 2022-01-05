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
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Minesweeper
{
public:
    QAction *actionEinstellungen;
    QAction *actionStatistik;
    QAction *actionHilfe;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *neu_button;
    QSpacerItem *horizontalSpacer;
    QPushButton *pause_button;
    QLCDNumber *Zeitanzeige;
    QLCDNumber *flaggen_anzahl;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *beenden_button;
    QFrame *haupt_frame;
    QGridLayout *gridLayout;
    QWidget *spielbrett_widget;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *spielbrett_gridLayout;
    QMenuBar *menubar;
    QMenu *menuMen;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Minesweeper)
    {
        if (Minesweeper->objectName().isEmpty())
            Minesweeper->setObjectName(QString::fromUtf8("Minesweeper"));
        Minesweeper->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/icons/Bombe.png"), QSize(), QIcon::Normal, QIcon::Off);
        Minesweeper->setWindowIcon(icon);
        actionEinstellungen = new QAction(Minesweeper);
        actionEinstellungen->setObjectName(QString::fromUtf8("actionEinstellungen"));
        actionStatistik = new QAction(Minesweeper);
        actionStatistik->setObjectName(QString::fromUtf8("actionStatistik"));
        actionHilfe = new QAction(Minesweeper);
        actionHilfe->setObjectName(QString::fromUtf8("actionHilfe"));
        centralwidget = new QWidget(Minesweeper);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        neu_button = new QPushButton(centralwidget);
        neu_button->setObjectName(QString::fromUtf8("neu_button"));

        horizontalLayout->addWidget(neu_button);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pause_button = new QPushButton(centralwidget);
        pause_button->setObjectName(QString::fromUtf8("pause_button"));

        horizontalLayout->addWidget(pause_button);

        Zeitanzeige = new QLCDNumber(centralwidget);
        Zeitanzeige->setObjectName(QString::fromUtf8("Zeitanzeige"));

        horizontalLayout->addWidget(Zeitanzeige);

        flaggen_anzahl = new QLCDNumber(centralwidget);
        flaggen_anzahl->setObjectName(QString::fromUtf8("flaggen_anzahl"));

        horizontalLayout->addWidget(flaggen_anzahl);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        beenden_button = new QPushButton(centralwidget);
        beenden_button->setObjectName(QString::fromUtf8("beenden_button"));

        horizontalLayout->addWidget(beenden_button);


        verticalLayout->addLayout(horizontalLayout);

        haupt_frame = new QFrame(centralwidget);
        haupt_frame->setObjectName(QString::fromUtf8("haupt_frame"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(haupt_frame->sizePolicy().hasHeightForWidth());
        haupt_frame->setSizePolicy(sizePolicy);
        haupt_frame->setFrameShape(QFrame::StyledPanel);
        haupt_frame->setFrameShadow(QFrame::Plain);
        gridLayout = new QGridLayout(haupt_frame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        spielbrett_widget = new QWidget(haupt_frame);
        spielbrett_widget->setObjectName(QString::fromUtf8("spielbrett_widget"));
        horizontalLayout_2 = new QHBoxLayout(spielbrett_widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        spielbrett_gridLayout = new QGridLayout();
        spielbrett_gridLayout->setSpacing(0);
        spielbrett_gridLayout->setObjectName(QString::fromUtf8("spielbrett_gridLayout"));
        spielbrett_gridLayout->setSizeConstraint(QLayout::SetFixedSize);

        horizontalLayout_2->addLayout(spielbrett_gridLayout);


        gridLayout->addWidget(spielbrett_widget, 0, 0, 1, 1);


        verticalLayout->addWidget(haupt_frame);

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
        neu_button->setText(QApplication::translate("Minesweeper", "Neu", nullptr));
        pause_button->setText(QApplication::translate("Minesweeper", "Pause", nullptr));
        beenden_button->setText(QApplication::translate("Minesweeper", "Beenden", nullptr));
        menuMen->setTitle(QApplication::translate("Minesweeper", "Extras", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Minesweeper: public Ui_Minesweeper {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MINESWEEPER_H
