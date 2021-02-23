/********************************************************************************
** Form generated from reading UI file 'hexmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HEXMENU_H
#define UI_HEXMENU_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_HexMenu
{
public:
    QPushButton *HexPlayButton;
    QPushButton *HexRulesButton;
    QPushButton *HexBackButton;

    void setupUi(QFrame *HexMenu)
    {
        if (HexMenu->objectName().isEmpty())
            HexMenu->setObjectName(QString::fromUtf8("HexMenu"));
        HexMenu->resize(570, 780);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../GUI pictures/bee-and-dripping-honeycomb-sticker-1561735216.3313851.png"), QSize(), QIcon::Normal, QIcon::Off);
        HexMenu->setWindowIcon(icon);
        HexPlayButton = new QPushButton(HexMenu);
        HexPlayButton->setObjectName(QString::fromUtf8("HexPlayButton"));
        HexPlayButton->setGeometry(QRect(160, 142, 251, 111));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../GUI pictures/HexPlay.png"), QSize(), QIcon::Normal, QIcon::Off);
        HexPlayButton->setIcon(icon1);
        HexPlayButton->setIconSize(QSize(400, 250));
        HexPlayButton->setFlat(true);
        HexRulesButton = new QPushButton(HexMenu);
        HexRulesButton->setObjectName(QString::fromUtf8("HexRulesButton"));
        HexRulesButton->setGeometry(QRect(160, 335, 251, 111));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../GUI pictures/HexRules.png"), QSize(), QIcon::Normal, QIcon::Off);
        HexRulesButton->setIcon(icon2);
        HexRulesButton->setIconSize(QSize(400, 250));
        HexRulesButton->setFlat(true);
        HexBackButton = new QPushButton(HexMenu);
        HexBackButton->setObjectName(QString::fromUtf8("HexBackButton"));
        HexBackButton->setGeometry(QRect(160, 518, 251, 111));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../GUI pictures/HexBack.png"), QSize(), QIcon::Normal, QIcon::Off);
        HexBackButton->setIcon(icon3);
        HexBackButton->setIconSize(QSize(400, 250));
        HexBackButton->setFlat(true);

        retranslateUi(HexMenu);

        QMetaObject::connectSlotsByName(HexMenu);
    } // setupUi

    void retranslateUi(QFrame *HexMenu)
    {
        HexMenu->setWindowTitle(QCoreApplication::translate("HexMenu", "Hex Game", nullptr));
        HexPlayButton->setText(QString());
        HexRulesButton->setText(QString());
        HexBackButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HexMenu: public Ui_HexMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEXMENU_H
