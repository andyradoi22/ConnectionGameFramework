/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QPushButton *YButton;
    QPushButton *HexButton;
    QPushButton *HavannahButton;
    QPushButton *ExitButton;

    void setupUi(QFrame *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName(QString::fromUtf8("MainMenu"));
        MainMenu->resize(570, 780);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../GUI pictures/bee-and-dripping-honeycomb-sticker-1561735216.3313851.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainMenu->setWindowIcon(icon);
        MainMenu->setFrameShape(QFrame::NoFrame);
        YButton = new QPushButton(MainMenu);
        YButton->setObjectName(QString::fromUtf8("YButton"));
        YButton->setGeometry(QRect(160, 67, 251, 111));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../GUI pictures/Y.png"), QSize(), QIcon::Normal, QIcon::Off);
        YButton->setIcon(icon1);
        YButton->setIconSize(QSize(400, 250));
        YButton->setFlat(true);
        HexButton = new QPushButton(MainMenu);
        HexButton->setObjectName(QString::fromUtf8("HexButton"));
        HexButton->setGeometry(QRect(160, 245, 251, 111));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../GUI pictures/Hex.png"), QSize(), QIcon::Normal, QIcon::Off);
        HexButton->setIcon(icon2);
        HexButton->setIconSize(QSize(400, 250));
        HexButton->setFlat(true);
        HavannahButton = new QPushButton(MainMenu);
        HavannahButton->setObjectName(QString::fromUtf8("HavannahButton"));
        HavannahButton->setGeometry(QRect(160, 423, 251, 111));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../GUI pictures/Havannah.png"), QSize(), QIcon::Normal, QIcon::Off);
        HavannahButton->setIcon(icon3);
        HavannahButton->setIconSize(QSize(400, 250));
        HavannahButton->setFlat(true);
        ExitButton = new QPushButton(MainMenu);
        ExitButton->setObjectName(QString::fromUtf8("ExitButton"));
        ExitButton->setGeometry(QRect(160, 601, 251, 111));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("../GUI pictures/ButonExit.png"), QSize(), QIcon::Normal, QIcon::Off);
        ExitButton->setIcon(icon4);
        ExitButton->setIconSize(QSize(400, 250));
        ExitButton->setFlat(true);

        retranslateUi(MainMenu);

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QFrame *MainMenu)
    {
        MainMenu->setWindowTitle(QCoreApplication::translate("MainMenu", "Connection Games", nullptr));
        YButton->setText(QString());
        HexButton->setText(QString());
        HavannahButton->setText(QString());
        ExitButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
