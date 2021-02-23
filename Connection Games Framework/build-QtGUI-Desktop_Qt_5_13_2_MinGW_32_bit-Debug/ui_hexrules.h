/********************************************************************************
** Form generated from reading UI file 'hexrules.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HEXRULES_H
#define UI_HEXRULES_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_HexRules
{
public:
    QPushButton *Back;

    void setupUi(QFrame *HexRules)
    {
        if (HexRules->objectName().isEmpty())
            HexRules->setObjectName(QString::fromUtf8("HexRules"));
        HexRules->resize(570, 780);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../GUI pictures/bee-and-dripping-honeycomb-sticker-1561735216.3313851.png"), QSize(), QIcon::Normal, QIcon::Off);
        HexRules->setWindowIcon(icon);
        Back = new QPushButton(HexRules);
        Back->setObjectName(QString::fromUtf8("Back"));
        Back->setGeometry(QRect(400, 680, 131, 71));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../GUI pictures/HexBack.png"), QSize(), QIcon::Normal, QIcon::Off);
        Back->setIcon(icon1);
        Back->setIconSize(QSize(150, 230));
        Back->setFlat(true);

        retranslateUi(HexRules);

        QMetaObject::connectSlotsByName(HexRules);
    } // setupUi

    void retranslateUi(QFrame *HexRules)
    {
        HexRules->setWindowTitle(QCoreApplication::translate("HexRules", "Hex Rules", nullptr));
        Back->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HexRules: public Ui_HexRules {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEXRULES_H
