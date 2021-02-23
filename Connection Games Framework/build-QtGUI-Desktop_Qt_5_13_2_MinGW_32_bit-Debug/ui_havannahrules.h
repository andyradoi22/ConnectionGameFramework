/********************************************************************************
** Form generated from reading UI file 'havannahrules.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HAVANNAHRULES_H
#define UI_HAVANNAHRULES_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_HavannahRules
{
public:
    QPushButton *Back;

    void setupUi(QFrame *HavannahRules)
    {
        if (HavannahRules->objectName().isEmpty())
            HavannahRules->setObjectName(QString::fromUtf8("HavannahRules"));
        HavannahRules->resize(570, 780);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../GUI pictures/bee-and-dripping-honeycomb-sticker-1561735216.3313851.png"), QSize(), QIcon::Normal, QIcon::Off);
        HavannahRules->setWindowIcon(icon);
        Back = new QPushButton(HavannahRules);
        Back->setObjectName(QString::fromUtf8("Back"));
        Back->setGeometry(QRect(374, 692, 131, 61));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../GUI pictures/HavannahBack.png"), QSize(), QIcon::Normal, QIcon::Off);
        Back->setIcon(icon1);
        Back->setIconSize(QSize(150, 230));
        Back->setFlat(true);

        retranslateUi(HavannahRules);

        QMetaObject::connectSlotsByName(HavannahRules);
    } // setupUi

    void retranslateUi(QFrame *HavannahRules)
    {
        HavannahRules->setWindowTitle(QCoreApplication::translate("HavannahRules", "Havannah Rules", nullptr));
        Back->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HavannahRules: public Ui_HavannahRules {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HAVANNAHRULES_H
