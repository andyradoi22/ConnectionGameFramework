#ifndef HEXMENU_H
#define HEXMENU_H

#include <QFrame>

namespace Ui {
class HexMenu;
}

class HexMenu : public QFrame
{
    Q_OBJECT

public:
    explicit HexMenu(QWidget *parent = nullptr);
    ~HexMenu();

private slots:
    void on_HexBackButton_clicked();

    void on_HexPlayButton_clicked();

    void on_HexRulesButton_clicked();

private:
    Ui::HexMenu *ui;
};

#endif // HEXMENU_H
