#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include <QApplication>
#include "qmessagebox.h"
#include "QGraphicsWidget"
#include "QFrame"
#include "ymenu.h"
#include "hexmenu.h"
#include "havannahmenu.h"

#include <QFrame>

namespace Ui {
class MainMenu;
}

class MainMenu : public QFrame
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

private slots:
    void on_YButton_clicked();

    void on_HexButton_clicked();

    void on_HavannahButton_clicked();

    void on_ExitButton_clicked();


private:
    Ui::MainMenu *ui;
};

#endif // MAINMENU_H
