#ifndef HEXUI_H
#define HEXUI_H

#include <QFrame>
#include <ConnectionGames.h>
#include <QIcon>

namespace Ui {
class HexUI;
}

class HexUI : public QFrame
{
    int16_t turnCount=0;
    HexGameLogic<Cells::Cell_Hex> game;
    Player playerCurrent;
    std::pair<uint16_t, uint16_t> CurrentMove;
    std::pair<uint16_t, uint16_t> ROPMove;

    QIcon iconP1, iconP2;
    Q_OBJECT

public:
    void ChangeTurn();
    QIcon ChangeIcon();
    explicit HexUI(QWidget *parent = nullptr);
    ~HexUI() override;

private slots:
    void on_pushButton_clicked();
    void draw_edges();
    void on_DaRop_clicked();

    void on_NuROP_clicked();

    void on_ButtonHex_0_0_clicked();
    void on_ButtonHex_0_1_clicked();
    void on_ButtonHex_0_2_clicked();
    void on_ButtonHex_0_3_clicked();
    void on_ButtonHex_0_4_clicked();
    void on_ButtonHex_0_5_clicked();
    void on_ButtonHex_0_6_clicked();
    void on_ButtonHex_0_7_clicked();
    void on_ButtonHex_0_8_clicked();
    void on_ButtonHex_0_9_clicked();
    void on_ButtonHex_0_10_clicked();

    void on_ButtonHex_1_0_clicked();
    void on_ButtonHex_1_1_clicked();
    void on_ButtonHex_1_2_clicked();
    void on_ButtonHex_1_3_clicked();
    void on_ButtonHex_1_4_clicked();
    void on_ButtonHex_1_5_clicked();
    void on_ButtonHex_1_6_clicked();
    void on_ButtonHex_1_7_clicked();
    void on_ButtonHex_1_8_clicked();
    void on_ButtonHex_1_9_clicked();
    void on_ButtonHex_1_10_clicked();

    void on_ButtonHex_2_0_clicked();
    void on_ButtonHex_2_1_clicked();
    void on_ButtonHex_2_2_clicked();
    void on_ButtonHex_2_3_clicked();
    void on_ButtonHex_2_4_clicked();
    void on_ButtonHex_2_5_clicked();
    void on_ButtonHex_2_6_clicked();
    void on_ButtonHex_2_7_clicked();
    void on_ButtonHex_2_8_clicked();
    void on_ButtonHex_2_9_clicked();
    void on_ButtonHex_2_10_clicked();

    void on_ButtonHex_3_0_clicked();
    void on_ButtonHex_3_1_clicked();
    void on_ButtonHex_3_2_clicked();
    void on_ButtonHex_3_3_clicked();
    void on_ButtonHex_3_4_clicked();
    void on_ButtonHex_3_5_clicked();
    void on_ButtonHex_3_6_clicked();
    void on_ButtonHex_3_7_clicked();
    void on_ButtonHex_3_8_clicked();
    void on_ButtonHex_3_9_clicked();
    void on_ButtonHex_3_10_clicked();

    void on_ButtonHex_4_0_clicked();
    void on_ButtonHex_4_1_clicked();
    void on_ButtonHex_4_2_clicked();
    void on_ButtonHex_4_3_clicked();
    void on_ButtonHex_4_4_clicked();
    void on_ButtonHex_4_5_clicked();
    void on_ButtonHex_4_6_clicked();
    void on_ButtonHex_4_7_clicked();
    void on_ButtonHex_4_8_clicked();
    void on_ButtonHex_4_9_clicked();
    void on_ButtonHex_4_10_clicked();

    void on_ButtonHex_5_0_clicked();
    void on_ButtonHex_5_1_clicked();
    void on_ButtonHex_5_2_clicked();
    void on_ButtonHex_5_3_clicked();
    void on_ButtonHex_5_4_clicked();
    void on_ButtonHex_5_5_clicked();
    void on_ButtonHex_5_6_clicked();
    void on_ButtonHex_5_7_clicked();
    void on_ButtonHex_5_8_clicked();
    void on_ButtonHex_5_9_clicked();
    void on_ButtonHex_5_10_clicked();

    void on_ButtonHex_6_0_clicked();
    void on_ButtonHex_6_1_clicked();
    void on_ButtonHex_6_2_clicked();
    void on_ButtonHex_6_3_clicked();
    void on_ButtonHex_6_4_clicked();
    void on_ButtonHex_6_5_clicked();
    void on_ButtonHex_6_6_clicked();
    void on_ButtonHex_6_7_clicked();
    void on_ButtonHex_6_8_clicked();
    void on_ButtonHex_6_9_clicked();
    void on_ButtonHex_6_10_clicked();

    void on_ButtonHex_7_0_clicked();
    void on_ButtonHex_7_1_clicked();
    void on_ButtonHex_7_2_clicked();
    void on_ButtonHex_7_3_clicked();
    void on_ButtonHex_7_4_clicked();
    void on_ButtonHex_7_5_clicked();
    void on_ButtonHex_7_6_clicked();
    void on_ButtonHex_7_7_clicked();
    void on_ButtonHex_7_8_clicked();
    void on_ButtonHex_7_9_clicked();
    void on_ButtonHex_7_10_clicked();

    void on_ButtonHex_8_0_clicked();
    void on_ButtonHex_8_1_clicked();
    void on_ButtonHex_8_2_clicked();
    void on_ButtonHex_8_3_clicked();
    void on_ButtonHex_8_4_clicked();
    void on_ButtonHex_8_5_clicked();
    void on_ButtonHex_8_6_clicked();
    void on_ButtonHex_8_7_clicked();
    void on_ButtonHex_8_8_clicked();
    void on_ButtonHex_8_9_clicked();
    void on_ButtonHex_8_10_clicked();

    void on_ButtonHex_9_0_clicked();
    void on_ButtonHex_9_1_clicked();
    void on_ButtonHex_9_2_clicked();
    void on_ButtonHex_9_3_clicked();
    void on_ButtonHex_9_4_clicked();
    void on_ButtonHex_9_5_clicked();
    void on_ButtonHex_9_6_clicked();
    void on_ButtonHex_9_7_clicked();
    void on_ButtonHex_9_8_clicked();
    void on_ButtonHex_9_9_clicked();
    void on_ButtonHex_9_10_clicked();

    void on_ButtonHex_10_0_clicked();
    void on_ButtonHex_10_1_clicked();
    void on_ButtonHex_10_2_clicked();
    void on_ButtonHex_10_3_clicked();
    void on_ButtonHex_10_4_clicked();
    void on_ButtonHex_10_5_clicked();
    void on_ButtonHex_10_6_clicked();
    void on_ButtonHex_10_7_clicked();
    void on_ButtonHex_10_8_clicked();
    void on_ButtonHex_10_9_clicked();
    void on_ButtonHex_10_10_clicked();

private:
    Ui::HexUI *ui;
};

#endif // HEXUI_H
