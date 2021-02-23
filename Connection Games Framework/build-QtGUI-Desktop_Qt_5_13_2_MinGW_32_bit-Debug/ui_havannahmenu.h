/********************************************************************************
** Form generated from reading UI file 'havannahmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HAVANNAHMENU_H
#define UI_HAVANNAHMENU_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_HavannahMenu
{
public:
    QPushButton *HavRulesButton;
    QPushButton *HavPlayButton;
    QPushButton *HavBackButton;

    void setupUi(QFrame *HavannahMenu)
    {
        if (HavannahMenu->objectName().isEmpty())
            HavannahMenu->setObjectName(QString::fromUtf8("HavannahMenu"));
        HavannahMenu->resize(570, 780);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../GUI pictures/bee-and-dripping-honeycomb-sticker-1561735216.3313851.png"), QSize(), QIcon::Normal, QIcon::Off);
        HavannahMenu->setWindowIcon(icon);
        HavRulesButton = new QPushButton(HavannahMenu);
        HavRulesButton->setObjectName(QString::fromUtf8("HavRulesButton"));
        HavRulesButton->setGeometry(QRect(160, 335, 251, 111));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../GUI pictures/HavannahRules.png"), QSize(), QIcon::Normal, QIcon::Off);
        HavRulesButton->setIcon(icon1);
        HavRulesButton->setIconSize(QSize(400, 250));
        HavRulesButton->setFlat(true);
        HavPlayButton = new QPushButton(HavannahMenu);
        HavPlayButton->setObjectName(QString::fromUtf8("HavPlayButton"));
        HavPlayButton->setGeometry(QRect(160, 142, 251, 111));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../GUI pictures/HavannahPlay.png"), QSize(), QIcon::Normal, QIcon::Off);
        HavPlayButton->setIcon(icon2);
        HavPlayButton->setIconSize(QSize(400, 250));
        HavPlayButton->setFlat(true);
        HavBackButton = new QPushButton(HavannahMenu);
        HavBackButton->setObjectName(QString::fromUtf8("HavBackButton"));
        HavBackButton->setGeometry(QRect(160, 518, 251, 111));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../GUI pictures/HavannahBack.png"), QSize(), QIcon::Normal, QIcon::Off);
        HavBackButton->setIcon(icon3);
        HavBackButton->setIconSize(QSize(400, 250));
        HavBackButton->setFlat(true);

        retranslateUi(HavannahMenu);

        QMetaObject::connectSlotsByName(HavannahMenu);
    } // setupUi

    void retranslateUi(QFrame *HavannahMenu)
    {
        HavannahMenu->setWindowTitle(QCoreApplication::translate("HavannahMenu", "Havannah Game", nullptr));
        HavRulesButton->setText(QString());
        HavPlayButton->setText(QString());
        HavBackButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HavannahMenu: public Ui_HavannahMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HAVANNAHMENU_H
