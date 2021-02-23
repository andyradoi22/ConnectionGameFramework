/********************************************************************************
** Form generated from reading UI file 'yrules.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_YRULES_H
#define UI_YRULES_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_YRules
{
public:
    QPushButton *Back;

    void setupUi(QFrame *YRules)
    {
        if (YRules->objectName().isEmpty())
            YRules->setObjectName(QString::fromUtf8("YRules"));
        YRules->resize(570, 780);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../GUI pictures/bee-and-dripping-honeycomb-sticker-1561735216.3313851.png"), QSize(), QIcon::Normal, QIcon::Off);
        YRules->setWindowIcon(icon);
        Back = new QPushButton(YRules);
        Back->setObjectName(QString::fromUtf8("Back"));
        Back->setGeometry(QRect(354, 700, 131, 61));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../GUI pictures/YBack.png"), QSize(), QIcon::Normal, QIcon::Off);
        Back->setIcon(icon1);
        Back->setIconSize(QSize(150, 230));
        Back->setFlat(true);

        retranslateUi(YRules);

        QMetaObject::connectSlotsByName(YRules);
    } // setupUi

    void retranslateUi(QFrame *YRules)
    {
        YRules->setWindowTitle(QCoreApplication::translate("YRules", "Y Rules", nullptr));
        Back->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class YRules: public Ui_YRules {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_YRULES_H
