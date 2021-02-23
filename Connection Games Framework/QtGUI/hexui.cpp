#include "hexui.h"
#include "ui_hexui.h"
#include <QPainter>
#include <QGraphicsView>

HexUI::HexUI(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::HexUI)
{
    ui->setupUi(this);


    QPixmap bkgd("../GUI pictures/GameBackground.jpg");
           bkgd=bkgd.scaled(this->size(),Qt::IgnoreAspectRatio);
           QPalette palette;
           palette.setBrush(QPalette::Background, bkgd);
           this->setPalette(palette);
     ui->stackedWidget->setCurrentIndex(0);
}

HexUI::~HexUI()
{
    delete ui;
}

void HexUI::ChangeTurn()
{
    if (turnCount == 0)
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->DaRop->setVisible(true);
        ui->NuROP->setVisible(true);
        ui->IntrebareROP->setVisible(true);
    }

    if(playerCurrent.GetName()==game.GetPlayer1().GetName())
    {
        playerCurrent=game.GetPlayer2();
    }
    else
       {
        playerCurrent=game.GetPlayer1();
       }
    if(ui->stackedWidget->currentIndex()==1)
    {
    ui->Turns->setText(playerCurrent.GetName()+" 's turn");
    }
    turnCount++;
}

QIcon HexUI::ChangeIcon()
{
    if(playerCurrent.GetName()==game.GetPlayer1().GetName())
    {
        return iconP1;
    }
    else
    {
       return iconP2;
    }
}

void HexUI::on_pushButton_clicked()
{
    ui->DaRop->setVisible(false);
    ui->NuROP->setVisible(false);
    ui->IntrebareROP->setVisible(false);
    ui->Patcher->setVisible(false);

    game.InitBoard();
    QString name=ui->NumePlayer1_2->toPlainText();

    game.GetPlayer1().SetName(name);
    game.GetPlayer1().SetColor(Player::Color::color1);

    name=ui->NumePlayer2_2->toPlainText();

    game.GetPlayer2().SetName(name);
    game.GetPlayer2().SetColor(Player::Color::color2);
    playerCurrent=game.GetPlayer1();
    ui->Turns->setText(playerCurrent.GetName()+" 's trun");


    repaint();
    if(ui->comboBox_P1->currentText()==ui->comboBox_P2->currentText())
    {
        ui->MesajEroare->setText("Culorile nu sunt diferite");
    }
    else
    {
        ui->stackedWidget->setCurrentIndex(1);
        draw_edges();
    }

    iconP2=ui->comboBox_P2->itemIcon(ui->comboBox_P2->currentIndex());
    QPixmap cell_P2=iconP2.pixmap(iconP2.actualSize(QSize(44,44)));
    iconP2.addPixmap(cell_P2,QIcon::Disabled);
    iconP2.addPixmap(cell_P2,QIcon::Normal);

    iconP1=ui->comboBox_P1->itemIcon(ui->comboBox_P1->currentIndex());
    QPixmap cell_P1=iconP1.pixmap(iconP1.actualSize(QSize(44,44)));
    iconP1.addPixmap(cell_P1,QIcon::Disabled);
    iconP1.addPixmap(cell_P1,QIcon::Normal);
}

void HexUI::draw_edges()
{
   QIcon icon;
   icon=ui->comboBox_P2->itemIcon(ui->comboBox_P2->currentIndex());
   QPixmap cell_P2=icon.pixmap(icon.actualSize(QSize(44,44)));


   ui->N1->setPixmap(cell_P2);
   ui->N2->setPixmap(cell_P2);
   ui->N3->setPixmap(cell_P2);
   ui->N4->setPixmap(cell_P2);
   ui->N5->setPixmap(cell_P2);
   ui->N6->setPixmap(cell_P2);
   ui->N7->setPixmap(cell_P2);
   ui->N8->setPixmap(cell_P2);
   ui->N9->setPixmap(cell_P2);
   ui->N10->setPixmap(cell_P2);
   ui->N11->setPixmap(cell_P2);

   ui->S1->setPixmap(cell_P2);
   ui->S2->setPixmap(cell_P2);
   ui->S3->setPixmap(cell_P2);
   ui->S4->setPixmap(cell_P2);
   ui->S5->setPixmap(cell_P2);
   ui->S6->setPixmap(cell_P2);
   ui->S7->setPixmap(cell_P2);
   ui->S8->setPixmap(cell_P2);
   ui->S9->setPixmap(cell_P2);
   ui->S10->setPixmap(cell_P2);
   ui->S11->setPixmap(cell_P2);

   icon=ui->comboBox_P1->itemIcon(ui->comboBox_P1->currentIndex());
   QPixmap cell_P1=icon.pixmap(icon.actualSize(QSize(44,44)));

   ui->V1->setPixmap(cell_P1);
   ui->V2->setPixmap(cell_P1);
   ui->V3->setPixmap(cell_P1);
   ui->V4->setPixmap(cell_P1);
   ui->V5->setPixmap(cell_P1);
   ui->V6->setPixmap(cell_P1);
   ui->V7->setPixmap(cell_P1);
   ui->V8->setPixmap(cell_P1);
   ui->V9->setPixmap(cell_P1);
   ui->V10->setPixmap(cell_P1);
   ui->V11->setPixmap(cell_P1);

   ui->E1->setPixmap(cell_P1);
   ui->E2->setPixmap(cell_P1);
   ui->E3->setPixmap(cell_P1);
   ui->E4->setPixmap(cell_P1);
   ui->E5->setPixmap(cell_P1);
   ui->E6->setPixmap(cell_P1);
   ui->E7->setPixmap(cell_P1);
   ui->E8->setPixmap(cell_P1);
   ui->E9->setPixmap(cell_P1);
   ui->E10->setPixmap(cell_P1);
   ui->E11->setPixmap(cell_P1);

   repaint();

}

void HexUI::on_DaRop_clicked()
{
    ui->DaRop->setVisible(false);
    ui->NuROP->setVisible(false);
    ui->IntrebareROP->setVisible(false);

    ui->stackedWidget->setCurrentIndex(1);

    ui->Patcher->setIcon(ChangeIcon());


    ui->Patcher->move(CurrentMove.first-9,CurrentMove.second-8);
    ui->Patcher->setFixedSize(44,44);
    ui->Patcher->setIconSize(QSize(44,44));
    ui->Patcher->setEnabled(false);
    ui->Patcher->raise();
    ui->Patcher->setVisible(true);
    game.RuleOfPie(ROPMove.first,ROPMove.second);

}

void HexUI::on_NuROP_clicked()
{
    ui->DaRop->setVisible(false);
    ui->NuROP->setVisible(false);
    ui->IntrebareROP->setVisible(false);
    ui->stackedWidget->setCurrentIndex(1);
}






void HexUI::on_ButtonHex_0_0_clicked()
{
    int x, y;
    x=ui->ButtonHex_0_0->x();
    y=ui->ButtonHex_0_0->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_0_0->x(), ui->ButtonHex_0_0->y());
    ROPMove=std::make_pair(0,0);

    ui->ButtonHex_0_0->setIcon(ChangeIcon());
    ui->ButtonHex_0_0->move(x-9,y-8);
    ui->ButtonHex_0_0->setFixedSize(44,44);
    ui->ButtonHex_0_0->setIconSize(QSize(44,44));
    ui->ButtonHex_0_0->setEnabled(false);

   game.PlayerTurn(0,0,playerCurrent);
   if(game.VerifyRules(0,0))
   {
      ui->Winner->setText(playerCurrent.GetName()+" a castigat");
      ui->stackedWidget->setCurrentIndex(2);
   }


}

void HexUI::on_ButtonHex_0_1_clicked()
{
    int x, y;
    x = ui->ButtonHex_0_1->x();
    y = ui->ButtonHex_0_1->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_0_1->x(), ui->ButtonHex_0_1->y());
       ROPMove=std::make_pair(0,1);

    ui->ButtonHex_0_1->setIcon(ChangeIcon());
    ui->ButtonHex_0_1->move(x - 9, y - 8);
    ui->ButtonHex_0_1->setFixedSize(44, 44);
    ui->ButtonHex_0_1->setIconSize(QSize(44, 44));
    ui->ButtonHex_0_1->setEnabled(false);

    game.PlayerTurn(0,1, playerCurrent);
    if (game.VerifyRules(0, 1))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}


void HexUI::on_ButtonHex_0_2_clicked()
{
    int x, y;
    x = ui->ButtonHex_0_2->x();
    y = ui->ButtonHex_0_2->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_0_2->x(), ui->ButtonHex_0_2->y());
       ROPMove=std::make_pair(0,2);

    ui->ButtonHex_0_2->setIcon(ChangeIcon());
    ui->ButtonHex_0_2->move(x - 9, y - 8);
    ui->ButtonHex_0_2->setFixedSize(44, 44);
    ui->ButtonHex_0_2->setIconSize(QSize(44, 44));
    ui->ButtonHex_0_2->setEnabled(false);



    game.PlayerTurn(0,2, playerCurrent);
    if (game.VerifyRules(0, 2))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}


void HexUI::on_ButtonHex_0_3_clicked()
{
    int x, y;
    x = ui->ButtonHex_0_3->x();
    y = ui->ButtonHex_0_3->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_0_3->x(), ui->ButtonHex_0_3->y()); ROPMove=std::make_pair(0,3);

    ui->ButtonHex_0_3->setIcon(ChangeIcon());
    ui->ButtonHex_0_3->move(x - 9, y - 8);
    ui->ButtonHex_0_3->setFixedSize(44, 44);
    ui->ButtonHex_0_3->setIconSize(QSize(44, 44));
    ui->ButtonHex_0_3->setEnabled(false);

    game.PlayerTurn(0,3, playerCurrent);
    if (game.VerifyRules(0, 3))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_0_4_clicked()
{
    int x, y;
    x = ui->ButtonHex_0_4->x();
    y = ui->ButtonHex_0_4->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_0_4->x(), ui->ButtonHex_0_4->y()); ROPMove=std::make_pair(0,4);

    ui->ButtonHex_0_4->setIcon(ChangeIcon());
    ui->ButtonHex_0_4->move(x - 9, y - 8);
    ui->ButtonHex_0_4->setFixedSize(44, 44);
    ui->ButtonHex_0_4->setIconSize(QSize(44, 44));
    ui->ButtonHex_0_4->setEnabled(false);

    game.PlayerTurn(0,4, playerCurrent);
    if (game.VerifyRules(0, 4))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_0_5_clicked()
{
    int x, y;
    x = ui->ButtonHex_0_5->x();
    y = ui->ButtonHex_0_5->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_0_5->x(), ui->ButtonHex_0_5->y()); ROPMove=std::make_pair(0,5);

    ui->ButtonHex_0_5->setIcon(ChangeIcon());
    ui->ButtonHex_0_5->move(x - 9, y - 8);
    ui->ButtonHex_0_5->setFixedSize(44, 44);
    ui->ButtonHex_0_5->setIconSize(QSize(44, 44));
    ui->ButtonHex_0_5->setEnabled(false);

    game.PlayerTurn(0,5, playerCurrent);
    if (game.VerifyRules(0, 5))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_0_6_clicked()
{
    int x, y;
    x = ui->ButtonHex_0_6->x();
    y = ui->ButtonHex_0_6->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_0_6->x(), ui->ButtonHex_0_6->y()); ROPMove=std::make_pair(0,6);

    ui->ButtonHex_0_6->setIcon(ChangeIcon());
    ui->ButtonHex_0_6->move(x - 9, y - 8);
    ui->ButtonHex_0_6->setFixedSize(44, 44);
    ui->ButtonHex_0_6->setIconSize(QSize(44, 44));
    ui->ButtonHex_0_6->setEnabled(false);

    game.PlayerTurn(0,6, playerCurrent);
    if (game.VerifyRules(0, 6))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_0_7_clicked()
{
    int x, y;
    x = ui->ButtonHex_0_7->x();
    y = ui->ButtonHex_0_7->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_0_7->x(), ui->ButtonHex_0_7->y()); ROPMove=std::make_pair(0,7);

    ui->ButtonHex_0_7->setIcon(ChangeIcon());
    ui->ButtonHex_0_7->move(x - 9, y - 8);
    ui->ButtonHex_0_7->setFixedSize(44, 44);
    ui->ButtonHex_0_7->setIconSize(QSize(44, 44));
    ui->ButtonHex_0_7->setEnabled(false);

    game.PlayerTurn(0,7, playerCurrent);
    if (game.VerifyRules(0, 7))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_0_8_clicked()
{
    int x, y;
    x = ui->ButtonHex_0_8->x();
    y = ui->ButtonHex_0_8->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_0_8->x(), ui->ButtonHex_0_8->y()); ROPMove=std::make_pair(0,8);

    ui->ButtonHex_0_8->setIcon(ChangeIcon());
    ui->ButtonHex_0_8->move(x - 9, y - 8);
    ui->ButtonHex_0_8->setFixedSize(44, 44);
    ui->ButtonHex_0_8->setIconSize(QSize(44, 44));
    ui->ButtonHex_0_8->setEnabled(false);

    game.PlayerTurn(0,8, playerCurrent);
    if (game.VerifyRules(0, 8))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}


void HexUI::on_ButtonHex_0_9_clicked()
{
    int x, y;
    x = ui->ButtonHex_0_9->x();
    y = ui->ButtonHex_0_9->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_0_9->x(), ui->ButtonHex_0_9->y()); ROPMove=std::make_pair(0,9);

    ui->ButtonHex_0_9->setIcon(ChangeIcon());
    ui->ButtonHex_0_9->move(x - 9, y - 8);
    ui->ButtonHex_0_9->setFixedSize(44, 44);
    ui->ButtonHex_0_9->setIconSize(QSize(44, 44));
    ui->ButtonHex_0_9->setEnabled(false);

    game.PlayerTurn(0,9, playerCurrent);
    if (game.VerifyRules(0, 9))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_0_10_clicked()
{
    int x, y;
    x = ui->ButtonHex_0_10->x();
    y = ui->ButtonHex_0_10->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_0_10->x(), ui->ButtonHex_0_10->y()); ROPMove=std::make_pair(0,10);

    ui->ButtonHex_0_10->setIcon(ChangeIcon());
    ui->ButtonHex_0_10->move(x - 9, y - 8);
    ui->ButtonHex_0_10->setFixedSize(44, 44);
    ui->ButtonHex_0_10->setIconSize(QSize(44, 44));
    ui->ButtonHex_0_10->setEnabled(false);

    game.PlayerTurn(0,10, playerCurrent);
    if (game.VerifyRules(0, 10))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_1_0_clicked()
{
    int x, y;
    x = ui->ButtonHex_1_0->x();
    y = ui->ButtonHex_1_0->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_1_0->x(), ui->ButtonHex_1_0->y()); ROPMove=std::make_pair(1,0);

    ui->ButtonHex_1_0->setIcon(ChangeIcon());
    ui->ButtonHex_1_0->move(x - 9, y - 8);
    ui->ButtonHex_1_0->setFixedSize(44, 44);
    ui->ButtonHex_1_0->setIconSize(QSize(44, 44));
    ui->ButtonHex_1_0->setEnabled(false);

    game.PlayerTurn(1,0, playerCurrent);
    if (game.VerifyRules(1, 0))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_1_1_clicked()
{
    int x, y;
    x = ui->ButtonHex_1_1->x();
    y = ui->ButtonHex_1_1->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_1_1->x(), ui->ButtonHex_1_1->y()); ROPMove=std::make_pair(1,1);

    ui->ButtonHex_1_1->setIcon(ChangeIcon());
    ui->ButtonHex_1_1->move(x - 9, y - 8);
    ui->ButtonHex_1_1->setFixedSize(44, 44);
    ui->ButtonHex_1_1->setIconSize(QSize(44, 44));
    ui->ButtonHex_1_1->setEnabled(false);

    game.PlayerTurn(1,1, playerCurrent);
    if (game.VerifyRules(1, 1))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}


void HexUI::on_ButtonHex_1_2_clicked()
{
    int x, y;
    x = ui->ButtonHex_1_2->x();
    y = ui->ButtonHex_1_2->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_1_2->x(), ui->ButtonHex_1_2->y()); ROPMove=std::make_pair(1,2);

    ui->ButtonHex_1_2->setIcon(ChangeIcon());
    ui->ButtonHex_1_2->move(x - 9, y - 8);
    ui->ButtonHex_1_2->setFixedSize(44, 44);
    ui->ButtonHex_1_2->setIconSize(QSize(44, 44));
    ui->ButtonHex_1_2->setEnabled(false);

    game.PlayerTurn(1,2, playerCurrent);
    if (game.VerifyRules(1, 2))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_1_3_clicked()
{
    int x, y;
    x = ui->ButtonHex_1_3->x();
    y = ui->ButtonHex_1_3->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_1_3->x(), ui->ButtonHex_1_3->y()); ROPMove=std::make_pair(1,3);

    ui->ButtonHex_1_3->setIcon(ChangeIcon());
    ui->ButtonHex_1_3->move(x - 9, y - 8);
    ui->ButtonHex_1_3->setFixedSize(44, 44);
    ui->ButtonHex_1_3->setIconSize(QSize(44, 44));
    ui->ButtonHex_1_3->setEnabled(false);

    game.PlayerTurn(1,3, playerCurrent);
    if (game.VerifyRules(1, 3))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_1_4_clicked()
{
    int x, y;
    x = ui->ButtonHex_1_4->x();
    y = ui->ButtonHex_1_4->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_1_4->x(), ui->ButtonHex_1_4->y()); ROPMove=std::make_pair(1,4);

    ui->ButtonHex_1_4->setIcon(ChangeIcon());
    ui->ButtonHex_1_4->move(x - 9, y - 8);
    ui->ButtonHex_1_4->setFixedSize(44, 44);
    ui->ButtonHex_1_4->setIconSize(QSize(44, 44));
    ui->ButtonHex_1_4->setEnabled(false);

    game.PlayerTurn(1,4, playerCurrent);
    if (game.VerifyRules(1, 4))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_1_5_clicked()
{
    int x, y;
    x = ui->ButtonHex_1_5->x();
    y = ui->ButtonHex_1_5->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_1_5->x(), ui->ButtonHex_1_5->y()); ROPMove=std::make_pair(1,5);

    ui->ButtonHex_1_5->setIcon(ChangeIcon());
    ui->ButtonHex_1_5->move(x - 9, y - 8);
    ui->ButtonHex_1_5->setFixedSize(44, 44);
    ui->ButtonHex_1_5->setIconSize(QSize(44, 44));
    ui->ButtonHex_1_5->setEnabled(false);

    game.PlayerTurn(1,5, playerCurrent);
    if (game.VerifyRules(1, 5))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_1_6_clicked()
{
    int x, y;
    x = ui->ButtonHex_1_6->x();
    y = ui->ButtonHex_1_6->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_1_6->x(), ui->ButtonHex_1_6->y()); ROPMove=std::make_pair(1,6);

    ui->ButtonHex_1_6->setIcon(ChangeIcon());
    ui->ButtonHex_1_6->move(x - 9, y - 8);
    ui->ButtonHex_1_6->setFixedSize(44, 44);
    ui->ButtonHex_1_6->setIconSize(QSize(44, 44));
    ui->ButtonHex_1_6->setEnabled(false);

    game.PlayerTurn(1,6, playerCurrent);
    if (game.VerifyRules(1, 6))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_1_7_clicked()
{
    int x, y;
    x = ui->ButtonHex_1_7->x();
    y = ui->ButtonHex_1_7->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_1_7->x(), ui->ButtonHex_1_7->y()); ROPMove=std::make_pair(1,7);

    ui->ButtonHex_1_7->setIcon(ChangeIcon());
    ui->ButtonHex_1_7->move(x - 9, y - 8);
    ui->ButtonHex_1_7->setFixedSize(44, 44);
    ui->ButtonHex_1_7->setIconSize(QSize(44, 44));
    ui->ButtonHex_1_7->setEnabled(false);

    game.PlayerTurn(1,7, playerCurrent);
    if (game.VerifyRules(1, 7))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_1_8_clicked()
{
    int x, y;
    x = ui->ButtonHex_1_8->x();
    y = ui->ButtonHex_1_8->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_1_8->x(), ui->ButtonHex_1_8->y()); ROPMove=std::make_pair(1,8);

    ui->ButtonHex_1_8->setIcon(ChangeIcon());
    ui->ButtonHex_1_8->move(x - 9, y - 8);
    ui->ButtonHex_1_8->setFixedSize(44, 44);
    ui->ButtonHex_1_8->setIconSize(QSize(44, 44));
    ui->ButtonHex_1_8->setEnabled(false);

    game.PlayerTurn(1,8, playerCurrent);
    if (game.VerifyRules(1, 8))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}


void HexUI::on_ButtonHex_1_9_clicked()
{
    int x, y;
    x = ui->ButtonHex_1_9->x();
    y = ui->ButtonHex_1_9->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_1_9->x(), ui->ButtonHex_1_9->y()); ROPMove=std::make_pair(1,9);

    ui->ButtonHex_1_9->setIcon(ChangeIcon());
    ui->ButtonHex_1_9->move(x - 9, y - 8);
    ui->ButtonHex_1_9->setFixedSize(44, 44);
    ui->ButtonHex_1_9->setIconSize(QSize(44, 44));
    ui->ButtonHex_1_9->setEnabled(false);

    game.PlayerTurn(1,9, playerCurrent);
    if (game.VerifyRules(1, 9))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_1_10_clicked()
{
    int x, y;
    x = ui->ButtonHex_1_10->x();
    y = ui->ButtonHex_1_10->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_1_10->x(), ui->ButtonHex_1_10->y()); ROPMove=std::make_pair(1,10);

    ui->ButtonHex_1_10->setIcon(ChangeIcon());
    ui->ButtonHex_1_10->move(x - 9, y - 8);
    ui->ButtonHex_1_10->setFixedSize(44, 44);
    ui->ButtonHex_1_10->setIconSize(QSize(44, 44));
    ui->ButtonHex_1_10->setEnabled(false);

    game.PlayerTurn(1,10, playerCurrent);
    if (game.VerifyRules(1, 10))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_2_1_clicked()
{
    int x, y;
    x = ui->ButtonHex_2_1->x();
    y = ui->ButtonHex_2_1->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_2_1->x(), ui->ButtonHex_2_1->y()); ROPMove=std::make_pair(2,1);

    ui->ButtonHex_2_1->setIcon(ChangeIcon());
    ui->ButtonHex_2_1->move(x - 9, y - 8);
    ui->ButtonHex_2_1->setFixedSize(44, 44);
    ui->ButtonHex_2_1->setIconSize(QSize(44, 44));
    ui->ButtonHex_2_1->setEnabled(false);

    game.PlayerTurn(2,1, playerCurrent);
    if (game.VerifyRules(2, 1))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}


void HexUI::on_ButtonHex_2_2_clicked()
{
    int x, y;
    x = ui->ButtonHex_2_2->x();
    y = ui->ButtonHex_2_2->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_2_2->x(), ui->ButtonHex_2_2->y()); ROPMove=std::make_pair(2,2);

    ui->ButtonHex_2_2->setIcon(ChangeIcon());
    ui->ButtonHex_2_2->move(x - 9, y - 8);
    ui->ButtonHex_2_2->setFixedSize(44, 44);
    ui->ButtonHex_2_2->setIconSize(QSize(44, 44));
    ui->ButtonHex_2_2->setEnabled(false);

    game.PlayerTurn(2,2, playerCurrent);
    if (game.VerifyRules(2, 2))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_2_3_clicked()
{
    int x, y;
    x = ui->ButtonHex_2_3->x();
    y = ui->ButtonHex_2_3->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_2_3->x(), ui->ButtonHex_2_3->y()); ROPMove=std::make_pair(2,3);

    ui->ButtonHex_2_3->setIcon(ChangeIcon());
    ui->ButtonHex_2_3->move(x - 9, y - 8);
    ui->ButtonHex_2_3->setFixedSize(44, 44);
    ui->ButtonHex_2_3->setIconSize(QSize(44, 44));
    ui->ButtonHex_2_3->setEnabled(false);

    game.PlayerTurn(2,3, playerCurrent);
    if (game.VerifyRules(2, 3))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_2_4_clicked()
{
    int x, y;
    x = ui->ButtonHex_2_4->x();
    y = ui->ButtonHex_2_4->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_2_4->x(), ui->ButtonHex_2_4->y()); ROPMove=std::make_pair(2,4);

    ui->ButtonHex_2_4->setIcon(ChangeIcon());
    ui->ButtonHex_2_4->move(x - 9, y - 8);
    ui->ButtonHex_2_4->setFixedSize(44, 44);
    ui->ButtonHex_2_4->setIconSize(QSize(44, 44));
    ui->ButtonHex_2_4->setEnabled(false);

    game.PlayerTurn(2,4, playerCurrent);
    if (game.VerifyRules(2, 4))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_2_5_clicked()
{
    int x, y;
    x = ui->ButtonHex_2_5->x();
    y = ui->ButtonHex_2_5->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_2_5->x(), ui->ButtonHex_2_5->y()); ROPMove=std::make_pair(2,5);

    ui->ButtonHex_2_5->setIcon(ChangeIcon());
    ui->ButtonHex_2_5->move(x - 9, y - 8);
    ui->ButtonHex_2_5->setFixedSize(44, 44);
    ui->ButtonHex_2_5->setIconSize(QSize(44, 44));
    ui->ButtonHex_2_5->setEnabled(false);

    game.PlayerTurn(2,5, playerCurrent);
    if (game.VerifyRules(2, 5))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_2_6_clicked()
{
    int x, y;
    x = ui->ButtonHex_2_6->x();
    y = ui->ButtonHex_2_6->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_2_6->x(), ui->ButtonHex_2_6->y()); ROPMove=std::make_pair(2,6);

    ui->ButtonHex_2_6->setIcon(ChangeIcon());
    ui->ButtonHex_2_6->move(x - 9, y - 8);
    ui->ButtonHex_2_6->setFixedSize(44, 44);
    ui->ButtonHex_2_6->setIconSize(QSize(44, 44));
    ui->ButtonHex_2_6->setEnabled(false);

    game.PlayerTurn(2,6, playerCurrent);
    if (game.VerifyRules(2, 6))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_2_7_clicked()
{
    int x, y;
    x = ui->ButtonHex_2_7->x();
    y = ui->ButtonHex_2_7->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_2_7->x(), ui->ButtonHex_2_7->y()); ROPMove=std::make_pair(2,7);

    ui->ButtonHex_2_7->setIcon(ChangeIcon());
    ui->ButtonHex_2_7->move(x - 9, y - 8);
    ui->ButtonHex_2_7->setFixedSize(44, 44);
    ui->ButtonHex_2_7->setIconSize(QSize(44, 44));
    ui->ButtonHex_2_7->setEnabled(false);

    game.PlayerTurn(2,7, playerCurrent);
    if (game.VerifyRules(2, 7))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_2_8_clicked()
{
    int x, y;
    x = ui->ButtonHex_2_8->x();
    y = ui->ButtonHex_2_8->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_2_8->x(), ui->ButtonHex_2_8->y()); ROPMove=std::make_pair(2,8);

    ui->ButtonHex_2_8->setIcon(ChangeIcon());
    ui->ButtonHex_2_8->move(x - 9, y - 8);
    ui->ButtonHex_2_8->setFixedSize(44, 44);
    ui->ButtonHex_2_8->setIconSize(QSize(44, 44));
    ui->ButtonHex_2_8->setEnabled(false);

    game.PlayerTurn(2,8, playerCurrent);
    if (game.VerifyRules(2, 8))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}


void HexUI::on_ButtonHex_2_9_clicked()
{
    int x, y;
    x = ui->ButtonHex_2_9->x();
    y = ui->ButtonHex_2_9->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_2_9->x(), ui->ButtonHex_2_9->y()); ROPMove=std::make_pair(2,9);

    ui->ButtonHex_2_9->setIcon(ChangeIcon());
    ui->ButtonHex_2_9->move(x - 9, y - 8);
    ui->ButtonHex_2_9->setFixedSize(44, 44);
    ui->ButtonHex_2_9->setIconSize(QSize(44, 44));
    ui->ButtonHex_2_9->setEnabled(false);

    game.PlayerTurn(2,9, playerCurrent);
    if (game.VerifyRules(2, 9))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_3_1_clicked()
{
    int x, y;
    x = ui->ButtonHex_3_1->x();
    y = ui->ButtonHex_3_1->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_3_1->x(), ui->ButtonHex_3_1->y()); ROPMove=std::make_pair(3,1);

    ui->ButtonHex_3_1->setIcon(ChangeIcon());
    ui->ButtonHex_3_1->move(x - 9, y - 8);
    ui->ButtonHex_3_1->setFixedSize(44, 44);
    ui->ButtonHex_3_1->setIconSize(QSize(44, 44));
    ui->ButtonHex_3_1->setEnabled(false);

    game.PlayerTurn(3,1, playerCurrent);
    if (game.VerifyRules(3, 1))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}


void HexUI::on_ButtonHex_3_2_clicked()
{
    int x, y;
    x = ui->ButtonHex_3_2->x();
    y = ui->ButtonHex_3_2->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_3_2->x(), ui->ButtonHex_3_2->y()); ROPMove=std::make_pair(3,2);

    ui->ButtonHex_3_2->setIcon(ChangeIcon());
    ui->ButtonHex_3_2->move(x - 9, y - 8);
    ui->ButtonHex_3_2->setFixedSize(44, 44);
    ui->ButtonHex_3_2->setIconSize(QSize(44, 44));
    ui->ButtonHex_3_2->setEnabled(false);

    game.PlayerTurn(3,2, playerCurrent);
    if (game.VerifyRules(3, 2))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_3_3_clicked()
{
    int x, y;
    x = ui->ButtonHex_3_3->x();
    y = ui->ButtonHex_3_3->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_3_3->x(), ui->ButtonHex_3_3->y()); ROPMove=std::make_pair(3,3);

    ui->ButtonHex_3_3->setIcon(ChangeIcon());
    ui->ButtonHex_3_3->move(x - 9, y - 8);
    ui->ButtonHex_3_3->setFixedSize(44, 44);
    ui->ButtonHex_3_3->setIconSize(QSize(44, 44));
    ui->ButtonHex_3_3->setEnabled(false);

    game.PlayerTurn(3,3, playerCurrent);
    if (game.VerifyRules(3, 3))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_3_4_clicked()
{
    int x, y;
    x = ui->ButtonHex_3_4->x();
    y = ui->ButtonHex_3_4->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_3_4->x(), ui->ButtonHex_3_4->y()); ROPMove=std::make_pair(3,4);

    ui->ButtonHex_3_4->setIcon(ChangeIcon());
    ui->ButtonHex_3_4->move(x - 9, y - 8);
    ui->ButtonHex_3_4->setFixedSize(44, 44);
    ui->ButtonHex_3_4->setIconSize(QSize(44, 44));
    ui->ButtonHex_3_4->setEnabled(false);

    game.PlayerTurn(3,4, playerCurrent);
    if (game.VerifyRules(3, 4))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_3_5_clicked()
{
    int x, y;
    x = ui->ButtonHex_3_5->x();
    y = ui->ButtonHex_3_5->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_3_5->x(), ui->ButtonHex_3_5->y()); ROPMove=std::make_pair(3,5);

    ui->ButtonHex_3_5->setIcon(ChangeIcon());
    ui->ButtonHex_3_5->move(x - 9, y - 8);
    ui->ButtonHex_3_5->setFixedSize(44, 44);
    ui->ButtonHex_3_5->setIconSize(QSize(44, 44));
    ui->ButtonHex_3_5->setEnabled(false);

    game.PlayerTurn(3,5, playerCurrent);
    if (game.VerifyRules(3, 5))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_3_6_clicked()
{
    int x, y;
    x = ui->ButtonHex_3_6->x();
    y = ui->ButtonHex_3_6->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_3_6->x(), ui->ButtonHex_3_6->y()); ROPMove=std::make_pair(3,6);

    ui->ButtonHex_3_6->setIcon(ChangeIcon());
    ui->ButtonHex_3_6->move(x - 9, y - 8);
    ui->ButtonHex_3_6->setFixedSize(44, 44);
    ui->ButtonHex_3_6->setIconSize(QSize(44, 44));
    ui->ButtonHex_3_6->setEnabled(false);

    game.PlayerTurn(3,6, playerCurrent);
    if (game.VerifyRules(3, 6))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_3_7_clicked()
{
    int x, y;
    x = ui->ButtonHex_3_7->x();
    y = ui->ButtonHex_3_7->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_3_7->x(), ui->ButtonHex_3_7->y()); ROPMove=std::make_pair(3,7);

    ui->ButtonHex_3_7->setIcon(ChangeIcon());
    ui->ButtonHex_3_7->move(x - 9, y - 8);
    ui->ButtonHex_3_7->setFixedSize(44, 44);
    ui->ButtonHex_3_7->setIconSize(QSize(44, 44));
    ui->ButtonHex_3_7->setEnabled(false);

    game.PlayerTurn(3,7, playerCurrent);
    if (game.VerifyRules(3, 7))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_3_8_clicked()
{
    int x, y;
    x = ui->ButtonHex_3_8->x();
    y = ui->ButtonHex_3_8->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_3_8->x(), ui->ButtonHex_3_8->y()); ROPMove=std::make_pair(3,8);

    ui->ButtonHex_3_8->setIcon(ChangeIcon());
    ui->ButtonHex_3_8->move(x - 9, y - 8);
    ui->ButtonHex_3_8->setFixedSize(44, 44);
    ui->ButtonHex_3_8->setIconSize(QSize(44, 44));
    ui->ButtonHex_3_8->setEnabled(false);

    game.PlayerTurn(3,8, playerCurrent);
    if (game.VerifyRules(3, 8))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}


void HexUI::on_ButtonHex_3_9_clicked()
{
    int x, y;
    x = ui->ButtonHex_3_9->x();
    y = ui->ButtonHex_3_9->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_3_9->x(), ui->ButtonHex_3_9->y()); ROPMove=std::make_pair(3,9);

    ui->ButtonHex_3_9->setIcon(ChangeIcon());
    ui->ButtonHex_3_9->move(x - 9, y - 8);
    ui->ButtonHex_3_9->setFixedSize(44, 44);
    ui->ButtonHex_3_9->setIconSize(QSize(44, 44));
    ui->ButtonHex_3_9->setEnabled(false);

    game.PlayerTurn(3,9, playerCurrent);
    if (game.VerifyRules(3, 9))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}
void HexUI::on_ButtonHex_4_1_clicked()
{
    int x, y;
    x = ui->ButtonHex_4_1->x();
    y = ui->ButtonHex_4_1->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_4_1->x(), ui->ButtonHex_4_1->y()); ROPMove=std::make_pair(4,1);

    ui->ButtonHex_4_1->setIcon(ChangeIcon());
    ui->ButtonHex_4_1->move(x - 9, y - 8);
    ui->ButtonHex_4_1->setFixedSize(44, 44);
    ui->ButtonHex_4_1->setIconSize(QSize(44, 44));
    ui->ButtonHex_4_1->setEnabled(false);

    game.PlayerTurn(4,1, playerCurrent);
    if (game.VerifyRules(4, 1))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}


void HexUI::on_ButtonHex_4_2_clicked()
{
    int x, y;
    x = ui->ButtonHex_4_2->x();
    y = ui->ButtonHex_4_2->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_4_2->x(), ui->ButtonHex_4_2->y()); ROPMove=std::make_pair(4,2);

    ui->ButtonHex_4_2->setIcon(ChangeIcon());
    ui->ButtonHex_4_2->move(x - 9, y - 8);
    ui->ButtonHex_4_2->setFixedSize(44, 44);
    ui->ButtonHex_4_2->setIconSize(QSize(44, 44));
    ui->ButtonHex_4_2->setEnabled(false);

    game.PlayerTurn(4,2, playerCurrent);
    if (game.VerifyRules(4, 2))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_4_3_clicked()
{
    int x, y;
    x = ui->ButtonHex_4_3->x();
    y = ui->ButtonHex_4_3->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_4_3->x(), ui->ButtonHex_4_3->y()); ROPMove=std::make_pair(4,3);

    ui->ButtonHex_4_3->setIcon(ChangeIcon());
    ui->ButtonHex_4_3->move(x - 9, y - 8);
    ui->ButtonHex_4_3->setFixedSize(44, 44);
    ui->ButtonHex_4_3->setIconSize(QSize(44, 44));
    ui->ButtonHex_4_3->setEnabled(false);

    game.PlayerTurn(4,3, playerCurrent);
    if (game.VerifyRules(4, 3))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_4_4_clicked()
{
    int x, y;
    x = ui->ButtonHex_4_4->x();
    y = ui->ButtonHex_4_4->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_4_4->x(), ui->ButtonHex_4_4->y()); ROPMove=std::make_pair(4,4);

    ui->ButtonHex_4_4->setIcon(ChangeIcon());
    ui->ButtonHex_4_4->move(x - 9, y - 8);
    ui->ButtonHex_4_4->setFixedSize(44, 44);
    ui->ButtonHex_4_4->setIconSize(QSize(44, 44));
    ui->ButtonHex_4_4->setEnabled(false);

    game.PlayerTurn(4,4, playerCurrent);
    if (game.VerifyRules(4, 4))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_4_5_clicked()
{
    int x, y;
    x = ui->ButtonHex_4_5->x();
    y = ui->ButtonHex_4_5->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_4_5->x(), ui->ButtonHex_4_5->y()); ROPMove=std::make_pair(4,5);

    ui->ButtonHex_4_5->setIcon(ChangeIcon());
    ui->ButtonHex_4_5->move(x - 9, y - 8);
    ui->ButtonHex_4_5->setFixedSize(44, 44);
    ui->ButtonHex_4_5->setIconSize(QSize(44, 44));
    ui->ButtonHex_4_5->setEnabled(false);

    game.PlayerTurn(4,5, playerCurrent);
    if (game.VerifyRules(4, 5))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_4_6_clicked()
{
    int x, y;
    x = ui->ButtonHex_4_6->x();
    y = ui->ButtonHex_4_6->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_4_6->x(), ui->ButtonHex_4_6->y()); ROPMove=std::make_pair(4,6);

    ui->ButtonHex_4_6->setIcon(ChangeIcon());
    ui->ButtonHex_4_6->move(x - 9, y - 8);
    ui->ButtonHex_4_6->setFixedSize(44, 44);
    ui->ButtonHex_4_6->setIconSize(QSize(44, 44));
    ui->ButtonHex_4_6->setEnabled(false);

    game.PlayerTurn(4,6, playerCurrent);
    if (game.VerifyRules(4, 6))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_4_7_clicked()
{
    int x, y;
    x = ui->ButtonHex_4_7->x();
    y = ui->ButtonHex_4_7->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_4_7->x(), ui->ButtonHex_4_7->y()); ROPMove=std::make_pair(4,7);

    ui->ButtonHex_4_7->setIcon(ChangeIcon());
    ui->ButtonHex_4_7->move(x - 9, y - 8);
    ui->ButtonHex_4_7->setFixedSize(44, 44);
    ui->ButtonHex_4_7->setIconSize(QSize(44, 44));
    ui->ButtonHex_4_7->setEnabled(false);

    game.PlayerTurn(4,7, playerCurrent);
    if (game.VerifyRules(4, 7))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_4_8_clicked()
{
    int x, y;
    x = ui->ButtonHex_4_8->x();
    y = ui->ButtonHex_4_8->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_4_8->x(), ui->ButtonHex_4_8->y()); ROPMove=std::make_pair(4,8);

    ui->ButtonHex_4_8->setIcon(ChangeIcon());
    ui->ButtonHex_4_8->move(x - 9, y - 8);
    ui->ButtonHex_4_8->setFixedSize(44, 44);
    ui->ButtonHex_4_8->setIconSize(QSize(44, 44));
    ui->ButtonHex_4_8->setEnabled(false);

    game.PlayerTurn(4,8, playerCurrent);
    if (game.VerifyRules(4, 8))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}


void HexUI::on_ButtonHex_4_9_clicked()
{
    int x, y;
    x = ui->ButtonHex_4_9->x();
    y = ui->ButtonHex_4_9->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_4_9->x(), ui->ButtonHex_4_9->y()); ROPMove=std::make_pair(4,9);

    ui->ButtonHex_4_9->setIcon(ChangeIcon());
    ui->ButtonHex_4_9->move(x - 9, y - 8);
    ui->ButtonHex_4_9->setFixedSize(44, 44);
    ui->ButtonHex_4_9->setIconSize(QSize(44, 44));
    ui->ButtonHex_4_9->setEnabled(false);

    game.PlayerTurn(4,9, playerCurrent);
    if (game.VerifyRules(4, 9))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}
void HexUI::on_ButtonHex_5_1_clicked()
{
    int x, y;
    x = ui->ButtonHex_5_1->x();
    y = ui->ButtonHex_5_1->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_5_1->x(), ui->ButtonHex_5_1->y()); ROPMove=std::make_pair(5,1);

    ui->ButtonHex_5_1->setIcon(ChangeIcon());
    ui->ButtonHex_5_1->move(x - 9, y - 8);
    ui->ButtonHex_5_1->setFixedSize(44, 44);
    ui->ButtonHex_5_1->setIconSize(QSize(44, 44));
    ui->ButtonHex_5_1->setEnabled(false);

    game.PlayerTurn(5,1, playerCurrent);
    if (game.VerifyRules(5, 1))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}


void HexUI::on_ButtonHex_5_2_clicked()
{
    int x, y;
    x = ui->ButtonHex_5_2->x();
    y = ui->ButtonHex_5_2->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_5_2->x(), ui->ButtonHex_5_2->y()); ROPMove=std::make_pair(5,2);

    ui->ButtonHex_5_2->setIcon(ChangeIcon());
    ui->ButtonHex_5_2->move(x - 9, y - 8);
    ui->ButtonHex_5_2->setFixedSize(44, 44);
    ui->ButtonHex_5_2->setIconSize(QSize(44, 44));
    ui->ButtonHex_5_2->setEnabled(false);

    game.PlayerTurn(5,2, playerCurrent);
    if (game.VerifyRules(5, 2))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_5_3_clicked()
{
    int x, y;
    x = ui->ButtonHex_5_3->x();
    y = ui->ButtonHex_5_3->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_5_3->x(), ui->ButtonHex_5_3->y()); ROPMove=std::make_pair(5,3);

    ui->ButtonHex_5_3->setIcon(ChangeIcon());
    ui->ButtonHex_5_3->move(x - 9, y - 8);
    ui->ButtonHex_5_3->setFixedSize(44, 44);
    ui->ButtonHex_5_3->setIconSize(QSize(44, 44));
    ui->ButtonHex_5_3->setEnabled(false);

    game.PlayerTurn(5,3, playerCurrent);
    if (game.VerifyRules(5, 3))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_5_4_clicked()
{
    int x, y;
    x = ui->ButtonHex_5_4->x();
    y = ui->ButtonHex_5_4->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_5_4->x(), ui->ButtonHex_5_4->y()); ROPMove=std::make_pair(5,4);
    ui->ButtonHex_5_4->setIcon(ChangeIcon());
    ui->ButtonHex_5_4->move(x - 9, y - 8);
    ui->ButtonHex_5_4->setFixedSize(44, 44);
    ui->ButtonHex_5_4->setIconSize(QSize(44, 44));
    ui->ButtonHex_5_4->setEnabled(false);

    game.PlayerTurn(5,4, playerCurrent);
    if (game.VerifyRules(5, 4))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_5_5_clicked()
{
    int x, y;
    x = ui->ButtonHex_5_5->x();
    y = ui->ButtonHex_5_5->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_5_5->x(), ui->ButtonHex_5_5->y()); ROPMove=std::make_pair(5,5);

    ui->ButtonHex_5_5->setIcon(ChangeIcon());
    ui->ButtonHex_5_5->move(x - 9, y - 8);
    ui->ButtonHex_5_5->setFixedSize(44, 44);
    ui->ButtonHex_5_5->setIconSize(QSize(44, 44));
    ui->ButtonHex_5_5->setEnabled(false);

    game.PlayerTurn(5,5, playerCurrent);
    if (game.VerifyRules(5, 5))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_5_6_clicked()
{
    int x, y;
    x = ui->ButtonHex_5_6->x();
    y = ui->ButtonHex_5_6->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_5_6->x(), ui->ButtonHex_5_6->y()); ROPMove=std::make_pair(5,6);

    ui->ButtonHex_5_6->setIcon(ChangeIcon());
    ui->ButtonHex_5_6->move(x - 9, y - 8);
    ui->ButtonHex_5_6->setFixedSize(44, 44);
    ui->ButtonHex_5_6->setIconSize(QSize(44, 44));
    ui->ButtonHex_5_6->setEnabled(false);

    game.PlayerTurn(5,6, playerCurrent);
    if (game.VerifyRules(5, 6))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_5_7_clicked()
{
    int x, y;
    x = ui->ButtonHex_5_7->x();
    y = ui->ButtonHex_5_7->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_5_7->x(), ui->ButtonHex_5_7->y()); ROPMove=std::make_pair(5,7);

    ui->ButtonHex_5_7->setIcon(ChangeIcon());
    ui->ButtonHex_5_7->move(x - 9, y - 8);
    ui->ButtonHex_5_7->setFixedSize(44, 44);
    ui->ButtonHex_5_7->setIconSize(QSize(44, 44));
    ui->ButtonHex_5_7->setEnabled(false);

    game.PlayerTurn(5,7, playerCurrent);
    if (game.VerifyRules(5, 7))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_5_8_clicked()
{
    int x, y;
    x = ui->ButtonHex_5_8->x();
    y = ui->ButtonHex_5_8->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_5_8->x(), ui->ButtonHex_5_8->y()); ROPMove=std::make_pair(5,8);

    ui->ButtonHex_5_8->setIcon(ChangeIcon());
    ui->ButtonHex_5_8->move(x - 9, y - 8);
    ui->ButtonHex_5_8->setFixedSize(44, 44);
    ui->ButtonHex_5_8->setIconSize(QSize(44, 44));
    ui->ButtonHex_5_8->setEnabled(false);

    game.PlayerTurn(5,8, playerCurrent);
    if (game.VerifyRules(5, 8))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}


void HexUI::on_ButtonHex_5_9_clicked()
{
    int x, y;
    x = ui->ButtonHex_5_9->x();
    y = ui->ButtonHex_5_9->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_5_9->x(), ui->ButtonHex_5_9->y()); ROPMove=std::make_pair(5,9);

    ui->ButtonHex_5_9->setIcon(ChangeIcon());
    ui->ButtonHex_5_9->move(x - 9, y - 8);
    ui->ButtonHex_5_9->setFixedSize(44, 44);
    ui->ButtonHex_5_9->setIconSize(QSize(44, 44));
    ui->ButtonHex_5_9->setEnabled(false);

    game.PlayerTurn(5,9, playerCurrent);
    if (game.VerifyRules(5, 9))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_6_1_clicked()
{
    int x, y;
    x = ui->ButtonHex_6_1->x();
    y = ui->ButtonHex_6_1->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_6_1->x(), ui->ButtonHex_6_1->y()); ROPMove=std::make_pair(6,1);

    ui->ButtonHex_6_1->setIcon(ChangeIcon());
    ui->ButtonHex_6_1->move(x - 9, y - 8);
    ui->ButtonHex_6_1->setFixedSize(44, 44);
    ui->ButtonHex_6_1->setIconSize(QSize(44, 44));
    ui->ButtonHex_6_1->setEnabled(false);

    game.PlayerTurn(6,1, playerCurrent);
    if (game.VerifyRules(6, 1))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}


void HexUI::on_ButtonHex_6_2_clicked()
{
    int x, y;
    x = ui->ButtonHex_6_2->x();
    y = ui->ButtonHex_6_2->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_6_2->x(), ui->ButtonHex_6_2->y()); ROPMove=std::make_pair(6,2);

    ui->ButtonHex_6_2->setIcon(ChangeIcon());
    ui->ButtonHex_6_2->move(x - 9, y - 8);
    ui->ButtonHex_6_2->setFixedSize(44, 44);
    ui->ButtonHex_6_2->setIconSize(QSize(44, 44));
    ui->ButtonHex_6_2->setEnabled(false);

    game.PlayerTurn(6,2, playerCurrent);
    if (game.VerifyRules(6, 2))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_6_3_clicked()
{
    int x, y;
    x = ui->ButtonHex_6_3->x();
    y = ui->ButtonHex_6_3->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_6_3->x(), ui->ButtonHex_6_3->y()); ROPMove=std::make_pair(6,3);

    ui->ButtonHex_6_3->setIcon(ChangeIcon());
    ui->ButtonHex_6_3->move(x - 9, y - 8);
    ui->ButtonHex_6_3->setFixedSize(44, 44);
    ui->ButtonHex_6_3->setIconSize(QSize(44, 44));
    ui->ButtonHex_6_3->setEnabled(false);

    game.PlayerTurn(6,3, playerCurrent);
    if (game.VerifyRules(6, 3))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_6_4_clicked()
{
    int x, y;
    x = ui->ButtonHex_6_4->x();
    y = ui->ButtonHex_6_4->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_6_4->x(), ui->ButtonHex_6_4->y()); ROPMove=std::make_pair(6,4);

    ui->ButtonHex_6_4->setIcon(ChangeIcon());
    ui->ButtonHex_6_4->move(x - 9, y - 8);
    ui->ButtonHex_6_4->setFixedSize(44, 44);
    ui->ButtonHex_6_4->setIconSize(QSize(44, 44));
    ui->ButtonHex_6_4->setEnabled(false);

    game.PlayerTurn(6,4, playerCurrent);
    if (game.VerifyRules(6, 4))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_6_5_clicked()
{
    int x, y;
    x = ui->ButtonHex_6_5->x();
    y = ui->ButtonHex_6_5->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_6_5->x(), ui->ButtonHex_6_5->y()); ROPMove=std::make_pair(6,5);

    ui->ButtonHex_6_5->setIcon(ChangeIcon());
    ui->ButtonHex_6_5->move(x - 9, y - 8);
    ui->ButtonHex_6_5->setFixedSize(44, 44);
    ui->ButtonHex_6_5->setIconSize(QSize(44, 44));
    ui->ButtonHex_6_5->setEnabled(false);

    game.PlayerTurn(6,5, playerCurrent);
    if (game.VerifyRules(6, 5))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_6_6_clicked()
{
    int x, y;
    x = ui->ButtonHex_6_6->x();
    y = ui->ButtonHex_6_6->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_6_6->x(), ui->ButtonHex_6_6->y()); ROPMove=std::make_pair(6,6);

    ui->ButtonHex_6_6->setIcon(ChangeIcon());
    ui->ButtonHex_6_6->move(x - 9, y - 8);
    ui->ButtonHex_6_6->setFixedSize(44, 44);
    ui->ButtonHex_6_6->setIconSize(QSize(44, 44));
    ui->ButtonHex_6_6->setEnabled(false);

    game.PlayerTurn(6,6, playerCurrent);
    if (game.VerifyRules(6, 6))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_6_7_clicked()
{
    int x, y;
    x = ui->ButtonHex_6_7->x();
    y = ui->ButtonHex_6_7->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_6_7->x(), ui->ButtonHex_6_7->y()); ROPMove=std::make_pair(6,7);

    ui->ButtonHex_6_7->setIcon(ChangeIcon());
    ui->ButtonHex_6_7->move(x - 9, y - 8);
    ui->ButtonHex_6_7->setFixedSize(44, 44);
    ui->ButtonHex_6_7->setIconSize(QSize(44, 44));
    ui->ButtonHex_6_7->setEnabled(false);

    game.PlayerTurn(6,7, playerCurrent);
    if (game.VerifyRules(6, 7))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_6_8_clicked()
{
    int x, y;
    x = ui->ButtonHex_6_8->x();
    y = ui->ButtonHex_6_8->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_6_8->x(), ui->ButtonHex_6_8->y()); ROPMove=std::make_pair(6,8);

    ui->ButtonHex_6_8->setIcon(ChangeIcon());
    ui->ButtonHex_6_8->move(x - 9, y - 8);
    ui->ButtonHex_6_8->setFixedSize(44, 44);
    ui->ButtonHex_6_8->setIconSize(QSize(44, 44));
    ui->ButtonHex_6_8->setEnabled(false);

    game.PlayerTurn(6,8, playerCurrent);
    if (game.VerifyRules(6, 8))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}


void HexUI::on_ButtonHex_6_9_clicked()
{
    int x, y;
    x = ui->ButtonHex_6_9->x();
    y = ui->ButtonHex_6_9->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_6_9->x(), ui->ButtonHex_6_9->y()); ROPMove=std::make_pair(6,9);

    ui->ButtonHex_6_9->setIcon(ChangeIcon());
    ui->ButtonHex_6_9->move(x - 9, y - 8);
    ui->ButtonHex_6_9->setFixedSize(44, 44);
    ui->ButtonHex_6_9->setIconSize(QSize(44, 44));
    ui->ButtonHex_6_9->setEnabled(false);

    game.PlayerTurn(6,9, playerCurrent);
    if (game.VerifyRules(6, 9))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_7_1_clicked()
{
    int x, y;
    x = ui->ButtonHex_7_1->x();
    y = ui->ButtonHex_7_1->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_7_1->x(), ui->ButtonHex_7_1->y()); ROPMove=std::make_pair(7,1);

    ui->ButtonHex_7_1->setIcon(ChangeIcon());
    ui->ButtonHex_7_1->move(x - 9, y - 8);
    ui->ButtonHex_7_1->setFixedSize(44, 44);
    ui->ButtonHex_7_1->setIconSize(QSize(44, 44));
    ui->ButtonHex_7_1->setEnabled(false);

    game.PlayerTurn(7,1, playerCurrent);
    if (game.VerifyRules(7, 1))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}


void HexUI::on_ButtonHex_7_2_clicked()
{
    int x, y;
    x = ui->ButtonHex_7_2->x();
    y = ui->ButtonHex_7_2->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_7_2->x(), ui->ButtonHex_7_2->y()); ROPMove=std::make_pair(7,2);

    ui->ButtonHex_7_2->setIcon(ChangeIcon());
    ui->ButtonHex_7_2->move(x - 9, y - 8);
    ui->ButtonHex_7_2->setFixedSize(44, 44);
    ui->ButtonHex_7_2->setIconSize(QSize(44, 44));
    ui->ButtonHex_7_2->setEnabled(false);

    game.PlayerTurn(7,2, playerCurrent);
    if (game.VerifyRules(7, 2))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_7_3_clicked()
{
    int x, y;
    x = ui->ButtonHex_7_3->x();
    y = ui->ButtonHex_7_3->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_7_3->x(), ui->ButtonHex_7_3->y()); ROPMove=std::make_pair(7,3);

    ui->ButtonHex_7_3->setIcon(ChangeIcon());
    ui->ButtonHex_7_3->move(x - 9, y - 8);
    ui->ButtonHex_7_3->setFixedSize(44, 44);
    ui->ButtonHex_7_3->setIconSize(QSize(44, 44));
    ui->ButtonHex_7_3->setEnabled(false);

    game.PlayerTurn(7,3, playerCurrent);
    if (game.VerifyRules(7, 3))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_7_4_clicked()
{
    int x, y;
    x = ui->ButtonHex_7_4->x();
    y = ui->ButtonHex_7_4->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_7_4->x(), ui->ButtonHex_7_4->y()); ROPMove=std::make_pair(7,4);

    ui->ButtonHex_7_4->setIcon(ChangeIcon());
    ui->ButtonHex_7_4->move(x - 9, y - 8);
    ui->ButtonHex_7_4->setFixedSize(44, 44);
    ui->ButtonHex_7_4->setIconSize(QSize(44, 44));
    ui->ButtonHex_7_4->setEnabled(false);

    game.PlayerTurn(7,4, playerCurrent);
    if (game.VerifyRules(7, 4))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_7_5_clicked()
{
    int x, y;
    x = ui->ButtonHex_7_5->x();
    y = ui->ButtonHex_7_5->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_7_5->x(), ui->ButtonHex_7_5->y()); ROPMove=std::make_pair(7,5);

    ui->ButtonHex_7_5->setIcon(ChangeIcon());
    ui->ButtonHex_7_5->move(x - 9, y - 8);
    ui->ButtonHex_7_5->setFixedSize(44, 44);
    ui->ButtonHex_7_5->setIconSize(QSize(44, 44));
    ui->ButtonHex_7_5->setEnabled(false);

    game.PlayerTurn(7,5, playerCurrent);
    if (game.VerifyRules(7, 5))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_7_6_clicked()
{
    int x, y;
    x = ui->ButtonHex_7_6->x();
    y = ui->ButtonHex_7_6->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_7_6->x(), ui->ButtonHex_7_6->y()); ROPMove=std::make_pair(7,6);

    ui->ButtonHex_7_6->setIcon(ChangeIcon());
    ui->ButtonHex_7_6->move(x - 9, y - 8);
    ui->ButtonHex_7_6->setFixedSize(44, 44);
    ui->ButtonHex_7_6->setIconSize(QSize(44, 44));
    ui->ButtonHex_7_6->setEnabled(false);

    game.PlayerTurn(7,6, playerCurrent);
    if (game.VerifyRules(7, 6))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_7_7_clicked()
{
    int x, y;
    x = ui->ButtonHex_7_7->x();
    y = ui->ButtonHex_7_7->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_7_7->x(), ui->ButtonHex_7_7->y()); ROPMove=std::make_pair(7,7);

    ui->ButtonHex_7_7->setIcon(ChangeIcon());
    ui->ButtonHex_7_7->move(x - 9, y - 8);
    ui->ButtonHex_7_7->setFixedSize(44, 44);
    ui->ButtonHex_7_7->setIconSize(QSize(44, 44));
    ui->ButtonHex_7_7->setEnabled(false);

    game.PlayerTurn(7,7, playerCurrent);
    if (game.VerifyRules(7, 7))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_7_8_clicked()
{
    int x, y;
    x = ui->ButtonHex_7_8->x();
    y = ui->ButtonHex_7_8->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_7_8->x(), ui->ButtonHex_7_8->y()); ROPMove=std::make_pair(7,8);

    ui->ButtonHex_7_8->setIcon(ChangeIcon());
    ui->ButtonHex_7_8->move(x - 9, y - 8);
    ui->ButtonHex_7_8->setFixedSize(44, 44);
    ui->ButtonHex_7_8->setIconSize(QSize(44, 44));
    ui->ButtonHex_7_8->setEnabled(false);

    game.PlayerTurn(7,8, playerCurrent);
    if (game.VerifyRules(7, 8))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}


void HexUI::on_ButtonHex_7_9_clicked()
{
    int x, y;
    x = ui->ButtonHex_7_9->x();
    y = ui->ButtonHex_7_9->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_7_9->x(), ui->ButtonHex_7_9->y()); ROPMove=std::make_pair(7,9);

    ui->ButtonHex_7_9->setIcon(ChangeIcon());
    ui->ButtonHex_7_9->move(x - 9, y - 8);
    ui->ButtonHex_7_9->setFixedSize(44, 44);
    ui->ButtonHex_7_9->setIconSize(QSize(44, 44));
    ui->ButtonHex_7_9->setEnabled(false);

    game.PlayerTurn(7,9, playerCurrent);
    if (game.VerifyRules(7, 9))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_8_1_clicked()
{
    int x, y;
    x = ui->ButtonHex_8_1->x();
    y = ui->ButtonHex_8_1->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_8_1->x(), ui->ButtonHex_8_1->y()); ROPMove=std::make_pair(8,1);

    ui->ButtonHex_8_1->setIcon(ChangeIcon());
    ui->ButtonHex_8_1->move(x - 9, y - 8);
    ui->ButtonHex_8_1->setFixedSize(44, 44);
    ui->ButtonHex_8_1->setIconSize(QSize(44, 44));
    ui->ButtonHex_8_1->setEnabled(false);

    game.PlayerTurn(8,1, playerCurrent);
    if (game.VerifyRules(8, 1))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}


void HexUI::on_ButtonHex_8_2_clicked()
{
    int x, y;
    x = ui->ButtonHex_8_2->x();
    y = ui->ButtonHex_8_2->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_8_2->x(), ui->ButtonHex_8_2->y()); ROPMove=std::make_pair(8,2);

    ui->ButtonHex_8_2->setIcon(ChangeIcon());
    ui->ButtonHex_8_2->move(x - 9, y - 8);
    ui->ButtonHex_8_2->setFixedSize(44, 44);
    ui->ButtonHex_8_2->setIconSize(QSize(44, 44));
    ui->ButtonHex_8_2->setEnabled(false);

    game.PlayerTurn(8,2, playerCurrent);
    if (game.VerifyRules(8, 2))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_8_3_clicked()
{
    int x, y;
    x = ui->ButtonHex_8_3->x();
    y = ui->ButtonHex_8_3->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_8_3->x(), ui->ButtonHex_8_3->y()); ROPMove=std::make_pair(8,3);

    ui->ButtonHex_8_3->setIcon(ChangeIcon());
    ui->ButtonHex_8_3->move(x - 9, y - 8);
    ui->ButtonHex_8_3->setFixedSize(44, 44);
    ui->ButtonHex_8_3->setIconSize(QSize(44, 44));
    ui->ButtonHex_8_3->setEnabled(false);

    game.PlayerTurn(8,3, playerCurrent);
    if (game.VerifyRules(8, 3))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_8_4_clicked()
{
    int x, y;
    x = ui->ButtonHex_8_4->x();
    y = ui->ButtonHex_8_4->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_8_4->x(), ui->ButtonHex_8_4->y()); ROPMove=std::make_pair(8,4);

    ui->ButtonHex_8_4->setIcon(ChangeIcon());
    ui->ButtonHex_8_4->move(x - 9, y - 8);
    ui->ButtonHex_8_4->setFixedSize(44, 44);
    ui->ButtonHex_8_4->setIconSize(QSize(44, 44));
    ui->ButtonHex_8_4->setEnabled(false);

    game.PlayerTurn(8,4, playerCurrent);
    if (game.VerifyRules(8, 4))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_8_5_clicked()
{
    int x, y;
    x = ui->ButtonHex_8_5->x();
    y = ui->ButtonHex_8_5->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_8_5->x(), ui->ButtonHex_8_5->y()); ROPMove=std::make_pair(8,5);

    ui->ButtonHex_8_5->setIcon(ChangeIcon());
    ui->ButtonHex_8_5->move(x - 9, y - 8);
    ui->ButtonHex_8_5->setFixedSize(44, 44);
    ui->ButtonHex_8_5->setIconSize(QSize(44, 44));
    ui->ButtonHex_8_5->setEnabled(false);

    game.PlayerTurn(8,5, playerCurrent);
    if (game.VerifyRules(8, 5))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_8_6_clicked()
{
    int x, y;
    x = ui->ButtonHex_8_6->x();
    y = ui->ButtonHex_8_6->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_8_6->x(), ui->ButtonHex_8_6->y()); ROPMove=std::make_pair(8,6);

    ui->ButtonHex_8_6->setIcon(ChangeIcon());
    ui->ButtonHex_8_6->move(x - 9, y - 8);
    ui->ButtonHex_8_6->setFixedSize(44, 44);
    ui->ButtonHex_8_6->setIconSize(QSize(44, 44));
    ui->ButtonHex_8_6->setEnabled(false);

    game.PlayerTurn(8,6, playerCurrent);
    if (game.VerifyRules(8, 6))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_8_7_clicked()
{
    int x, y;
    x = ui->ButtonHex_8_7->x();
    y = ui->ButtonHex_8_7->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_8_7->x(), ui->ButtonHex_8_7->y()); ROPMove=std::make_pair(8,7);

    ui->ButtonHex_8_7->setIcon(ChangeIcon());
    ui->ButtonHex_8_7->move(x - 9, y - 8);
    ui->ButtonHex_8_7->setFixedSize(44, 44);
    ui->ButtonHex_8_7->setIconSize(QSize(44, 44));
    ui->ButtonHex_8_7->setEnabled(false);

    game.PlayerTurn(8,7, playerCurrent);
    if (game.VerifyRules(8, 7))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_8_8_clicked()
{
    int x, y;
    x = ui->ButtonHex_8_8->x();
    y = ui->ButtonHex_8_8->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_8_8->x(), ui->ButtonHex_8_8->y()); ROPMove=std::make_pair(8,8);

    ui->ButtonHex_8_8->setIcon(ChangeIcon());
    ui->ButtonHex_8_8->move(x - 9, y - 8);
    ui->ButtonHex_8_8->setFixedSize(44, 44);
    ui->ButtonHex_8_8->setIconSize(QSize(44, 44));
    ui->ButtonHex_8_8->setEnabled(false);

    game.PlayerTurn(8,8, playerCurrent);
    if (game.VerifyRules(8, 8))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}


void HexUI::on_ButtonHex_8_9_clicked()
{
    int x, y;
    x = ui->ButtonHex_8_9->x();
    y = ui->ButtonHex_8_9->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_8_9->x(), ui->ButtonHex_8_9->y()); ROPMove=std::make_pair(8,9);

    ui->ButtonHex_8_9->setIcon(ChangeIcon());
    ui->ButtonHex_8_9->move(x - 9, y - 8);
    ui->ButtonHex_8_9->setFixedSize(44, 44);
    ui->ButtonHex_8_9->setIconSize(QSize(44, 44));
    ui->ButtonHex_8_9->setEnabled(false);

    game.PlayerTurn(8,9, playerCurrent);
    if (game.VerifyRules(8, 9))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_9_1_clicked()
{
    int x, y;
    x = ui->ButtonHex_9_1->x();
    y = ui->ButtonHex_9_1->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_9_1->x(), ui->ButtonHex_9_1->y()); ROPMove=std::make_pair(9,1);

    ui->ButtonHex_9_1->setIcon(ChangeIcon());
    ui->ButtonHex_9_1->move(x - 9, y - 8);
    ui->ButtonHex_9_1->setFixedSize(44, 44);
    ui->ButtonHex_9_1->setIconSize(QSize(44, 44));
    ui->ButtonHex_9_1->setEnabled(false);

    game.PlayerTurn(9,1, playerCurrent);
    if (game.VerifyRules(9, 1))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}


void HexUI::on_ButtonHex_9_2_clicked()
{
    int x, y;
    x = ui->ButtonHex_9_2->x();
    y = ui->ButtonHex_9_2->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_9_2->x(), ui->ButtonHex_9_2->y()); ROPMove=std::make_pair(9,2);

    ui->ButtonHex_9_2->setIcon(ChangeIcon());
    ui->ButtonHex_9_2->move(x - 9, y - 8);
    ui->ButtonHex_9_2->setFixedSize(44, 44);
    ui->ButtonHex_9_2->setIconSize(QSize(44, 44));
    ui->ButtonHex_9_2->setEnabled(false);

    game.PlayerTurn(9,2, playerCurrent);
    if (game.VerifyRules(9, 2))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_9_3_clicked()
{
    int x, y;
    x = ui->ButtonHex_9_3->x();
    y = ui->ButtonHex_9_3->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_9_3->x(), ui->ButtonHex_9_3->y()); ROPMove=std::make_pair(9,3);

    ui->ButtonHex_9_3->setIcon(ChangeIcon());
    ui->ButtonHex_9_3->move(x - 9, y - 8);
    ui->ButtonHex_9_3->setFixedSize(44, 44);
    ui->ButtonHex_9_3->setIconSize(QSize(44, 44));
    ui->ButtonHex_9_3->setEnabled(false);

    game.PlayerTurn(9,3, playerCurrent);
    if (game.VerifyRules(9, 3))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_9_4_clicked()
{
    int x, y;
    x = ui->ButtonHex_9_4->x();
    y = ui->ButtonHex_9_4->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_9_4->x(), ui->ButtonHex_9_4->y()); ROPMove=std::make_pair(9,4);

    ui->ButtonHex_9_4->setIcon(ChangeIcon());
    ui->ButtonHex_9_4->move(x - 9, y - 8);
    ui->ButtonHex_9_4->setFixedSize(44, 44);
    ui->ButtonHex_9_4->setIconSize(QSize(44, 44));
    ui->ButtonHex_9_4->setEnabled(false);

    game.PlayerTurn(9,4, playerCurrent);
    if (game.VerifyRules(9, 4))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_9_5_clicked()
{
    int x, y;
    x = ui->ButtonHex_9_5->x();
    y = ui->ButtonHex_9_5->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_9_5->x(), ui->ButtonHex_9_5->y()); ROPMove=std::make_pair(9,5);

    ui->ButtonHex_9_5->setIcon(ChangeIcon());
    ui->ButtonHex_9_5->move(x - 9, y - 8);
    ui->ButtonHex_9_5->setFixedSize(44, 44);
    ui->ButtonHex_9_5->setIconSize(QSize(44, 44));
    ui->ButtonHex_9_5->setEnabled(false);

    game.PlayerTurn(9,5, playerCurrent);
    if (game.VerifyRules(9, 5))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_9_6_clicked()
{
    int x, y;
    x = ui->ButtonHex_9_6->x();
    y = ui->ButtonHex_9_6->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_9_6->x(), ui->ButtonHex_9_6->y()); ROPMove=std::make_pair(9,6);

    ui->ButtonHex_9_6->setIcon(ChangeIcon());
    ui->ButtonHex_9_6->move(x - 9, y - 8);
    ui->ButtonHex_9_6->setFixedSize(44, 44);
    ui->ButtonHex_9_6->setIconSize(QSize(44, 44));
    ui->ButtonHex_9_6->setEnabled(false);

    game.PlayerTurn(9,6, playerCurrent);
    if (game.VerifyRules(9, 6))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_9_7_clicked()
{
    int x, y;
    x = ui->ButtonHex_9_7->x();
    y = ui->ButtonHex_9_7->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_9_7->x(), ui->ButtonHex_9_7->y()); ROPMove=std::make_pair(9,7);

    ui->ButtonHex_9_7->setIcon(ChangeIcon());
    ui->ButtonHex_9_7->move(x - 9, y - 8);
    ui->ButtonHex_9_7->setFixedSize(44, 44);
    ui->ButtonHex_9_7->setIconSize(QSize(44, 44));
    ui->ButtonHex_9_7->setEnabled(false);

    game.PlayerTurn(9,7, playerCurrent);
    if (game.VerifyRules(9, 7))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_9_8_clicked()
{
    int x, y;
    x = ui->ButtonHex_9_8->x();
    y = ui->ButtonHex_9_8->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_9_8->x(), ui->ButtonHex_9_8->y()); ROPMove=std::make_pair(9,8);

    ui->ButtonHex_9_8->setIcon(ChangeIcon());
    ui->ButtonHex_9_8->move(x - 9, y - 8);
    ui->ButtonHex_9_8->setFixedSize(44, 44);
    ui->ButtonHex_9_8->setIconSize(QSize(44, 44));
    ui->ButtonHex_9_8->setEnabled(false);

    game.PlayerTurn(9,8, playerCurrent);
    if (game.VerifyRules(9, 8))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}


void HexUI::on_ButtonHex_9_9_clicked()
{
    int x, y;
    x = ui->ButtonHex_9_9->x();
    y = ui->ButtonHex_9_9->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_9_9->x(), ui->ButtonHex_9_9->y()); ROPMove=std::make_pair(9,9);

    ui->ButtonHex_9_9->setIcon(ChangeIcon());
    ui->ButtonHex_9_9->move(x - 9, y - 8);
    ui->ButtonHex_9_9->setFixedSize(44, 44);
    ui->ButtonHex_9_9->setIconSize(QSize(44, 44));
    ui->ButtonHex_9_9->setEnabled(false);

    game.PlayerTurn(9,9, playerCurrent);
    if (game.VerifyRules(9, 9))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_10_1_clicked()
{
    int x, y;
    x = ui->ButtonHex_10_1->x();
    y = ui->ButtonHex_10_1->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_10_1->x(), ui->ButtonHex_10_1->y()); ROPMove=std::make_pair(10,1);

    ui->ButtonHex_10_1->setIcon(ChangeIcon());
    ui->ButtonHex_10_1->move(x - 9, y - 8);
    ui->ButtonHex_10_1->setFixedSize(44, 44);
    ui->ButtonHex_10_1->setIconSize(QSize(44, 44));
    ui->ButtonHex_10_1->setEnabled(false);

    game.PlayerTurn(10,1, playerCurrent);
    if (game.VerifyRules(10, 1))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}


void HexUI::on_ButtonHex_10_2_clicked()
{
    int x, y;
    x = ui->ButtonHex_10_2->x();
    y = ui->ButtonHex_10_2->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_10_2->x(), ui->ButtonHex_10_2->y()); ROPMove=std::make_pair(10,2);

    ui->ButtonHex_10_2->setIcon(ChangeIcon());
    ui->ButtonHex_10_2->move(x - 9, y - 8);
    ui->ButtonHex_10_2->setFixedSize(44, 44);
    ui->ButtonHex_10_2->setIconSize(QSize(44, 44));
    ui->ButtonHex_10_2->setEnabled(false);

    game.PlayerTurn(10,2, playerCurrent);
    if (game.VerifyRules(10, 2))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_10_3_clicked()
{
    int x, y;
    x = ui->ButtonHex_10_3->x();
    y = ui->ButtonHex_10_3->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_10_3->x(), ui->ButtonHex_10_3->y()); ROPMove=std::make_pair(10,3);

    ui->ButtonHex_10_3->setIcon(ChangeIcon());
    ui->ButtonHex_10_3->move(x - 9, y - 8);
    ui->ButtonHex_10_3->setFixedSize(44, 44);
    ui->ButtonHex_10_3->setIconSize(QSize(44, 44));
    ui->ButtonHex_10_3->setEnabled(false);

    game.PlayerTurn(10,3, playerCurrent);
    if (game.VerifyRules(10, 3))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_10_4_clicked()
{
    int x, y;
    x = ui->ButtonHex_10_4->x();
    y = ui->ButtonHex_10_4->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_10_4->x(), ui->ButtonHex_10_4->y()); ROPMove=std::make_pair(10,4);

    ui->ButtonHex_10_4->setIcon(ChangeIcon());
    ui->ButtonHex_10_4->move(x - 9, y - 8);
    ui->ButtonHex_10_4->setFixedSize(44, 44);
    ui->ButtonHex_10_4->setIconSize(QSize(44, 44));
    ui->ButtonHex_10_4->setEnabled(false);

    game.PlayerTurn(10,4, playerCurrent);
    if (game.VerifyRules(10, 4))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_10_5_clicked()
{
    int x, y;
    x = ui->ButtonHex_10_5->x();
    y = ui->ButtonHex_10_5->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_10_5->x(), ui->ButtonHex_10_5->y()); ROPMove=std::make_pair(10,5);

    ui->ButtonHex_10_5->setIcon(ChangeIcon());
    ui->ButtonHex_10_5->move(x - 9, y - 8);
    ui->ButtonHex_10_5->setFixedSize(44, 44);
    ui->ButtonHex_10_5->setIconSize(QSize(44, 44));
    ui->ButtonHex_10_5->setEnabled(false);

    game.PlayerTurn(10,5, playerCurrent);
    if (game.VerifyRules(10, 5))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_10_6_clicked()
{
    int x, y;
    x = ui->ButtonHex_10_6->x();
    y = ui->ButtonHex_10_6->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_10_6->x(), ui->ButtonHex_10_6->y()); ROPMove=std::make_pair(10,6);

    ui->ButtonHex_10_6->setIcon(ChangeIcon());
    ui->ButtonHex_10_6->move(x - 9, y - 8);
    ui->ButtonHex_10_6->setFixedSize(44, 44);
    ui->ButtonHex_10_6->setIconSize(QSize(44, 44));
    ui->ButtonHex_10_6->setEnabled(false);

    game.PlayerTurn(10,6, playerCurrent);
    if (game.VerifyRules(10, 6))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_10_7_clicked()
{
    int x, y;
    x = ui->ButtonHex_10_7->x();
    y = ui->ButtonHex_10_7->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_10_7->x(), ui->ButtonHex_10_7->y()); ROPMove=std::make_pair(10,7);

    ui->ButtonHex_10_7->setIcon(ChangeIcon());
    ui->ButtonHex_10_7->move(x - 9, y - 8);
    ui->ButtonHex_10_7->setFixedSize(44, 44);
    ui->ButtonHex_10_7->setIconSize(QSize(44, 44));
    ui->ButtonHex_10_7->setEnabled(false);

    game.PlayerTurn(10,7, playerCurrent);
    if (game.VerifyRules(10, 7))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_10_8_clicked()
{
    int x, y;
    x = ui->ButtonHex_10_8->x();
    y = ui->ButtonHex_10_8->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_10_8->x(), ui->ButtonHex_10_8->y()); ROPMove=std::make_pair(10,8);

    ui->ButtonHex_10_8->setIcon(ChangeIcon());
    ui->ButtonHex_10_8->move(x - 9, y - 8);
    ui->ButtonHex_10_8->setFixedSize(44, 44);
    ui->ButtonHex_10_8->setIconSize(QSize(44, 44));
    ui->ButtonHex_10_8->setEnabled(false);

    game.PlayerTurn(10,8, playerCurrent);
    if (game.VerifyRules(10, 8))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}


void HexUI::on_ButtonHex_10_9_clicked()
{
    int x, y;
    x = ui->ButtonHex_10_9->x();
    y = ui->ButtonHex_10_9->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_10_9->x(), ui->ButtonHex_10_9->y()); ROPMove=std::make_pair(10,9);

    ui->ButtonHex_10_9->setIcon(ChangeIcon());
    ui->ButtonHex_10_9->move(x - 9, y - 8);
    ui->ButtonHex_10_9->setFixedSize(44, 44);
    ui->ButtonHex_10_9->setIconSize(QSize(44, 44));
    ui->ButtonHex_10_9->setEnabled(false);

    game.PlayerTurn(10,9, playerCurrent);
    if (game.VerifyRules(10, 9))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_2_0_clicked()
{
    int x, y;
    x = ui->ButtonHex_2_0->x();
    y = ui->ButtonHex_2_0->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_2_0->x(), ui->ButtonHex_2_0->y()); ROPMove=std::make_pair(2,0);

    ui->ButtonHex_2_0->setIcon(ChangeIcon());
    ui->ButtonHex_2_0->move(x - 9, y - 8);
    ui->ButtonHex_2_0->setFixedSize(44, 44);
    ui->ButtonHex_2_0->setIconSize(QSize(44, 44));
    ui->ButtonHex_2_0->setEnabled(false);

    game.PlayerTurn(2,0, playerCurrent);
    if (game.VerifyRules(2, 0))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_2_10_clicked()
{
    int x, y;
    x = ui->ButtonHex_2_10->x();
    y = ui->ButtonHex_2_10->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_2_10->x(), ui->ButtonHex_2_10->y()); ROPMove=std::make_pair(2,10);

    ui->ButtonHex_2_10->setIcon(ChangeIcon());
    ui->ButtonHex_2_10->move(x - 9, y - 8);
    ui->ButtonHex_2_10->setFixedSize(44, 44);
    ui->ButtonHex_2_10->setIconSize(QSize(44, 44));
    ui->ButtonHex_2_10->setEnabled(false);

    game.PlayerTurn(2,10, playerCurrent);
    if (game.VerifyRules(2, 10))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}
void HexUI::on_ButtonHex_3_0_clicked()
{
    int x, y;
    x = ui->ButtonHex_3_0->x();
    y = ui->ButtonHex_3_0->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_3_0->x(), ui->ButtonHex_3_0->y()); ROPMove=std::make_pair(3,0);

    ui->ButtonHex_3_0->setIcon(ChangeIcon());
    ui->ButtonHex_3_0->move(x - 9, y - 8);
    ui->ButtonHex_3_0->setFixedSize(44, 44);
    ui->ButtonHex_3_0->setIconSize(QSize(44, 44));
    ui->ButtonHex_3_0->setEnabled(false);

    game.PlayerTurn(3,0, playerCurrent);
    if (game.VerifyRules(3, 0))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_3_10_clicked()
{
    int x, y;
    x = ui->ButtonHex_3_10->x();
    y = ui->ButtonHex_3_10->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_3_10->x(), ui->ButtonHex_3_10->y()); ROPMove=std::make_pair(3,10);

    ui->ButtonHex_3_10->setIcon(ChangeIcon());
    ui->ButtonHex_3_10->move(x - 9, y - 8);
    ui->ButtonHex_3_10->setFixedSize(44, 44);
    ui->ButtonHex_3_10->setIconSize(QSize(44, 44));
    ui->ButtonHex_3_10->setEnabled(false);

    game.PlayerTurn(3,10, playerCurrent);
    if (game.VerifyRules(3, 10))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_4_0_clicked()
{
    int x, y;
    x = ui->ButtonHex_4_0->x();
    y = ui->ButtonHex_4_0->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_4_0->x(), ui->ButtonHex_4_0->y()); ROPMove=std::make_pair(4,0);

    ui->ButtonHex_4_0->setIcon(ChangeIcon());
    ui->ButtonHex_4_0->move(x - 9, y - 8);
    ui->ButtonHex_4_0->setFixedSize(44, 44);
    ui->ButtonHex_4_0->setIconSize(QSize(44, 44));
    ui->ButtonHex_4_0->setEnabled(false);

    game.PlayerTurn(4,0, playerCurrent);
    if (game.VerifyRules(4, 0))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_4_10_clicked()
{
    int x, y;
    x = ui->ButtonHex_4_10->x();
    y = ui->ButtonHex_4_10->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_4_10->x(), ui->ButtonHex_4_10->y()); ROPMove=std::make_pair(4,10);

    ui->ButtonHex_4_10->setIcon(ChangeIcon());
    ui->ButtonHex_4_10->move(x - 9, y - 8);
    ui->ButtonHex_4_10->setFixedSize(44, 44);
    ui->ButtonHex_4_10->setIconSize(QSize(44, 44));
    ui->ButtonHex_4_10->setEnabled(false);

    game.PlayerTurn(4,10, playerCurrent);
    if (game.VerifyRules(4, 10))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_5_0_clicked()
{
    int x, y;
    x = ui->ButtonHex_5_0->x();
    y = ui->ButtonHex_5_0->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_5_0->x(), ui->ButtonHex_5_0->y()); ROPMove=std::make_pair(5,0);

    ui->ButtonHex_5_0->setIcon(ChangeIcon());
    ui->ButtonHex_5_0->move(x - 9, y - 8);
    ui->ButtonHex_5_0->setFixedSize(44, 44);
    ui->ButtonHex_5_0->setIconSize(QSize(44, 44));
    ui->ButtonHex_5_0->setEnabled(false);

    game.PlayerTurn(5,0, playerCurrent);
    if (game.VerifyRules(5, 0))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_5_10_clicked()
{
    int x, y;
    x = ui->ButtonHex_5_10->x();
    y = ui->ButtonHex_5_10->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_5_10->x(), ui->ButtonHex_5_10->y()); ROPMove=std::make_pair(5,10);

    ui->ButtonHex_5_10->setIcon(ChangeIcon());
    ui->ButtonHex_5_10->move(x - 9, y - 8);
    ui->ButtonHex_5_10->setFixedSize(44, 44);
    ui->ButtonHex_5_10->setIconSize(QSize(44, 44));
    ui->ButtonHex_5_10->setEnabled(false);

    game.PlayerTurn(5,10, playerCurrent);
    if (game.VerifyRules(5, 10))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_6_0_clicked()
{
    int x, y;
    x = ui->ButtonHex_6_0->x();
    y = ui->ButtonHex_6_0->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_6_0->x(), ui->ButtonHex_6_0->y()); ROPMove=std::make_pair(6,0);

    ui->ButtonHex_6_0->setIcon(ChangeIcon());
    ui->ButtonHex_6_0->move(x - 9, y - 8);
    ui->ButtonHex_6_0->setFixedSize(44, 44);
    ui->ButtonHex_6_0->setIconSize(QSize(44, 44));
    ui->ButtonHex_6_0->setEnabled(false);

    game.PlayerTurn(6,0, playerCurrent);
    if (game.VerifyRules(6, 0))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_6_10_clicked()
{
    int x, y;
    x = ui->ButtonHex_6_10->x();
    y = ui->ButtonHex_6_10->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_6_10->x(), ui->ButtonHex_6_10->y()); ROPMove=std::make_pair(6,10);

    ui->ButtonHex_6_10->setIcon(ChangeIcon());
    ui->ButtonHex_6_10->move(x - 9, y - 8);
    ui->ButtonHex_6_10->setFixedSize(44, 44);
    ui->ButtonHex_6_10->setIconSize(QSize(44, 44));
    ui->ButtonHex_6_10->setEnabled(false);

    game.PlayerTurn(6,10, playerCurrent);
    if (game.VerifyRules(6, 10))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}
void HexUI::on_ButtonHex_7_0_clicked()
{
    int x, y;
    x = ui->ButtonHex_7_0->x();
    y = ui->ButtonHex_7_0->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_7_0->x(), ui->ButtonHex_7_0->y()); ROPMove=std::make_pair(7,0);

    ui->ButtonHex_7_0->setIcon(ChangeIcon());
    ui->ButtonHex_7_0->move(x - 9, y - 8);
    ui->ButtonHex_7_0->setFixedSize(44, 44);
    ui->ButtonHex_7_0->setIconSize(QSize(44, 44));
    ui->ButtonHex_7_0->setEnabled(false);

    game.PlayerTurn(7,0, playerCurrent);
    if (game.VerifyRules(7, 0))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_7_10_clicked()
{
    int x, y;
    x = ui->ButtonHex_7_10->x();
    y = ui->ButtonHex_7_10->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_7_10->x(), ui->ButtonHex_7_10->y()); ROPMove=std::make_pair(7,10);

    ui->ButtonHex_7_10->setIcon(ChangeIcon());
    ui->ButtonHex_7_10->move(x - 9, y - 8);
    ui->ButtonHex_7_10->setFixedSize(44, 44);
    ui->ButtonHex_7_10->setIconSize(QSize(44, 44));
    ui->ButtonHex_7_10->setEnabled(false);

    game.PlayerTurn(7,10, playerCurrent);
    if (game.VerifyRules(7, 10))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}
void HexUI::on_ButtonHex_8_0_clicked()
{
    int x, y;
    x = ui->ButtonHex_8_0->x();
    y = ui->ButtonHex_8_0->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_8_0->x(), ui->ButtonHex_8_0->y()); ROPMove=std::make_pair(8,0);

    ui->ButtonHex_8_0->setIcon(ChangeIcon());
    ui->ButtonHex_8_0->move(x - 9, y - 8);
    ui->ButtonHex_8_0->setFixedSize(44, 44);
    ui->ButtonHex_8_0->setIconSize(QSize(44, 44));
    ui->ButtonHex_8_0->setEnabled(false);

    game.PlayerTurn(8,0, playerCurrent);
    if (game.VerifyRules(8, 0))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_8_10_clicked()
{
    int x, y;
    x = ui->ButtonHex_8_10->x();
    y = ui->ButtonHex_8_10->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_8_10->x(), ui->ButtonHex_8_10->y()); ROPMove=std::make_pair(8,10);

    ui->ButtonHex_8_10->setIcon(ChangeIcon());
    ui->ButtonHex_8_10->move(x - 9, y - 8);
    ui->ButtonHex_8_10->setFixedSize(44, 44);
    ui->ButtonHex_8_10->setIconSize(QSize(44, 44));
    ui->ButtonHex_8_10->setEnabled(false);

    game.PlayerTurn(8,10, playerCurrent);
    if (game.VerifyRules(8, 10))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}
void HexUI::on_ButtonHex_9_0_clicked()
{
    int x, y;
    x = ui->ButtonHex_9_0->x();
    y = ui->ButtonHex_9_0->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_9_0->x(), ui->ButtonHex_9_0->y()); ROPMove=std::make_pair(9,0);

    ui->ButtonHex_9_0->setIcon(ChangeIcon());
    ui->ButtonHex_9_0->move(x - 9, y - 8);
    ui->ButtonHex_9_0->setFixedSize(44, 44);
    ui->ButtonHex_9_0->setIconSize(QSize(44, 44));
    ui->ButtonHex_9_0->setEnabled(false);

    game.PlayerTurn(9,0, playerCurrent);
    if (game.VerifyRules(9, 0))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_9_10_clicked()
{
    int x, y;
    x = ui->ButtonHex_9_10->x();
    y = ui->ButtonHex_9_10->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_9_10->x(), ui->ButtonHex_9_10->y()); ROPMove=std::make_pair(9,10);

    ui->ButtonHex_9_10->setIcon(ChangeIcon());
    ui->ButtonHex_9_10->move(x - 9, y - 8);
    ui->ButtonHex_9_10->setFixedSize(44, 44);
    ui->ButtonHex_9_10->setIconSize(QSize(44, 44));
    ui->ButtonHex_9_10->setEnabled(false);

    game.PlayerTurn(9,10, playerCurrent);
    if (game.VerifyRules(9, 10))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_10_0_clicked()
{
    int x, y;
    x = ui->ButtonHex_10_0->x();
    y = ui->ButtonHex_10_0->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_10_0->x(), ui->ButtonHex_10_0->y()); ROPMove=std::make_pair(10,0);

    ui->ButtonHex_10_0->setIcon(ChangeIcon());
    ui->ButtonHex_10_0->move(x - 9, y - 8);
    ui->ButtonHex_10_0->setFixedSize(44, 44);
    ui->ButtonHex_10_0->setIconSize(QSize(44, 44));
    ui->ButtonHex_10_0->setEnabled(false);

    game.PlayerTurn(10,0, playerCurrent);
    if (game.VerifyRules(10, 0))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}

void HexUI::on_ButtonHex_10_10_clicked()
{
    int x, y;
    x = ui->ButtonHex_10_10->x();
    y = ui->ButtonHex_10_10->y(); ChangeTurn();

    CurrentMove = std::make_pair(ui->ButtonHex_10_10->x(), ui->ButtonHex_10_10->y()); ROPMove=std::make_pair(10,10);

    ui->ButtonHex_10_10->setIcon(ChangeIcon());
    ui->ButtonHex_10_10->move(x - 9, y - 8);
    ui->ButtonHex_10_10->setFixedSize(44, 44);
    ui->ButtonHex_10_10->setIconSize(QSize(44, 44));
    ui->ButtonHex_10_10->setEnabled(false);

    game.PlayerTurn(10,10, playerCurrent);
    if (game.VerifyRules(10, 10))
    {
        ui->Winner->setText(playerCurrent.GetName() + " a castigat");  ui->stackedWidget->setCurrentIndex(2);
    }


}


