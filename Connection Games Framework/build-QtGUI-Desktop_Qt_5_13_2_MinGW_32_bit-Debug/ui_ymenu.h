/********************************************************************************
** Form generated from reading UI file 'ymenu.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_YMENU_H
#define UI_YMENU_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_YMenu
{
public:
    QPushButton *YPlayButton;
    QPushButton *YRulesButton;
    QPushButton *YBackButton;

    void setupUi(QFrame *YMenu)
    {
        if (YMenu->objectName().isEmpty())
            YMenu->setObjectName(QString::fromUtf8("YMenu"));
        YMenu->resize(570, 780);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../GUI pictures/bee-and-dripping-honeycomb-sticker-1561735216.3313851.png"), QSize(), QIcon::Normal, QIcon::Off);
        YMenu->setWindowIcon(icon);
        YPlayButton = new QPushButton(YMenu);
        YPlayButton->setObjectName(QString::fromUtf8("YPlayButton"));
        YPlayButton->setGeometry(QRect(160, 142, 251, 111));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../GUI pictures/YPlay.png"), QSize(), QIcon::Normal, QIcon::Off);
        YPlayButton->setIcon(icon1);
        YPlayButton->setIconSize(QSize(400, 250));
        YPlayButton->setFlat(true);
        YRulesButton = new QPushButton(YMenu);
        YRulesButton->setObjectName(QString::fromUtf8("YRulesButton"));
        YRulesButton->setGeometry(QRect(160, 335, 251, 111));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../GUI pictures/YRules.png"), QSize(), QIcon::Normal, QIcon::Off);
        YRulesButton->setIcon(icon2);
        YRulesButton->setIconSize(QSize(400, 250));
        YRulesButton->setFlat(true);
        YBackButton = new QPushButton(YMenu);
        YBackButton->setObjectName(QString::fromUtf8("YBackButton"));
        YBackButton->setGeometry(QRect(160, 518, 251, 111));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../GUI pictures/YBack.png"), QSize(), QIcon::Normal, QIcon::Off);
        YBackButton->setIcon(icon3);
        YBackButton->setIconSize(QSize(400, 250));
        YBackButton->setFlat(true);

        retranslateUi(YMenu);

        QMetaObject::connectSlotsByName(YMenu);
    } // setupUi

    void retranslateUi(QFrame *YMenu)
    {
        YMenu->setWindowTitle(QCoreApplication::translate("YMenu", "Y Game", nullptr));
        YPlayButton->setText(QString());
        YRulesButton->setText(QString());
        YBackButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class YMenu: public Ui_YMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_YMENU_H
