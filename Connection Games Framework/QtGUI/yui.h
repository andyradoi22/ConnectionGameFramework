#ifndef YUI_H
#define YUI_H

#include <QFrame>
#include "ConnectionGames.h"
#include <QIcon>

namespace Ui {
class YUI;
}

class YUI : public QFrame
{
    int16_t turnCount=0;
    YGameLogic<Cells::Cell_Y> game;
    Player playerCurrent;
    std::pair<uint16_t, uint16_t> CurrentMove;
    std::pair<uint16_t, uint16_t> ROPMove;

    QIcon iconP1, iconP2;
    Q_OBJECT

public:
    void ChangeTurn();
    QIcon ChangeIcon();
    explicit YUI(QWidget *parent = nullptr);
    ~YUI();

private slots:
    void on_pushButton_clicked();

    void on_DaRop_clicked();

    void on_NuROP_clicked();

    void on_ButtonY_0_0_clicked();

    void on_ButtonY_1_0_clicked();

    void on_ButtonY_1_1_clicked();

    void on_ButtonY_2_0_clicked();

    void on_ButtonY_2_1_clicked();

    void on_ButtonY_2_2_clicked();

    void on_ButtonY_3_0_clicked();

    void on_ButtonY_3_1_clicked();

    void on_ButtonY_3_2_clicked();

    void on_ButtonY_3_3_clicked();

    void on_ButtonY_4_0_clicked();

    void on_ButtonY_4_1_clicked();

    void on_ButtonY_4_2_clicked();

    void on_ButtonY_4_3_clicked();

    void on_ButtonY_4_4_clicked();

    void on_ButtonY_5_0_clicked();

    void on_ButtonY_5_1_clicked();

    void on_ButtonY_5_2_clicked();

    void on_ButtonY_5_3_clicked();

    void on_ButtonY_5_4_clicked();

    void on_ButtonY_5_5_clicked();

    void on_ButtonY_6_0_clicked();

    void on_ButtonY_6_1_clicked();

    void on_ButtonY_6_2_clicked();

    void on_ButtonY_6_3_clicked();

    void on_ButtonY_6_4_clicked();

    void on_ButtonY_6_5_clicked();

    void on_ButtonY_6_6_clicked();

    void on_ButtonY_7_0_clicked();

    void on_ButtonY_7_1_clicked();

    void on_ButtonY_7_2_clicked();

    void on_ButtonY_7_3_clicked();

    void on_ButtonY_7_4_clicked();

    void on_ButtonY_7_5_clicked();

    void on_ButtonY_7_6_clicked();

    void on_ButtonY_7_7_clicked();

    void on_ButtonY_8_0_clicked();

    void on_ButtonY_8_1_clicked();

    void on_ButtonY_8_2_clicked();

    void on_ButtonY_8_3_clicked();

    void on_ButtonY_8_4_clicked();

    void on_ButtonY_8_5_clicked();

    void on_ButtonY_8_6_clicked();

    void on_ButtonY_8_7_clicked();

    void on_ButtonY_8_8_clicked();

    void on_ButtonY_9_0_clicked();

    void on_ButtonY_9_1_clicked();

    void on_ButtonY_9_2_clicked();

    void on_ButtonY_9_3_clicked();

    void on_ButtonY_9_4_clicked();

    void on_ButtonY_9_5_clicked();

    void on_ButtonY_9_6_clicked();

    void on_ButtonY_9_7_clicked();

    void on_ButtonY_9_8_clicked();

    void on_ButtonY_9_9_clicked();

    void on_ButtonY_10_0_clicked();

    void on_ButtonY_10_1_clicked();

    void on_ButtonY_10_2_clicked();

    void on_ButtonY_10_3_clicked();

    void on_ButtonY_10_4_clicked();

    void on_ButtonY_10_5_clicked();

    void on_ButtonY_10_6_clicked();

    void on_ButtonY_10_7_clicked();

    void on_ButtonY_10_8_clicked();

    void on_ButtonY_10_9_clicked();

    void on_ButtonY_10_10_clicked();

    void on_ButtonY_11_0_clicked();

    void on_ButtonY_11_1_clicked();

    void on_ButtonY_11_2_clicked();

    void on_ButtonY_11_3_clicked();

    void on_ButtonY_11_4_clicked();

    void on_ButtonY_11_5_clicked();

    void on_ButtonY_11_6_clicked();

    void on_ButtonY_11_7_clicked();

    void on_ButtonY_11_8_clicked();

    void on_ButtonY_11_9_clicked();

    void on_ButtonY_11_10_clicked();

    void on_ButtonY_11_11_clicked();

    void on_ButtonY_12_0_clicked();

    void on_ButtonY_12_1_clicked();

    void on_ButtonY_12_2_clicked();

    void on_ButtonY_12_3_clicked();

    void on_ButtonY_12_4_clicked();

    void on_ButtonY_12_5_clicked();

    void on_ButtonY_12_6_clicked();

    void on_ButtonY_12_7_clicked();

    void on_ButtonY_12_8_clicked();

    void on_ButtonY_12_9_clicked();

    void on_ButtonY_12_10_clicked();

    void on_ButtonY_12_11_clicked();

    void on_ButtonY_12_12_clicked();

    void on_ButtonY_13_0_clicked();

    void on_ButtonY_13_1_clicked();

    void on_ButtonY_13_2_clicked();

    void on_ButtonY_13_3_clicked();

    void on_ButtonY_13_4_clicked();

    void on_ButtonY_13_5_clicked();

    void on_ButtonY_13_6_clicked();

    void on_ButtonY_13_7_clicked();

    void on_ButtonY_13_8_clicked();

    void on_ButtonY_13_9_clicked();

    void on_ButtonY_13_10_clicked();

    void on_ButtonY_13_11_clicked();

    void on_ButtonY_13_12_clicked();

    void on_ButtonY_13_13_clicked();

private:
    Ui::YUI *ui;
};

#endif // YUI_H
