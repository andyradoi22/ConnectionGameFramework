#ifndef HAVANNAHUI_H
#define HAVANNAHUI_H

#include <QFrame>
#include <ConnectionGames.h>
#include <QIcon>

namespace Ui {
class HavannahUI;
}

class HavannahUI : public QFrame
{
    int16_t turnCount=0;
    HavannahGameLogic<Cells::Cell_Havannah> game;
    Player playerCurrent;
    std::pair<uint16_t, uint16_t> CurrentMove;
    std::pair<uint16_t, uint16_t> ROPMove;

    QIcon iconP1, iconP2;
    Q_OBJECT

public:
    void ChangeTurn();
    QIcon ChangeIcon();
    explicit HavannahUI(QWidget *parent = nullptr);
    ~HavannahUI();

private slots:
    void on_pushButton_clicked();

    void on_DaRop_clicked();

    void on_NuROP_clicked();

    void on_ButtonHav_0_0_clicked();

    void on_ButtonHav_0_1_clicked();

    void on_ButtonHav_0_2_clicked();

    void on_ButtonHav_0_3_clicked();

    void on_ButtonHav_0_4_clicked();

    void on_ButtonHav_0_5_clicked();

    void on_ButtonHav_0_6_clicked();

    void on_ButtonHav_0_7_clicked();

    void on_ButtonHav_0_8_clicked();

    void on_ButtonHav_0_9_clicked();

    void on_ButtonHav_1_0_clicked();

    void on_ButtonHav_1_1_clicked();

    void on_ButtonHav_1_2_clicked();

    void on_ButtonHav_1_3_clicked();

    void on_ButtonHav_1_4_clicked();

    void on_ButtonHav_1_5_clicked();

    void on_ButtonHav_1_6_clicked();

    void on_ButtonHav_1_7_clicked();

    void on_ButtonHav_1_8_clicked();

    void on_ButtonHav_1_9_clicked();

    void on_ButtonHav_1_10_clicked();

    void on_ButtonHav_2_0_clicked();

    void on_ButtonHav_2_1_clicked();

    void on_ButtonHav_2_2_clicked();

    void on_ButtonHav_2_3_clicked();

    void on_ButtonHav_2_4_clicked();

    void on_ButtonHav_2_5_clicked();

    void on_ButtonHav_2_6_clicked();

    void on_ButtonHav_2_7_clicked();

    void on_ButtonHav_2_8_clicked();

    void on_ButtonHav_2_9_clicked();

    void on_ButtonHav_2_10_clicked();

    void on_ButtonHav_2_11_clicked();

    void on_ButtonHav_3_0_clicked();

    void on_ButtonHav_3_1_clicked();

    void on_ButtonHav_3_2_clicked();

    void on_ButtonHav_3_3_clicked();

    void on_ButtonHav_3_4_clicked();

    void on_ButtonHav_3_5_clicked();

    void on_ButtonHav_3_6_clicked();

    void on_ButtonHav_3_7_clicked();

    void on_ButtonHav_3_8_clicked();

    void on_ButtonHav_3_9_clicked();

    void on_ButtonHav_3_10_clicked();

    void on_ButtonHav_3_11_clicked();

    void on_ButtonHav_3_12_clicked();

    void on_ButtonHav_4_0_clicked();

    void on_ButtonHav_4_1_clicked();

    void on_ButtonHav_4_2_clicked();

    void on_ButtonHav_4_3_clicked();

    void on_ButtonHav_4_4_clicked();

    void on_ButtonHav_4_5_clicked();

    void on_ButtonHav_4_6_clicked();

    void on_ButtonHav_4_7_clicked();

    void on_ButtonHav_4_8_clicked();

    void on_ButtonHav_4_9_clicked();

    void on_ButtonHav_4_10_clicked();

    void on_ButtonHav_4_11_clicked();

    void on_ButtonHav_4_12_clicked();

    void on_ButtonHav_4_13_clicked();

    void on_ButtonHav_5_0_clicked();

    void on_ButtonHav_5_1_clicked();

    void on_ButtonHav_5_2_clicked();

    void on_ButtonHav_5_3_clicked();

    void on_ButtonHav_5_4_clicked();

    void on_ButtonHav_5_5_clicked();

    void on_ButtonHav_5_6_clicked();

    void on_ButtonHav_5_7_clicked();

    void on_ButtonHav_5_8_clicked();

    void on_ButtonHav_5_9_clicked();

    void on_ButtonHav_5_10_clicked();

    void on_ButtonHav_5_11_clicked();

    void on_ButtonHav_5_12_clicked();

    void on_ButtonHav_5_13_clicked();

    void on_ButtonHav_5_14_clicked();

    void on_ButtonHav_6_0_clicked();

    void on_ButtonHav_6_1_clicked();

    void on_ButtonHav_6_2_clicked();

    void on_ButtonHav_6_3_clicked();

    void on_ButtonHav_6_4_clicked();

    void on_ButtonHav_6_5_clicked();

    void on_ButtonHav_6_6_clicked();

    void on_ButtonHav_6_7_clicked();

    void on_ButtonHav_6_8_clicked();

    void on_ButtonHav_6_9_clicked();

    void on_ButtonHav_6_10_clicked();

    void on_ButtonHav_6_11_clicked();

    void on_ButtonHav_6_12_clicked();

    void on_ButtonHav_6_13_clicked();

    void on_ButtonHav_6_14_clicked();

    void on_ButtonHav_6_15_clicked();

    void on_ButtonHav_7_0_clicked();

    void on_ButtonHav_7_1_clicked();

    void on_ButtonHav_7_2_clicked();

    void on_ButtonHav_7_3_clicked();

    void on_ButtonHav_7_4_clicked();

    void on_ButtonHav_7_5_clicked();

    void on_ButtonHav_7_6_clicked();

    void on_ButtonHav_7_7_clicked();

    void on_ButtonHav_7_8_clicked();

    void on_ButtonHav_7_9_clicked();

    void on_ButtonHav_7_10_clicked();

    void on_ButtonHav_7_11_clicked();

    void on_ButtonHav_7_12_clicked();

    void on_ButtonHav_7_13_clicked();

    void on_ButtonHav_7_14_clicked();

    void on_ButtonHav_7_15_clicked();

    void on_ButtonHav_7_16_clicked();

    void on_ButtonHav_8_0_clicked();

    void on_ButtonHav_8_1_clicked();

    void on_ButtonHav_8_2_clicked();

    void on_ButtonHav_8_3_clicked();

    void on_ButtonHav_8_4_clicked();

    void on_ButtonHav_8_5_clicked();

    void on_ButtonHav_8_6_clicked();

    void on_ButtonHav_8_7_clicked();

    void on_ButtonHav_8_8_clicked();

    void on_ButtonHav_8_9_clicked();

    void on_ButtonHav_8_10_clicked();

    void on_ButtonHav_8_11_clicked();

    void on_ButtonHav_8_12_clicked();

    void on_ButtonHav_8_13_clicked();

    void on_ButtonHav_8_14_clicked();

    void on_ButtonHav_8_15_clicked();

    void on_ButtonHav_8_16_clicked();

    void on_ButtonHav_8_17_clicked();

    void on_ButtonHav_9_0_clicked();

    void on_ButtonHav_9_1_clicked();

    void on_ButtonHav_9_2_clicked();

    void on_ButtonHav_9_3_clicked();

    void on_ButtonHav_9_4_clicked();

    void on_ButtonHav_9_5_clicked();

    void on_ButtonHav_9_6_clicked();

    void on_ButtonHav_9_7_clicked();

    void on_ButtonHav_9_8_clicked();

    void on_ButtonHav_9_9_clicked();

    void on_ButtonHav_9_10_clicked();

    void on_ButtonHav_9_11_clicked();

    void on_ButtonHav_9_12_clicked();

    void on_ButtonHav_9_13_clicked();

    void on_ButtonHav_9_14_clicked();

    void on_ButtonHav_9_15_clicked();

    void on_ButtonHav_9_16_clicked();

    void on_ButtonHav_9_17_clicked();

    void on_ButtonHav_9_18_clicked();

    void on_ButtonHav_10_0_clicked();

    void on_ButtonHav_10_1_clicked();

    void on_ButtonHav_10_2_clicked();

    void on_ButtonHav_10_3_clicked();

    void on_ButtonHav_10_4_clicked();

    void on_ButtonHav_10_5_clicked();

    void on_ButtonHav_10_6_clicked();

    void on_ButtonHav_10_7_clicked();

    void on_ButtonHav_10_8_clicked();

    void on_ButtonHav_10_9_clicked();

    void on_ButtonHav_10_10_clicked();

    void on_ButtonHav_10_11_clicked();

    void on_ButtonHav_10_12_clicked();

    void on_ButtonHav_10_13_clicked();

    void on_ButtonHav_10_14_clicked();

    void on_ButtonHav_10_15_clicked();

    void on_ButtonHav_10_16_clicked();

    void on_ButtonHav_10_17_clicked();

    void on_ButtonHav_11_0_clicked();

    void on_ButtonHav_11_1_clicked();

    void on_ButtonHav_11_2_clicked();

    void on_ButtonHav_11_3_clicked();

    void on_ButtonHav_11_4_clicked();

    void on_ButtonHav_11_5_clicked();

    void on_ButtonHav_11_6_clicked();

    void on_ButtonHav_11_7_clicked();

    void on_ButtonHav_11_8_clicked();

    void on_ButtonHav_11_9_clicked();

    void on_ButtonHav_11_10_clicked();

    void on_ButtonHav_11_11_clicked();

    void on_ButtonHav_11_12_clicked();

    void on_ButtonHav_11_13_clicked();

    void on_ButtonHav_11_14_clicked();

    void on_ButtonHav_11_15_clicked();

    void on_ButtonHav_11_16_clicked();

    void on_ButtonHav_12_0_clicked();

    void on_ButtonHav_12_1_clicked();

    void on_ButtonHav_12_2_clicked();

    void on_ButtonHav_12_3_clicked();

    void on_ButtonHav_12_4_clicked();

    void on_ButtonHav_12_5_clicked();

    void on_ButtonHav_12_6_clicked();

    void on_ButtonHav_12_7_clicked();

    void on_ButtonHav_12_8_clicked();

    void on_ButtonHav_12_9_clicked();

    void on_ButtonHav_12_10_clicked();

    void on_ButtonHav_12_11_clicked();

    void on_ButtonHav_12_12_clicked();

    void on_ButtonHav_12_13_clicked();

    void on_ButtonHav_12_14_clicked();

    void on_ButtonHav_12_15_clicked();

    void on_ButtonHav_13_0_clicked();

    void on_ButtonHav_13_1_clicked();

    void on_ButtonHav_13_2_clicked();

    void on_ButtonHav_13_3_clicked();

    void on_ButtonHav_13_4_clicked();

    void on_ButtonHav_13_5_clicked();

    void on_ButtonHav_13_6_clicked();

    void on_ButtonHav_13_7_clicked();

    void on_ButtonHav_13_8_clicked();

    void on_ButtonHav_13_9_clicked();

    void on_ButtonHav_13_10_clicked();

    void on_ButtonHav_13_11_clicked();

    void on_ButtonHav_13_12_clicked();

    void on_ButtonHav_13_13_clicked();

    void on_ButtonHav_13_14_clicked();

    void on_ButtonHav_14_0_clicked();

    void on_ButtonHav_14_1_clicked();

    void on_ButtonHav_14_2_clicked();

    void on_ButtonHav_14_3_clicked();

    void on_ButtonHav_14_4_clicked();

    void on_ButtonHav_14_5_clicked();

    void on_ButtonHav_14_6_clicked();

    void on_ButtonHav_14_7_clicked();

    void on_ButtonHav_14_8_clicked();

    void on_ButtonHav_14_9_clicked();

    void on_ButtonHav_14_10_clicked();

    void on_ButtonHav_14_11_clicked();

    void on_ButtonHav_14_12_clicked();

    void on_ButtonHav_14_13_clicked();

    void on_ButtonHav_15_0_clicked();

    void on_ButtonHav_15_1_clicked();

    void on_ButtonHav_15_2_clicked();

    void on_ButtonHav_15_3_clicked();

    void on_ButtonHav_15_4_clicked();

    void on_ButtonHav_15_5_clicked();

    void on_ButtonHav_15_6_clicked();

    void on_ButtonHav_15_7_clicked();

    void on_ButtonHav_15_8_clicked();

    void on_ButtonHav_15_9_clicked();

    void on_ButtonHav_15_10_clicked();

    void on_ButtonHav_15_11_clicked();

    void on_ButtonHav_15_12_clicked();

    void on_ButtonHav_16_0_clicked();

    void on_ButtonHav_16_1_clicked();

    void on_ButtonHav_16_2_clicked();

    void on_ButtonHav_16_3_clicked();

    void on_ButtonHav_16_4_clicked();

    void on_ButtonHav_16_5_clicked();

    void on_ButtonHav_16_6_clicked();

    void on_ButtonHav_16_7_clicked();

    void on_ButtonHav_16_8_clicked();

    void on_ButtonHav_16_9_clicked();

    void on_ButtonHav_16_10_clicked();

    void on_ButtonHav_16_11_clicked();

    void on_ButtonHav_17_0_clicked();

    void on_ButtonHav_17_1_clicked();

    void on_ButtonHav_17_2_clicked();

    void on_ButtonHav_17_3_clicked();

    void on_ButtonHav_17_4_clicked();

    void on_ButtonHav_17_5_clicked();

    void on_ButtonHav_17_6_clicked();

    void on_ButtonHav_17_7_clicked();

    void on_ButtonHav_17_8_clicked();

    void on_ButtonHav_17_9_clicked();

    void on_ButtonHav_17_10_clicked();

    void on_ButtonHav_18_0_clicked();

    void on_ButtonHav_18_1_clicked();

    void on_ButtonHav_18_2_clicked();

    void on_ButtonHav_18_3_clicked();

    void on_ButtonHav_18_4_clicked();

    void on_ButtonHav_18_5_clicked();

    void on_ButtonHav_18_6_clicked();

    void on_ButtonHav_18_7_clicked();

    void on_ButtonHav_18_8_clicked();

    void on_ButtonHav_18_9_clicked();

private:
    Ui::HavannahUI *ui;
};

#endif // HAVANNAHUI_H
