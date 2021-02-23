#include "yui.h"
#include "ui_yui.h"
#include <QIcon>
#include <QToolBar>
#include "ConnectionGames.h"

YUI::YUI(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::YUI)
{

    ui->setupUi(this);
    QPixmap bkgd("../GUI pictures/GameBackground.jpg");
           bkgd=bkgd.scaled(this->size(),Qt::IgnoreAspectRatio);
           QPalette palette;
           palette.setBrush(QPalette::Background, bkgd);
           this->setPalette(palette);
     ui->stackedWidget->setCurrentIndex(0);
}

YUI::~YUI()
{
    delete ui;
}

void YUI::ChangeTurn()
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

QIcon YUI::ChangeIcon()
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

void YUI::on_pushButton_clicked()
{

    ui->DaRop->setVisible(false);
    ui->NuROP->setVisible(false);
    ui->IntrebareROP->setVisible(false);
    ui->Patcher->setVisible(false);

    game.InitBoard();
    QString name=ui->NumePlayer1_2->toPlainText();

    game.GetPlayer1().SetName(name);
    name=ui->NumePlayer2_2->toPlainText();
    game.GetPlayer1().SetColor(Player::Color::color1);


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

void YUI::on_DaRop_clicked()
{
    ui->DaRop->setVisible(false);
    ui->NuROP->setVisible(false);
    ui->IntrebareROP->setVisible(false);

    ui->stackedWidget->setCurrentIndex(1);

    ui->Patcher->setIcon(ChangeIcon());

    ChangeTurn();

    ui->Patcher->move(CurrentMove.first-9,CurrentMove.second-8);
    ui->Patcher->setFixedSize(44,44);
    ui->Patcher->setIconSize(QSize(44,44));
    ui->Patcher->setEnabled(false);
    ui->Patcher->raise();
    ui->Patcher->setVisible(true);
    game.RuleOfPie(ROPMove.first,ROPMove.second);
}

void YUI::on_NuROP_clicked()
{
    ui->DaRop->setVisible(false);
    ui->NuROP->setVisible(false);
    ui->IntrebareROP->setVisible(false);
    ui->stackedWidget->setCurrentIndex(1);
}

void YUI::on_ButtonY_0_0_clicked()
{
    int x,y;
    x=ui->ButtonY_0_0->x();
    y=ui->ButtonY_0_0->y();

    CurrentMove = std::make_pair(ui->ButtonY_0_0->x(), ui->ButtonY_0_0->y());
    ROPMove=std::make_pair(0,0);

    ui->ButtonY_0_0->setIcon(ChangeIcon());
    ui->ButtonY_0_0->move(x-9,y-8);
    ui->ButtonY_0_0->setFixedSize(44,44);
    ui->ButtonY_0_0->setIconSize(QSize(44,44));
    ui->ButtonY_0_0->setEnabled(false);

   game.PlayerTurn(0,0,playerCurrent);
   if(game.VerifyRules(0,0))
   {
       ui->Winner->setText(playerCurrent.GetName()+" a castigat");
       ui->stackedWidget->setCurrentIndex(2);
   }

   ChangeTurn();
}


void YUI::on_ButtonY_1_0_clicked()
{
    int x,y;
    x=ui->ButtonY_1_0->x();
    y=ui->ButtonY_1_0->y();

    CurrentMove = std::make_pair(ui->ButtonY_1_0->x(), ui->ButtonY_1_0->y());
    ROPMove=std::make_pair(1,0);
    ui->ButtonY_1_0->setIcon(ChangeIcon());
    ui->ButtonY_1_0->move(x-9,y-8);
    ui->ButtonY_1_0->setFixedSize(44,44);
    ui->ButtonY_1_0->setIconSize(QSize(44,44));
    ui->ButtonY_1_0->setEnabled(false);

   game.PlayerTurn(1,0,playerCurrent);
   if(game.VerifyRules(1,0))
   {
      ui->Winner->setText(playerCurrent.GetName()+" a castigat");
      ui->stackedWidget->setCurrentIndex(2);
   }

   ChangeTurn();
}

void YUI::on_ButtonY_1_1_clicked()
{
    int x,y;
    x=ui->ButtonY_1_1->x();
    y=ui->ButtonY_1_1->y();

    CurrentMove = std::make_pair(ui->ButtonY_1_1->x(), ui->ButtonY_1_1->y());
    ROPMove=std::make_pair(1,1);
    ui->ButtonY_1_1->setIcon(ChangeIcon());
    ui->ButtonY_1_1->move(x-9,y-8);
    ui->ButtonY_1_1->setFixedSize(44,44);
    ui->ButtonY_1_1->setIconSize(QSize(44,44));
    ui->ButtonY_1_1->setEnabled(false);

   game.PlayerTurn(1,1,playerCurrent);
   if(game.VerifyRules(1,1))
   {
      ui->Winner->setText(playerCurrent.GetName()+" a castigat");
      ui->stackedWidget->setCurrentIndex(2);
   }

   ChangeTurn();
}

void YUI::on_ButtonY_2_0_clicked()
{
    int x, y;
    x = ui->ButtonY_2_0->x();
    y = ui->ButtonY_2_0->y();

    CurrentMove = std::make_pair(ui->ButtonY_2_0->x(), ui->ButtonY_2_0->y());
    ROPMove=std::make_pair(2,0);
    ui->ButtonY_2_0->setIcon(ChangeIcon());
    ui->ButtonY_2_0->move(x - 9, y - 8);
    ui->ButtonY_2_0->setFixedSize(44, 44);
    ui->ButtonY_2_0->setIconSize(QSize(44, 44));
    ui->ButtonY_2_0->setEnabled(false);

    game.PlayerTurn(2, 0, playerCurrent);
    if (game.VerifyRules(2, 0))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_2_1_clicked()
{
    int x, y;
    x = ui->ButtonY_2_1->x();
    y = ui->ButtonY_2_1->y();

    CurrentMove = std::make_pair(ui->ButtonY_2_1->x(), ui->ButtonY_2_1->y());
    ROPMove=std::make_pair(2,1);
    ui->ButtonY_2_1->setIcon(ChangeIcon());
    ui->ButtonY_2_1->move(x - 9, y - 8);
    ui->ButtonY_2_1->setFixedSize(44, 44);
    ui->ButtonY_2_1->setIconSize(QSize(44, 44));
    ui->ButtonY_2_1->setEnabled(false);

    game.PlayerTurn(2, 1, playerCurrent);
    if (game.VerifyRules(2, 1))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_2_2_clicked()
{
    int x, y;
    x = ui->ButtonY_2_2->x();
    y = ui->ButtonY_2_2->y();

    CurrentMove = std::make_pair(ui->ButtonY_2_2->x(), ui->ButtonY_2_2->y());
    ROPMove=std::make_pair(2,2);
    ui->ButtonY_2_2->setIcon(ChangeIcon());
    ui->ButtonY_2_2->move(x - 9, y - 8);
    ui->ButtonY_2_2->setFixedSize(44, 44);
    ui->ButtonY_2_2->setIconSize(QSize(44, 44));
    ui->ButtonY_2_2->setEnabled(false);

    game.PlayerTurn(2, 2, playerCurrent);
    if (game.VerifyRules(2, 2))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_3_0_clicked()
{
    int x, y;
    x = ui->ButtonY_3_0->x();
    y = ui->ButtonY_3_0->y();

    CurrentMove = std::make_pair(ui->ButtonY_3_0->x(), ui->ButtonY_3_0->y());
    ROPMove=std::make_pair(3,0);
    ui->ButtonY_3_0->setIcon(ChangeIcon());
    ui->ButtonY_3_0->move(x - 9, y - 8);
    ui->ButtonY_3_0->setFixedSize(44, 44);
    ui->ButtonY_3_0->setIconSize(QSize(44, 44));
    ui->ButtonY_3_0->setEnabled(false);

    game.PlayerTurn(3, 0, playerCurrent);
    if (game.VerifyRules(3, 0))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_3_1_clicked()
{
    int x, y;
    x = ui->ButtonY_3_1->x();
    y = ui->ButtonY_3_1->y();

    CurrentMove = std::make_pair(ui->ButtonY_3_1->x(), ui->ButtonY_3_1->y());
    ROPMove=std::make_pair(3,1);
    ui->ButtonY_3_1->setIcon(ChangeIcon());
    ui->ButtonY_3_1->move(x - 9, y - 8);
    ui->ButtonY_3_1->setFixedSize(44, 44);
    ui->ButtonY_3_1->setIconSize(QSize(44, 44));
    ui->ButtonY_3_1->setEnabled(false);

    game.PlayerTurn(3, 1, playerCurrent);
    if (game.VerifyRules(3, 1))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_3_2_clicked()
{
    int x, y;
    x = ui->ButtonY_3_2->x();
    y = ui->ButtonY_3_2->y();

    CurrentMove = std::make_pair(ui->ButtonY_3_2->x(), ui->ButtonY_3_2->y());
    ROPMove=std::make_pair(3,2);
    ui->ButtonY_3_2->setIcon(ChangeIcon());
    ui->ButtonY_3_2->move(x - 9, y - 8);
    ui->ButtonY_3_2->setFixedSize(44, 44);
    ui->ButtonY_3_2->setIconSize(QSize(44, 44));
    ui->ButtonY_3_2->setEnabled(false);

    game.PlayerTurn(3, 2, playerCurrent);
    if (game.VerifyRules(3, 2))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_3_3_clicked()
{
    int x, y;
    x = ui->ButtonY_3_3->x();
    y = ui->ButtonY_3_3->y();

    CurrentMove = std::make_pair(ui->ButtonY_3_3->x(), ui->ButtonY_3_3->y());
    ROPMove=std::make_pair(3,3);
    ui->ButtonY_3_3->setIcon(ChangeIcon());
    ui->ButtonY_3_3->move(x - 9, y - 8);
    ui->ButtonY_3_3->setFixedSize(44, 44);
    ui->ButtonY_3_3->setIconSize(QSize(44, 44));
    ui->ButtonY_3_3->setEnabled(false);

    game.PlayerTurn(3, 3, playerCurrent);
    if (game.VerifyRules(3, 3))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_4_0_clicked()
{
    int x, y;
    x = ui->ButtonY_4_0->x();
    y = ui->ButtonY_4_0->y();

    CurrentMove = std::make_pair(ui->ButtonY_4_0->x(), ui->ButtonY_4_0->y());
ROPMove=std::make_pair(4,0);
    ui->ButtonY_4_0->setIcon(ChangeIcon());
    ui->ButtonY_4_0->move(x - 9, y - 8);
    ui->ButtonY_4_0->setFixedSize(44, 44);
    ui->ButtonY_4_0->setIconSize(QSize(44, 44));
    ui->ButtonY_4_0->setEnabled(false);

    game.PlayerTurn(4, 0, playerCurrent);
    if (game.VerifyRules(4, 0))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_4_1_clicked()
{
    int x, y;
    x = ui->ButtonY_4_1->x();
    y = ui->ButtonY_4_1->y();

    CurrentMove = std::make_pair(ui->ButtonY_4_1->x(), ui->ButtonY_4_1->y());
ROPMove=std::make_pair(4,1);
    ui->ButtonY_4_1->setIcon(ChangeIcon());
    ui->ButtonY_4_1->move(x - 9, y - 8);
    ui->ButtonY_4_1->setFixedSize(44, 44);
    ui->ButtonY_4_1->setIconSize(QSize(44, 44));
    ui->ButtonY_4_1->setEnabled(false);

    game.PlayerTurn(4, 1, playerCurrent);
    if (game.VerifyRules(4, 1))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_4_2_clicked()
{
    int x, y;
    x = ui->ButtonY_4_2->x();
    y = ui->ButtonY_4_2->y();

    CurrentMove = std::make_pair(ui->ButtonY_4_2->x(), ui->ButtonY_4_2->y());
ROPMove=std::make_pair(4,2);
    ui->ButtonY_4_2->setIcon(ChangeIcon());
    ui->ButtonY_4_2->move(x - 9, y - 8);
    ui->ButtonY_4_2->setFixedSize(44, 44);
    ui->ButtonY_4_2->setIconSize(QSize(44, 44));
    ui->ButtonY_4_2->setEnabled(false);

    game.PlayerTurn(4, 2, playerCurrent);
    if (game.VerifyRules(4, 2))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_4_3_clicked()
{
    int x, y;
    x = ui->ButtonY_4_3->x();
    y = ui->ButtonY_4_3->y();

    CurrentMove = std::make_pair(ui->ButtonY_4_3->x(), ui->ButtonY_4_3->y());
ROPMove=std::make_pair(4,3);
    ui->ButtonY_4_3->setIcon(ChangeIcon());
    ui->ButtonY_4_3->move(x - 9, y - 8);
    ui->ButtonY_4_3->setFixedSize(44, 44);
    ui->ButtonY_4_3->setIconSize(QSize(44, 44));
    ui->ButtonY_4_3->setEnabled(false);

    game.PlayerTurn(4, 3, playerCurrent);
    if (game.VerifyRules(4, 3))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_4_4_clicked()
{
    int x, y;
    x = ui->ButtonY_4_4->x();
    y = ui->ButtonY_4_4->y();

    CurrentMove = std::make_pair(ui->ButtonY_4_4->x(), ui->ButtonY_4_4->y());
 ROPMove=std::make_pair(4,4);
    ui->ButtonY_4_4->setIcon(ChangeIcon());
    ui->ButtonY_4_4->move(x - 9, y - 8);
    ui->ButtonY_4_4->setFixedSize(44, 44);
    ui->ButtonY_4_4->setIconSize(QSize(44, 44));
    ui->ButtonY_4_4->setEnabled(false);

    game.PlayerTurn(4, 4, playerCurrent);
    if (game.VerifyRules(4, 4))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_5_0_clicked()
{
    int x, y;
    x = ui->ButtonY_5_0->x();
    y = ui->ButtonY_5_0->y();

    CurrentMove = std::make_pair(ui->ButtonY_5_0->x(), ui->ButtonY_5_0->y());
 ROPMove=std::make_pair(5,0);
    ui->ButtonY_5_0->setIcon(ChangeIcon());
    ui->ButtonY_5_0->move(x - 9, y - 8);
    ui->ButtonY_5_0->setFixedSize(44, 44);
    ui->ButtonY_5_0->setIconSize(QSize(44, 44));
    ui->ButtonY_5_0->setEnabled(false);

    game.PlayerTurn(5, 0, playerCurrent);
    if (game.VerifyRules(5, 0))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_5_1_clicked()
{
    int x, y;
    x = ui->ButtonY_5_1->x();
    y = ui->ButtonY_5_1->y();

    CurrentMove = std::make_pair(ui->ButtonY_5_1->x(), ui->ButtonY_5_1->y());
 ROPMove=std::make_pair(5,1);
    ui->ButtonY_5_1->setIcon(ChangeIcon());
    ui->ButtonY_5_1->move(x - 9, y - 8);
    ui->ButtonY_5_1->setFixedSize(44, 44);
    ui->ButtonY_5_1->setIconSize(QSize(44, 44));
    ui->ButtonY_5_1->setEnabled(false);

    game.PlayerTurn(5, 1, playerCurrent);
    if (game.VerifyRules(5, 1))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_5_2_clicked()
{
    int x, y;
    x = ui->ButtonY_5_2->x();
    y = ui->ButtonY_5_2->y();

    CurrentMove = std::make_pair(ui->ButtonY_5_2->x(), ui->ButtonY_5_2->y());
 ROPMove=std::make_pair(5,2);
    ui->ButtonY_5_2->setIcon(ChangeIcon());
    ui->ButtonY_5_2->move(x - 9, y - 8);
    ui->ButtonY_5_2->setFixedSize(44, 44);
    ui->ButtonY_5_2->setIconSize(QSize(44, 44));
    ui->ButtonY_5_2->setEnabled(false);

    game.PlayerTurn(5, 2, playerCurrent);
    if (game.VerifyRules(5, 2))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_5_3_clicked()
{
    int x, y;
    x = ui->ButtonY_5_3->x();
    y = ui->ButtonY_5_3->y();

    CurrentMove = std::make_pair(ui->ButtonY_5_3->x(), ui->ButtonY_5_3->y());
 ROPMove=std::make_pair(5,3);
    ui->ButtonY_5_3->setIcon(ChangeIcon());
    ui->ButtonY_5_3->move(x - 9, y - 8);
    ui->ButtonY_5_3->setFixedSize(44, 44);
    ui->ButtonY_5_3->setIconSize(QSize(44, 44));
    ui->ButtonY_5_3->setEnabled(false);

    game.PlayerTurn(5, 3, playerCurrent);
    if (game.VerifyRules(5, 3))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_5_4_clicked()
{
    int x, y;
    x = ui->ButtonY_5_4->x();
    y = ui->ButtonY_5_4->y();

    CurrentMove = std::make_pair(ui->ButtonY_5_4->x(), ui->ButtonY_5_4->y());
 ROPMove=std::make_pair(5,4);
    ui->ButtonY_5_4->setIcon(ChangeIcon());
    ui->ButtonY_5_4->move(x - 9, y - 8);
    ui->ButtonY_5_4->setFixedSize(44, 44);
    ui->ButtonY_5_4->setIconSize(QSize(44, 44));
    ui->ButtonY_5_4->setEnabled(false);

    game.PlayerTurn(5, 4, playerCurrent);
    if (game.VerifyRules(5, 4))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_5_5_clicked()
{
    int x, y;
    x = ui->ButtonY_5_5->x();
    y = ui->ButtonY_5_5->y();

    CurrentMove = std::make_pair(ui->ButtonY_5_5->x(), ui->ButtonY_5_5->y());
     ROPMove=std::make_pair(5,5);
    ui->ButtonY_5_5->setIcon(ChangeIcon());
    ui->ButtonY_5_5->move(x - 9, y - 8);
    ui->ButtonY_5_5->setFixedSize(44, 44);
    ui->ButtonY_5_5->setIconSize(QSize(44, 44));
    ui->ButtonY_5_5->setEnabled(false);

    game.PlayerTurn(5, 5, playerCurrent);
    if (game.VerifyRules(5, 5))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_6_0_clicked()
{
    int x, y;
    x = ui->ButtonY_6_0->x();
    y = ui->ButtonY_6_0->y();

    CurrentMove = std::make_pair(ui->ButtonY_6_0->x(), ui->ButtonY_6_0->y());
     ROPMove=std::make_pair(6,0);
    ui->ButtonY_6_0->setIcon(ChangeIcon());
    ui->ButtonY_6_0->move(x - 9, y - 8);
    ui->ButtonY_6_0->setFixedSize(44, 44);
    ui->ButtonY_6_0->setIconSize(QSize(44, 44));
    ui->ButtonY_6_0->setEnabled(false);

    game.PlayerTurn(6, 0, playerCurrent);
    if (game.VerifyRules(6, 0))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_6_1_clicked()
{
    int x, y;
    x = ui->ButtonY_6_1->x();
    y = ui->ButtonY_6_1->y();

    CurrentMove = std::make_pair(ui->ButtonY_6_1->x(), ui->ButtonY_6_1->y());
     ROPMove=std::make_pair(6,1);
    ui->ButtonY_6_1->setIcon(ChangeIcon());
    ui->ButtonY_6_1->move(x - 9, y - 8);
    ui->ButtonY_6_1->setFixedSize(44, 44);
    ui->ButtonY_6_1->setIconSize(QSize(44, 44));
    ui->ButtonY_6_1->setEnabled(false);

    game.PlayerTurn(6, 1, playerCurrent);
    if (game.VerifyRules(6, 1))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_6_2_clicked()
{
    int x, y;
    x = ui->ButtonY_6_2->x();
    y = ui->ButtonY_6_2->y();
     ROPMove=std::make_pair(6,2);
    CurrentMove = std::make_pair(ui->ButtonY_6_2->x(), ui->ButtonY_6_2->y());

    ui->ButtonY_6_2->setIcon(ChangeIcon());
    ui->ButtonY_6_2->move(x - 9, y - 8);
    ui->ButtonY_6_2->setFixedSize(44, 44);
    ui->ButtonY_6_2->setIconSize(QSize(44, 44));
    ui->ButtonY_6_2->setEnabled(false);

    game.PlayerTurn(6, 2, playerCurrent);
    if (game.VerifyRules(6, 2))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_6_3_clicked()
{
    int x, y;
    x = ui->ButtonY_6_3->x();
    y = ui->ButtonY_6_3->y();

    CurrentMove = std::make_pair(ui->ButtonY_6_3->x(), ui->ButtonY_6_3->y());
     ROPMove=std::make_pair(6,3);
    ui->ButtonY_6_3->setIcon(ChangeIcon());
    ui->ButtonY_6_3->move(x - 9, y - 8);
    ui->ButtonY_6_3->setFixedSize(44, 44);
    ui->ButtonY_6_3->setIconSize(QSize(44, 44));
    ui->ButtonY_6_3->setEnabled(false);

    game.PlayerTurn(6, 3, playerCurrent);
    if (game.VerifyRules(6, 3))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_6_4_clicked()
{
    int x, y;
    x = ui->ButtonY_6_4->x();
    y = ui->ButtonY_6_4->y();

    CurrentMove = std::make_pair(ui->ButtonY_6_4->x(), ui->ButtonY_6_4->y());
     ROPMove=std::make_pair(6,4);
    ui->ButtonY_6_4->setIcon(ChangeIcon());
    ui->ButtonY_6_4->move(x - 9, y - 8);
    ui->ButtonY_6_4->setFixedSize(44, 44);
    ui->ButtonY_6_4->setIconSize(QSize(44, 44));
    ui->ButtonY_6_4->setEnabled(false);

    game.PlayerTurn(6, 4, playerCurrent);
    if (game.VerifyRules(6, 4))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_6_5_clicked()
{
    int x, y;
    x = ui->ButtonY_6_5->x();
    y = ui->ButtonY_6_5->y();

    CurrentMove = std::make_pair(ui->ButtonY_6_5->x(), ui->ButtonY_6_5->y());
     ROPMove=std::make_pair(6,5);
    ui->ButtonY_6_5->setIcon(ChangeIcon());
    ui->ButtonY_6_5->move(x - 9, y - 8);
    ui->ButtonY_6_5->setFixedSize(44, 44);
    ui->ButtonY_6_5->setIconSize(QSize(44, 44));
    ui->ButtonY_6_5->setEnabled(false);

    game.PlayerTurn(6, 5, playerCurrent);
    if (game.VerifyRules(6, 5))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_6_6_clicked()
{
    int x, y;
    x = ui->ButtonY_6_6->x();
    y = ui->ButtonY_6_6->y();

    CurrentMove = std::make_pair(ui->ButtonY_6_6->x(), ui->ButtonY_6_6->y());
     ROPMove=std::make_pair(6,6);

    ui->ButtonY_6_6->setIcon(ChangeIcon());
    ui->ButtonY_6_6->move(x - 9, y - 8);
    ui->ButtonY_6_6->setFixedSize(44, 44);
    ui->ButtonY_6_6->setIconSize(QSize(44, 44));
    ui->ButtonY_6_6->setEnabled(false);

    game.PlayerTurn(6, 6, playerCurrent);
    if (game.VerifyRules(6, 6))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_7_0_clicked()
{
    int x, y;
    x = ui->ButtonY_7_0->x();
    y = ui->ButtonY_7_0->y();
 ROPMove=std::make_pair(7,0);
    CurrentMove = std::make_pair(ui->ButtonY_7_0->x(), ui->ButtonY_7_0->y());

    ui->ButtonY_7_0->setIcon(ChangeIcon());
    ui->ButtonY_7_0->move(x - 9, y - 8);
    ui->ButtonY_7_0->setFixedSize(44, 44);
    ui->ButtonY_7_0->setIconSize(QSize(44, 44));
    ui->ButtonY_7_0->setEnabled(false);

    game.PlayerTurn(7, 0, playerCurrent);
    if (game.VerifyRules(7, 0))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_7_1_clicked()
{
    int x, y;
    x = ui->ButtonY_7_1->x();
    y = ui->ButtonY_7_1->y();

    CurrentMove = std::make_pair(ui->ButtonY_7_1->x(), ui->ButtonY_7_1->y());
 ROPMove=std::make_pair(7,1);
    ui->ButtonY_7_1->setIcon(ChangeIcon());
    ui->ButtonY_7_1->move(x - 9, y - 8);
    ui->ButtonY_7_1->setFixedSize(44, 44);
    ui->ButtonY_7_1->setIconSize(QSize(44, 44));
    ui->ButtonY_7_1->setEnabled(false);

    game.PlayerTurn(7, 1, playerCurrent);
    if (game.VerifyRules(7, 1))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_7_2_clicked()
{
    int x, y;
    x = ui->ButtonY_7_2->x();
    y = ui->ButtonY_7_2->y();

    CurrentMove = std::make_pair(ui->ButtonY_7_2->x(), ui->ButtonY_7_2->y());
 ROPMove=std::make_pair(7,2);
    ui->ButtonY_7_2->setIcon(ChangeIcon());
    ui->ButtonY_7_2->move(x - 9, y - 8);
    ui->ButtonY_7_2->setFixedSize(44, 44);
    ui->ButtonY_7_2->setIconSize(QSize(44, 44));
    ui->ButtonY_7_2->setEnabled(false);

    game.PlayerTurn(7, 2, playerCurrent);
    if (game.VerifyRules(7, 2))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_7_3_clicked()
{
    int x, y;
    x = ui->ButtonY_7_3->x();
    y = ui->ButtonY_7_3->y();

    CurrentMove = std::make_pair(ui->ButtonY_7_3->x(), ui->ButtonY_7_3->y());
 ROPMove=std::make_pair(7,3);
    ui->ButtonY_7_3->setIcon(ChangeIcon());
    ui->ButtonY_7_3->move(x - 9, y - 8);
    ui->ButtonY_7_3->setFixedSize(44, 44);
    ui->ButtonY_7_3->setIconSize(QSize(44, 44));
    ui->ButtonY_7_3->setEnabled(false);

    game.PlayerTurn(7, 3, playerCurrent);
    if (game.VerifyRules(7, 3))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_7_4_clicked()
{
    int x, y;
    x = ui->ButtonY_7_4->x();
    y = ui->ButtonY_7_4->y();
 ROPMove=std::make_pair(7,4);
    CurrentMove = std::make_pair(ui->ButtonY_7_4->x(), ui->ButtonY_7_4->y());

    ui->ButtonY_7_4->setIcon(ChangeIcon());
    ui->ButtonY_7_4->move(x - 9, y - 8);
    ui->ButtonY_7_4->setFixedSize(44, 44);
    ui->ButtonY_7_4->setIconSize(QSize(44, 44));
    ui->ButtonY_7_4->setEnabled(false);

    game.PlayerTurn(7, 4, playerCurrent);
    if (game.VerifyRules(7, 4))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_7_5_clicked()
{
    int x, y;
    x = ui->ButtonY_7_5->x();
    y = ui->ButtonY_7_5->y();

    CurrentMove = std::make_pair(ui->ButtonY_7_5->x(), ui->ButtonY_7_5->y());
 ROPMove=std::make_pair(7,5);
    ui->ButtonY_7_5->setIcon(ChangeIcon());
    ui->ButtonY_7_5->move(x - 9, y - 8);
    ui->ButtonY_7_5->setFixedSize(44, 44);
    ui->ButtonY_7_5->setIconSize(QSize(44, 44));
    ui->ButtonY_7_5->setEnabled(false);

    game.PlayerTurn(7, 5, playerCurrent);
    if (game.VerifyRules(7, 5))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_7_6_clicked()
{
    int x, y;
    x = ui->ButtonY_7_6->x();
    y = ui->ButtonY_7_6->y();

    CurrentMove = std::make_pair(ui->ButtonY_7_6->x(), ui->ButtonY_7_6->y());
 ROPMove=std::make_pair(7,6);
    ui->ButtonY_7_6->setIcon(ChangeIcon());
    ui->ButtonY_7_6->move(x - 9, y - 8);
    ui->ButtonY_7_6->setFixedSize(44, 44);
    ui->ButtonY_7_6->setIconSize(QSize(44, 44));
    ui->ButtonY_7_6->setEnabled(false);

    game.PlayerTurn(7, 6, playerCurrent);
    if (game.VerifyRules(7, 6))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_7_7_clicked()
{
    int x, y;
    x = ui->ButtonY_7_7->x();
    y = ui->ButtonY_7_7->y();

    CurrentMove = std::make_pair(ui->ButtonY_7_7->x(), ui->ButtonY_7_7->y());
        ROPMove=std::make_pair(7,7);
    ui->ButtonY_7_7->setIcon(ChangeIcon());
    ui->ButtonY_7_7->move(x - 9, y - 8);
    ui->ButtonY_7_7->setFixedSize(44, 44);
    ui->ButtonY_7_7->setIconSize(QSize(44, 44));
    ui->ButtonY_7_7->setEnabled(false);

    game.PlayerTurn(7, 7, playerCurrent);
    if (game.VerifyRules(7, 7))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_8_0_clicked()
{
    int x, y;
    x = ui->ButtonY_8_0->x();
    y = ui->ButtonY_8_0->y();

    CurrentMove = std::make_pair(ui->ButtonY_8_0->x(), ui->ButtonY_8_0->y());
        ROPMove=std::make_pair(8,0);

    ui->ButtonY_8_0->setIcon(ChangeIcon());
    ui->ButtonY_8_0->move(x - 9, y - 8);
    ui->ButtonY_8_0->setFixedSize(44, 44);
    ui->ButtonY_8_0->setIconSize(QSize(44, 44));
    ui->ButtonY_8_0->setEnabled(false);

    game.PlayerTurn(8, 0, playerCurrent);
    if (game.VerifyRules(8, 0))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_8_1_clicked()
{
    int x, y;
    x = ui->ButtonY_8_1->x();
    y = ui->ButtonY_8_1->y();

    CurrentMove = std::make_pair(ui->ButtonY_8_1->x(), ui->ButtonY_8_1->y());
    ROPMove=std::make_pair(8,1);
    ui->ButtonY_8_1->setIcon(ChangeIcon());
    ui->ButtonY_8_1->move(x - 9, y - 8);
    ui->ButtonY_8_1->setFixedSize(44, 44);
    ui->ButtonY_8_1->setIconSize(QSize(44, 44));
    ui->ButtonY_8_1->setEnabled(false);

    game.PlayerTurn(8, 1, playerCurrent);
    if (game.VerifyRules(8, 1))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_8_2_clicked()
{
    int x, y;
    x = ui->ButtonY_8_2->x();
    y = ui->ButtonY_8_2->y();

    CurrentMove = std::make_pair(ui->ButtonY_8_2->x(), ui->ButtonY_8_2->y());
        ROPMove=std::make_pair(8,2);

    ui->ButtonY_8_2->setIcon(ChangeIcon());
    ui->ButtonY_8_2->move(x - 9, y - 8);
    ui->ButtonY_8_2->setFixedSize(44, 44);
    ui->ButtonY_8_2->setIconSize(QSize(44, 44));
    ui->ButtonY_8_2->setEnabled(false);

    game.PlayerTurn(8, 2, playerCurrent);
    if (game.VerifyRules(8, 2))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_8_3_clicked()
{
    int x, y;
    x = ui->ButtonY_8_3->x();
    y = ui->ButtonY_8_3->y();

    CurrentMove = std::make_pair(ui->ButtonY_8_3->x(), ui->ButtonY_8_3->y());
        ROPMove=std::make_pair(8,3);

    ui->ButtonY_8_3->setIcon(ChangeIcon());
    ui->ButtonY_8_3->move(x - 9, y - 8);
    ui->ButtonY_8_3->setFixedSize(44, 44);
    ui->ButtonY_8_3->setIconSize(QSize(44, 44));
    ui->ButtonY_8_3->setEnabled(false);

    game.PlayerTurn(8, 3, playerCurrent);
    if (game.VerifyRules(8, 3))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_8_4_clicked()
{
    int x, y;
    x = ui->ButtonY_8_4->x();
    y = ui->ButtonY_8_4->y();

    CurrentMove = std::make_pair(ui->ButtonY_8_4->x(), ui->ButtonY_8_4->y());
        ROPMove=std::make_pair(8,4);

    ui->ButtonY_8_4->setIcon(ChangeIcon());
    ui->ButtonY_8_4->move(x - 9, y - 8);
    ui->ButtonY_8_4->setFixedSize(44, 44);
    ui->ButtonY_8_4->setIconSize(QSize(44, 44));
    ui->ButtonY_8_4->setEnabled(false);

    game.PlayerTurn(8, 4, playerCurrent);
    if (game.VerifyRules(8, 4))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_8_5_clicked()
{
    int x, y;
    x = ui->ButtonY_8_5->x();
    y = ui->ButtonY_8_5->y();

    CurrentMove = std::make_pair(ui->ButtonY_8_5->x(), ui->ButtonY_8_5->y());
        ROPMove=std::make_pair(8,5);

    ui->ButtonY_8_5->setIcon(ChangeIcon());
    ui->ButtonY_8_5->move(x - 9, y - 8);
    ui->ButtonY_8_5->setFixedSize(44, 44);
    ui->ButtonY_8_5->setIconSize(QSize(44, 44));
    ui->ButtonY_8_5->setEnabled(false);

    game.PlayerTurn(8, 5, playerCurrent);
    if (game.VerifyRules(8, 5))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_8_6_clicked()
{
    int x, y;
    x = ui->ButtonY_8_6->x();
    y = ui->ButtonY_8_6->y();
    ROPMove=std::make_pair(8,6);
    CurrentMove = std::make_pair(ui->ButtonY_8_6->x(), ui->ButtonY_8_6->y());

    ui->ButtonY_8_6->setIcon(ChangeIcon());
    ui->ButtonY_8_6->move(x - 9, y - 8);
    ui->ButtonY_8_6->setFixedSize(44, 44);
    ui->ButtonY_8_6->setIconSize(QSize(44, 44));
    ui->ButtonY_8_6->setEnabled(false);

    game.PlayerTurn(8, 6, playerCurrent);
    if (game.VerifyRules(8, 6))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_8_7_clicked()
{
    int x, y;
    x = ui->ButtonY_8_7->x();
    y = ui->ButtonY_8_7->y();

    CurrentMove = std::make_pair(ui->ButtonY_8_7->x(), ui->ButtonY_8_7->y());
    ROPMove=std::make_pair(8,7);
    ui->ButtonY_8_7->setIcon(ChangeIcon());
    ui->ButtonY_8_7->move(x - 9, y - 8);
    ui->ButtonY_8_7->setFixedSize(44, 44);
    ui->ButtonY_8_7->setIconSize(QSize(44, 44));
    ui->ButtonY_8_7->setEnabled(false);

    game.PlayerTurn(8, 7, playerCurrent);
    if (game.VerifyRules(8, 7))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_8_8_clicked()
{
    int x, y;
    x = ui->ButtonY_8_8->x();
    y = ui->ButtonY_8_8->y();

    CurrentMove = std::make_pair(ui->ButtonY_8_8->x(), ui->ButtonY_8_8->y());
    ROPMove=std::make_pair(8,8);

    ui->ButtonY_8_8->setIcon(ChangeIcon());
    ui->ButtonY_8_8->move(x - 9, y - 8);
    ui->ButtonY_8_8->setFixedSize(44, 44);
    ui->ButtonY_8_8->setIconSize(QSize(44, 44));
    ui->ButtonY_8_8->setEnabled(false);

    game.PlayerTurn(8, 8, playerCurrent);
    if (game.VerifyRules(8, 8))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_9_0_clicked()
{
    int x, y;
    x = ui->ButtonY_9_0->x();
    y = ui->ButtonY_9_0->y();

    CurrentMove = std::make_pair(ui->ButtonY_9_0->x(), ui->ButtonY_9_0->y());
            ROPMove=std::make_pair(9,0);

    ui->ButtonY_9_0->setIcon(ChangeIcon());
    ui->ButtonY_9_0->move(x - 9, y - 8);
    ui->ButtonY_9_0->setFixedSize(44, 44);
    ui->ButtonY_9_0->setIconSize(QSize(44, 44));
    ui->ButtonY_9_0->setEnabled(false);

    game.PlayerTurn(9, 0, playerCurrent);
    if (game.VerifyRules(9, 0))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_9_1_clicked()
{
    int x, y;
    x = ui->ButtonY_9_1->x();
    y = ui->ButtonY_9_1->y();

    CurrentMove = std::make_pair(ui->ButtonY_9_1->x(), ui->ButtonY_9_1->y());
            ROPMove=std::make_pair(9,1);

    ui->ButtonY_9_1->setIcon(ChangeIcon());
    ui->ButtonY_9_1->move(x - 9, y - 8);
    ui->ButtonY_9_1->setFixedSize(44, 44);
    ui->ButtonY_9_1->setIconSize(QSize(44, 44));
    ui->ButtonY_9_1->setEnabled(false);

    game.PlayerTurn(9, 1, playerCurrent);
    if (game.VerifyRules(9, 1))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_9_2_clicked()
{
    int x, y;
    x = ui->ButtonY_9_2->x();
    y = ui->ButtonY_9_2->y();

    CurrentMove = std::make_pair(ui->ButtonY_9_2->x(), ui->ButtonY_9_2->y());
        ROPMove=std::make_pair(9,2);
    ui->ButtonY_9_2->setIcon(ChangeIcon());
    ui->ButtonY_9_2->move(x - 9, y - 8);
    ui->ButtonY_9_2->setFixedSize(44, 44);
    ui->ButtonY_9_2->setIconSize(QSize(44, 44));
    ui->ButtonY_9_2->setEnabled(false);

    game.PlayerTurn(9, 2, playerCurrent);
    if (game.VerifyRules(9, 2))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_9_3_clicked()
{
    int x, y;
    x = ui->ButtonY_9_3->x();
    y = ui->ButtonY_9_3->y();

    CurrentMove = std::make_pair(ui->ButtonY_9_3->x(), ui->ButtonY_9_3->y());
            ROPMove=std::make_pair(9,3);

    ui->ButtonY_9_3->setIcon(ChangeIcon());
    ui->ButtonY_9_3->move(x - 9, y - 8);
    ui->ButtonY_9_3->setFixedSize(44, 44);
    ui->ButtonY_9_3->setIconSize(QSize(44, 44));
    ui->ButtonY_9_3->setEnabled(false);

    game.PlayerTurn(9, 3, playerCurrent);
    if (game.VerifyRules(9, 3))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_9_4_clicked()
{
    int x, y;
    x = ui->ButtonY_9_4->x();
    y = ui->ButtonY_9_4->y();

    CurrentMove = std::make_pair(ui->ButtonY_9_4->x(), ui->ButtonY_9_4->y());
        ROPMove=std::make_pair(9,4);
    ui->ButtonY_9_4->setIcon(ChangeIcon());
    ui->ButtonY_9_4->move(x - 9, y - 8);
    ui->ButtonY_9_4->setFixedSize(44, 44);
    ui->ButtonY_9_4->setIconSize(QSize(44, 44));
    ui->ButtonY_9_4->setEnabled(false);

    game.PlayerTurn(9, 4, playerCurrent);
    if (game.VerifyRules(9, 4))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_9_5_clicked()
{
    int x, y;
    x = ui->ButtonY_9_5->x();
    y = ui->ButtonY_9_5->y();

    CurrentMove = std::make_pair(ui->ButtonY_9_5->x(), ui->ButtonY_9_5->y());
        ROPMove=std::make_pair(9,5);
    ui->ButtonY_9_5->setIcon(ChangeIcon());
    ui->ButtonY_9_5->move(x - 9, y - 8);
    ui->ButtonY_9_5->setFixedSize(44, 44);
    ui->ButtonY_9_5->setIconSize(QSize(44, 44));
    ui->ButtonY_9_5->setEnabled(false);

    game.PlayerTurn(9, 5, playerCurrent);
    if (game.VerifyRules(9, 5))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_9_6_clicked()
{
    int x, y;
    x = ui->ButtonY_9_6->x();
    y = ui->ButtonY_9_6->y();

    CurrentMove = std::make_pair(ui->ButtonY_9_6->x(), ui->ButtonY_9_6->y());
        ROPMove=std::make_pair(9,6);
    ui->ButtonY_9_6->setIcon(ChangeIcon());
    ui->ButtonY_9_6->move(x - 9, y - 8);
    ui->ButtonY_9_6->setFixedSize(44, 44);
    ui->ButtonY_9_6->setIconSize(QSize(44, 44));
    ui->ButtonY_9_6->setEnabled(false);

    game.PlayerTurn(9, 6, playerCurrent);
    if (game.VerifyRules(9, 6))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_9_7_clicked()
{
    int x, y;
    x = ui->ButtonY_9_7->x();
    y = ui->ButtonY_9_7->y();

    CurrentMove = std::make_pair(ui->ButtonY_9_7->x(), ui->ButtonY_9_7->y());
        ROPMove=std::make_pair(9,7);
    ui->ButtonY_9_7->setIcon(ChangeIcon());
    ui->ButtonY_9_7->move(x - 9, y - 8);
    ui->ButtonY_9_7->setFixedSize(44, 44);
    ui->ButtonY_9_7->setIconSize(QSize(44, 44));
    ui->ButtonY_9_7->setEnabled(false);

    game.PlayerTurn(9, 7, playerCurrent);
    if (game.VerifyRules(9, 7))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_9_8_clicked()
{
    int x, y;
    x = ui->ButtonY_9_8->x();
    y = ui->ButtonY_9_8->y();

    CurrentMove = std::make_pair(ui->ButtonY_9_8->x(), ui->ButtonY_9_8->y());
            ROPMove=std::make_pair(9,8);

    ui->ButtonY_9_8->setIcon(ChangeIcon());
    ui->ButtonY_9_8->move(x - 9, y - 8);
    ui->ButtonY_9_8->setFixedSize(44, 44);
    ui->ButtonY_9_8->setIconSize(QSize(44, 44));
    ui->ButtonY_9_8->setEnabled(false);

    game.PlayerTurn(9, 8, playerCurrent);
    if (game.VerifyRules(9, 8))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_9_9_clicked()
{
    int x, y;
    x = ui->ButtonY_9_9->x();
    y = ui->ButtonY_9_9->y();

    CurrentMove = std::make_pair(ui->ButtonY_9_9->x(), ui->ButtonY_9_9->y());
        ROPMove=std::make_pair(9,9);

    ui->ButtonY_9_9->setIcon(ChangeIcon());
    ui->ButtonY_9_9->move(x - 9, y - 8);
    ui->ButtonY_9_9->setFixedSize(44, 44);
    ui->ButtonY_9_9->setIconSize(QSize(44, 44));
    ui->ButtonY_9_9->setEnabled(false);

    game.PlayerTurn(9, 9, playerCurrent);
    if (game.VerifyRules(9, 9))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_10_0_clicked()
{
    int x, y;
    x = ui->ButtonY_10_0->x();
    y = ui->ButtonY_10_0->y();

    CurrentMove = std::make_pair(ui->ButtonY_10_0->x(), ui->ButtonY_10_0->y());
        ROPMove=std::make_pair(10,0);

    ui->ButtonY_10_0->setIcon(ChangeIcon());
    ui->ButtonY_10_0->move(x - 9, y - 8);
    ui->ButtonY_10_0->setFixedSize(44, 44);
    ui->ButtonY_10_0->setIconSize(QSize(44, 44));
    ui->ButtonY_10_0->setEnabled(false);

    game.PlayerTurn(10, 0, playerCurrent);
    if (game.VerifyRules(10, 0))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_10_1_clicked()
{
    int x, y;
    x = ui->ButtonY_10_1->x();
    y = ui->ButtonY_10_1->y();

    CurrentMove = std::make_pair(ui->ButtonY_10_1->x(), ui->ButtonY_10_1->y());
        ROPMove=std::make_pair(10,1);

    ui->ButtonY_10_1->setIcon(ChangeIcon());
    ui->ButtonY_10_1->move(x - 9, y - 8);
    ui->ButtonY_10_1->setFixedSize(44, 44);
    ui->ButtonY_10_1->setIconSize(QSize(44, 44));
    ui->ButtonY_10_1->setEnabled(false);

    game.PlayerTurn(10, 1, playerCurrent);
    if (game.VerifyRules(10, 1))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_10_2_clicked()
{
    int x, y;
    x = ui->ButtonY_10_2->x();
    y = ui->ButtonY_10_2->y();

    CurrentMove = std::make_pair(ui->ButtonY_10_2->x(), ui->ButtonY_10_2->y());
        ROPMove=std::make_pair(10,2);

    ui->ButtonY_10_2->setIcon(ChangeIcon());
    ui->ButtonY_10_2->move(x - 9, y - 8);
    ui->ButtonY_10_2->setFixedSize(44, 44);
    ui->ButtonY_10_2->setIconSize(QSize(44, 44));
    ui->ButtonY_10_2->setEnabled(false);

    game.PlayerTurn(10, 2, playerCurrent);
    if (game.VerifyRules(10, 2))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_10_3_clicked()
{
    int x, y;
    x = ui->ButtonY_10_3->x();
    y = ui->ButtonY_10_3->y();

    CurrentMove = std::make_pair(ui->ButtonY_10_3->x(), ui->ButtonY_10_3->y());
        ROPMove=std::make_pair(10,3);

    ui->ButtonY_10_3->setIcon(ChangeIcon());
    ui->ButtonY_10_3->move(x - 9, y - 8);
    ui->ButtonY_10_3->setFixedSize(44, 44);
    ui->ButtonY_10_3->setIconSize(QSize(44, 44));
    ui->ButtonY_10_3->setEnabled(false);

    game.PlayerTurn(10, 3, playerCurrent);
    if (game.VerifyRules(10, 3))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_10_4_clicked()
{
    int x, y;
    x = ui->ButtonY_10_4->x();
    y = ui->ButtonY_10_4->y();

    CurrentMove = std::make_pair(ui->ButtonY_10_4->x(), ui->ButtonY_10_4->y());
        ROPMove=std::make_pair(10,4);

    ui->ButtonY_10_4->setIcon(ChangeIcon());
    ui->ButtonY_10_4->move(x - 9, y - 8);
    ui->ButtonY_10_4->setFixedSize(44, 44);
    ui->ButtonY_10_4->setIconSize(QSize(44, 44));
    ui->ButtonY_10_4->setEnabled(false);

    game.PlayerTurn(10, 4, playerCurrent);
    if (game.VerifyRules(10, 4))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_10_5_clicked()
{
    int x, y;
    x = ui->ButtonY_10_5->x();
    y = ui->ButtonY_10_5->y();

    CurrentMove = std::make_pair(ui->ButtonY_10_5->x(), ui->ButtonY_10_5->y());
        ROPMove=std::make_pair(10,5);

    ui->ButtonY_10_5->setIcon(ChangeIcon());
    ui->ButtonY_10_5->move(x - 9, y - 8);
    ui->ButtonY_10_5->setFixedSize(44, 44);
    ui->ButtonY_10_5->setIconSize(QSize(44, 44));
    ui->ButtonY_10_5->setEnabled(false);

    game.PlayerTurn(10, 5, playerCurrent);
    if (game.VerifyRules(10, 5))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_10_6_clicked()
{
    int x, y;
    x = ui->ButtonY_10_6->x();
    y = ui->ButtonY_10_6->y();

    CurrentMove = std::make_pair(ui->ButtonY_10_6->x(), ui->ButtonY_10_6->y());
        ROPMove=std::make_pair(10,6);

    ui->ButtonY_10_6->setIcon(ChangeIcon());
    ui->ButtonY_10_6->move(x - 9, y - 8);
    ui->ButtonY_10_6->setFixedSize(44, 44);
    ui->ButtonY_10_6->setIconSize(QSize(44, 44));
    ui->ButtonY_10_6->setEnabled(false);

    game.PlayerTurn(10, 6, playerCurrent);
    if (game.VerifyRules(10, 6))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_10_7_clicked()
{
    int x, y;
    x = ui->ButtonY_10_7->x();
    y = ui->ButtonY_10_7->y();

    CurrentMove = std::make_pair(ui->ButtonY_10_7->x(), ui->ButtonY_10_7->y());
    ROPMove=std::make_pair(10,7);

    ui->ButtonY_10_7->setIcon(ChangeIcon());
    ui->ButtonY_10_7->move(x - 9, y - 8);
    ui->ButtonY_10_7->setFixedSize(44, 44);
    ui->ButtonY_10_7->setIconSize(QSize(44, 44));
    ui->ButtonY_10_7->setEnabled(false);

    game.PlayerTurn(10, 7, playerCurrent);
    if (game.VerifyRules(10, 7))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_10_8_clicked()
{
    int x, y;
    x = ui->ButtonY_10_8->x();
    y = ui->ButtonY_10_8->y();

    CurrentMove = std::make_pair(ui->ButtonY_10_8->x(), ui->ButtonY_10_8->y());
                    ROPMove=std::make_pair(10,8);

    ui->ButtonY_10_8->setIcon(ChangeIcon());
    ui->ButtonY_10_8->move(x - 9, y - 8);
    ui->ButtonY_10_8->setFixedSize(44, 44);
    ui->ButtonY_10_8->setIconSize(QSize(44, 44));
    ui->ButtonY_10_8->setEnabled(false);

    game.PlayerTurn(10, 8, playerCurrent);
    if (game.VerifyRules(10, 8))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_10_9_clicked()
{
    int x, y;
    x = ui->ButtonY_10_9->x();
    y = ui->ButtonY_10_9->y();

    CurrentMove = std::make_pair(ui->ButtonY_10_9->x(), ui->ButtonY_10_9->y());
                ROPMove=std::make_pair(10,9);

    ui->ButtonY_10_9->setIcon(ChangeIcon());
    ui->ButtonY_10_9->move(x - 9, y - 8);
    ui->ButtonY_10_9->setFixedSize(44, 44);
    ui->ButtonY_10_9->setIconSize(QSize(44, 44));
    ui->ButtonY_10_9->setEnabled(false);

    game.PlayerTurn(10, 9, playerCurrent);
    if (game.VerifyRules(10, 9))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_10_10_clicked()
{
    int x, y;
    x = ui->ButtonY_10_10->x();
    y = ui->ButtonY_10_10->y();

    CurrentMove = std::make_pair(ui->ButtonY_10_10->x(), ui->ButtonY_10_10->y());
            ROPMove=std::make_pair(10,10);

    ui->ButtonY_10_10->setIcon(ChangeIcon());
    ui->ButtonY_10_10->move(x - 9, y - 8);
    ui->ButtonY_10_10->setFixedSize(44, 44);
    ui->ButtonY_10_10->setIconSize(QSize(44, 44));
    ui->ButtonY_10_10->setEnabled(false);

    game.PlayerTurn(10, 10, playerCurrent);
    if (game.VerifyRules(10, 10))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_11_0_clicked()
{
    int x, y;
    x = ui->ButtonY_11_0->x();
    y = ui->ButtonY_11_0->y();

    CurrentMove = std::make_pair(ui->ButtonY_11_0->x(), ui->ButtonY_11_0->y());
    ROPMove=std::make_pair(11,0);

    ui->ButtonY_11_0->setIcon(ChangeIcon());
    ui->ButtonY_11_0->move(x - 9, y - 8);
    ui->ButtonY_11_0->setFixedSize(44, 44);
    ui->ButtonY_11_0->setIconSize(QSize(44, 44));
    ui->ButtonY_11_0->setEnabled(false);

    game.PlayerTurn(11, 0, playerCurrent);
    if (game.VerifyRules(11, 0))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_11_1_clicked()
{
    int x, y;
    x = ui->ButtonY_11_1->x();
    y = ui->ButtonY_11_1->y();

    CurrentMove = std::make_pair(ui->ButtonY_11_1->x(), ui->ButtonY_11_1->y());
            ROPMove=std::make_pair(11,1);

    ui->ButtonY_11_1->setIcon(ChangeIcon());
    ui->ButtonY_11_1->move(x - 9, y - 8);
    ui->ButtonY_11_1->setFixedSize(44, 44);
    ui->ButtonY_11_1->setIconSize(QSize(44, 44));
    ui->ButtonY_11_1->setEnabled(false);

    game.PlayerTurn(11, 1, playerCurrent);
    if (game.VerifyRules(11, 1))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}
\
void YUI::on_ButtonY_11_2_clicked()
{
    int x, y;
    x = ui->ButtonY_11_2->x();
    y = ui->ButtonY_11_2->y();

    CurrentMove = std::make_pair(ui->ButtonY_11_2->x(), ui->ButtonY_11_2->y());
            ROPMove=std::make_pair(11,2);

    ui->ButtonY_11_2->setIcon(ChangeIcon());
    ui->ButtonY_11_2->move(x - 9, y - 8);
    ui->ButtonY_11_2->setFixedSize(44, 44);
    ui->ButtonY_11_2->setIconSize(QSize(44, 44));
    ui->ButtonY_11_2->setEnabled(false);

    game.PlayerTurn(11, 2, playerCurrent);
    if (game.VerifyRules(11, 2))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_11_3_clicked()
{
    int x, y;
    x = ui->ButtonY_11_3->x();
    y = ui->ButtonY_11_3->y();

    CurrentMove = std::make_pair(ui->ButtonY_11_3->x(), ui->ButtonY_11_3->y());
            ROPMove=std::make_pair(11,3);

    ui->ButtonY_11_3->setIcon(ChangeIcon());
    ui->ButtonY_11_3->move(x - 9, y - 8);
    ui->ButtonY_11_3->setFixedSize(44, 44);
    ui->ButtonY_11_3->setIconSize(QSize(44, 44));
    ui->ButtonY_11_3->setEnabled(false);

    game.PlayerTurn(11, 3, playerCurrent);
    if (game.VerifyRules(11, 3))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_11_4_clicked()
{
    int x, y;
    x = ui->ButtonY_11_4->x();
    y = ui->ButtonY_11_4->y();

    CurrentMove = std::make_pair(ui->ButtonY_11_4->x(), ui->ButtonY_11_4->y());
            ROPMove=std::make_pair(11,4);

    ui->ButtonY_11_4->setIcon(ChangeIcon());
    ui->ButtonY_11_4->move(x - 9, y - 8);
    ui->ButtonY_11_4->setFixedSize(44, 44);
    ui->ButtonY_11_4->setIconSize(QSize(44, 44));
    ui->ButtonY_11_4->setEnabled(false);

    game.PlayerTurn(11, 4, playerCurrent);
    if (game.VerifyRules(11, 4))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_11_5_clicked()
{
    int x, y;
    x = ui->ButtonY_11_5->x();
    y = ui->ButtonY_11_5->y();

    CurrentMove = std::make_pair(ui->ButtonY_11_5->x(), ui->ButtonY_11_5->y());
            ROPMove=std::make_pair(11,5);

    ui->ButtonY_11_5->setIcon(ChangeIcon());
    ui->ButtonY_11_5->move(x - 9, y - 8);
    ui->ButtonY_11_5->setFixedSize(44, 44);
    ui->ButtonY_11_5->setIconSize(QSize(44, 44));
    ui->ButtonY_11_5->setEnabled(false);

    game.PlayerTurn(11, 5, playerCurrent);
    if (game.VerifyRules(11, 5))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_11_6_clicked()
{
    int x, y;
    x = ui->ButtonY_11_6->x();
    y = ui->ButtonY_11_6->y();

    CurrentMove = std::make_pair(ui->ButtonY_11_6->x(), ui->ButtonY_11_6->y());
            ROPMove=std::make_pair(11,6);

    ui->ButtonY_11_6->setIcon(ChangeIcon());
    ui->ButtonY_11_6->move(x - 9, y - 8);
    ui->ButtonY_11_6->setFixedSize(44, 44);
    ui->ButtonY_11_6->setIconSize(QSize(44, 44));
    ui->ButtonY_11_6->setEnabled(false);

    game.PlayerTurn(11, 6, playerCurrent);
    if (game.VerifyRules(11, 6))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();

}

void YUI::on_ButtonY_11_7_clicked()
{
    int x, y;
    x = ui->ButtonY_11_7->x();
    y = ui->ButtonY_11_7->y();

    CurrentMove = std::make_pair(ui->ButtonY_11_7->x(), ui->ButtonY_11_7->y());
            ROPMove=std::make_pair(11,7);

    ui->ButtonY_11_7->setIcon(ChangeIcon());
    ui->ButtonY_11_7->move(x - 9, y - 8);
    ui->ButtonY_11_7->setFixedSize(44, 44);
    ui->ButtonY_11_7->setIconSize(QSize(44, 44));
    ui->ButtonY_11_7->setEnabled(false);

    game.PlayerTurn(11, 7, playerCurrent);
    if (game.VerifyRules(11, 7))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_11_8_clicked()
{
    int x, y;
    x = ui->ButtonY_11_8->x();
    y = ui->ButtonY_11_8->y();

    CurrentMove = std::make_pair(ui->ButtonY_11_8->x(), ui->ButtonY_11_8->y());
            ROPMove=std::make_pair(11,8);

    ui->ButtonY_11_8->setIcon(ChangeIcon());
    ui->ButtonY_11_8->move(x - 9, y - 8);
    ui->ButtonY_11_8->setFixedSize(44, 44);
    ui->ButtonY_11_8->setIconSize(QSize(44, 44));
    ui->ButtonY_11_8->setEnabled(false);

    game.PlayerTurn(11, 8, playerCurrent);
    if (game.VerifyRules(11, 8))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_11_9_clicked()
{
    int x, y;
    x = ui->ButtonY_11_9->x();
    y = ui->ButtonY_11_9->y();

    CurrentMove = std::make_pair(ui->ButtonY_11_9->x(), ui->ButtonY_11_9->y());
            ROPMove=std::make_pair(11,9);

    ui->ButtonY_11_9->setIcon(ChangeIcon());
    ui->ButtonY_11_9->move(x - 9, y - 8);
    ui->ButtonY_11_9->setFixedSize(44, 44);
    ui->ButtonY_11_9->setIconSize(QSize(44, 44));
    ui->ButtonY_11_9->setEnabled(false);

    game.PlayerTurn(11, 9, playerCurrent);
    if (game.VerifyRules(11, 9))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_11_10_clicked()
{
    int x, y;
    x = ui->ButtonY_11_10->x();
    y = ui->ButtonY_11_10->y();

    CurrentMove = std::make_pair(ui->ButtonY_11_10->x(), ui->ButtonY_11_10->y());
            ROPMove=std::make_pair(11,10);

    ui->ButtonY_11_10->setIcon(ChangeIcon());
    ui->ButtonY_11_10->move(x - 9, y - 8);
    ui->ButtonY_11_10->setFixedSize(44, 44);
    ui->ButtonY_11_10->setIconSize(QSize(44, 44));
    ui->ButtonY_11_10->setEnabled(false);

    game.PlayerTurn(11, 10, playerCurrent);
    if (game.VerifyRules(11, 10))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_11_11_clicked()
{
    int x, y;
    x = ui->ButtonY_11_11->x();
    y = ui->ButtonY_11_11->y();

    CurrentMove = std::make_pair(ui->ButtonY_11_11->x(), ui->ButtonY_11_11->y());
        ROPMove=std::make_pair(11,11);

    ui->ButtonY_11_11->setIcon(ChangeIcon());
    ui->ButtonY_11_11->move(x - 9, y - 8);
    ui->ButtonY_11_11->setFixedSize(44, 44);
    ui->ButtonY_11_11->setIconSize(QSize(44, 44));
    ui->ButtonY_11_11->setEnabled(false);

    game.PlayerTurn(11, 11, playerCurrent);
    if (game.VerifyRules(11, 11))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_12_0_clicked()
{
    int x, y;
    x = ui->ButtonY_12_0->x();
    y = ui->ButtonY_12_0->y();

    CurrentMove = std::make_pair(ui->ButtonY_12_0->x(), ui->ButtonY_12_0->y());
        ROPMove=std::make_pair(12,0);

    ui->ButtonY_12_0->setIcon(ChangeIcon());
    ui->ButtonY_12_0->move(x - 9, y - 8);
    ui->ButtonY_12_0->setFixedSize(44, 44);
    ui->ButtonY_12_0->setIconSize(QSize(44, 44));
    ui->ButtonY_12_0->setEnabled(false);

    game.PlayerTurn(12, 0, playerCurrent);
    if (game.VerifyRules(12, 0))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_12_1_clicked()
{
    int x, y;
    x = ui->ButtonY_12_1->x();
    y = ui->ButtonY_12_1->y();

    CurrentMove = std::make_pair(ui->ButtonY_12_1->x(), ui->ButtonY_12_1->y());
        ROPMove=std::make_pair(12,1);

    ui->ButtonY_12_1->setIcon(ChangeIcon());
    ui->ButtonY_12_1->move(x - 9, y - 8);
    ui->ButtonY_12_1->setFixedSize(44, 44);
    ui->ButtonY_12_1->setIconSize(QSize(44, 44));
    ui->ButtonY_12_1->setEnabled(false);

    game.PlayerTurn(12, 1, playerCurrent);
    if (game.VerifyRules(12, 1))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_12_2_clicked()
{
    int x, y;
    x = ui->ButtonY_12_2->x();
    y = ui->ButtonY_12_2->y();

    CurrentMove = std::make_pair(ui->ButtonY_12_2->x(), ui->ButtonY_12_2->y());
        ROPMove=std::make_pair(12,2);

    ui->ButtonY_12_2->setIcon(ChangeIcon());
    ui->ButtonY_12_2->move(x - 9, y - 8);
    ui->ButtonY_12_2->setFixedSize(44, 44);
    ui->ButtonY_12_2->setIconSize(QSize(44, 44));
    ui->ButtonY_12_2->setEnabled(false);

    game.PlayerTurn(12, 2, playerCurrent);
    if (game.VerifyRules(12, 2))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_12_3_clicked()
{
    int x, y;
    x = ui->ButtonY_12_3->x();
    y = ui->ButtonY_12_3->y();

    CurrentMove = std::make_pair(ui->ButtonY_12_3->x(), ui->ButtonY_12_3->y());
        ROPMove=std::make_pair(12,3);

    ui->ButtonY_12_3->setIcon(ChangeIcon());
    ui->ButtonY_12_3->move(x - 9, y - 8);
    ui->ButtonY_12_3->setFixedSize(44, 44);
    ui->ButtonY_12_3->setIconSize(QSize(44, 44));
    ui->ButtonY_12_3->setEnabled(false);

    game.PlayerTurn(12, 3, playerCurrent);
    if (game.VerifyRules(12, 3))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_12_4_clicked()
{
    int x, y;
    x = ui->ButtonY_12_4->x();
    y = ui->ButtonY_12_4->y();

    CurrentMove = std::make_pair(ui->ButtonY_12_4->x(), ui->ButtonY_12_4->y());
        ROPMove=std::make_pair(12,4);

    ui->ButtonY_12_4->setIcon(ChangeIcon());
    ui->ButtonY_12_4->move(x - 9, y - 8);
    ui->ButtonY_12_4->setFixedSize(44, 44);
    ui->ButtonY_12_4->setIconSize(QSize(44, 44));
    ui->ButtonY_12_4->setEnabled(false);

    game.PlayerTurn(12, 4, playerCurrent);
    if (game.VerifyRules(12, 4))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_12_5_clicked()
{
    int x, y;
    x = ui->ButtonY_12_5->x();
    y = ui->ButtonY_12_5->y();

    CurrentMove = std::make_pair(ui->ButtonY_12_5->x(), ui->ButtonY_12_5->y());
        ROPMove=std::make_pair(12,5);

    ui->ButtonY_12_5->setIcon(ChangeIcon());
    ui->ButtonY_12_5->move(x - 9, y - 8);
    ui->ButtonY_12_5->setFixedSize(44, 44);
    ui->ButtonY_12_5->setIconSize(QSize(44, 44));
    ui->ButtonY_12_5->setEnabled(false);

    game.PlayerTurn(12, 5, playerCurrent);
    if (game.VerifyRules(12, 5))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_12_6_clicked()
{
    int x, y;
    x = ui->ButtonY_12_6->x();
    y = ui->ButtonY_12_6->y();

    CurrentMove = std::make_pair(ui->ButtonY_12_6->x(), ui->ButtonY_12_6->y());
        ROPMove=std::make_pair(12,6);

    ui->ButtonY_12_6->setIcon(ChangeIcon());
    ui->ButtonY_12_6->move(x - 9, y - 8);
    ui->ButtonY_12_6->setFixedSize(44, 44);
    ui->ButtonY_12_6->setIconSize(QSize(44, 44));
    ui->ButtonY_12_6->setEnabled(false);

    game.PlayerTurn(12, 6, playerCurrent);
    if (game.VerifyRules(12, 6))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_12_7_clicked()
{
    int x, y;
    x = ui->ButtonY_12_7->x();
    y = ui->ButtonY_12_7->y();

    CurrentMove = std::make_pair(ui->ButtonY_12_7->x(), ui->ButtonY_12_7->y());
        ROPMove=std::make_pair(12,7);

    ui->ButtonY_12_7->setIcon(ChangeIcon());
    ui->ButtonY_12_7->move(x - 9, y - 8);
    ui->ButtonY_12_7->setFixedSize(44, 44);
    ui->ButtonY_12_7->setIconSize(QSize(44, 44));
    ui->ButtonY_12_7->setEnabled(false);

    game.PlayerTurn(12, 7, playerCurrent);
    if (game.VerifyRules(12, 7))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_12_8_clicked()
{
    int x, y;
    x = ui->ButtonY_12_8->x();
    y = ui->ButtonY_12_8->y();

    CurrentMove = std::make_pair(ui->ButtonY_12_8->x(), ui->ButtonY_12_8->y());
        ROPMove=std::make_pair(12,8);

    ui->ButtonY_12_8->setIcon(ChangeIcon());
    ui->ButtonY_12_8->move(x - 9, y - 8);
    ui->ButtonY_12_8->setFixedSize(44, 44);
    ui->ButtonY_12_8->setIconSize(QSize(44, 44));
    ui->ButtonY_12_8->setEnabled(false);

    game.PlayerTurn(12, 8, playerCurrent);
    if (game.VerifyRules(12, 8))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_12_9_clicked()
{
    int x, y;
    x = ui->ButtonY_12_9->x();
    y = ui->ButtonY_12_9->y();

    CurrentMove = std::make_pair(ui->ButtonY_12_9->x(), ui->ButtonY_12_9->y());
        ROPMove=std::make_pair(12,9);

    ui->ButtonY_12_9->setIcon(ChangeIcon());
    ui->ButtonY_12_9->move(x - 9, y - 8);
    ui->ButtonY_12_9->setFixedSize(44, 44);
    ui->ButtonY_12_9->setIconSize(QSize(44, 44));
    ui->ButtonY_12_9->setEnabled(false);

    game.PlayerTurn(12, 9, playerCurrent);
    if (game.VerifyRules(12, 9))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_12_10_clicked()
{
    int x, y;
    x = ui->ButtonY_12_10->x();
    y = ui->ButtonY_12_10->y();

    CurrentMove = std::make_pair(ui->ButtonY_12_10->x(), ui->ButtonY_12_10->y());
        ROPMove=std::make_pair(12,10);

    ui->ButtonY_12_10->setIcon(ChangeIcon());
    ui->ButtonY_12_10->move(x - 9, y - 8);
    ui->ButtonY_12_10->setFixedSize(44, 44);
    ui->ButtonY_12_10->setIconSize(QSize(44, 44));
    ui->ButtonY_12_10->setEnabled(false);

    game.PlayerTurn(12, 10, playerCurrent);
    if (game.VerifyRules(12, 10))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_12_11_clicked()
{
    int x, y;
    x = ui->ButtonY_12_11->x();
    y = ui->ButtonY_12_11->y();

    CurrentMove = std::make_pair(ui->ButtonY_12_11->x(), ui->ButtonY_12_11->y());
        ROPMove=std::make_pair(12,11);

    ui->ButtonY_12_11->setIcon(ChangeIcon());
    ui->ButtonY_12_11->move(x - 9, y - 8);
    ui->ButtonY_12_11->setFixedSize(44, 44);
    ui->ButtonY_12_11->setIconSize(QSize(44, 44));
    ui->ButtonY_12_11->setEnabled(false);

    game.PlayerTurn(12, 11, playerCurrent);
    if (game.VerifyRules(12, 11))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_12_12_clicked()
{
    int x, y;
    x = ui->ButtonY_12_12->x();
    y = ui->ButtonY_12_12->y();

    CurrentMove = std::make_pair(ui->ButtonY_12_12->x(), ui->ButtonY_12_12->y());
    ROPMove=std::make_pair(12,12);

    ui->ButtonY_12_12->setIcon(ChangeIcon());
    ui->ButtonY_12_12->move(x - 9, y - 8);
    ui->ButtonY_12_12->setFixedSize(44, 44);
    ui->ButtonY_12_12->setIconSize(QSize(44, 44));
    ui->ButtonY_12_12->setEnabled(false);

    game.PlayerTurn(12, 12, playerCurrent);
    if (game.VerifyRules(12, 12))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_13_0_clicked()
{
    int x, y;
    x = ui->ButtonY_13_0->x();
    y = ui->ButtonY_13_0->y();

    CurrentMove = std::make_pair(ui->ButtonY_13_0->x(), ui->ButtonY_13_0->y());
    ROPMove=std::make_pair(13,0);

    ui->ButtonY_13_0->setIcon(ChangeIcon());
    ui->ButtonY_13_0->move(x - 9, y - 8);
    ui->ButtonY_13_0->setFixedSize(44, 44);
    ui->ButtonY_13_0->setIconSize(QSize(44, 44));
    ui->ButtonY_13_0->setEnabled(false);

    game.PlayerTurn(13, 0, playerCurrent);
    if (game.VerifyRules(13, 0))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_13_1_clicked()
{
    int x, y;
    x = ui->ButtonY_13_1->x();
    y = ui->ButtonY_13_1->y();

    CurrentMove = std::make_pair(ui->ButtonY_13_1->x(), ui->ButtonY_13_1->y());
    ROPMove=std::make_pair(13,1);

    ui->ButtonY_13_1->setIcon(ChangeIcon());
    ui->ButtonY_13_1->move(x - 9, y - 8);
    ui->ButtonY_13_1->setFixedSize(44, 44);
    ui->ButtonY_13_1->setIconSize(QSize(44, 44));
    ui->ButtonY_13_1->setEnabled(false);

    game.PlayerTurn(13, 1, playerCurrent);
    if (game.VerifyRules(13, 1))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_13_2_clicked()
{
    int x, y;
    x = ui->ButtonY_13_2->x();
    y = ui->ButtonY_13_2->y();

    CurrentMove = std::make_pair(ui->ButtonY_13_2->x(), ui->ButtonY_13_2->y());
    ROPMove=std::make_pair(13,2);

    ui->ButtonY_13_2->setIcon(ChangeIcon());
    ui->ButtonY_13_2->move(x - 9, y - 8);
    ui->ButtonY_13_2->setFixedSize(44, 44);
    ui->ButtonY_13_2->setIconSize(QSize(44, 44));
    ui->ButtonY_13_2->setEnabled(false);

    game.PlayerTurn(13, 2, playerCurrent);
    if (game.VerifyRules(13, 2))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_13_3_clicked()
{
    int x, y;
    x = ui->ButtonY_13_3->x();
    y = ui->ButtonY_13_3->y();

    CurrentMove = std::make_pair(ui->ButtonY_13_3->x(), ui->ButtonY_13_3->y());
    ROPMove=std::make_pair(13,3);

    ui->ButtonY_13_3->setIcon(ChangeIcon());
    ui->ButtonY_13_3->move(x - 9, y - 8);
    ui->ButtonY_13_3->setFixedSize(44, 44);
    ui->ButtonY_13_3->setIconSize(QSize(44, 44));
    ui->ButtonY_13_3->setEnabled(false);

    game.PlayerTurn(13, 3, playerCurrent);
    if (game.VerifyRules(13, 3))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_13_4_clicked()
{
    int x, y;
    x = ui->ButtonY_13_4->x();
    y = ui->ButtonY_13_4->y();

    CurrentMove = std::make_pair(ui->ButtonY_13_4->x(), ui->ButtonY_13_4->y());
    ROPMove=std::make_pair(13,4);

    ui->ButtonY_13_4->setIcon(ChangeIcon());
    ui->ButtonY_13_4->move(x - 9, y - 8);
    ui->ButtonY_13_4->setFixedSize(44, 44);
    ui->ButtonY_13_4->setIconSize(QSize(44, 44));
    ui->ButtonY_13_4->setEnabled(false);

    game.PlayerTurn(13, 4, playerCurrent);
    if (game.VerifyRules(13, 4))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_13_5_clicked()
{
    int x, y;
    x = ui->ButtonY_13_5->x();
    y = ui->ButtonY_13_5->y();

    CurrentMove = std::make_pair(ui->ButtonY_13_5->x(), ui->ButtonY_13_5->y());
    ROPMove=std::make_pair(13,5);

    ui->ButtonY_13_5->setIcon(ChangeIcon());
    ui->ButtonY_13_5->move(x - 9, y - 8);
    ui->ButtonY_13_5->setFixedSize(44, 44);
    ui->ButtonY_13_5->setIconSize(QSize(44, 44));
    ui->ButtonY_13_5->setEnabled(false);

    game.PlayerTurn(13, 5, playerCurrent);
    if (game.VerifyRules(13, 5))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_13_6_clicked()
{
    int x, y;
    x = ui->ButtonY_13_6->x();
    y = ui->ButtonY_13_6->y();

    CurrentMove = std::make_pair(ui->ButtonY_13_6->x(), ui->ButtonY_13_6->y());
ROPMove=std::make_pair(13,6);
    ui->ButtonY_13_6->setIcon(ChangeIcon());
    ui->ButtonY_13_6->move(x - 9, y - 8);
    ui->ButtonY_13_6->setFixedSize(44, 44);
    ui->ButtonY_13_6->setIconSize(QSize(44, 44));
    ui->ButtonY_13_6->setEnabled(false);

    game.PlayerTurn(13, 6, playerCurrent);
    if (game.VerifyRules(13, 6))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_13_7_clicked()
{
    int x, y;
    x = ui->ButtonY_13_7->x();
    y = ui->ButtonY_13_7->y();

    CurrentMove = std::make_pair(ui->ButtonY_13_7->x(), ui->ButtonY_13_7->y());
ROPMove=std::make_pair(13,7);
    ui->ButtonY_13_7->setIcon(ChangeIcon());
    ui->ButtonY_13_7->move(x - 9, y - 8);
    ui->ButtonY_13_7->setFixedSize(44, 44);
    ui->ButtonY_13_7->setIconSize(QSize(44, 44));
    ui->ButtonY_13_7->setEnabled(false);

    game.PlayerTurn(13, 7, playerCurrent);
    if (game.VerifyRules(13, 7))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_13_8_clicked()
{
    int x, y;
    x = ui->ButtonY_13_8->x();
    y = ui->ButtonY_13_8->y();

    CurrentMove = std::make_pair(ui->ButtonY_13_8->x(), ui->ButtonY_13_8->y());
    ROPMove=std::make_pair(13,8);

    ui->ButtonY_13_8->setIcon(ChangeIcon());
    ui->ButtonY_13_8->move(x - 9, y - 8);
    ui->ButtonY_13_8->setFixedSize(44, 44);
    ui->ButtonY_13_8->setIconSize(QSize(44, 44));
    ui->ButtonY_13_8->setEnabled(false);

    game.PlayerTurn(13, 8, playerCurrent);
    if (game.VerifyRules(13, 8))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_13_9_clicked()
{
    int x, y;
    x = ui->ButtonY_13_9->x();
    y = ui->ButtonY_13_9->y();

    CurrentMove = std::make_pair(ui->ButtonY_13_9->x(), ui->ButtonY_13_9->y());
ROPMove=std::make_pair(13,9);
    ui->ButtonY_13_9->setIcon(ChangeIcon());
    ui->ButtonY_13_9->move(x - 9, y - 8);
    ui->ButtonY_13_9->setFixedSize(44, 44);
    ui->ButtonY_13_9->setIconSize(QSize(44, 44));
    ui->ButtonY_13_9->setEnabled(false);

    game.PlayerTurn(13, 9, playerCurrent);
    if (game.VerifyRules(13, 9))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_13_10_clicked()
{
    int x, y;
    x = ui->ButtonY_13_10->x();
    y = ui->ButtonY_13_10->y();

    CurrentMove = std::make_pair(ui->ButtonY_13_10->x(), ui->ButtonY_13_10->y());
    ROPMove=std::make_pair(13,10);

    ui->ButtonY_13_10->setIcon(ChangeIcon());
    ui->ButtonY_13_10->move(x - 9, y - 8);
    ui->ButtonY_13_10->setFixedSize(44, 44);
    ui->ButtonY_13_10->setIconSize(QSize(44, 44));
    ui->ButtonY_13_10->setEnabled(false);

    game.PlayerTurn(13, 10, playerCurrent);
    if (game.VerifyRules(13, 10))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_13_11_clicked()
{
    int x, y;
    x = ui->ButtonY_13_11->x();
    y = ui->ButtonY_13_11->y();

    CurrentMove = std::make_pair(ui->ButtonY_13_11->x(), ui->ButtonY_13_11->y());
    ROPMove=std::make_pair(13,11);

    ui->ButtonY_13_11->setIcon(ChangeIcon());
    ui->ButtonY_13_11->move(x - 9, y - 8);
    ui->ButtonY_13_11->setFixedSize(44, 44);
    ui->ButtonY_13_11->setIconSize(QSize(44, 44));
    ui->ButtonY_13_11->setEnabled(false);

    game.PlayerTurn(13, 11, playerCurrent);
    if (game.VerifyRules(13, 11))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_13_12_clicked()
{
    int x, y;
    x = ui->ButtonY_13_12->x();
    y = ui->ButtonY_13_12->y();

    CurrentMove = std::make_pair(ui->ButtonY_13_12->x(), ui->ButtonY_13_12->y());
    ROPMove=std::make_pair(13,12);

    ui->ButtonY_13_12->setIcon(ChangeIcon());
    ui->ButtonY_13_12->move(x - 9, y - 8);
    ui->ButtonY_13_12->setFixedSize(44, 44);
    ui->ButtonY_13_12->setIconSize(QSize(44, 44));
    ui->ButtonY_13_12->setEnabled(false);

    game.PlayerTurn(13, 12, playerCurrent);
    if (game.VerifyRules(13, 12))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void YUI::on_ButtonY_13_13_clicked()
{
    int x, y;
    x = ui->ButtonY_13_13->x();
    y = ui->ButtonY_13_13->y();

    CurrentMove = std::make_pair(ui->ButtonY_13_13->x(), ui->ButtonY_13_13->y());
    ROPMove=std::make_pair(13,13);

    ui->ButtonY_13_13->setIcon(ChangeIcon());
    ui->ButtonY_13_13->move(x - 9, y - 8);
    ui->ButtonY_13_13->setFixedSize(44, 44);
    ui->ButtonY_13_13->setIconSize(QSize(44, 44));
    ui->ButtonY_13_13->setEnabled(false);

    game.PlayerTurn(13, 13, playerCurrent);
    if (game.VerifyRules(13, 13))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat");
        ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}
