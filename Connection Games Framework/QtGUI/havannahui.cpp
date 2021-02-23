#include "havannahui.h"
#include "ui_havannahui.h"
#include <QPainter>
#include <QGraphicsView>

HavannahUI::HavannahUI(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::HavannahUI)
{
    ui->setupUi(this);

    QPixmap bkgd("../GUI pictures/GameBackground.jpg");
           bkgd=bkgd.scaled(this->size(),Qt::IgnoreAspectRatio);
           QPalette palette;
           palette.setBrush(QPalette::Background, bkgd);
           this->setPalette(palette);
     ui->stackedWidget->setCurrentIndex(0);
}

HavannahUI::~HavannahUI()
{
    delete ui;
}

void HavannahUI::ChangeTurn()
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

QIcon HavannahUI::ChangeIcon()
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

void HavannahUI::on_pushButton_clicked()
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
    ui->Winner->setText(playerCurrent.GetName()+" 's trun");


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

void HavannahUI::on_ButtonHav_0_0_clicked()
{
    int x, y;
    x = ui->ButtonHav_0_0->x();
    y = ui->ButtonHav_0_0->y();

    CurrentMove = std::make_pair(ui->ButtonHav_0_0->x(), ui->ButtonHav_0_0->y());
           ROPMove=std::make_pair(0,0);

    ui->ButtonHav_0_0->setIcon(ChangeIcon());
    ui->ButtonHav_0_0->move(x - 9, y - 8);
    ui->ButtonHav_0_0->setFixedSize(44, 44);
    ui->ButtonHav_0_0->setIconSize(QSize(44, 44));
    ui->ButtonHav_0_0->setEnabled(false);

    game.PlayerTurn(0, 0, playerCurrent);
    if (game.VerifyRules(0, 0))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_0_1_clicked()
{
    int x, y;
    x = ui->ButtonHav_0_1->x();
    y = ui->ButtonHav_0_1->y();

    CurrentMove = std::make_pair(ui->ButtonHav_0_1->x(), ui->ButtonHav_0_1->y());
           ROPMove=std::make_pair(0,1);

    ui->ButtonHav_0_1->setIcon(ChangeIcon());
    ui->ButtonHav_0_1->move(x - 9, y - 8);
    ui->ButtonHav_0_1->setFixedSize(44, 44);
    ui->ButtonHav_0_1->setIconSize(QSize(44, 44));
    ui->ButtonHav_0_1->setEnabled(false);

    game.PlayerTurn(0, 1, playerCurrent);
    if (game.VerifyRules(0, 1))
    {
       ui->Winner->setText(playerCurrent.GetName() + " a castigat");
       ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_0_2_clicked()
{
    int x, y;
    x = ui->ButtonHav_0_2->x();
    y = ui->ButtonHav_0_2->y();

    CurrentMove = std::make_pair(ui->ButtonHav_0_2->x(), ui->ButtonHav_0_2->y());
       ROPMove=std::make_pair(0,2);
    ui->ButtonHav_0_2->setIcon(ChangeIcon());
    ui->ButtonHav_0_2->move(x - 9, y - 8);
    ui->ButtonHav_0_2->setFixedSize(44, 44);
    ui->ButtonHav_0_2->setIconSize(QSize(44, 44));
    ui->ButtonHav_0_2->setEnabled(false);

    game.PlayerTurn(0, 2, playerCurrent);
    if (game.VerifyRules(0, 2))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_0_3_clicked()
{
    int x, y;
    x = ui->ButtonHav_0_3->x();
    y = ui->ButtonHav_0_3->y();

    CurrentMove = std::make_pair(ui->ButtonHav_0_3->x(), ui->ButtonHav_0_3->y());
       ROPMove=std::make_pair(0,3);
    ui->ButtonHav_0_3->setIcon(ChangeIcon());
    ui->ButtonHav_0_3->move(x - 9, y - 8);
    ui->ButtonHav_0_3->setFixedSize(44, 44);
    ui->ButtonHav_0_3->setIconSize(QSize(44, 44));
    ui->ButtonHav_0_3->setEnabled(false);

    game.PlayerTurn(0, 3, playerCurrent);
    if (game.VerifyRules(0, 3))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_0_5_clicked()
{
    int x, y;
    x = ui->ButtonHav_0_5->x();
    y = ui->ButtonHav_0_5->y();

    CurrentMove = std::make_pair(ui->ButtonHav_0_5->x(), ui->ButtonHav_0_5->y());
       ROPMove=std::make_pair(0,5);
    ui->ButtonHav_0_5->setIcon(ChangeIcon());
    ui->ButtonHav_0_5->move(x - 9, y - 8);
    ui->ButtonHav_0_5->setFixedSize(44, 44);
    ui->ButtonHav_0_5->setIconSize(QSize(44, 44));
    ui->ButtonHav_0_5->setEnabled(false);

    game.PlayerTurn(0, 5, playerCurrent);
    if (game.VerifyRules(0, 5))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_0_6_clicked()
{
    int x, y;
    x = ui->ButtonHav_0_6->x();
    y = ui->ButtonHav_0_6->y();
       ROPMove=std::make_pair(0,6);
    CurrentMove = std::make_pair(ui->ButtonHav_0_6->x(), ui->ButtonHav_0_6->y());

    ui->ButtonHav_0_6->setIcon(ChangeIcon());
    ui->ButtonHav_0_6->move(x - 9, y - 8);
    ui->ButtonHav_0_6->setFixedSize(44, 44);
    ui->ButtonHav_0_6->setIconSize(QSize(44, 44));
    ui->ButtonHav_0_6->setEnabled(false);

    game.PlayerTurn(0, 6, playerCurrent);
    if (game.VerifyRules(0, 6))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_0_7_clicked()
{
    int x, y;
    x = ui->ButtonHav_0_7->x();
    y = ui->ButtonHav_0_7->y();

    CurrentMove = std::make_pair(ui->ButtonHav_0_7->x(), ui->ButtonHav_0_7->y());
       ROPMove=std::make_pair(0,7);
    ui->ButtonHav_0_7->setIcon(ChangeIcon());
    ui->ButtonHav_0_7->move(x - 9, y - 8);
    ui->ButtonHav_0_7->setFixedSize(44, 44);
    ui->ButtonHav_0_7->setIconSize(QSize(44, 44));
    ui->ButtonHav_0_7->setEnabled(false);

    game.PlayerTurn(0, 7, playerCurrent);
    if (game.VerifyRules(0, 7))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_0_8_clicked()
{
    int x, y;
    x = ui->ButtonHav_0_8->x();
    y = ui->ButtonHav_0_8->y();

    CurrentMove = std::make_pair(ui->ButtonHav_0_8->x(), ui->ButtonHav_0_8->y());
       ROPMove=std::make_pair(0,8);
    ui->ButtonHav_0_8->setIcon(ChangeIcon());
    ui->ButtonHav_0_8->move(x - 9, y - 8);
    ui->ButtonHav_0_8->setFixedSize(44, 44);
    ui->ButtonHav_0_8->setIconSize(QSize(44, 44));
    ui->ButtonHav_0_8->setEnabled(false);

    game.PlayerTurn(0, 8, playerCurrent);
    if (game.VerifyRules(0, 8))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_0_9_clicked()
{
    int x, y;
    x = ui->ButtonHav_0_9->x();
    y = ui->ButtonHav_0_9->y();

    CurrentMove = std::make_pair(ui->ButtonHav_0_9->x(), ui->ButtonHav_0_9->y());
       ROPMove=std::make_pair(0,9);
    ui->ButtonHav_0_9->setIcon(ChangeIcon());
    ui->ButtonHav_0_9->move(x - 9, y - 8);
    ui->ButtonHav_0_9->setFixedSize(44, 44);
    ui->ButtonHav_0_9->setIconSize(QSize(44, 44));
    ui->ButtonHav_0_9->setEnabled(false);

    game.PlayerTurn(0, 9, playerCurrent);
    if (game.VerifyRules(0, 9))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_1_0_clicked()
{
    int x, y;
    x = ui->ButtonHav_1_0->x();
    y = ui->ButtonHav_1_0->y();

    CurrentMove = std::make_pair(ui->ButtonHav_1_0->x(), ui->ButtonHav_1_0->y());
       ROPMove=std::make_pair(1,0);
    ui->ButtonHav_1_0->setIcon(ChangeIcon());
    ui->ButtonHav_1_0->move(x - 9, y - 8);
    ui->ButtonHav_1_0->setFixedSize(44, 44);
    ui->ButtonHav_1_0->setIconSize(QSize(44, 44));
    ui->ButtonHav_1_0->setEnabled(false);

    game.PlayerTurn(1, 0, playerCurrent);
    if (game.VerifyRules(1, 0))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_1_1_clicked()
{
    int x, y;
    x = ui->ButtonHav_1_1->x();
    y = ui->ButtonHav_1_1->y();

    CurrentMove = std::make_pair(ui->ButtonHav_1_1->x(), ui->ButtonHav_1_1->y());
       ROPMove=std::make_pair(1,1);
    ui->ButtonHav_1_1->setIcon(ChangeIcon());
    ui->ButtonHav_1_1->move(x - 9, y - 8);
    ui->ButtonHav_1_1->setFixedSize(44, 44);
    ui->ButtonHav_1_1->setIconSize(QSize(44, 44));
    ui->ButtonHav_1_1->setEnabled(false);

    game.PlayerTurn(1, 1, playerCurrent);
    if (game.VerifyRules(1, 1))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_1_2_clicked()
{
    int x, y;
    x = ui->ButtonHav_1_2->x();
    y = ui->ButtonHav_1_2->y();

    CurrentMove = std::make_pair(ui->ButtonHav_1_2->x(), ui->ButtonHav_1_2->y());
       ROPMove=std::make_pair(1,2);
    ui->ButtonHav_1_2->setIcon(ChangeIcon());
    ui->ButtonHav_1_2->move(x - 9, y - 8);
    ui->ButtonHav_1_2->setFixedSize(44, 44);
    ui->ButtonHav_1_2->setIconSize(QSize(44, 44));
    ui->ButtonHav_1_2->setEnabled(false);

    game.PlayerTurn(1, 2, playerCurrent);
    if (game.VerifyRules(1, 2))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_1_3_clicked()
{
    int x, y;
    x = ui->ButtonHav_1_3->x();
    y = ui->ButtonHav_1_3->y();
       ROPMove=std::make_pair(1,3);
    CurrentMove = std::make_pair(ui->ButtonHav_1_3->x(), ui->ButtonHav_1_3->y());

    ui->ButtonHav_1_3->setIcon(ChangeIcon());
    ui->ButtonHav_1_3->move(x - 9, y - 8);
    ui->ButtonHav_1_3->setFixedSize(44, 44);
    ui->ButtonHav_1_3->setIconSize(QSize(44, 44));
    ui->ButtonHav_1_3->setEnabled(false);

    game.PlayerTurn(1, 3, playerCurrent);
    if (game.VerifyRules(1, 3))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_1_4_clicked()
{
    int x, y;
    x = ui->ButtonHav_1_4->x();
    y = ui->ButtonHav_1_4->y();

    CurrentMove = std::make_pair(ui->ButtonHav_1_4->x(), ui->ButtonHav_1_4->y());
 ROPMove=std::make_pair(1,4);
    ui->ButtonHav_1_4->setIcon(ChangeIcon());
    ui->ButtonHav_1_4->move(x - 9, y - 8);
    ui->ButtonHav_1_4->setFixedSize(44, 44);
    ui->ButtonHav_1_4->setIconSize(QSize(44, 44));
    ui->ButtonHav_1_4->setEnabled(false);

    game.PlayerTurn(1, 4, playerCurrent);
    if (game.VerifyRules(1, 4))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_1_5_clicked()
{
    int x, y;
    x = ui->ButtonHav_1_5->x();
    y = ui->ButtonHav_1_5->y();

    CurrentMove = std::make_pair(ui->ButtonHav_1_5->x(), ui->ButtonHav_1_5->y());
 ROPMove=std::make_pair(1,5);
    ui->ButtonHav_1_5->setIcon(ChangeIcon());
    ui->ButtonHav_1_5->move(x - 9, y - 8);
    ui->ButtonHav_1_5->setFixedSize(44, 44);
    ui->ButtonHav_1_5->setIconSize(QSize(44, 44));
    ui->ButtonHav_1_5->setEnabled(false);

    game.PlayerTurn(1, 5, playerCurrent);
    if (game.VerifyRules(1, 5))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_1_6_clicked()
{
    int x, y;
    x = ui->ButtonHav_1_6->x();
    y = ui->ButtonHav_1_6->y();

    CurrentMove = std::make_pair(ui->ButtonHav_1_6->x(), ui->ButtonHav_1_6->y());
 ROPMove=std::make_pair(1,6);
    ui->ButtonHav_1_6->setIcon(ChangeIcon());
    ui->ButtonHav_1_6->move(x - 9, y - 8);
    ui->ButtonHav_1_6->setFixedSize(44, 44);
    ui->ButtonHav_1_6->setIconSize(QSize(44, 44));
    ui->ButtonHav_1_6->setEnabled(false);

    game.PlayerTurn(1, 6, playerCurrent);
    if (game.VerifyRules(1, 6))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_1_7_clicked()
{
    int x, y;
    x = ui->ButtonHav_1_7->x();
    y = ui->ButtonHav_1_7->y();

    CurrentMove = std::make_pair(ui->ButtonHav_1_7->x(), ui->ButtonHav_1_7->y());
 ROPMove=std::make_pair(1,7);
    ui->ButtonHav_1_7->setIcon(ChangeIcon());
    ui->ButtonHav_1_7->move(x - 9, y - 8);
    ui->ButtonHav_1_7->setFixedSize(44, 44);
    ui->ButtonHav_1_7->setIconSize(QSize(44, 44));
    ui->ButtonHav_1_7->setEnabled(false);

    game.PlayerTurn(1, 7, playerCurrent);
    if (game.VerifyRules(1, 7))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_1_8_clicked()
{
    int x, y;
    x = ui->ButtonHav_1_8->x();
    y = ui->ButtonHav_1_8->y();

    CurrentMove = std::make_pair(ui->ButtonHav_1_8->x(), ui->ButtonHav_1_8->y());
 ROPMove=std::make_pair(1,8);
    ui->ButtonHav_1_8->setIcon(ChangeIcon());
    ui->ButtonHav_1_8->move(x - 9, y - 8);
    ui->ButtonHav_1_8->setFixedSize(44, 44);
    ui->ButtonHav_1_8->setIconSize(QSize(44, 44));
    ui->ButtonHav_1_8->setEnabled(false);

    game.PlayerTurn(1, 8, playerCurrent);
    if (game.VerifyRules(1, 8))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_1_9_clicked()
{
    int x, y;
    x = ui->ButtonHav_1_9->x();
    y = ui->ButtonHav_1_9->y();
 ROPMove=std::make_pair(1,9);
    CurrentMove = std::make_pair(ui->ButtonHav_1_9->x(), ui->ButtonHav_1_9->y());

    ui->ButtonHav_1_9->setIcon(ChangeIcon());
    ui->ButtonHav_1_9->move(x - 9, y - 8);
    ui->ButtonHav_1_9->setFixedSize(44, 44);
    ui->ButtonHav_1_9->setIconSize(QSize(44, 44));
    ui->ButtonHav_1_9->setEnabled(false);

    game.PlayerTurn(1, 9, playerCurrent);
    if (game.VerifyRules(1, 9))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_1_10_clicked()
{
    int x, y;
    x = ui->ButtonHav_1_10->x();
    y = ui->ButtonHav_1_10->y();

    CurrentMove = std::make_pair(ui->ButtonHav_1_10->x(), ui->ButtonHav_1_10->y());
 ROPMove=std::make_pair(1,10);
    ui->ButtonHav_1_10->setIcon(ChangeIcon());
    ui->ButtonHav_1_10->move(x - 9, y - 8);
    ui->ButtonHav_1_10->setFixedSize(44, 44);
    ui->ButtonHav_1_10->setIconSize(QSize(44, 44));
    ui->ButtonHav_1_10->setEnabled(false);

    game.PlayerTurn(1, 10, playerCurrent);
    if (game.VerifyRules(1, 10))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_2_0_clicked()
{
    int x, y;
    x = ui->ButtonHav_2_0->x();
    y = ui->ButtonHav_2_0->y();

    CurrentMove = std::make_pair(ui->ButtonHav_2_0->x(), ui->ButtonHav_2_0->y());
 ROPMove=std::make_pair(2,0);
    ui->ButtonHav_2_0->setIcon(ChangeIcon());
    ui->ButtonHav_2_0->move(x - 9, y - 8);
    ui->ButtonHav_2_0->setFixedSize(44, 44);
    ui->ButtonHav_2_0->setIconSize(QSize(44, 44));
    ui->ButtonHav_2_0->setEnabled(false);

    game.PlayerTurn(2, 0, playerCurrent);
    if (game.VerifyRules(2, 0))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_2_1_clicked()
{
    int x, y;
    x = ui->ButtonHav_2_1->x();
    y = ui->ButtonHav_2_1->y();

    CurrentMove = std::make_pair(ui->ButtonHav_2_1->x(), ui->ButtonHav_2_1->y());
 ROPMove=std::make_pair(2,1);
    ui->ButtonHav_2_1->setIcon(ChangeIcon());
    ui->ButtonHav_2_1->move(x - 9, y - 8);
    ui->ButtonHav_2_1->setFixedSize(44, 44);
    ui->ButtonHav_2_1->setIconSize(QSize(44, 44));
    ui->ButtonHav_2_1->setEnabled(false);

    game.PlayerTurn(2, 1, playerCurrent);
    if (game.VerifyRules(2, 1))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_2_2_clicked()
{
    int x, y;
    x = ui->ButtonHav_2_2->x();
    y = ui->ButtonHav_2_2->y();

    CurrentMove = std::make_pair(ui->ButtonHav_2_2->x(), ui->ButtonHav_2_2->y());
 ROPMove=std::make_pair(2,2);
    ui->ButtonHav_2_2->setIcon(ChangeIcon());
    ui->ButtonHav_2_2->move(x - 9, y - 8);
    ui->ButtonHav_2_2->setFixedSize(44, 44);
    ui->ButtonHav_2_2->setIconSize(QSize(44, 44));
    ui->ButtonHav_2_2->setEnabled(false);

    game.PlayerTurn(2, 2, playerCurrent);
    if (game.VerifyRules(2, 2))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_2_3_clicked()
{
    int x, y;
    x = ui->ButtonHav_2_3->x();
    y = ui->ButtonHav_2_3->y();
 ROPMove=std::make_pair(2,3);
    CurrentMove = std::make_pair(ui->ButtonHav_2_3->x(), ui->ButtonHav_2_3->y());

    ui->ButtonHav_2_3->setIcon(ChangeIcon());
    ui->ButtonHav_2_3->move(x - 9, y - 8);
    ui->ButtonHav_2_3->setFixedSize(44, 44);
    ui->ButtonHav_2_3->setIconSize(QSize(44, 44));
    ui->ButtonHav_2_3->setEnabled(false);

    game.PlayerTurn(2, 3, playerCurrent);
    if (game.VerifyRules(2, 3))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_2_4_clicked()
{
    int x, y;
    x = ui->ButtonHav_2_4->x();
    y = ui->ButtonHav_2_4->y();

    CurrentMove = std::make_pair(ui->ButtonHav_2_4->x(), ui->ButtonHav_2_4->y());
 ROPMove=std::make_pair(2,4);
    ui->ButtonHav_2_4->setIcon(ChangeIcon());
    ui->ButtonHav_2_4->move(x - 9, y - 8);
    ui->ButtonHav_2_4->setFixedSize(44, 44);
    ui->ButtonHav_2_4->setIconSize(QSize(44, 44));
    ui->ButtonHav_2_4->setEnabled(false);

    game.PlayerTurn(2, 4, playerCurrent);
    if (game.VerifyRules(2, 4))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_2_5_clicked()
{
    int x, y;
    x = ui->ButtonHav_2_5->x();
    y = ui->ButtonHav_2_5->y();

    CurrentMove = std::make_pair(ui->ButtonHav_2_5->x(), ui->ButtonHav_2_5->y());
 ROPMove=std::make_pair(2,5);
    ui->ButtonHav_2_5->setIcon(ChangeIcon());
    ui->ButtonHav_2_5->move(x - 9, y - 8);
    ui->ButtonHav_2_5->setFixedSize(44, 44);
    ui->ButtonHav_2_5->setIconSize(QSize(44, 44));
    ui->ButtonHav_2_5->setEnabled(false);

    game.PlayerTurn(2, 5, playerCurrent);
    if (game.VerifyRules(2, 5))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_2_6_clicked()
{
    int x, y;
    x = ui->ButtonHav_2_6->x();
    y = ui->ButtonHav_2_6->y();

    CurrentMove = std::make_pair(ui->ButtonHav_2_6->x(), ui->ButtonHav_2_6->y());
 ROPMove=std::make_pair(2,6);
    ui->ButtonHav_2_6->setIcon(ChangeIcon());
    ui->ButtonHav_2_6->move(x - 9, y - 8);
    ui->ButtonHav_2_6->setFixedSize(44, 44);
    ui->ButtonHav_2_6->setIconSize(QSize(44, 44));
    ui->ButtonHav_2_6->setEnabled(false);

    game.PlayerTurn(2, 6, playerCurrent);
    if (game.VerifyRules(2, 6))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_2_7_clicked()
{
    int x, y;
    x = ui->ButtonHav_2_7->x();
    y = ui->ButtonHav_2_7->y();

    CurrentMove = std::make_pair(ui->ButtonHav_2_7->x(), ui->ButtonHav_2_7->y());
 ROPMove=std::make_pair(2,7);
    ui->ButtonHav_2_7->setIcon(ChangeIcon());
    ui->ButtonHav_2_7->move(x - 9, y - 8);
    ui->ButtonHav_2_7->setFixedSize(44, 44);
    ui->ButtonHav_2_7->setIconSize(QSize(44, 44));
    ui->ButtonHav_2_7->setEnabled(false);

    game.PlayerTurn(2, 7, playerCurrent);
    if (game.VerifyRules(2, 7))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_2_8_clicked()
{
    int x, y;
    x = ui->ButtonHav_2_8->x();
    y = ui->ButtonHav_2_8->y();

    CurrentMove = std::make_pair(ui->ButtonHav_2_8->x(), ui->ButtonHav_2_8->y());
 ROPMove=std::make_pair(2,8);
    ui->ButtonHav_2_8->setIcon(ChangeIcon());
    ui->ButtonHav_2_8->move(x - 9, y - 8);
    ui->ButtonHav_2_8->setFixedSize(44, 44);
    ui->ButtonHav_2_8->setIconSize(QSize(44, 44));
    ui->ButtonHav_2_8->setEnabled(false);

    game.PlayerTurn(2, 8, playerCurrent);
    if (game.VerifyRules(2, 8))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_2_9_clicked()
{
    int x, y;
    x = ui->ButtonHav_2_9->x();
    y = ui->ButtonHav_2_9->y();

    CurrentMove = std::make_pair(ui->ButtonHav_2_9->x(), ui->ButtonHav_2_9->y());
 ROPMove=std::make_pair(2,9);
    ui->ButtonHav_2_9->setIcon(ChangeIcon());
    ui->ButtonHav_2_9->move(x - 9, y - 8);
    ui->ButtonHav_2_9->setFixedSize(44, 44);
    ui->ButtonHav_2_9->setIconSize(QSize(44, 44));
    ui->ButtonHav_2_9->setEnabled(false);

    game.PlayerTurn(2, 9, playerCurrent);
    if (game.VerifyRules(2, 9))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_2_10_clicked()
{
    int x, y;
    x = ui->ButtonHav_2_10->x();
    y = ui->ButtonHav_2_10->y();

    CurrentMove = std::make_pair(ui->ButtonHav_2_10->x(), ui->ButtonHav_2_10->y());
 ROPMove=std::make_pair(2,10);
    ui->ButtonHav_2_10->setIcon(ChangeIcon());
    ui->ButtonHav_2_10->move(x - 9, y - 8);
    ui->ButtonHav_2_10->setFixedSize(44, 44);
    ui->ButtonHav_2_10->setIconSize(QSize(44, 44));
    ui->ButtonHav_2_10->setEnabled(false);

    game.PlayerTurn(2, 10, playerCurrent);
    if (game.VerifyRules(2, 10))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_2_11_clicked()
{
    int x, y;
    x = ui->ButtonHav_2_11->x();
    y = ui->ButtonHav_2_11->y();

    CurrentMove = std::make_pair(ui->ButtonHav_2_11->x(), ui->ButtonHav_2_11->y());
 ROPMove=std::make_pair(2,11);
    ui->ButtonHav_2_11->setIcon(ChangeIcon());
    ui->ButtonHav_2_11->move(x - 9, y - 8);
    ui->ButtonHav_2_11->setFixedSize(44, 44);
    ui->ButtonHav_2_11->setIconSize(QSize(44, 44));
    ui->ButtonHav_2_11->setEnabled(false);

    game.PlayerTurn(2, 11, playerCurrent);
    if (game.VerifyRules(2, 11))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_3_0_clicked()
{
    int x, y;
    x = ui->ButtonHav_3_0->x();
    y = ui->ButtonHav_3_0->y();

    CurrentMove = std::make_pair(ui->ButtonHav_3_0->x(), ui->ButtonHav_3_0->y());
 ROPMove=std::make_pair(3,0);
    ui->ButtonHav_3_0->setIcon(ChangeIcon());
    ui->ButtonHav_3_0->move(x - 9, y - 8);
    ui->ButtonHav_3_0->setFixedSize(44, 44);
    ui->ButtonHav_3_0->setIconSize(QSize(44, 44));
    ui->ButtonHav_3_0->setEnabled(false);

    game.PlayerTurn(3, 0, playerCurrent);
    if (game.VerifyRules(3, 0))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_3_1_clicked()
{
    int x, y;
    x = ui->ButtonHav_3_1->x();
    y = ui->ButtonHav_3_1->y();

    CurrentMove = std::make_pair(ui->ButtonHav_3_1->x(), ui->ButtonHav_3_1->y());
ROPMove=std::make_pair(3,1);
    ui->ButtonHav_3_1->setIcon(ChangeIcon());
    ui->ButtonHav_3_1->move(x - 9, y - 8);
    ui->ButtonHav_3_1->setFixedSize(44, 44);
    ui->ButtonHav_3_1->setIconSize(QSize(44, 44));
    ui->ButtonHav_3_1->setEnabled(false);

    game.PlayerTurn(3, 1, playerCurrent);
    if (game.VerifyRules(3, 1))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_3_2_clicked()
{
    int x, y;
    x = ui->ButtonHav_3_2->x();
    y = ui->ButtonHav_3_2->y();

    CurrentMove = std::make_pair(ui->ButtonHav_3_2->x(), ui->ButtonHav_3_2->y());
ROPMove=std::make_pair(3,2);
    ui->ButtonHav_3_2->setIcon(ChangeIcon());
    ui->ButtonHav_3_2->move(x - 9, y - 8);
    ui->ButtonHav_3_2->setFixedSize(44, 44);
    ui->ButtonHav_3_2->setIconSize(QSize(44, 44));
    ui->ButtonHav_3_2->setEnabled(false);

    game.PlayerTurn(3, 2, playerCurrent);
    if (game.VerifyRules(3, 2))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_3_3_clicked()
{
    int x, y;
    x = ui->ButtonHav_3_3->x();
    y = ui->ButtonHav_3_3->y();

    CurrentMove = std::make_pair(ui->ButtonHav_3_3->x(), ui->ButtonHav_3_3->y());
ROPMove=std::make_pair(3,3);
    ui->ButtonHav_3_3->setIcon(ChangeIcon());
    ui->ButtonHav_3_3->move(x - 9, y - 8);
    ui->ButtonHav_3_3->setFixedSize(44, 44);
    ui->ButtonHav_3_3->setIconSize(QSize(44, 44));
    ui->ButtonHav_3_3->setEnabled(false);

    game.PlayerTurn(3, 3, playerCurrent);
    if (game.VerifyRules(3, 3))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_3_4_clicked()
{
    int x, y;
    x = ui->ButtonHav_3_4->x();
    y = ui->ButtonHav_3_4->y();

    CurrentMove = std::make_pair(ui->ButtonHav_3_4->x(), ui->ButtonHav_3_4->y());
ROPMove=std::make_pair(3,4);
    ui->ButtonHav_3_4->setIcon(ChangeIcon());
    ui->ButtonHav_3_4->move(x - 9, y - 8);
    ui->ButtonHav_3_4->setFixedSize(44, 44);
    ui->ButtonHav_3_4->setIconSize(QSize(44, 44));
    ui->ButtonHav_3_4->setEnabled(false);

    game.PlayerTurn(3, 4, playerCurrent);
    if (game.VerifyRules(3, 4))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_3_5_clicked()
{
    int x, y;
    x = ui->ButtonHav_3_5->x();
    y = ui->ButtonHav_3_5->y();

    CurrentMove = std::make_pair(ui->ButtonHav_3_5->x(), ui->ButtonHav_3_5->y());
ROPMove=std::make_pair(3,5);
    ui->ButtonHav_3_5->setIcon(ChangeIcon());
    ui->ButtonHav_3_5->move(x - 9, y - 8);
    ui->ButtonHav_3_5->setFixedSize(44, 44);
    ui->ButtonHav_3_5->setIconSize(QSize(44, 44));
    ui->ButtonHav_3_5->setEnabled(false);

    game.PlayerTurn(3, 5, playerCurrent);
    if (game.VerifyRules(3, 5))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_3_6_clicked()
{
    int x, y;
    x = ui->ButtonHav_3_6->x();
    y = ui->ButtonHav_3_6->y();

    CurrentMove = std::make_pair(ui->ButtonHav_3_6->x(), ui->ButtonHav_3_6->y());
ROPMove=std::make_pair(3,6);
    ui->ButtonHav_3_6->setIcon(ChangeIcon());
    ui->ButtonHav_3_6->move(x - 9, y - 8);
    ui->ButtonHav_3_6->setFixedSize(44, 44);
    ui->ButtonHav_3_6->setIconSize(QSize(44, 44));
    ui->ButtonHav_3_6->setEnabled(false);

    game.PlayerTurn(3, 6, playerCurrent);
    if (game.VerifyRules(3, 6))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_3_7_clicked()
{
    int x, y;
    x = ui->ButtonHav_3_7->x();
    y = ui->ButtonHav_3_7->y();
ROPMove=std::make_pair(3,7);
    CurrentMove = std::make_pair(ui->ButtonHav_3_7->x(), ui->ButtonHav_3_7->y());

    ui->ButtonHav_3_7->setIcon(ChangeIcon());
    ui->ButtonHav_3_7->move(x - 9, y - 8);
    ui->ButtonHav_3_7->setFixedSize(44, 44);
    ui->ButtonHav_3_7->setIconSize(QSize(44, 44));
    ui->ButtonHav_3_7->setEnabled(false);

    game.PlayerTurn(3, 7, playerCurrent);
    if (game.VerifyRules(3, 7))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_3_8_clicked()
{
    int x, y;
    x = ui->ButtonHav_3_8->x();
    y = ui->ButtonHav_3_8->y();

    CurrentMove = std::make_pair(ui->ButtonHav_3_8->x(), ui->ButtonHav_3_8->y());
ROPMove=std::make_pair(3,8);
    ui->ButtonHav_3_8->setIcon(ChangeIcon());
    ui->ButtonHav_3_8->move(x - 9, y - 8);
    ui->ButtonHav_3_8->setFixedSize(44, 44);
    ui->ButtonHav_3_8->setIconSize(QSize(44, 44));
    ui->ButtonHav_3_8->setEnabled(false);

    game.PlayerTurn(3, 8, playerCurrent);
    if (game.VerifyRules(3, 8))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_3_9_clicked()
{
    int x, y;
    x = ui->ButtonHav_3_9->x();
    y = ui->ButtonHav_3_9->y();

    CurrentMove = std::make_pair(ui->ButtonHav_3_9->x(), ui->ButtonHav_3_9->y());
ROPMove=std::make_pair(3,9);
    ui->ButtonHav_3_9->setIcon(ChangeIcon());
    ui->ButtonHav_3_9->move(x - 9, y - 8);
    ui->ButtonHav_3_9->setFixedSize(44, 44);
    ui->ButtonHav_3_9->setIconSize(QSize(44, 44));
    ui->ButtonHav_3_9->setEnabled(false);

    game.PlayerTurn(3, 9, playerCurrent);
    if (game.VerifyRules(3, 9))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_3_10_clicked()
{
    int x, y;
    x = ui->ButtonHav_3_10->x();
    y = ui->ButtonHav_3_10->y();

    CurrentMove = std::make_pair(ui->ButtonHav_3_10->x(), ui->ButtonHav_3_10->y());
ROPMove=std::make_pair(3,10);
    ui->ButtonHav_3_10->setIcon(ChangeIcon());
    ui->ButtonHav_3_10->move(x - 9, y - 8);
    ui->ButtonHav_3_10->setFixedSize(44, 44);
    ui->ButtonHav_3_10->setIconSize(QSize(44, 44));
    ui->ButtonHav_3_10->setEnabled(false);

    game.PlayerTurn(3, 10, playerCurrent);
    if (game.VerifyRules(3, 10))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_3_11_clicked()
{
    int x, y;
    x = ui->ButtonHav_3_11->x();
    y = ui->ButtonHav_3_11->y();
ROPMove=std::make_pair(3,11);
    CurrentMove = std::make_pair(ui->ButtonHav_3_11->x(), ui->ButtonHav_3_11->y());

    ui->ButtonHav_3_11->setIcon(ChangeIcon());
    ui->ButtonHav_3_11->move(x - 9, y - 8);
    ui->ButtonHav_3_11->setFixedSize(44, 44);
    ui->ButtonHav_3_11->setIconSize(QSize(44, 44));
    ui->ButtonHav_3_11->setEnabled(false);

    game.PlayerTurn(3, 11, playerCurrent);
    if (game.VerifyRules(3, 11))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_3_12_clicked()
{
    int x, y;
    x = ui->ButtonHav_3_12->x();
    y = ui->ButtonHav_3_12->y();

    CurrentMove = std::make_pair(ui->ButtonHav_3_12->x(), ui->ButtonHav_3_12->y());
ROPMove=std::make_pair(3,12);
    ui->ButtonHav_3_12->setIcon(ChangeIcon());
    ui->ButtonHav_3_12->move(x - 9, y - 8);
    ui->ButtonHav_3_12->setFixedSize(44, 44);
    ui->ButtonHav_3_12->setIconSize(QSize(44, 44));
    ui->ButtonHav_3_12->setEnabled(false);

    game.PlayerTurn(3, 12, playerCurrent);
    if (game.VerifyRules(3, 12))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_4_0_clicked()
{
    int x, y;
    x = ui->ButtonHav_4_0->x();
    y = ui->ButtonHav_4_0->y();

    CurrentMove = std::make_pair(ui->ButtonHav_4_0->x(), ui->ButtonHav_4_0->y());
ROPMove=std::make_pair(4,0);
    ui->ButtonHav_4_0->setIcon(ChangeIcon());
    ui->ButtonHav_4_0->move(x - 9, y - 8);
    ui->ButtonHav_4_0->setFixedSize(44, 44);
    ui->ButtonHav_4_0->setIconSize(QSize(44, 44));
    ui->ButtonHav_4_0->setEnabled(false);

    game.PlayerTurn(4, 0, playerCurrent);
    if (game.VerifyRules(4, 0))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_4_1_clicked()
{
    int x, y;
    x = ui->ButtonHav_4_1->x();
    y = ui->ButtonHav_4_1->y();

    CurrentMove = std::make_pair(ui->ButtonHav_4_1->x(), ui->ButtonHav_4_1->y());
ROPMove=std::make_pair(4,1);
    ui->ButtonHav_4_1->setIcon(ChangeIcon());
    ui->ButtonHav_4_1->move(x - 9, y - 8);
    ui->ButtonHav_4_1->setFixedSize(44, 44);
    ui->ButtonHav_4_1->setIconSize(QSize(44, 44));
    ui->ButtonHav_4_1->setEnabled(false);

    game.PlayerTurn(4, 1, playerCurrent);
    if (game.VerifyRules(4, 1))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_4_2_clicked()
{
    int x, y;
    x = ui->ButtonHav_4_2->x();
    y = ui->ButtonHav_4_2->y();

    CurrentMove = std::make_pair(ui->ButtonHav_4_2->x(), ui->ButtonHav_4_2->y());
ROPMove=std::make_pair(4,2);
    ui->ButtonHav_4_2->setIcon(ChangeIcon());
    ui->ButtonHav_4_2->move(x - 9, y - 8);
    ui->ButtonHav_4_2->setFixedSize(44, 44);
    ui->ButtonHav_4_2->setIconSize(QSize(44, 44));
    ui->ButtonHav_4_2->setEnabled(false);

    game.PlayerTurn(4, 2, playerCurrent);
    if (game.VerifyRules(4, 2))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_4_3_clicked()
{
    int x, y;
    x = ui->ButtonHav_4_3->x();
    y = ui->ButtonHav_4_3->y();

    CurrentMove = std::make_pair(ui->ButtonHav_4_3->x(), ui->ButtonHav_4_3->y());
ROPMove=std::make_pair(4,3);
    ui->ButtonHav_4_3->setIcon(ChangeIcon());
    ui->ButtonHav_4_3->move(x - 9, y - 8);
    ui->ButtonHav_4_3->setFixedSize(44, 44);
    ui->ButtonHav_4_3->setIconSize(QSize(44, 44));
    ui->ButtonHav_4_3->setEnabled(false);

    game.PlayerTurn(4, 3, playerCurrent);
    if (game.VerifyRules(4, 3))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_4_4_clicked()
{
    int x, y;
    x = ui->ButtonHav_4_4->x();
    y = ui->ButtonHav_4_4->y();

    CurrentMove = std::make_pair(ui->ButtonHav_4_4->x(), ui->ButtonHav_4_4->y());
ROPMove=std::make_pair(4,4);
    ui->ButtonHav_4_4->setIcon(ChangeIcon());
    ui->ButtonHav_4_4->move(x - 9, y - 8);
    ui->ButtonHav_4_4->setFixedSize(44, 44);
    ui->ButtonHav_4_4->setIconSize(QSize(44, 44));
    ui->ButtonHav_4_4->setEnabled(false);

    game.PlayerTurn(4, 4, playerCurrent);
    if (game.VerifyRules(4, 4))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_4_5_clicked()
{
    int x, y;
    x = ui->ButtonHav_4_5->x();
    y = ui->ButtonHav_4_5->y();

    CurrentMove = std::make_pair(ui->ButtonHav_4_5->x(), ui->ButtonHav_4_5->y());
ROPMove=std::make_pair(4,5);
    ui->ButtonHav_4_5->setIcon(ChangeIcon());
    ui->ButtonHav_4_5->move(x - 9, y - 8);
    ui->ButtonHav_4_5->setFixedSize(44, 44);
    ui->ButtonHav_4_5->setIconSize(QSize(44, 44));
    ui->ButtonHav_4_5->setEnabled(false);

    game.PlayerTurn(4, 5, playerCurrent);
    if (game.VerifyRules(4, 5))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_4_6_clicked()
{
    int x, y;
    x = ui->ButtonHav_4_6->x();
    y = ui->ButtonHav_4_6->y();

    CurrentMove = std::make_pair(ui->ButtonHav_4_6->x(), ui->ButtonHav_4_6->y());
ROPMove=std::make_pair(4,6);
    ui->ButtonHav_4_6->setIcon(ChangeIcon());
    ui->ButtonHav_4_6->move(x - 9, y - 8);
    ui->ButtonHav_4_6->setFixedSize(44, 44);
    ui->ButtonHav_4_6->setIconSize(QSize(44, 44));
    ui->ButtonHav_4_6->setEnabled(false);

    game.PlayerTurn(4, 6, playerCurrent);
    if (game.VerifyRules(4, 6))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_4_7_clicked()
{
    int x, y;
    x = ui->ButtonHav_4_7->x();
    y = ui->ButtonHav_4_7->y();

    CurrentMove = std::make_pair(ui->ButtonHav_4_7->x(), ui->ButtonHav_4_7->y());
ROPMove=std::make_pair(4,7);
    ui->ButtonHav_4_7->setIcon(ChangeIcon());
    ui->ButtonHav_4_7->move(x - 9, y - 8);
    ui->ButtonHav_4_7->setFixedSize(44, 44);
    ui->ButtonHav_4_7->setIconSize(QSize(44, 44));
    ui->ButtonHav_4_7->setEnabled(false);

    game.PlayerTurn(4, 7, playerCurrent);
    if (game.VerifyRules(4, 7))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_4_8_clicked()
{
    int x, y;
    x = ui->ButtonHav_4_8->x();
    y = ui->ButtonHav_4_8->y();

    CurrentMove = std::make_pair(ui->ButtonHav_4_8->x(), ui->ButtonHav_4_8->y());
ROPMove=std::make_pair(4,8);
    ui->ButtonHav_4_8->setIcon(ChangeIcon());
    ui->ButtonHav_4_8->move(x - 9, y - 8);
    ui->ButtonHav_4_8->setFixedSize(44, 44);
    ui->ButtonHav_4_8->setIconSize(QSize(44, 44));
    ui->ButtonHav_4_8->setEnabled(false);

    game.PlayerTurn(4, 8, playerCurrent);
    if (game.VerifyRules(4, 8))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_4_9_clicked()
{
    int x, y;
    x = ui->ButtonHav_4_9->x();
    y = ui->ButtonHav_4_9->y();

    CurrentMove = std::make_pair(ui->ButtonHav_4_9->x(), ui->ButtonHav_4_9->y());
ROPMove=std::make_pair(4,9);
    ui->ButtonHav_4_9->setIcon(ChangeIcon());
    ui->ButtonHav_4_9->move(x - 9, y - 8);
    ui->ButtonHav_4_9->setFixedSize(44, 44);
    ui->ButtonHav_4_9->setIconSize(QSize(44, 44));
    ui->ButtonHav_4_9->setEnabled(false);

    game.PlayerTurn(4, 9, playerCurrent);
    if (game.VerifyRules(4, 9))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_4_10_clicked()
{
    int x, y;
    x = ui->ButtonHav_4_10->x();
    y = ui->ButtonHav_4_10->y();

    CurrentMove = std::make_pair(ui->ButtonHav_4_10->x(), ui->ButtonHav_4_10->y());
ROPMove=std::make_pair(4,10);
    ui->ButtonHav_4_10->setIcon(ChangeIcon());
    ui->ButtonHav_4_10->move(x - 9, y - 8);
    ui->ButtonHav_4_10->setFixedSize(44, 44);
    ui->ButtonHav_4_10->setIconSize(QSize(44, 44));
    ui->ButtonHav_4_10->setEnabled(false);

    game.PlayerTurn(4, 10, playerCurrent);
    if (game.VerifyRules(4, 10))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_4_11_clicked()
{
    int x, y;
    x = ui->ButtonHav_4_11->x();
    y = ui->ButtonHav_4_11->y();

    CurrentMove = std::make_pair(ui->ButtonHav_4_11->x(), ui->ButtonHav_4_11->y());
ROPMove=std::make_pair(4,11);
    ui->ButtonHav_4_11->setIcon(ChangeIcon());
    ui->ButtonHav_4_11->move(x - 9, y - 8);
    ui->ButtonHav_4_11->setFixedSize(44, 44);
    ui->ButtonHav_4_11->setIconSize(QSize(44, 44));
    ui->ButtonHav_4_11->setEnabled(false);

    game.PlayerTurn(4, 11, playerCurrent);
    if (game.VerifyRules(4, 11))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_4_12_clicked()
{
    int x, y;
    x = ui->ButtonHav_4_12->x();
    y = ui->ButtonHav_4_12->y();

    CurrentMove = std::make_pair(ui->ButtonHav_4_12->x(), ui->ButtonHav_4_12->y());
ROPMove=std::make_pair(4,12);
    ui->ButtonHav_4_12->setIcon(ChangeIcon());
    ui->ButtonHav_4_12->move(x - 9, y - 8);
    ui->ButtonHav_4_12->setFixedSize(44, 44);
    ui->ButtonHav_4_12->setIconSize(QSize(44, 44));
    ui->ButtonHav_4_12->setEnabled(false);

    game.PlayerTurn(4, 12, playerCurrent);
    if (game.VerifyRules(4, 12))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_4_13_clicked()
{
    int x, y;
    x = ui->ButtonHav_4_13->x();
    y = ui->ButtonHav_4_13->y();

    CurrentMove = std::make_pair(ui->ButtonHav_4_13->x(), ui->ButtonHav_4_13->y());
ROPMove=std::make_pair(4,13);
    ui->ButtonHav_4_13->setIcon(ChangeIcon());
    ui->ButtonHav_4_13->move(x - 9, y - 8);
    ui->ButtonHav_4_13->setFixedSize(44, 44);
    ui->ButtonHav_4_13->setIconSize(QSize(44, 44));
    ui->ButtonHav_4_13->setEnabled(false);

    game.PlayerTurn(4, 13, playerCurrent);
    if (game.VerifyRules(4, 13))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_5_0_clicked()
{
    int x, y;
    x = ui->ButtonHav_5_0->x();
    y = ui->ButtonHav_5_0->y();

    CurrentMove = std::make_pair(ui->ButtonHav_5_0->x(), ui->ButtonHav_5_0->y());
ROPMove=std::make_pair(5,0);
    ui->ButtonHav_5_0->setIcon(ChangeIcon());
    ui->ButtonHav_5_0->move(x - 9, y - 8);
    ui->ButtonHav_5_0->setFixedSize(44, 44);
    ui->ButtonHav_5_0->setIconSize(QSize(44, 44));
    ui->ButtonHav_5_0->setEnabled(false);

    game.PlayerTurn(5, 0, playerCurrent);
    if (game.VerifyRules(5, 0))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_5_1_clicked()
{
    int x, y;
    x = ui->ButtonHav_5_1->x();
    y = ui->ButtonHav_5_1->y();

    CurrentMove = std::make_pair(ui->ButtonHav_5_1->x(), ui->ButtonHav_5_1->y());
ROPMove=std::make_pair(5,1);
    ui->ButtonHav_5_1->setIcon(ChangeIcon());
    ui->ButtonHav_5_1->move(x - 9, y - 8);
    ui->ButtonHav_5_1->setFixedSize(44, 44);
    ui->ButtonHav_5_1->setIconSize(QSize(44, 44));
    ui->ButtonHav_5_1->setEnabled(false);

    game.PlayerTurn(5, 1, playerCurrent);
    if (game.VerifyRules(5, 1))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_5_2_clicked()
{
    int x, y;
    x = ui->ButtonHav_5_2->x();
    y = ui->ButtonHav_5_2->y();

    CurrentMove = std::make_pair(ui->ButtonHav_5_2->x(), ui->ButtonHav_5_2->y());
ROPMove=std::make_pair(5,2);
    ui->ButtonHav_5_2->setIcon(ChangeIcon());
    ui->ButtonHav_5_2->move(x - 9, y - 8);
    ui->ButtonHav_5_2->setFixedSize(44, 44);
    ui->ButtonHav_5_2->setIconSize(QSize(44, 44));
    ui->ButtonHav_5_2->setEnabled(false);

    game.PlayerTurn(5, 2, playerCurrent);
    if (game.VerifyRules(5, 2))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_5_3_clicked()
{
    int x, y;
    x = ui->ButtonHav_5_3->x();
    y = ui->ButtonHav_5_3->y();

    CurrentMove = std::make_pair(ui->ButtonHav_5_3->x(), ui->ButtonHav_5_3->y());
ROPMove=std::make_pair(5,3);
    ui->ButtonHav_5_3->setIcon(ChangeIcon());
    ui->ButtonHav_5_3->move(x - 9, y - 8);
    ui->ButtonHav_5_3->setFixedSize(44, 44);
    ui->ButtonHav_5_3->setIconSize(QSize(44, 44));
    ui->ButtonHav_5_3->setEnabled(false);

    game.PlayerTurn(5, 3, playerCurrent);
    if (game.VerifyRules(5, 3))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_5_4_clicked()
{
    int x, y;
    x = ui->ButtonHav_5_4->x();
    y = ui->ButtonHav_5_4->y();

    CurrentMove = std::make_pair(ui->ButtonHav_5_4->x(), ui->ButtonHav_5_4->y());
ROPMove=std::make_pair(5,4);
    ui->ButtonHav_5_4->setIcon(ChangeIcon());
    ui->ButtonHav_5_4->move(x - 9, y - 8);
    ui->ButtonHav_5_4->setFixedSize(44, 44);
    ui->ButtonHav_5_4->setIconSize(QSize(44, 44));
    ui->ButtonHav_5_4->setEnabled(false);

    game.PlayerTurn(5, 4, playerCurrent);
    if (game.VerifyRules(5, 4))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_5_5_clicked()
{
    int x, y;
    x = ui->ButtonHav_5_5->x();
    y = ui->ButtonHav_5_5->y();

    CurrentMove = std::make_pair(ui->ButtonHav_5_5->x(), ui->ButtonHav_5_5->y());
ROPMove=std::make_pair(5,5);
    ui->ButtonHav_5_5->setIcon(ChangeIcon());
    ui->ButtonHav_5_5->move(x - 9, y - 8);
    ui->ButtonHav_5_5->setFixedSize(44, 44);
    ui->ButtonHav_5_5->setIconSize(QSize(44, 44));
    ui->ButtonHav_5_5->setEnabled(false);

    game.PlayerTurn(5, 5, playerCurrent);
    if (game.VerifyRules(5, 5))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_5_6_clicked()
{
    int x, y;
    x = ui->ButtonHav_5_6->x();
    y = ui->ButtonHav_5_6->y();

    CurrentMove = std::make_pair(ui->ButtonHav_5_6->x(), ui->ButtonHav_5_6->y());
ROPMove=std::make_pair(5,6);
    ui->ButtonHav_5_6->setIcon(ChangeIcon());
    ui->ButtonHav_5_6->move(x - 9, y - 8);
    ui->ButtonHav_5_6->setFixedSize(44, 44);
    ui->ButtonHav_5_6->setIconSize(QSize(44, 44));
    ui->ButtonHav_5_6->setEnabled(false);

    game.PlayerTurn(5, 6, playerCurrent);
    if (game.VerifyRules(5, 6))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_5_7_clicked()
{
    int x, y;
    x = ui->ButtonHav_5_7->x();
    y = ui->ButtonHav_5_7->y();

    CurrentMove = std::make_pair(ui->ButtonHav_5_7->x(), ui->ButtonHav_5_7->y());
ROPMove=std::make_pair(5,7);
    ui->ButtonHav_5_7->setIcon(ChangeIcon());
    ui->ButtonHav_5_7->move(x - 9, y - 8);
    ui->ButtonHav_5_7->setFixedSize(44, 44);
    ui->ButtonHav_5_7->setIconSize(QSize(44, 44));
    ui->ButtonHav_5_7->setEnabled(false);

    game.PlayerTurn(5, 7, playerCurrent);
    if (game.VerifyRules(5, 7))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_5_8_clicked()
{
    int x, y;
    x = ui->ButtonHav_5_8->x();
    y = ui->ButtonHav_5_8->y();

    CurrentMove = std::make_pair(ui->ButtonHav_5_8->x(), ui->ButtonHav_5_8->y());
ROPMove=std::make_pair(5,8);
    ui->ButtonHav_5_8->setIcon(ChangeIcon());
    ui->ButtonHav_5_8->move(x - 9, y - 8);
    ui->ButtonHav_5_8->setFixedSize(44, 44);
    ui->ButtonHav_5_8->setIconSize(QSize(44, 44));
    ui->ButtonHav_5_8->setEnabled(false);

    game.PlayerTurn(5, 8, playerCurrent);
    if (game.VerifyRules(5, 8))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_5_9_clicked()
{
    int x, y;
    x = ui->ButtonHav_5_9->x();
    y = ui->ButtonHav_5_9->y();

    CurrentMove = std::make_pair(ui->ButtonHav_5_9->x(), ui->ButtonHav_5_9->y());
ROPMove=std::make_pair(5,9);
    ui->ButtonHav_5_9->setIcon(ChangeIcon());
    ui->ButtonHav_5_9->move(x - 9, y - 8);
    ui->ButtonHav_5_9->setFixedSize(44, 44);
    ui->ButtonHav_5_9->setIconSize(QSize(44, 44));
    ui->ButtonHav_5_9->setEnabled(false);

    game.PlayerTurn(5, 9, playerCurrent);
    if (game.VerifyRules(5, 9))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_5_10_clicked()
{
    int x, y;
    x = ui->ButtonHav_5_10->x();
    y = ui->ButtonHav_5_10->y();

    CurrentMove = std::make_pair(ui->ButtonHav_5_10->x(), ui->ButtonHav_5_10->y());
ROPMove=std::make_pair(5,10);
    ui->ButtonHav_5_10->setIcon(ChangeIcon());
    ui->ButtonHav_5_10->move(x - 9, y - 8);
    ui->ButtonHav_5_10->setFixedSize(44, 44);
    ui->ButtonHav_5_10->setIconSize(QSize(44, 44));
    ui->ButtonHav_5_10->setEnabled(false);

    game.PlayerTurn(5, 10, playerCurrent);
    if (game.VerifyRules(5, 10))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_5_11_clicked()
{
    int x, y;
    x = ui->ButtonHav_5_11->x();
    y = ui->ButtonHav_5_11->y();

    CurrentMove = std::make_pair(ui->ButtonHav_5_11->x(), ui->ButtonHav_5_11->y());
ROPMove=std::make_pair(5,11);
    ui->ButtonHav_5_11->setIcon(ChangeIcon());
    ui->ButtonHav_5_11->move(x - 9, y - 8);
    ui->ButtonHav_5_11->setFixedSize(44, 44);
    ui->ButtonHav_5_11->setIconSize(QSize(44, 44));
    ui->ButtonHav_5_11->setEnabled(false);

    game.PlayerTurn(5, 11, playerCurrent);
    if (game.VerifyRules(5, 11))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_5_12_clicked()
{
    int x, y;
    x = ui->ButtonHav_5_12->x();
    y = ui->ButtonHav_5_12->y();

    CurrentMove = std::make_pair(ui->ButtonHav_5_12->x(), ui->ButtonHav_5_12->y());
ROPMove=std::make_pair(5,12);
    ui->ButtonHav_5_12->setIcon(ChangeIcon());
    ui->ButtonHav_5_12->move(x - 9, y - 8);
    ui->ButtonHav_5_12->setFixedSize(44, 44);
    ui->ButtonHav_5_12->setIconSize(QSize(44, 44));
    ui->ButtonHav_5_12->setEnabled(false);

    game.PlayerTurn(5, 12, playerCurrent);
    if (game.VerifyRules(5, 12))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_5_13_clicked()
{
    int x, y;
    x = ui->ButtonHav_5_13->x();
    y = ui->ButtonHav_5_13->y();

    CurrentMove = std::make_pair(ui->ButtonHav_5_13->x(), ui->ButtonHav_5_13->y());
ROPMove=std::make_pair(5,13);
    ui->ButtonHav_5_13->setIcon(ChangeIcon());
    ui->ButtonHav_5_13->move(x - 9, y - 8);
    ui->ButtonHav_5_13->setFixedSize(44, 44);
    ui->ButtonHav_5_13->setIconSize(QSize(44, 44));
    ui->ButtonHav_5_13->setEnabled(false);

    game.PlayerTurn(5, 13, playerCurrent);
    if (game.VerifyRules(5, 13))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_5_14_clicked()
{
    int x, y;
    x = ui->ButtonHav_5_14->x();
    y = ui->ButtonHav_5_14->y();

    CurrentMove = std::make_pair(ui->ButtonHav_5_14->x(), ui->ButtonHav_5_14->y());
ROPMove=std::make_pair(5,14);
    ui->ButtonHav_5_14->setIcon(ChangeIcon());
    ui->ButtonHav_5_14->move(x - 9, y - 8);
    ui->ButtonHav_5_14->setFixedSize(44, 44);
    ui->ButtonHav_5_14->setIconSize(QSize(44, 44));
    ui->ButtonHav_5_14->setEnabled(false);

    game.PlayerTurn(5, 14, playerCurrent);
    if (game.VerifyRules(5, 14))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_6_0_clicked()
{
    int x, y;
    x = ui->ButtonHav_6_0->x();
    y = ui->ButtonHav_6_0->y();

    CurrentMove = std::make_pair(ui->ButtonHav_6_0->x(), ui->ButtonHav_6_0->y());
ROPMove=std::make_pair(6,0);
    ui->ButtonHav_6_0->setIcon(ChangeIcon());
    ui->ButtonHav_6_0->move(x - 9, y - 8);
    ui->ButtonHav_6_0->setFixedSize(44, 44);
    ui->ButtonHav_6_0->setIconSize(QSize(44, 44));
    ui->ButtonHav_6_0->setEnabled(false);

    game.PlayerTurn(6, 0, playerCurrent);
    if (game.VerifyRules(6, 0))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_6_1_clicked()
{
    int x, y;
    x = ui->ButtonHav_6_1->x();
    y = ui->ButtonHav_6_1->y();

    CurrentMove = std::make_pair(ui->ButtonHav_6_1->x(), ui->ButtonHav_6_1->y());
ROPMove=std::make_pair(6,1);
    ui->ButtonHav_6_1->setIcon(ChangeIcon());
    ui->ButtonHav_6_1->move(x - 9, y - 8);
    ui->ButtonHav_6_1->setFixedSize(44, 44);
    ui->ButtonHav_6_1->setIconSize(QSize(44, 44));
    ui->ButtonHav_6_1->setEnabled(false);

    game.PlayerTurn(6, 1, playerCurrent);
    if (game.VerifyRules(6, 1))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_6_2_clicked()
{
    int x, y;
    x = ui->ButtonHav_6_2->x();
    y = ui->ButtonHav_6_2->y();

    CurrentMove = std::make_pair(ui->ButtonHav_6_2->x(), ui->ButtonHav_6_2->y());
ROPMove=std::make_pair(6,2);
    ui->ButtonHav_6_2->setIcon(ChangeIcon());
    ui->ButtonHav_6_2->move(x - 9, y - 8);
    ui->ButtonHav_6_2->setFixedSize(44, 44);
    ui->ButtonHav_6_2->setIconSize(QSize(44, 44));
    ui->ButtonHav_6_2->setEnabled(false);

    game.PlayerTurn(6, 2, playerCurrent);
    if (game.VerifyRules(6, 2))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_6_3_clicked()
{
    int x, y;
    x = ui->ButtonHav_6_3->x();
    y = ui->ButtonHav_6_3->y();

    CurrentMove = std::make_pair(ui->ButtonHav_6_3->x(), ui->ButtonHav_6_3->y());
ROPMove=std::make_pair(6,3);
    ui->ButtonHav_6_3->setIcon(ChangeIcon());
    ui->ButtonHav_6_3->move(x - 9, y - 8);
    ui->ButtonHav_6_3->setFixedSize(44, 44);
    ui->ButtonHav_6_3->setIconSize(QSize(44, 44));
    ui->ButtonHav_6_3->setEnabled(false);

    game.PlayerTurn(6, 3, playerCurrent);
    if (game.VerifyRules(6, 3))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_6_4_clicked()
{
    int x, y;
    x = ui->ButtonHav_6_4->x();
    y = ui->ButtonHav_6_4->y();

    CurrentMove = std::make_pair(ui->ButtonHav_6_4->x(), ui->ButtonHav_6_4->y());
ROPMove=std::make_pair(6,4);
    ui->ButtonHav_6_4->setIcon(ChangeIcon());
    ui->ButtonHav_6_4->move(x - 9, y - 8);
    ui->ButtonHav_6_4->setFixedSize(44, 44);
    ui->ButtonHav_6_4->setIconSize(QSize(44, 44));
    ui->ButtonHav_6_4->setEnabled(false);

    game.PlayerTurn(6, 4, playerCurrent);
    if (game.VerifyRules(6, 4))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_6_5_clicked()
{
    int x, y;
    x = ui->ButtonHav_6_5->x();
    y = ui->ButtonHav_6_5->y();

    CurrentMove = std::make_pair(ui->ButtonHav_6_5->x(), ui->ButtonHav_6_5->y());
ROPMove=std::make_pair(6,5);
    ui->ButtonHav_6_5->setIcon(ChangeIcon());
    ui->ButtonHav_6_5->move(x - 9, y - 8);
    ui->ButtonHav_6_5->setFixedSize(44, 44);
    ui->ButtonHav_6_5->setIconSize(QSize(44, 44));
    ui->ButtonHav_6_5->setEnabled(false);

    game.PlayerTurn(6, 5, playerCurrent);
    if (game.VerifyRules(6, 5))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_6_6_clicked()
{
    int x, y;
    x = ui->ButtonHav_6_6->x();
    y = ui->ButtonHav_6_6->y();

    CurrentMove = std::make_pair(ui->ButtonHav_6_6->x(), ui->ButtonHav_6_6->y());
ROPMove=std::make_pair(6,6);
    ui->ButtonHav_6_6->setIcon(ChangeIcon());
    ui->ButtonHav_6_6->move(x - 9, y - 8);
    ui->ButtonHav_6_6->setFixedSize(44, 44);
    ui->ButtonHav_6_6->setIconSize(QSize(44, 44));
    ui->ButtonHav_6_6->setEnabled(false);

    game.PlayerTurn(6, 6, playerCurrent);
    if (game.VerifyRules(6, 6))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_6_7_clicked()
{
    int x, y;
    x = ui->ButtonHav_6_7->x();
    y = ui->ButtonHav_6_7->y();

    CurrentMove = std::make_pair(ui->ButtonHav_6_7->x(), ui->ButtonHav_6_7->y());
ROPMove=std::make_pair(6,7);
    ui->ButtonHav_6_7->setIcon(ChangeIcon());
    ui->ButtonHav_6_7->move(x - 9, y - 8);
    ui->ButtonHav_6_7->setFixedSize(44, 44);
    ui->ButtonHav_6_7->setIconSize(QSize(44, 44));
    ui->ButtonHav_6_7->setEnabled(false);

    game.PlayerTurn(6, 7, playerCurrent);
    if (game.VerifyRules(6, 7))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_6_8_clicked()
{
    int x, y;
    x = ui->ButtonHav_6_8->x();
    y = ui->ButtonHav_6_8->y();

    CurrentMove = std::make_pair(ui->ButtonHav_6_8->x(), ui->ButtonHav_6_8->y());
ROPMove=std::make_pair(6,8);
    ui->ButtonHav_6_8->setIcon(ChangeIcon());
    ui->ButtonHav_6_8->move(x - 9, y - 8);
    ui->ButtonHav_6_8->setFixedSize(44, 44);
    ui->ButtonHav_6_8->setIconSize(QSize(44, 44));
    ui->ButtonHav_6_8->setEnabled(false);

    game.PlayerTurn(6, 8, playerCurrent);
    if (game.VerifyRules(6, 8))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_6_9_clicked()
{
    int x, y;
    x = ui->ButtonHav_6_9->x();
    y = ui->ButtonHav_6_9->y();

    CurrentMove = std::make_pair(ui->ButtonHav_6_9->x(), ui->ButtonHav_6_9->y());
ROPMove=std::make_pair(6,9);
    ui->ButtonHav_6_9->setIcon(ChangeIcon());
    ui->ButtonHav_6_9->move(x - 9, y - 8);
    ui->ButtonHav_6_9->setFixedSize(44, 44);
    ui->ButtonHav_6_9->setIconSize(QSize(44, 44));
    ui->ButtonHav_6_9->setEnabled(false);

    game.PlayerTurn(6, 9, playerCurrent);
    if (game.VerifyRules(6, 9))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_6_10_clicked()
{
    int x, y;
    x = ui->ButtonHav_6_10->x();
    y = ui->ButtonHav_6_10->y();

    CurrentMove = std::make_pair(ui->ButtonHav_6_10->x(), ui->ButtonHav_6_10->y());
ROPMove=std::make_pair(6,10);
    ui->ButtonHav_6_10->setIcon(ChangeIcon());
    ui->ButtonHav_6_10->move(x - 9, y - 8);
    ui->ButtonHav_6_10->setFixedSize(44, 44);
    ui->ButtonHav_6_10->setIconSize(QSize(44, 44));
    ui->ButtonHav_6_10->setEnabled(false);

    game.PlayerTurn(6, 10, playerCurrent);
    if (game.VerifyRules(6, 10))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_6_11_clicked()
{
    int x, y;
    x = ui->ButtonHav_6_11->x();
    y = ui->ButtonHav_6_11->y();

    CurrentMove = std::make_pair(ui->ButtonHav_6_11->x(), ui->ButtonHav_6_11->y());
ROPMove=std::make_pair(6,11);
    ui->ButtonHav_6_11->setIcon(ChangeIcon());
    ui->ButtonHav_6_11->move(x - 9, y - 8);
    ui->ButtonHav_6_11->setFixedSize(44, 44);
    ui->ButtonHav_6_11->setIconSize(QSize(44, 44));
    ui->ButtonHav_6_11->setEnabled(false);

    game.PlayerTurn(6, 11, playerCurrent);
    if (game.VerifyRules(6, 11))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_6_12_clicked()
{
    int x, y;
    x = ui->ButtonHav_6_12->x();
    y = ui->ButtonHav_6_12->y();

    CurrentMove = std::make_pair(ui->ButtonHav_6_12->x(), ui->ButtonHav_6_12->y());
ROPMove=std::make_pair(6,12);
    ui->ButtonHav_6_12->setIcon(ChangeIcon());
    ui->ButtonHav_6_12->move(x - 9, y - 8);
    ui->ButtonHav_6_12->setFixedSize(44, 44);
    ui->ButtonHav_6_12->setIconSize(QSize(44, 44));
    ui->ButtonHav_6_12->setEnabled(false);

    game.PlayerTurn(6, 12, playerCurrent);
    if (game.VerifyRules(6, 12))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_6_13_clicked()
{
    int x, y;
    x = ui->ButtonHav_6_13->x();
    y = ui->ButtonHav_6_13->y();

    CurrentMove = std::make_pair(ui->ButtonHav_6_13->x(), ui->ButtonHav_6_13->y());
ROPMove=std::make_pair(6,13);
    ui->ButtonHav_6_13->setIcon(ChangeIcon());
    ui->ButtonHav_6_13->move(x - 9, y - 8);
    ui->ButtonHav_6_13->setFixedSize(44, 44);
    ui->ButtonHav_6_13->setIconSize(QSize(44, 44));
    ui->ButtonHav_6_13->setEnabled(false);

    game.PlayerTurn(6, 13, playerCurrent);
    if (game.VerifyRules(6, 13))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_6_14_clicked()
{
    int x, y;
    x = ui->ButtonHav_6_14->x();
    y = ui->ButtonHav_6_14->y();

    CurrentMove = std::make_pair(ui->ButtonHav_6_14->x(), ui->ButtonHav_6_14->y());
ROPMove=std::make_pair(6,14);
    ui->ButtonHav_6_14->setIcon(ChangeIcon());
    ui->ButtonHav_6_14->move(x - 9, y - 8);
    ui->ButtonHav_6_14->setFixedSize(44, 44);
    ui->ButtonHav_6_14->setIconSize(QSize(44, 44));
    ui->ButtonHav_6_14->setEnabled(false);

    game.PlayerTurn(6, 14, playerCurrent);
    if (game.VerifyRules(6, 14))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_6_15_clicked()
{
    int x, y;
    x = ui->ButtonHav_6_15->x();
    y = ui->ButtonHav_6_15->y();

    CurrentMove = std::make_pair(ui->ButtonHav_6_15->x(), ui->ButtonHav_6_15->y());
ROPMove=std::make_pair(6,15);
    ui->ButtonHav_6_15->setIcon(ChangeIcon());
    ui->ButtonHav_6_15->move(x - 9, y - 8);
    ui->ButtonHav_6_15->setFixedSize(44, 44);
    ui->ButtonHav_6_15->setIconSize(QSize(44, 44));
    ui->ButtonHav_6_15->setEnabled(false);

    game.PlayerTurn(6, 15, playerCurrent);
    if (game.VerifyRules(6, 15))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}


void HavannahUI::on_ButtonHav_7_0_clicked()
{
    int x, y;
    x = ui->ButtonHav_7_0->x();
    y = ui->ButtonHav_7_0->y();

    CurrentMove = std::make_pair(ui->ButtonHav_7_0->x(), ui->ButtonHav_7_0->y());
ROPMove=std::make_pair(7,0);
    ui->ButtonHav_7_0->setIcon(ChangeIcon());
    ui->ButtonHav_7_0->move(x - 9, y - 8);
    ui->ButtonHav_7_0->setFixedSize(44, 44);
    ui->ButtonHav_7_0->setIconSize(QSize(44, 44));
    ui->ButtonHav_7_0->setEnabled(false);

    game.PlayerTurn(7, 0, playerCurrent);
    if (game.VerifyRules(7, 0))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_7_1_clicked()
{
    int x, y;
    x = ui->ButtonHav_7_1->x();
    y = ui->ButtonHav_7_1->y();

    CurrentMove = std::make_pair(ui->ButtonHav_7_1->x(), ui->ButtonHav_7_1->y());
ROPMove=std::make_pair(7,1);
    ui->ButtonHav_7_1->setIcon(ChangeIcon());
    ui->ButtonHav_7_1->move(x - 9, y - 8);
    ui->ButtonHav_7_1->setFixedSize(44, 44);
    ui->ButtonHav_7_1->setIconSize(QSize(44, 44));
    ui->ButtonHav_7_1->setEnabled(false);

    game.PlayerTurn(7, 1, playerCurrent);
    if (game.VerifyRules(7, 1))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_7_2_clicked()
{
    int x, y;
    x = ui->ButtonHav_7_2->x();
    y = ui->ButtonHav_7_2->y();

    CurrentMove = std::make_pair(ui->ButtonHav_7_2->x(), ui->ButtonHav_7_2->y());
ROPMove=std::make_pair(7,2);
    ui->ButtonHav_7_2->setIcon(ChangeIcon());
    ui->ButtonHav_7_2->move(x - 9, y - 8);
    ui->ButtonHav_7_2->setFixedSize(44, 44);
    ui->ButtonHav_7_2->setIconSize(QSize(44, 44));
    ui->ButtonHav_7_2->setEnabled(false);

    game.PlayerTurn(7, 2, playerCurrent);
    if (game.VerifyRules(7, 2))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_7_3_clicked()
{
    int x, y;
    x = ui->ButtonHav_7_3->x();
    y = ui->ButtonHav_7_3->y();

    CurrentMove = std::make_pair(ui->ButtonHav_7_3->x(), ui->ButtonHav_7_3->y());
ROPMove=std::make_pair(7,3);
    ui->ButtonHav_7_3->setIcon(ChangeIcon());
    ui->ButtonHav_7_3->move(x - 9, y - 8);
    ui->ButtonHav_7_3->setFixedSize(44, 44);
    ui->ButtonHav_7_3->setIconSize(QSize(44, 44));
    ui->ButtonHav_7_3->setEnabled(false);

    game.PlayerTurn(7, 3, playerCurrent);
    if (game.VerifyRules(7, 3))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_7_4_clicked()
{
    int x, y;
    x = ui->ButtonHav_7_4->x();
    y = ui->ButtonHav_7_4->y();

    CurrentMove = std::make_pair(ui->ButtonHav_7_4->x(), ui->ButtonHav_7_4->y());
ROPMove=std::make_pair(7,4);
    ui->ButtonHav_7_4->setIcon(ChangeIcon());
    ui->ButtonHav_7_4->move(x - 9, y - 8);
    ui->ButtonHav_7_4->setFixedSize(44, 44);
    ui->ButtonHav_7_4->setIconSize(QSize(44, 44));
    ui->ButtonHav_7_4->setEnabled(false);

    game.PlayerTurn(7, 4, playerCurrent);
    if (game.VerifyRules(7, 4))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_7_5_clicked()
{
    int x, y;
    x = ui->ButtonHav_7_5->x();
    y = ui->ButtonHav_7_5->y();

    CurrentMove = std::make_pair(ui->ButtonHav_7_5->x(), ui->ButtonHav_7_5->y());
ROPMove=std::make_pair(7,5);
    ui->ButtonHav_7_5->setIcon(ChangeIcon());
    ui->ButtonHav_7_5->move(x - 9, y - 8);
    ui->ButtonHav_7_5->setFixedSize(44, 44);
    ui->ButtonHav_7_5->setIconSize(QSize(44, 44));
    ui->ButtonHav_7_5->setEnabled(false);

    game.PlayerTurn(7, 5, playerCurrent);
    if (game.VerifyRules(7, 5))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_7_6_clicked()
{
    int x, y;
    x = ui->ButtonHav_7_6->x();
    y = ui->ButtonHav_7_6->y();

    CurrentMove = std::make_pair(ui->ButtonHav_7_6->x(), ui->ButtonHav_7_6->y());
ROPMove=std::make_pair(7,6);
    ui->ButtonHav_7_6->setIcon(ChangeIcon());
    ui->ButtonHav_7_6->move(x - 9, y - 8);
    ui->ButtonHav_7_6->setFixedSize(44, 44);
    ui->ButtonHav_7_6->setIconSize(QSize(44, 44));
    ui->ButtonHav_7_6->setEnabled(false);

    game.PlayerTurn(7, 6, playerCurrent);
    if (game.VerifyRules(7, 6))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_7_7_clicked()
{
    int x, y;
    x = ui->ButtonHav_7_7->x();
    y = ui->ButtonHav_7_7->y();

    CurrentMove = std::make_pair(ui->ButtonHav_7_7->x(), ui->ButtonHav_7_7->y());
ROPMove=std::make_pair(7,7);
    ui->ButtonHav_7_7->setIcon(ChangeIcon());
    ui->ButtonHav_7_7->move(x - 9, y - 8);
    ui->ButtonHav_7_7->setFixedSize(44, 44);
    ui->ButtonHav_7_7->setIconSize(QSize(44, 44));
    ui->ButtonHav_7_7->setEnabled(false);

    game.PlayerTurn(7, 7, playerCurrent);
    if (game.VerifyRules(7, 7))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_7_8_clicked()
{
    int x, y;
    x = ui->ButtonHav_7_8->x();
    y = ui->ButtonHav_7_8->y();

    CurrentMove = std::make_pair(ui->ButtonHav_7_8->x(), ui->ButtonHav_7_8->y());
ROPMove=std::make_pair(7,8);
    ui->ButtonHav_7_8->setIcon(ChangeIcon());
    ui->ButtonHav_7_8->move(x - 9, y - 8);
    ui->ButtonHav_7_8->setFixedSize(44, 44);
    ui->ButtonHav_7_8->setIconSize(QSize(44, 44));
    ui->ButtonHav_7_8->setEnabled(false);

    game.PlayerTurn(7, 8, playerCurrent);
    if (game.VerifyRules(7, 8))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_7_9_clicked()
{
    int x, y;
    x = ui->ButtonHav_7_9->x();
    y = ui->ButtonHav_7_9->y();

    CurrentMove = std::make_pair(ui->ButtonHav_7_9->x(), ui->ButtonHav_7_9->y());
ROPMove=std::make_pair(7,9);
    ui->ButtonHav_7_9->setIcon(ChangeIcon());
    ui->ButtonHav_7_9->move(x - 9, y - 8);
    ui->ButtonHav_7_9->setFixedSize(44, 44);
    ui->ButtonHav_7_9->setIconSize(QSize(44, 44));
    ui->ButtonHav_7_9->setEnabled(false);

    game.PlayerTurn(7, 9, playerCurrent);
    if (game.VerifyRules(7, 9))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_7_10_clicked()
{
    int x, y;
    x = ui->ButtonHav_7_10->x();
    y = ui->ButtonHav_7_10->y();

    CurrentMove = std::make_pair(ui->ButtonHav_7_10->x(), ui->ButtonHav_7_10->y());
ROPMove=std::make_pair(7,10);
    ui->ButtonHav_7_10->setIcon(ChangeIcon());
    ui->ButtonHav_7_10->move(x - 9, y - 8);
    ui->ButtonHav_7_10->setFixedSize(44, 44);
    ui->ButtonHav_7_10->setIconSize(QSize(44, 44));
    ui->ButtonHav_7_10->setEnabled(false);

    game.PlayerTurn(7, 10, playerCurrent);
    if (game.VerifyRules(7, 10))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_7_11_clicked()
{
    int x, y;
    x = ui->ButtonHav_7_11->x();
    y = ui->ButtonHav_7_11->y();

    CurrentMove = std::make_pair(ui->ButtonHav_7_11->x(), ui->ButtonHav_7_11->y());
ROPMove=std::make_pair(7,11);
    ui->ButtonHav_7_11->setIcon(ChangeIcon());
    ui->ButtonHav_7_11->move(x - 9, y - 8);
    ui->ButtonHav_7_11->setFixedSize(44, 44);
    ui->ButtonHav_7_11->setIconSize(QSize(44, 44));
    ui->ButtonHav_7_11->setEnabled(false);

    game.PlayerTurn(7, 11, playerCurrent);
    if (game.VerifyRules(7, 11))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_7_12_clicked()
{
    int x, y;
    x = ui->ButtonHav_7_12->x();
    y = ui->ButtonHav_7_12->y();

    CurrentMove = std::make_pair(ui->ButtonHav_7_12->x(), ui->ButtonHav_7_12->y());
ROPMove=std::make_pair(7,12);
    ui->ButtonHav_7_12->setIcon(ChangeIcon());
    ui->ButtonHav_7_12->move(x - 9, y - 8);
    ui->ButtonHav_7_12->setFixedSize(44, 44);
    ui->ButtonHav_7_12->setIconSize(QSize(44, 44));
    ui->ButtonHav_7_12->setEnabled(false);

    game.PlayerTurn(7, 12, playerCurrent);
    if (game.VerifyRules(7, 12))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_7_13_clicked()
{
    int x, y;
    x = ui->ButtonHav_7_13->x();
    y = ui->ButtonHav_7_13->y();

    CurrentMove = std::make_pair(ui->ButtonHav_7_13->x(), ui->ButtonHav_7_13->y());
ROPMove=std::make_pair(7,13);
    ui->ButtonHav_7_13->setIcon(ChangeIcon());
    ui->ButtonHav_7_13->move(x - 9, y - 8);
    ui->ButtonHav_7_13->setFixedSize(44, 44);
    ui->ButtonHav_7_13->setIconSize(QSize(44, 44));
    ui->ButtonHav_7_13->setEnabled(false);

    game.PlayerTurn(7, 13, playerCurrent);
    if (game.VerifyRules(7, 13))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_7_14_clicked()
{
    int x, y;
    x = ui->ButtonHav_7_14->x();
    y = ui->ButtonHav_7_14->y();

    CurrentMove = std::make_pair(ui->ButtonHav_7_14->x(), ui->ButtonHav_7_14->y());
ROPMove=std::make_pair(7,14);
    ui->ButtonHav_7_14->setIcon(ChangeIcon());
    ui->ButtonHav_7_14->move(x - 9, y - 8);
    ui->ButtonHav_7_14->setFixedSize(44, 44);
    ui->ButtonHav_7_14->setIconSize(QSize(44, 44));
    ui->ButtonHav_7_14->setEnabled(false);

    game.PlayerTurn(7, 14, playerCurrent);
    if (game.VerifyRules(7, 14))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_7_15_clicked()
{
    int x, y;
    x = ui->ButtonHav_7_15->x();
    y = ui->ButtonHav_7_15->y();

    CurrentMove = std::make_pair(ui->ButtonHav_7_15->x(), ui->ButtonHav_7_15->y());
ROPMove=std::make_pair(7,15);
    ui->ButtonHav_7_15->setIcon(ChangeIcon());
    ui->ButtonHav_7_15->move(x - 9, y - 8);
    ui->ButtonHav_7_15->setFixedSize(44, 44);
    ui->ButtonHav_7_15->setIconSize(QSize(44, 44));
    ui->ButtonHav_7_15->setEnabled(false);

    game.PlayerTurn(7, 15, playerCurrent);
    if (game.VerifyRules(7, 15))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_7_16_clicked()
{
    int x, y;
    x = ui->ButtonHav_7_16->x();
    y = ui->ButtonHav_7_16->y();

    CurrentMove = std::make_pair(ui->ButtonHav_7_16->x(), ui->ButtonHav_7_16->y());
ROPMove=std::make_pair(7,16);
    ui->ButtonHav_7_16->setIcon(ChangeIcon());
    ui->ButtonHav_7_16->move(x - 9, y - 8);
    ui->ButtonHav_7_16->setFixedSize(44, 44);
    ui->ButtonHav_7_16->setIconSize(QSize(44, 44));
    ui->ButtonHav_7_16->setEnabled(false);

    game.PlayerTurn(7, 16, playerCurrent);
    if (game.VerifyRules(7, 16))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_8_0_clicked()
{
    int x, y;
    x = ui->ButtonHav_8_0->x();
    y = ui->ButtonHav_8_0->y();

    CurrentMove = std::make_pair(ui->ButtonHav_8_0->x(), ui->ButtonHav_8_0->y());
ROPMove=std::make_pair(8,0);
    ui->ButtonHav_8_0->setIcon(ChangeIcon());
    ui->ButtonHav_8_0->move(x - 9, y - 8);
    ui->ButtonHav_8_0->setFixedSize(44, 44);
    ui->ButtonHav_8_0->setIconSize(QSize(44, 44));
    ui->ButtonHav_8_0->setEnabled(false);

    game.PlayerTurn(8, 0, playerCurrent);
    if (game.VerifyRules(8, 0))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_8_1_clicked()
{
    int x, y;
    x = ui->ButtonHav_8_1->x();
    y = ui->ButtonHav_8_1->y();

    CurrentMove = std::make_pair(ui->ButtonHav_8_1->x(), ui->ButtonHav_8_1->y());
ROPMove=std::make_pair(8,1);
    ui->ButtonHav_8_1->setIcon(ChangeIcon());
    ui->ButtonHav_8_1->move(x - 9, y - 8);
    ui->ButtonHav_8_1->setFixedSize(44, 44);
    ui->ButtonHav_8_1->setIconSize(QSize(44, 44));
    ui->ButtonHav_8_1->setEnabled(false);

    game.PlayerTurn(8, 1, playerCurrent);
    if (game.VerifyRules(8, 1))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_8_2_clicked()
{
    int x, y;
    x = ui->ButtonHav_8_2->x();
    y = ui->ButtonHav_8_2->y();

    CurrentMove = std::make_pair(ui->ButtonHav_8_2->x(), ui->ButtonHav_8_2->y());
ROPMove=std::make_pair(8,2);
    ui->ButtonHav_8_2->setIcon(ChangeIcon());
    ui->ButtonHav_8_2->move(x - 9, y - 8);
    ui->ButtonHav_8_2->setFixedSize(44, 44);
    ui->ButtonHav_8_2->setIconSize(QSize(44, 44));
    ui->ButtonHav_8_2->setEnabled(false);

    game.PlayerTurn(8, 2, playerCurrent);
    if (game.VerifyRules(8, 2))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_8_3_clicked()
{
    int x, y;
    x = ui->ButtonHav_8_3->x();
    y = ui->ButtonHav_8_3->y();

    CurrentMove = std::make_pair(ui->ButtonHav_8_3->x(), ui->ButtonHav_8_3->y());
ROPMove=std::make_pair(8,3);
    ui->ButtonHav_8_3->setIcon(ChangeIcon());
    ui->ButtonHav_8_3->move(x - 9, y - 8);
    ui->ButtonHav_8_3->setFixedSize(44, 44);
    ui->ButtonHav_8_3->setIconSize(QSize(44, 44));
    ui->ButtonHav_8_3->setEnabled(false);

    game.PlayerTurn(8, 3, playerCurrent);
    if (game.VerifyRules(8, 3))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_8_4_clicked()
{
    int x, y;
    x = ui->ButtonHav_8_4->x();
    y = ui->ButtonHav_8_4->y();

    CurrentMove = std::make_pair(ui->ButtonHav_8_4->x(), ui->ButtonHav_8_4->y());
ROPMove=std::make_pair(8,4);
    ui->ButtonHav_8_4->setIcon(ChangeIcon());
    ui->ButtonHav_8_4->move(x - 9, y - 8);
    ui->ButtonHav_8_4->setFixedSize(44, 44);
    ui->ButtonHav_8_4->setIconSize(QSize(44, 44));
    ui->ButtonHav_8_4->setEnabled(false);

    game.PlayerTurn(8, 4, playerCurrent);
    if (game.VerifyRules(8, 4))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_8_5_clicked()
{
    int x, y;
    x = ui->ButtonHav_8_5->x();
    y = ui->ButtonHav_8_5->y();

    CurrentMove = std::make_pair(ui->ButtonHav_8_5->x(), ui->ButtonHav_8_5->y());
ROPMove=std::make_pair(8,5);
    ui->ButtonHav_8_5->setIcon(ChangeIcon());
    ui->ButtonHav_8_5->move(x - 9, y - 8);
    ui->ButtonHav_8_5->setFixedSize(44, 44);
    ui->ButtonHav_8_5->setIconSize(QSize(44, 44));
    ui->ButtonHav_8_5->setEnabled(false);

    game.PlayerTurn(8, 5, playerCurrent);
    if (game.VerifyRules(8, 5))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_8_6_clicked()
{
    int x, y;
    x = ui->ButtonHav_8_6->x();
    y = ui->ButtonHav_8_6->y();

    CurrentMove = std::make_pair(ui->ButtonHav_8_6->x(), ui->ButtonHav_8_6->y());
ROPMove=std::make_pair(8,6);
    ui->ButtonHav_8_6->setIcon(ChangeIcon());
    ui->ButtonHav_8_6->move(x - 9, y - 8);
    ui->ButtonHav_8_6->setFixedSize(44, 44);
    ui->ButtonHav_8_6->setIconSize(QSize(44, 44));
    ui->ButtonHav_8_6->setEnabled(false);

    game.PlayerTurn(8, 6, playerCurrent);
    if (game.VerifyRules(8, 6))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_8_7_clicked()
{
    int x, y;
    x = ui->ButtonHav_8_7->x();
    y = ui->ButtonHav_8_7->y();

    CurrentMove = std::make_pair(ui->ButtonHav_8_7->x(), ui->ButtonHav_8_7->y());
ROPMove=std::make_pair(8,7);
    ui->ButtonHav_8_7->setIcon(ChangeIcon());
    ui->ButtonHav_8_7->move(x - 9, y - 8);
    ui->ButtonHav_8_7->setFixedSize(44, 44);
    ui->ButtonHav_8_7->setIconSize(QSize(44, 44));
    ui->ButtonHav_8_7->setEnabled(false);

    game.PlayerTurn(8, 7, playerCurrent);
    if (game.VerifyRules(8, 7))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_8_8_clicked()
{
    int x, y;
    x = ui->ButtonHav_8_8->x();
    y = ui->ButtonHav_8_8->y();

    CurrentMove = std::make_pair(ui->ButtonHav_8_8->x(), ui->ButtonHav_8_8->y());
ROPMove=std::make_pair(8,8);
    ui->ButtonHav_8_8->setIcon(ChangeIcon());
    ui->ButtonHav_8_8->move(x - 9, y - 8);
    ui->ButtonHav_8_8->setFixedSize(44, 44);
    ui->ButtonHav_8_8->setIconSize(QSize(44, 44));
    ui->ButtonHav_8_8->setEnabled(false);

    game.PlayerTurn(8, 8, playerCurrent);
    if (game.VerifyRules(8, 8))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_8_9_clicked()
{
    int x, y;
    x = ui->ButtonHav_8_9->x();
    y = ui->ButtonHav_8_9->y();

    CurrentMove = std::make_pair(ui->ButtonHav_8_9->x(), ui->ButtonHav_8_9->y());
ROPMove=std::make_pair(8,9);
    ui->ButtonHav_8_9->setIcon(ChangeIcon());
    ui->ButtonHav_8_9->move(x - 9, y - 8);
    ui->ButtonHav_8_9->setFixedSize(44, 44);
    ui->ButtonHav_8_9->setIconSize(QSize(44, 44));
    ui->ButtonHav_8_9->setEnabled(false);

    game.PlayerTurn(8, 9, playerCurrent);
    if (game.VerifyRules(8, 9))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_8_10_clicked()
{
    int x, y;
    x = ui->ButtonHav_8_10->x();
    y = ui->ButtonHav_8_10->y();

    CurrentMove = std::make_pair(ui->ButtonHav_8_10->x(), ui->ButtonHav_8_10->y());
ROPMove=std::make_pair(8,10);
    ui->ButtonHav_8_10->setIcon(ChangeIcon());
    ui->ButtonHav_8_10->move(x - 9, y - 8);
    ui->ButtonHav_8_10->setFixedSize(44, 44);
    ui->ButtonHav_8_10->setIconSize(QSize(44, 44));
    ui->ButtonHav_8_10->setEnabled(false);

    game.PlayerTurn(8, 10, playerCurrent);
    if (game.VerifyRules(8, 10))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_8_11_clicked()
{
    int x, y;
    x = ui->ButtonHav_8_11->x();
    y = ui->ButtonHav_8_11->y();

    CurrentMove = std::make_pair(ui->ButtonHav_8_11->x(), ui->ButtonHav_8_11->y());
ROPMove=std::make_pair(8,11);
    ui->ButtonHav_8_11->setIcon(ChangeIcon());
    ui->ButtonHav_8_11->move(x - 9, y - 8);
    ui->ButtonHav_8_11->setFixedSize(44, 44);
    ui->ButtonHav_8_11->setIconSize(QSize(44, 44));
    ui->ButtonHav_8_11->setEnabled(false);

    game.PlayerTurn(8, 11, playerCurrent);
    if (game.VerifyRules(8, 11))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_8_12_clicked()
{
    int x, y;
    x = ui->ButtonHav_8_12->x();
    y = ui->ButtonHav_8_12->y();

    CurrentMove = std::make_pair(ui->ButtonHav_8_12->x(), ui->ButtonHav_8_12->y());
ROPMove=std::make_pair(8,12);
    ui->ButtonHav_8_12->setIcon(ChangeIcon());
    ui->ButtonHav_8_12->move(x - 9, y - 8);
    ui->ButtonHav_8_12->setFixedSize(44, 44);
    ui->ButtonHav_8_12->setIconSize(QSize(44, 44));
    ui->ButtonHav_8_12->setEnabled(false);

    game.PlayerTurn(8, 12, playerCurrent);
    if (game.VerifyRules(8, 12))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_8_13_clicked()
{
    int x, y;
    x = ui->ButtonHav_8_13->x();
    y = ui->ButtonHav_8_13->y();

    CurrentMove = std::make_pair(ui->ButtonHav_8_13->x(), ui->ButtonHav_8_13->y());
ROPMove=std::make_pair(8,13);
    ui->ButtonHav_8_13->setIcon(ChangeIcon());
    ui->ButtonHav_8_13->move(x - 9, y - 8);
    ui->ButtonHav_8_13->setFixedSize(44, 44);
    ui->ButtonHav_8_13->setIconSize(QSize(44, 44));
    ui->ButtonHav_8_13->setEnabled(false);

    game.PlayerTurn(8, 13, playerCurrent);
    if (game.VerifyRules(8, 13))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_8_14_clicked()
{
    int x, y;
    x = ui->ButtonHav_8_14->x();
    y = ui->ButtonHav_8_14->y();

    CurrentMove = std::make_pair(ui->ButtonHav_8_14->x(), ui->ButtonHav_8_14->y());
ROPMove=std::make_pair(8,14);
    ui->ButtonHav_8_14->setIcon(ChangeIcon());
    ui->ButtonHav_8_14->move(x - 9, y - 8);
    ui->ButtonHav_8_14->setFixedSize(44, 44);
    ui->ButtonHav_8_14->setIconSize(QSize(44, 44));
    ui->ButtonHav_8_14->setEnabled(false);

    game.PlayerTurn(8, 14, playerCurrent);
    if (game.VerifyRules(8, 14))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_8_15_clicked()
{
    int x, y;
    x = ui->ButtonHav_8_15->x();
    y = ui->ButtonHav_8_15->y();

    CurrentMove = std::make_pair(ui->ButtonHav_8_15->x(), ui->ButtonHav_8_15->y());
ROPMove=std::make_pair(8,15);
    ui->ButtonHav_8_15->setIcon(ChangeIcon());
    ui->ButtonHav_8_15->move(x - 9, y - 8);
    ui->ButtonHav_8_15->setFixedSize(44, 44);
    ui->ButtonHav_8_15->setIconSize(QSize(44, 44));
    ui->ButtonHav_8_15->setEnabled(false);

    game.PlayerTurn(8, 15, playerCurrent);
    if (game.VerifyRules(8, 15))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_8_16_clicked()
{
    int x, y;
    x = ui->ButtonHav_8_16->x();
    y = ui->ButtonHav_8_16->y();

    CurrentMove = std::make_pair(ui->ButtonHav_8_16->x(), ui->ButtonHav_8_16->y());
ROPMove=std::make_pair(8,16);
    ui->ButtonHav_8_16->setIcon(ChangeIcon());
    ui->ButtonHav_8_16->move(x - 9, y - 8);
    ui->ButtonHav_8_16->setFixedSize(44, 44);
    ui->ButtonHav_8_16->setIconSize(QSize(44, 44));
    ui->ButtonHav_8_16->setEnabled(false);

    game.PlayerTurn(8, 16, playerCurrent);
    if (game.VerifyRules(8, 16))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_8_17_clicked()
{
    int x, y;
    x = ui->ButtonHav_8_17->x();
    y = ui->ButtonHav_8_17->y();

    CurrentMove = std::make_pair(ui->ButtonHav_8_17->x(), ui->ButtonHav_8_17->y());
ROPMove=std::make_pair(8,17);
    ui->ButtonHav_8_17->setIcon(ChangeIcon());
    ui->ButtonHav_8_17->move(x - 9, y - 8);
    ui->ButtonHav_8_17->setFixedSize(44, 44);
    ui->ButtonHav_8_17->setIconSize(QSize(44, 44));
    ui->ButtonHav_8_17->setEnabled(false);

    game.PlayerTurn(8, 17, playerCurrent);
    if (game.VerifyRules(8, 17))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_9_0_clicked()
{
    int x, y;
    x = ui->ButtonHav_9_0->x();
    y = ui->ButtonHav_9_0->y();

    CurrentMove = std::make_pair(ui->ButtonHav_9_0->x(), ui->ButtonHav_9_0->y());
ROPMove=std::make_pair(9,0);
    ui->ButtonHav_9_0->setIcon(ChangeIcon());
    ui->ButtonHav_9_0->move(x - 9, y - 8);
    ui->ButtonHav_9_0->setFixedSize(44, 44);
    ui->ButtonHav_9_0->setIconSize(QSize(44, 44));
    ui->ButtonHav_9_0->setEnabled(false);

    game.PlayerTurn(9, 0, playerCurrent);
    if (game.VerifyRules(9, 0))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_9_1_clicked()
{
    int x, y;
    x = ui->ButtonHav_9_1->x();
    y = ui->ButtonHav_9_1->y();

    CurrentMove = std::make_pair(ui->ButtonHav_9_1->x(), ui->ButtonHav_9_1->y());
ROPMove=std::make_pair(9,1);
    ui->ButtonHav_9_1->setIcon(ChangeIcon());
    ui->ButtonHav_9_1->move(x - 9, y - 8);
    ui->ButtonHav_9_1->setFixedSize(44, 44);
    ui->ButtonHav_9_1->setIconSize(QSize(44, 44));
    ui->ButtonHav_9_1->setEnabled(false);

    game.PlayerTurn(9, 1, playerCurrent);
    if (game.VerifyRules(9, 1))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_9_2_clicked()
{
    int x, y;
    x = ui->ButtonHav_9_2->x();
    y = ui->ButtonHav_9_2->y();

    CurrentMove = std::make_pair(ui->ButtonHav_9_2->x(), ui->ButtonHav_9_2->y());
ROPMove=std::make_pair(9,2);
    ui->ButtonHav_9_2->setIcon(ChangeIcon());
    ui->ButtonHav_9_2->move(x - 9, y - 8);
    ui->ButtonHav_9_2->setFixedSize(44, 44);
    ui->ButtonHav_9_2->setIconSize(QSize(44, 44));
    ui->ButtonHav_9_2->setEnabled(false);

    game.PlayerTurn(9, 2, playerCurrent);
    if (game.VerifyRules(9, 2))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_9_3_clicked()
{
    int x, y;
    x = ui->ButtonHav_9_3->x();
    y = ui->ButtonHav_9_3->y();

    CurrentMove = std::make_pair(ui->ButtonHav_9_3->x(), ui->ButtonHav_9_3->y());
ROPMove=std::make_pair(9,3);
    ui->ButtonHav_9_3->setIcon(ChangeIcon());
    ui->ButtonHav_9_3->move(x - 9, y - 8);
    ui->ButtonHav_9_3->setFixedSize(44, 44);
    ui->ButtonHav_9_3->setIconSize(QSize(44, 44));
    ui->ButtonHav_9_3->setEnabled(false);

    game.PlayerTurn(9, 3, playerCurrent);
    if (game.VerifyRules(9, 3))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_9_4_clicked()
{
    int x, y;
    x = ui->ButtonHav_9_4->x();
    y = ui->ButtonHav_9_4->y();

    CurrentMove = std::make_pair(ui->ButtonHav_9_4->x(), ui->ButtonHav_9_4->y());
ROPMove=std::make_pair(9,4);
    ui->ButtonHav_9_4->setIcon(ChangeIcon());
    ui->ButtonHav_9_4->move(x - 9, y - 8);
    ui->ButtonHav_9_4->setFixedSize(44, 44);
    ui->ButtonHav_9_4->setIconSize(QSize(44, 44));
    ui->ButtonHav_9_4->setEnabled(false);

    game.PlayerTurn(9, 4, playerCurrent);
    if (game.VerifyRules(9, 4))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_9_5_clicked()
{
    int x, y;
    x = ui->ButtonHav_9_5->x();
    y = ui->ButtonHav_9_5->y();

    CurrentMove = std::make_pair(ui->ButtonHav_9_5->x(), ui->ButtonHav_9_5->y());
ROPMove=std::make_pair(9,5);
    ui->ButtonHav_9_5->setIcon(ChangeIcon());
    ui->ButtonHav_9_5->move(x - 9, y - 8);
    ui->ButtonHav_9_5->setFixedSize(44, 44);
    ui->ButtonHav_9_5->setIconSize(QSize(44, 44));
    ui->ButtonHav_9_5->setEnabled(false);

    game.PlayerTurn(9, 5, playerCurrent);
    if (game.VerifyRules(9, 5))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_9_6_clicked()
{
    int x, y;
    x = ui->ButtonHav_9_6->x();
    y = ui->ButtonHav_9_6->y();

    CurrentMove = std::make_pair(ui->ButtonHav_9_6->x(), ui->ButtonHav_9_6->y());
ROPMove=std::make_pair(9,6);
    ui->ButtonHav_9_6->setIcon(ChangeIcon());
    ui->ButtonHav_9_6->move(x - 9, y - 8);
    ui->ButtonHav_9_6->setFixedSize(44, 44);
    ui->ButtonHav_9_6->setIconSize(QSize(44, 44));
    ui->ButtonHav_9_6->setEnabled(false);

    game.PlayerTurn(9, 6, playerCurrent);
    if (game.VerifyRules(9, 6))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_9_7_clicked()
{
    int x, y;
    x = ui->ButtonHav_9_7->x();
    y = ui->ButtonHav_9_7->y();

    CurrentMove = std::make_pair(ui->ButtonHav_9_7->x(), ui->ButtonHav_9_7->y());
ROPMove=std::make_pair(9,7);
    ui->ButtonHav_9_7->setIcon(ChangeIcon());
    ui->ButtonHav_9_7->move(x - 9, y - 8);
    ui->ButtonHav_9_7->setFixedSize(44, 44);
    ui->ButtonHav_9_7->setIconSize(QSize(44, 44));
    ui->ButtonHav_9_7->setEnabled(false);

    game.PlayerTurn(9, 7, playerCurrent);
    if (game.VerifyRules(9, 7))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_9_8_clicked()
{
    int x, y;
    x = ui->ButtonHav_9_8->x();
    y = ui->ButtonHav_9_8->y();

    CurrentMove = std::make_pair(ui->ButtonHav_9_8->x(), ui->ButtonHav_9_8->y());
ROPMove=std::make_pair(9,8);
    ui->ButtonHav_9_8->setIcon(ChangeIcon());
    ui->ButtonHav_9_8->move(x - 9, y - 8);
    ui->ButtonHav_9_8->setFixedSize(44, 44);
    ui->ButtonHav_9_8->setIconSize(QSize(44, 44));
    ui->ButtonHav_9_8->setEnabled(false);

    game.PlayerTurn(9, 8, playerCurrent);
    if (game.VerifyRules(9, 8))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_9_9_clicked()
{
    int x, y;
    x = ui->ButtonHav_9_9->x();
    y = ui->ButtonHav_9_9->y();

    CurrentMove = std::make_pair(ui->ButtonHav_9_9->x(), ui->ButtonHav_9_9->y());
ROPMove=std::make_pair(9,9);
    ui->ButtonHav_9_9->setIcon(ChangeIcon());
    ui->ButtonHav_9_9->move(x - 9, y - 8);
    ui->ButtonHav_9_9->setFixedSize(44, 44);
    ui->ButtonHav_9_9->setIconSize(QSize(44, 44));
    ui->ButtonHav_9_9->setEnabled(false);

    game.PlayerTurn(9, 9, playerCurrent);
    if (game.VerifyRules(9, 9))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_9_10_clicked()
{
    int x, y;
    x = ui->ButtonHav_9_10->x();
    y = ui->ButtonHav_9_10->y();

    CurrentMove = std::make_pair(ui->ButtonHav_9_10->x(), ui->ButtonHav_9_10->y());
ROPMove=std::make_pair(9,10);
    ui->ButtonHav_9_10->setIcon(ChangeIcon());
    ui->ButtonHav_9_10->move(x - 9, y - 8);
    ui->ButtonHav_9_10->setFixedSize(44, 44);
    ui->ButtonHav_9_10->setIconSize(QSize(44, 44));
    ui->ButtonHav_9_10->setEnabled(false);

    game.PlayerTurn(9, 10, playerCurrent);
    if (game.VerifyRules(9, 10))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_9_11_clicked()
{
    int x, y;
    x = ui->ButtonHav_9_11->x();
    y = ui->ButtonHav_9_11->y();

    CurrentMove = std::make_pair(ui->ButtonHav_9_11->x(), ui->ButtonHav_9_11->y());
ROPMove=std::make_pair(9,11);
    ui->ButtonHav_9_11->setIcon(ChangeIcon());
    ui->ButtonHav_9_11->move(x - 9, y - 8);
    ui->ButtonHav_9_11->setFixedSize(44, 44);
    ui->ButtonHav_9_11->setIconSize(QSize(44, 44));
    ui->ButtonHav_9_11->setEnabled(false);

    game.PlayerTurn(9, 11, playerCurrent);
    if (game.VerifyRules(9, 11))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_9_12_clicked()
{
    int x, y;
    x = ui->ButtonHav_9_12->x();
    y = ui->ButtonHav_9_12->y();

    CurrentMove = std::make_pair(ui->ButtonHav_9_12->x(), ui->ButtonHav_9_12->y());
ROPMove=std::make_pair(9,12);
    ui->ButtonHav_9_12->setIcon(ChangeIcon());
    ui->ButtonHav_9_12->move(x - 9, y - 8);
    ui->ButtonHav_9_12->setFixedSize(44, 44);
    ui->ButtonHav_9_12->setIconSize(QSize(44, 44));
    ui->ButtonHav_9_12->setEnabled(false);

    game.PlayerTurn(9, 12, playerCurrent);
    if (game.VerifyRules(9, 12))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_9_13_clicked()
{
    int x, y;
    x = ui->ButtonHav_9_13->x();
    y = ui->ButtonHav_9_13->y();

    CurrentMove = std::make_pair(ui->ButtonHav_9_13->x(), ui->ButtonHav_9_13->y());
ROPMove=std::make_pair(9,13);
    ui->ButtonHav_9_13->setIcon(ChangeIcon());
    ui->ButtonHav_9_13->move(x - 9, y - 8);
    ui->ButtonHav_9_13->setFixedSize(44, 44);
    ui->ButtonHav_9_13->setIconSize(QSize(44, 44));
    ui->ButtonHav_9_13->setEnabled(false);

    game.PlayerTurn(9, 13, playerCurrent);
    if (game.VerifyRules(9, 13))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_9_14_clicked()
{
    int x, y;
    x = ui->ButtonHav_9_14->x();
    y = ui->ButtonHav_9_14->y();

    CurrentMove = std::make_pair(ui->ButtonHav_9_14->x(), ui->ButtonHav_9_14->y());
ROPMove=std::make_pair(9,14);
    ui->ButtonHav_9_14->setIcon(ChangeIcon());
    ui->ButtonHav_9_14->move(x - 9, y - 8);
    ui->ButtonHav_9_14->setFixedSize(44, 44);
    ui->ButtonHav_9_14->setIconSize(QSize(44, 44));
    ui->ButtonHav_9_14->setEnabled(false);

    game.PlayerTurn(9, 14, playerCurrent);
    if (game.VerifyRules(9, 14))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_9_15_clicked()
{
    int x, y;
    x = ui->ButtonHav_9_15->x();
    y = ui->ButtonHav_9_15->y();

    CurrentMove = std::make_pair(ui->ButtonHav_9_15->x(), ui->ButtonHav_9_15->y());
ROPMove=std::make_pair(9,15);
    ui->ButtonHav_9_15->setIcon(ChangeIcon());
    ui->ButtonHav_9_15->move(x - 9, y - 8);
    ui->ButtonHav_9_15->setFixedSize(44, 44);
    ui->ButtonHav_9_15->setIconSize(QSize(44, 44));
    ui->ButtonHav_9_15->setEnabled(false);

    game.PlayerTurn(9, 15, playerCurrent);
    if (game.VerifyRules(9, 15))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_9_16_clicked()
{
    int x, y;
    x = ui->ButtonHav_9_16->x();
    y = ui->ButtonHav_9_16->y();

    CurrentMove = std::make_pair(ui->ButtonHav_9_16->x(), ui->ButtonHav_9_16->y());
ROPMove=std::make_pair(9,16);
    ui->ButtonHav_9_16->setIcon(ChangeIcon());
    ui->ButtonHav_9_16->move(x - 9, y - 8);
    ui->ButtonHav_9_16->setFixedSize(44, 44);
    ui->ButtonHav_9_16->setIconSize(QSize(44, 44));
    ui->ButtonHav_9_16->setEnabled(false);

    game.PlayerTurn(9, 16, playerCurrent);
    if (game.VerifyRules(9, 16))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_9_17_clicked()
{
    int x, y;
    x = ui->ButtonHav_9_17->x();
    y = ui->ButtonHav_9_17->y();

    CurrentMove = std::make_pair(ui->ButtonHav_9_17->x(), ui->ButtonHav_9_17->y());
ROPMove=std::make_pair(9,17);
    ui->ButtonHav_9_17->setIcon(ChangeIcon());
    ui->ButtonHav_9_17->move(x - 9, y - 8);
    ui->ButtonHav_9_17->setFixedSize(44, 44);
    ui->ButtonHav_9_17->setIconSize(QSize(44, 44));
    ui->ButtonHav_9_17->setEnabled(false);

    game.PlayerTurn(9, 17, playerCurrent);
    if (game.VerifyRules(9, 17))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_9_18_clicked()
{
    int x, y;
    x = ui->ButtonHav_9_18->x();
    y = ui->ButtonHav_9_18->y();

    CurrentMove = std::make_pair(ui->ButtonHav_9_18->x(), ui->ButtonHav_9_18->y());
ROPMove=std::make_pair(9,18);
    ui->ButtonHav_9_18->setIcon(ChangeIcon());
    ui->ButtonHav_9_18->move(x - 9, y - 8);
    ui->ButtonHav_9_18->setFixedSize(44, 44);
    ui->ButtonHav_9_18->setIconSize(QSize(44, 44));
    ui->ButtonHav_9_18->setEnabled(false);

    game.PlayerTurn(9, 18, playerCurrent);
    if (game.VerifyRules(9, 18))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_10_0_clicked()
{
    int x, y;
    x = ui->ButtonHav_10_0->x();
    y = ui->ButtonHav_10_0->y();

    CurrentMove = std::make_pair(ui->ButtonHav_10_0->x(), ui->ButtonHav_10_0->y());
ROPMove=std::make_pair(10,0);
    ui->ButtonHav_10_0->setIcon(ChangeIcon());
    ui->ButtonHav_10_0->move(x - 9, y - 8);
    ui->ButtonHav_10_0->setFixedSize(44, 44);
    ui->ButtonHav_10_0->setIconSize(QSize(44, 44));
    ui->ButtonHav_10_0->setEnabled(false);

    game.PlayerTurn(10, 0, playerCurrent);
    if (game.VerifyRules(10, 0))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_10_1_clicked()
{
    int x, y;
    x = ui->ButtonHav_10_1->x();
    y = ui->ButtonHav_10_1->y();

    CurrentMove = std::make_pair(ui->ButtonHav_10_1->x(), ui->ButtonHav_10_1->y());
ROPMove=std::make_pair(10,1);
    ui->ButtonHav_10_1->setIcon(ChangeIcon());
    ui->ButtonHav_10_1->move(x - 9, y - 8);
    ui->ButtonHav_10_1->setFixedSize(44, 44);
    ui->ButtonHav_10_1->setIconSize(QSize(44, 44));
    ui->ButtonHav_10_1->setEnabled(false);

    game.PlayerTurn(10, 1, playerCurrent);
    if (game.VerifyRules(10, 1))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_10_2_clicked()
{
    int x, y;
    x = ui->ButtonHav_10_2->x();
    y = ui->ButtonHav_10_2->y();

    CurrentMove = std::make_pair(ui->ButtonHav_10_2->x(), ui->ButtonHav_10_2->y());
ROPMove=std::make_pair(10,2);
    ui->ButtonHav_10_2->setIcon(ChangeIcon());
    ui->ButtonHav_10_2->move(x - 9, y - 8);
    ui->ButtonHav_10_2->setFixedSize(44, 44);
    ui->ButtonHav_10_2->setIconSize(QSize(44, 44));
    ui->ButtonHav_10_2->setEnabled(false);

    game.PlayerTurn(10, 2, playerCurrent);
    if (game.VerifyRules(10, 2))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_10_3_clicked()
{
    int x, y;
    x = ui->ButtonHav_10_3->x();
    y = ui->ButtonHav_10_3->y();

    CurrentMove = std::make_pair(ui->ButtonHav_10_3->x(), ui->ButtonHav_10_3->y());
ROPMove=std::make_pair(10,3);
    ui->ButtonHav_10_3->setIcon(ChangeIcon());
    ui->ButtonHav_10_3->move(x - 9, y - 8);
    ui->ButtonHav_10_3->setFixedSize(44, 44);
    ui->ButtonHav_10_3->setIconSize(QSize(44, 44));
    ui->ButtonHav_10_3->setEnabled(false);

    game.PlayerTurn(10, 3, playerCurrent);
    if (game.VerifyRules(10, 3))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_10_4_clicked()
{
    int x, y;
    x = ui->ButtonHav_10_4->x();
    y = ui->ButtonHav_10_4->y();

    CurrentMove = std::make_pair(ui->ButtonHav_10_4->x(), ui->ButtonHav_10_4->y());
ROPMove=std::make_pair(10,4);
    ui->ButtonHav_10_4->setIcon(ChangeIcon());
    ui->ButtonHav_10_4->move(x - 9, y - 8);
    ui->ButtonHav_10_4->setFixedSize(44, 44);
    ui->ButtonHav_10_4->setIconSize(QSize(44, 44));
    ui->ButtonHav_10_4->setEnabled(false);

    game.PlayerTurn(10, 4, playerCurrent);
    if (game.VerifyRules(10, 4))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_10_5_clicked()
{
    int x, y;
    x = ui->ButtonHav_10_5->x();
    y = ui->ButtonHav_10_5->y();

    CurrentMove = std::make_pair(ui->ButtonHav_10_5->x(), ui->ButtonHav_10_5->y());
ROPMove=std::make_pair(10,5);
    ui->ButtonHav_10_5->setIcon(ChangeIcon());
    ui->ButtonHav_10_5->move(x - 9, y - 8);
    ui->ButtonHav_10_5->setFixedSize(44, 44);
    ui->ButtonHav_10_5->setIconSize(QSize(44, 44));
    ui->ButtonHav_10_5->setEnabled(false);

    game.PlayerTurn(10, 5, playerCurrent);
    if (game.VerifyRules(10, 5))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_10_6_clicked()
{
    int x, y;
    x = ui->ButtonHav_10_6->x();
    y = ui->ButtonHav_10_6->y();

    CurrentMove = std::make_pair(ui->ButtonHav_10_6->x(), ui->ButtonHav_10_6->y());
ROPMove=std::make_pair(10,6);
    ui->ButtonHav_10_6->setIcon(ChangeIcon());
    ui->ButtonHav_10_6->move(x - 9, y - 8);
    ui->ButtonHav_10_6->setFixedSize(44, 44);
    ui->ButtonHav_10_6->setIconSize(QSize(44, 44));
    ui->ButtonHav_10_6->setEnabled(false);

    game.PlayerTurn(10, 6, playerCurrent);
    if (game.VerifyRules(10, 6))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_10_7_clicked()
{
    int x, y;
    x = ui->ButtonHav_10_7->x();
    y = ui->ButtonHav_10_7->y();

    CurrentMove = std::make_pair(ui->ButtonHav_10_7->x(), ui->ButtonHav_10_7->y());
ROPMove=std::make_pair(10,7);
    ui->ButtonHav_10_7->setIcon(ChangeIcon());
    ui->ButtonHav_10_7->move(x - 9, y - 8);
    ui->ButtonHav_10_7->setFixedSize(44, 44);
    ui->ButtonHav_10_7->setIconSize(QSize(44, 44));
    ui->ButtonHav_10_7->setEnabled(false);

    game.PlayerTurn(10, 7, playerCurrent);
    if (game.VerifyRules(10, 7))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_10_8_clicked()
{
    int x, y;
    x = ui->ButtonHav_10_8->x();
    y = ui->ButtonHav_10_8->y();

    CurrentMove = std::make_pair(ui->ButtonHav_10_8->x(), ui->ButtonHav_10_8->y());
ROPMove=std::make_pair(10,8);
    ui->ButtonHav_10_8->setIcon(ChangeIcon());
    ui->ButtonHav_10_8->move(x - 9, y - 8);
    ui->ButtonHav_10_8->setFixedSize(44, 44);
    ui->ButtonHav_10_8->setIconSize(QSize(44, 44));
    ui->ButtonHav_10_8->setEnabled(false);

    game.PlayerTurn(10, 8, playerCurrent);
    if (game.VerifyRules(10, 8))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_10_9_clicked()
{
    int x, y;
    x = ui->ButtonHav_10_9->x();
    y = ui->ButtonHav_10_9->y();

    CurrentMove = std::make_pair(ui->ButtonHav_10_9->x(), ui->ButtonHav_10_9->y());
ROPMove=std::make_pair(10,9);
    ui->ButtonHav_10_9->setIcon(ChangeIcon());
    ui->ButtonHav_10_9->move(x - 9, y - 8);
    ui->ButtonHav_10_9->setFixedSize(44, 44);
    ui->ButtonHav_10_9->setIconSize(QSize(44, 44));
    ui->ButtonHav_10_9->setEnabled(false);

    game.PlayerTurn(10, 9, playerCurrent);
    if (game.VerifyRules(10, 9))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_10_10_clicked()
{
    int x, y;
    x = ui->ButtonHav_10_10->x();
    y = ui->ButtonHav_10_10->y();

    CurrentMove = std::make_pair(ui->ButtonHav_10_10->x(), ui->ButtonHav_10_10->y());
ROPMove=std::make_pair(10,10);
    ui->ButtonHav_10_10->setIcon(ChangeIcon());
    ui->ButtonHav_10_10->move(x - 9, y - 8);
    ui->ButtonHav_10_10->setFixedSize(44, 44);
    ui->ButtonHav_10_10->setIconSize(QSize(44, 44));
    ui->ButtonHav_10_10->setEnabled(false);

    game.PlayerTurn(10, 10, playerCurrent);
    if (game.VerifyRules(10, 10))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_10_11_clicked()
{
    int x, y;
    x = ui->ButtonHav_10_11->x();
    y = ui->ButtonHav_10_11->y();

    CurrentMove = std::make_pair(ui->ButtonHav_10_11->x(), ui->ButtonHav_10_11->y());
ROPMove=std::make_pair(10,11);
    ui->ButtonHav_10_11->setIcon(ChangeIcon());
    ui->ButtonHav_10_11->move(x - 9, y - 8);
    ui->ButtonHav_10_11->setFixedSize(44, 44);
    ui->ButtonHav_10_11->setIconSize(QSize(44, 44));
    ui->ButtonHav_10_11->setEnabled(false);

    game.PlayerTurn(10, 11, playerCurrent);
    if (game.VerifyRules(10, 11))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_10_12_clicked()
{
    int x, y;
    x = ui->ButtonHav_10_12->x();
    y = ui->ButtonHav_10_12->y();

    CurrentMove = std::make_pair(ui->ButtonHav_10_12->x(), ui->ButtonHav_10_12->y());
ROPMove=std::make_pair(10,12);
    ui->ButtonHav_10_12->setIcon(ChangeIcon());
    ui->ButtonHav_10_12->move(x - 9, y - 8);
    ui->ButtonHav_10_12->setFixedSize(44, 44);
    ui->ButtonHav_10_12->setIconSize(QSize(44, 44));
    ui->ButtonHav_10_12->setEnabled(false);

    game.PlayerTurn(10, 12, playerCurrent);
    if (game.VerifyRules(10, 12))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_10_13_clicked()
{
    int x, y;
    x = ui->ButtonHav_10_13->x();
    y = ui->ButtonHav_10_13->y();

    CurrentMove = std::make_pair(ui->ButtonHav_10_13->x(), ui->ButtonHav_10_13->y());
ROPMove=std::make_pair(10,13);
    ui->ButtonHav_10_13->setIcon(ChangeIcon());
    ui->ButtonHav_10_13->move(x - 9, y - 8);
    ui->ButtonHav_10_13->setFixedSize(44, 44);
    ui->ButtonHav_10_13->setIconSize(QSize(44, 44));
    ui->ButtonHav_10_13->setEnabled(false);

    game.PlayerTurn(10, 13, playerCurrent);
    if (game.VerifyRules(10, 13))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_10_14_clicked()
{
    int x, y;
    x = ui->ButtonHav_10_14->x();
    y = ui->ButtonHav_10_14->y();

    CurrentMove = std::make_pair(ui->ButtonHav_10_14->x(), ui->ButtonHav_10_14->y());
ROPMove=std::make_pair(10,14);
    ui->ButtonHav_10_14->setIcon(ChangeIcon());
    ui->ButtonHav_10_14->move(x - 9, y - 8);
    ui->ButtonHav_10_14->setFixedSize(44, 44);
    ui->ButtonHav_10_14->setIconSize(QSize(44, 44));
    ui->ButtonHav_10_14->setEnabled(false);

    game.PlayerTurn(10, 14, playerCurrent);
    if (game.VerifyRules(10, 14))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_10_15_clicked()
{
    int x, y;
    x = ui->ButtonHav_10_15->x();
    y = ui->ButtonHav_10_15->y();

    CurrentMove = std::make_pair(ui->ButtonHav_10_15->x(), ui->ButtonHav_10_15->y());
ROPMove=std::make_pair(10,15);
    ui->ButtonHav_10_15->setIcon(ChangeIcon());
    ui->ButtonHav_10_15->move(x - 9, y - 8);
    ui->ButtonHav_10_15->setFixedSize(44, 44);
    ui->ButtonHav_10_15->setIconSize(QSize(44, 44));
    ui->ButtonHav_10_15->setEnabled(false);

    game.PlayerTurn(10, 15, playerCurrent);
    if (game.VerifyRules(10, 15))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_10_16_clicked()
{
    int x, y;
    x = ui->ButtonHav_10_16->x();
    y = ui->ButtonHav_10_16->y();

    CurrentMove = std::make_pair(ui->ButtonHav_10_16->x(), ui->ButtonHav_10_16->y());
ROPMove=std::make_pair(10,16);
    ui->ButtonHav_10_16->setIcon(ChangeIcon());
    ui->ButtonHav_10_16->move(x - 9, y - 8);
    ui->ButtonHav_10_16->setFixedSize(44, 44);
    ui->ButtonHav_10_16->setIconSize(QSize(44, 44));
    ui->ButtonHav_10_16->setEnabled(false);

    game.PlayerTurn(10, 16, playerCurrent);
    if (game.VerifyRules(10, 16))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_10_17_clicked()
{
    int x, y;
    x = ui->ButtonHav_10_17->x();
    y = ui->ButtonHav_10_17->y();

    CurrentMove = std::make_pair(ui->ButtonHav_10_17->x(), ui->ButtonHav_10_17->y());
ROPMove=std::make_pair(10,17);
    ui->ButtonHav_10_17->setIcon(ChangeIcon());
    ui->ButtonHav_10_17->move(x - 9, y - 8);
    ui->ButtonHav_10_17->setFixedSize(44, 44);
    ui->ButtonHav_10_17->setIconSize(QSize(44, 44));
    ui->ButtonHav_10_17->setEnabled(false);

    game.PlayerTurn(10, 17, playerCurrent);
    if (game.VerifyRules(10, 17))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_11_0_clicked()
{
    int x, y;
    x = ui->ButtonHav_11_0->x();
    y = ui->ButtonHav_11_0->y();
ROPMove=std::make_pair(11,0);
    CurrentMove = std::make_pair(ui->ButtonHav_11_0->x(), ui->ButtonHav_11_0->y());

    ui->ButtonHav_11_0->setIcon(ChangeIcon());
    ui->ButtonHav_11_0->move(x - 9, y - 8);
    ui->ButtonHav_11_0->setFixedSize(44, 44);
    ui->ButtonHav_11_0->setIconSize(QSize(44, 44));
    ui->ButtonHav_11_0->setEnabled(false);

    game.PlayerTurn(11, 0, playerCurrent);
    if (game.VerifyRules(11, 0))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_11_1_clicked()
{
    int x, y;
    x = ui->ButtonHav_11_1->x();
    y = ui->ButtonHav_11_1->y();

    CurrentMove = std::make_pair(ui->ButtonHav_11_1->x(), ui->ButtonHav_11_1->y());
ROPMove=std::make_pair(11,1);
    ui->ButtonHav_11_1->setIcon(ChangeIcon());
    ui->ButtonHav_11_1->move(x - 9, y - 8);
    ui->ButtonHav_11_1->setFixedSize(44, 44);
    ui->ButtonHav_11_1->setIconSize(QSize(44, 44));
    ui->ButtonHav_11_1->setEnabled(false);

    game.PlayerTurn(11, 1, playerCurrent);
    if (game.VerifyRules(11, 1))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}
\
void HavannahUI::on_ButtonHav_11_2_clicked()
{
    int x, y;
    x = ui->ButtonHav_11_2->x();
    y = ui->ButtonHav_11_2->y();

    CurrentMove = std::make_pair(ui->ButtonHav_11_2->x(), ui->ButtonHav_11_2->y());
ROPMove=std::make_pair(11,2);
    ui->ButtonHav_11_2->setIcon(ChangeIcon());
    ui->ButtonHav_11_2->move(x - 9, y - 8);
    ui->ButtonHav_11_2->setFixedSize(44, 44);
    ui->ButtonHav_11_2->setIconSize(QSize(44, 44));
    ui->ButtonHav_11_2->setEnabled(false);

    game.PlayerTurn(11, 2, playerCurrent);
    if (game.VerifyRules(11, 2))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_11_3_clicked()
{
    int x, y;
    x = ui->ButtonHav_11_3->x();
    y = ui->ButtonHav_11_3->y();

    CurrentMove = std::make_pair(ui->ButtonHav_11_3->x(), ui->ButtonHav_11_3->y());
ROPMove=std::make_pair(11,3);
    ui->ButtonHav_11_3->setIcon(ChangeIcon());
    ui->ButtonHav_11_3->move(x - 9, y - 8);
    ui->ButtonHav_11_3->setFixedSize(44, 44);
    ui->ButtonHav_11_3->setIconSize(QSize(44, 44));
    ui->ButtonHav_11_3->setEnabled(false);

    game.PlayerTurn(11, 3, playerCurrent);
    if (game.VerifyRules(11, 3))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_11_4_clicked()
{
    int x, y;
    x = ui->ButtonHav_11_4->x();
    y = ui->ButtonHav_11_4->y();

    CurrentMove = std::make_pair(ui->ButtonHav_11_4->x(), ui->ButtonHav_11_4->y());
ROPMove=std::make_pair(11,4);
    ui->ButtonHav_11_4->setIcon(ChangeIcon());
    ui->ButtonHav_11_4->move(x - 9, y - 8);
    ui->ButtonHav_11_4->setFixedSize(44, 44);
    ui->ButtonHav_11_4->setIconSize(QSize(44, 44));
    ui->ButtonHav_11_4->setEnabled(false);

    game.PlayerTurn(11, 4, playerCurrent);
    if (game.VerifyRules(11, 4))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_11_5_clicked()
{
    int x, y;
    x = ui->ButtonHav_11_5->x();
    y = ui->ButtonHav_11_5->y();

    CurrentMove = std::make_pair(ui->ButtonHav_11_5->x(), ui->ButtonHav_11_5->y());
ROPMove=std::make_pair(11,5);
    ui->ButtonHav_11_5->setIcon(ChangeIcon());
    ui->ButtonHav_11_5->move(x - 9, y - 8);
    ui->ButtonHav_11_5->setFixedSize(44, 44);
    ui->ButtonHav_11_5->setIconSize(QSize(44, 44));
    ui->ButtonHav_11_5->setEnabled(false);

    game.PlayerTurn(11, 5, playerCurrent);
    if (game.VerifyRules(11, 5))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_11_6_clicked()
{
    int x, y;
    x = ui->ButtonHav_11_6->x();
    y = ui->ButtonHav_11_6->y();

    CurrentMove = std::make_pair(ui->ButtonHav_11_6->x(), ui->ButtonHav_11_6->y());
ROPMove=std::make_pair(11,6);
    ui->ButtonHav_11_6->setIcon(ChangeIcon());
    ui->ButtonHav_11_6->move(x - 9, y - 8);
    ui->ButtonHav_11_6->setFixedSize(44, 44);
    ui->ButtonHav_11_6->setIconSize(QSize(44, 44));
    ui->ButtonHav_11_6->setEnabled(false);

    game.PlayerTurn(11, 6, playerCurrent);
    if (game.VerifyRules(11, 6))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();

}

void HavannahUI::on_ButtonHav_11_7_clicked()
{
    int x, y;
    x = ui->ButtonHav_11_7->x();
    y = ui->ButtonHav_11_7->y();

    CurrentMove = std::make_pair(ui->ButtonHav_11_7->x(), ui->ButtonHav_11_7->y());
ROPMove=std::make_pair(11,7);
    ui->ButtonHav_11_7->setIcon(ChangeIcon());
    ui->ButtonHav_11_7->move(x - 9, y - 8);
    ui->ButtonHav_11_7->setFixedSize(44, 44);
    ui->ButtonHav_11_7->setIconSize(QSize(44, 44));
    ui->ButtonHav_11_7->setEnabled(false);

    game.PlayerTurn(11, 7, playerCurrent);
    if (game.VerifyRules(11, 7))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_11_8_clicked()
{
    int x, y;
    x = ui->ButtonHav_11_8->x();
    y = ui->ButtonHav_11_8->y();

    CurrentMove = std::make_pair(ui->ButtonHav_11_8->x(), ui->ButtonHav_11_8->y());
ROPMove=std::make_pair(11,8);
    ui->ButtonHav_11_8->setIcon(ChangeIcon());
    ui->ButtonHav_11_8->move(x - 9, y - 8);
    ui->ButtonHav_11_8->setFixedSize(44, 44);
    ui->ButtonHav_11_8->setIconSize(QSize(44, 44));
    ui->ButtonHav_11_8->setEnabled(false);

    game.PlayerTurn(11, 8, playerCurrent);
    if (game.VerifyRules(11, 8))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_11_9_clicked()
{
    int x, y;
    x = ui->ButtonHav_11_9->x();
    y = ui->ButtonHav_11_9->y();

    CurrentMove = std::make_pair(ui->ButtonHav_11_9->x(), ui->ButtonHav_11_9->y());
ROPMove=std::make_pair(11,9);
    ui->ButtonHav_11_9->setIcon(ChangeIcon());
    ui->ButtonHav_11_9->move(x - 9, y - 8);
    ui->ButtonHav_11_9->setFixedSize(44, 44);
    ui->ButtonHav_11_9->setIconSize(QSize(44, 44));
    ui->ButtonHav_11_9->setEnabled(false);

    game.PlayerTurn(11, 9, playerCurrent);
    if (game.VerifyRules(11, 9))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_11_10_clicked()
{
    int x, y;
    x = ui->ButtonHav_11_10->x();
    y = ui->ButtonHav_11_10->y();

    CurrentMove = std::make_pair(ui->ButtonHav_11_10->x(), ui->ButtonHav_11_10->y());
ROPMove=std::make_pair(11,10);
    ui->ButtonHav_11_10->setIcon(ChangeIcon());
    ui->ButtonHav_11_10->move(x - 9, y - 8);
    ui->ButtonHav_11_10->setFixedSize(44, 44);
    ui->ButtonHav_11_10->setIconSize(QSize(44, 44));
    ui->ButtonHav_11_10->setEnabled(false);

    game.PlayerTurn(11, 10, playerCurrent);
    if (game.VerifyRules(11, 10))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_11_11_clicked()
{
    int x, y;
    x = ui->ButtonHav_11_11->x();
    y = ui->ButtonHav_11_11->y();

    CurrentMove = std::make_pair(ui->ButtonHav_11_11->x(), ui->ButtonHav_11_11->y());
ROPMove=std::make_pair(11,11);
    ui->ButtonHav_11_11->setIcon(ChangeIcon());
    ui->ButtonHav_11_11->move(x - 9, y - 8);
    ui->ButtonHav_11_11->setFixedSize(44, 44);
    ui->ButtonHav_11_11->setIconSize(QSize(44, 44));
    ui->ButtonHav_11_11->setEnabled(false);

    game.PlayerTurn(11, 11, playerCurrent);
    if (game.VerifyRules(11, 11))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_11_12_clicked()
{
    int x, y;
    x = ui->ButtonHav_11_12->x();
    y = ui->ButtonHav_11_12->y();

    CurrentMove = std::make_pair(ui->ButtonHav_11_12->x(), ui->ButtonHav_11_12->y());
ROPMove=std::make_pair(11,12);
    ui->ButtonHav_11_12->setIcon(ChangeIcon());
    ui->ButtonHav_11_12->move(x - 9, y - 8);
    ui->ButtonHav_11_12->setFixedSize(44, 44);
    ui->ButtonHav_11_12->setIconSize(QSize(44, 44));
    ui->ButtonHav_11_12->setEnabled(false);

    game.PlayerTurn(11, 12, playerCurrent);
    if (game.VerifyRules(11, 12))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_11_13_clicked()
{
    int x, y;
    x = ui->ButtonHav_11_13->x();
    y = ui->ButtonHav_11_13->y();

    CurrentMove = std::make_pair(ui->ButtonHav_11_13->x(), ui->ButtonHav_11_13->y());
ROPMove=std::make_pair(11,13);
    ui->ButtonHav_11_13->setIcon(ChangeIcon());
    ui->ButtonHav_11_13->move(x - 9, y - 8);
    ui->ButtonHav_11_13->setFixedSize(44, 44);
    ui->ButtonHav_11_13->setIconSize(QSize(44, 44));
    ui->ButtonHav_11_13->setEnabled(false);

    game.PlayerTurn(11, 13, playerCurrent);
    if (game.VerifyRules(11, 13))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_11_14_clicked()
{
    int x, y;
    x = ui->ButtonHav_11_14->x();
    y = ui->ButtonHav_11_14->y();

    CurrentMove = std::make_pair(ui->ButtonHav_11_14->x(), ui->ButtonHav_11_14->y());
ROPMove=std::make_pair(11,14);
    ui->ButtonHav_11_14->setIcon(ChangeIcon());
    ui->ButtonHav_11_14->move(x - 9, y - 8);
    ui->ButtonHav_11_14->setFixedSize(44, 44);
    ui->ButtonHav_11_14->setIconSize(QSize(44, 44));
    ui->ButtonHav_11_14->setEnabled(false);

    game.PlayerTurn(11, 14, playerCurrent);
    if (game.VerifyRules(11, 14))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_11_15_clicked()
{
    int x, y;
    x = ui->ButtonHav_11_15->x();
    y = ui->ButtonHav_11_15->y();

    CurrentMove = std::make_pair(ui->ButtonHav_11_15->x(), ui->ButtonHav_11_15->y());
ROPMove=std::make_pair(11,15);
    ui->ButtonHav_11_15->setIcon(ChangeIcon());
    ui->ButtonHav_11_15->move(x - 9, y - 8);
    ui->ButtonHav_11_15->setFixedSize(44, 44);
    ui->ButtonHav_11_15->setIconSize(QSize(44, 44));
    ui->ButtonHav_11_15->setEnabled(false);

    game.PlayerTurn(11, 15, playerCurrent);
    if (game.VerifyRules(11, 15))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_11_16_clicked()
{
    int x, y;
    x = ui->ButtonHav_11_16->x();
    y = ui->ButtonHav_11_16->y();

    CurrentMove = std::make_pair(ui->ButtonHav_11_16->x(), ui->ButtonHav_11_16->y());
ROPMove=std::make_pair(11,16);
    ui->ButtonHav_11_16->setIcon(ChangeIcon());
    ui->ButtonHav_11_16->move(x - 9, y - 8);
    ui->ButtonHav_11_16->setFixedSize(44, 44);
    ui->ButtonHav_11_16->setIconSize(QSize(44, 44));
    ui->ButtonHav_11_16->setEnabled(false);

    game.PlayerTurn(11, 16, playerCurrent);
    if (game.VerifyRules(11, 16))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_12_0_clicked()
{
    int x, y;
    x = ui->ButtonHav_12_0->x();
    y = ui->ButtonHav_12_0->y();

    CurrentMove = std::make_pair(ui->ButtonHav_12_0->x(), ui->ButtonHav_12_0->y());
ROPMove=std::make_pair(12,0);
    ui->ButtonHav_12_0->setIcon(ChangeIcon());
    ui->ButtonHav_12_0->move(x - 9, y - 8);
    ui->ButtonHav_12_0->setFixedSize(44, 44);
    ui->ButtonHav_12_0->setIconSize(QSize(44, 44));
    ui->ButtonHav_12_0->setEnabled(false);

    game.PlayerTurn(12, 0, playerCurrent);
    if (game.VerifyRules(12, 0))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_12_1_clicked()
{
    int x, y;
    x = ui->ButtonHav_12_1->x();
    y = ui->ButtonHav_12_1->y();

    CurrentMove = std::make_pair(ui->ButtonHav_12_1->x(), ui->ButtonHav_12_1->y());
ROPMove=std::make_pair(12,1);
    ui->ButtonHav_12_1->setIcon(ChangeIcon());
    ui->ButtonHav_12_1->move(x - 9, y - 8);
    ui->ButtonHav_12_1->setFixedSize(44, 44);
    ui->ButtonHav_12_1->setIconSize(QSize(44, 44));
    ui->ButtonHav_12_1->setEnabled(false);

    game.PlayerTurn(12, 1, playerCurrent);
    if (game.VerifyRules(12, 1))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_12_2_clicked()
{
    int x, y;
    x = ui->ButtonHav_12_2->x();
    y = ui->ButtonHav_12_2->y();

    CurrentMove = std::make_pair(ui->ButtonHav_12_2->x(), ui->ButtonHav_12_2->y());
ROPMove=std::make_pair(12,2);
    ui->ButtonHav_12_2->setIcon(ChangeIcon());
    ui->ButtonHav_12_2->move(x - 9, y - 8);
    ui->ButtonHav_12_2->setFixedSize(44, 44);
    ui->ButtonHav_12_2->setIconSize(QSize(44, 44));
    ui->ButtonHav_12_2->setEnabled(false);

    game.PlayerTurn(12, 2, playerCurrent);
    if (game.VerifyRules(12, 2))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_12_3_clicked()
{
    int x, y;
    x = ui->ButtonHav_12_3->x();
    y = ui->ButtonHav_12_3->y();

    CurrentMove = std::make_pair(ui->ButtonHav_12_3->x(), ui->ButtonHav_12_3->y());
ROPMove=std::make_pair(12,3);
    ui->ButtonHav_12_3->setIcon(ChangeIcon());
    ui->ButtonHav_12_3->move(x - 9, y - 8);
    ui->ButtonHav_12_3->setFixedSize(44, 44);
    ui->ButtonHav_12_3->setIconSize(QSize(44, 44));
    ui->ButtonHav_12_3->setEnabled(false);

    game.PlayerTurn(12, 3, playerCurrent);
    if (game.VerifyRules(12, 3))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_12_4_clicked()
{
    int x, y;
    x = ui->ButtonHav_12_4->x();
    y = ui->ButtonHav_12_4->y();

    CurrentMove = std::make_pair(ui->ButtonHav_12_4->x(), ui->ButtonHav_12_4->y());
ROPMove=std::make_pair(12,4);
    ui->ButtonHav_12_4->setIcon(ChangeIcon());
    ui->ButtonHav_12_4->move(x - 9, y - 8);
    ui->ButtonHav_12_4->setFixedSize(44, 44);
    ui->ButtonHav_12_4->setIconSize(QSize(44, 44));
    ui->ButtonHav_12_4->setEnabled(false);

    game.PlayerTurn(12, 4, playerCurrent);
    if (game.VerifyRules(12, 4))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_12_5_clicked()
{
    int x, y;
    x = ui->ButtonHav_12_5->x();
    y = ui->ButtonHav_12_5->y();

    CurrentMove = std::make_pair(ui->ButtonHav_12_5->x(), ui->ButtonHav_12_5->y());
ROPMove=std::make_pair(12,5);
    ui->ButtonHav_12_5->setIcon(ChangeIcon());
    ui->ButtonHav_12_5->move(x - 9, y - 8);
    ui->ButtonHav_12_5->setFixedSize(44, 44);
    ui->ButtonHav_12_5->setIconSize(QSize(44, 44));
    ui->ButtonHav_12_5->setEnabled(false);

    game.PlayerTurn(12, 5, playerCurrent);
    if (game.VerifyRules(12, 5))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_12_6_clicked()
{
    int x, y;
    x = ui->ButtonHav_12_6->x();
    y = ui->ButtonHav_12_6->y();

    CurrentMove = std::make_pair(ui->ButtonHav_12_6->x(), ui->ButtonHav_12_6->y());
ROPMove=std::make_pair(12,6);
    ui->ButtonHav_12_6->setIcon(ChangeIcon());
    ui->ButtonHav_12_6->move(x - 9, y - 8);
    ui->ButtonHav_12_6->setFixedSize(44, 44);
    ui->ButtonHav_12_6->setIconSize(QSize(44, 44));
    ui->ButtonHav_12_6->setEnabled(false);

    game.PlayerTurn(12, 6, playerCurrent);
    if (game.VerifyRules(12, 6))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_12_7_clicked()
{
    int x, y;
    x = ui->ButtonHav_12_7->x();
    y = ui->ButtonHav_12_7->y();

    CurrentMove = std::make_pair(ui->ButtonHav_12_7->x(), ui->ButtonHav_12_7->y());
ROPMove=std::make_pair(12,7);
    ui->ButtonHav_12_7->setIcon(ChangeIcon());
    ui->ButtonHav_12_7->move(x - 9, y - 8);
    ui->ButtonHav_12_7->setFixedSize(44, 44);
    ui->ButtonHav_12_7->setIconSize(QSize(44, 44));
    ui->ButtonHav_12_7->setEnabled(false);

    game.PlayerTurn(12, 7, playerCurrent);
    if (game.VerifyRules(12, 7))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_12_8_clicked()
{
    int x, y;
    x = ui->ButtonHav_12_8->x();
    y = ui->ButtonHav_12_8->y();

    CurrentMove = std::make_pair(ui->ButtonHav_12_8->x(), ui->ButtonHav_12_8->y());
ROPMove=std::make_pair(12,8);
    ui->ButtonHav_12_8->setIcon(ChangeIcon());
    ui->ButtonHav_12_8->move(x - 9, y - 8);
    ui->ButtonHav_12_8->setFixedSize(44, 44);
    ui->ButtonHav_12_8->setIconSize(QSize(44, 44));
    ui->ButtonHav_12_8->setEnabled(false);

    game.PlayerTurn(12, 8, playerCurrent);
    if (game.VerifyRules(12, 8))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_12_9_clicked()
{
    int x, y;
    x = ui->ButtonHav_12_9->x();
    y = ui->ButtonHav_12_9->y();

    CurrentMove = std::make_pair(ui->ButtonHav_12_9->x(), ui->ButtonHav_12_9->y());
ROPMove=std::make_pair(12,9);
    ui->ButtonHav_12_9->setIcon(ChangeIcon());
    ui->ButtonHav_12_9->move(x - 9, y - 8);
    ui->ButtonHav_12_9->setFixedSize(44, 44);
    ui->ButtonHav_12_9->setIconSize(QSize(44, 44));
    ui->ButtonHav_12_9->setEnabled(false);

    game.PlayerTurn(12, 9, playerCurrent);
    if (game.VerifyRules(12, 9))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_12_10_clicked()
{
    int x, y;
    x = ui->ButtonHav_12_10->x();
    y = ui->ButtonHav_12_10->y();

    CurrentMove = std::make_pair(ui->ButtonHav_12_10->x(), ui->ButtonHav_12_10->y());
ROPMove=std::make_pair(12,10);
    ui->ButtonHav_12_10->setIcon(ChangeIcon());
    ui->ButtonHav_12_10->move(x - 9, y - 8);
    ui->ButtonHav_12_10->setFixedSize(44, 44);
    ui->ButtonHav_12_10->setIconSize(QSize(44, 44));
    ui->ButtonHav_12_10->setEnabled(false);

    game.PlayerTurn(12, 10, playerCurrent);
    if (game.VerifyRules(12, 10))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_12_11_clicked()
{
    int x, y;
    x = ui->ButtonHav_12_11->x();
    y = ui->ButtonHav_12_11->y();

    CurrentMove = std::make_pair(ui->ButtonHav_12_11->x(), ui->ButtonHav_12_11->y());
ROPMove=std::make_pair(12,11);
    ui->ButtonHav_12_11->setIcon(ChangeIcon());
    ui->ButtonHav_12_11->move(x - 9, y - 8);
    ui->ButtonHav_12_11->setFixedSize(44, 44);
    ui->ButtonHav_12_11->setIconSize(QSize(44, 44));
    ui->ButtonHav_12_11->setEnabled(false);

    game.PlayerTurn(12, 11, playerCurrent);
    if (game.VerifyRules(12, 11))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_12_12_clicked()
{
    int x, y;
    x = ui->ButtonHav_12_12->x();
    y = ui->ButtonHav_12_12->y();

    CurrentMove = std::make_pair(ui->ButtonHav_12_12->x(), ui->ButtonHav_12_12->y());
ROPMove=std::make_pair(12,12);
    ui->ButtonHav_12_12->setIcon(ChangeIcon());
    ui->ButtonHav_12_12->move(x - 9, y - 8);
    ui->ButtonHav_12_12->setFixedSize(44, 44);
    ui->ButtonHav_12_12->setIconSize(QSize(44, 44));
    ui->ButtonHav_12_12->setEnabled(false);

    game.PlayerTurn(12, 12, playerCurrent);
    if (game.VerifyRules(12, 12))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_12_13_clicked()
{
    int x, y;
    x = ui->ButtonHav_12_13->x();
    y = ui->ButtonHav_12_13->y();

    CurrentMove = std::make_pair(ui->ButtonHav_12_13->x(), ui->ButtonHav_12_13->y());
ROPMove=std::make_pair(12,13);
    ui->ButtonHav_12_13->setIcon(ChangeIcon());
    ui->ButtonHav_12_13->move(x - 9, y - 8);
    ui->ButtonHav_12_13->setFixedSize(44, 44);
    ui->ButtonHav_12_13->setIconSize(QSize(44, 44));
    ui->ButtonHav_12_13->setEnabled(false);

    game.PlayerTurn(12, 13, playerCurrent);
    if (game.VerifyRules(12, 13))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_12_14_clicked()
{
    int x, y;
    x = ui->ButtonHav_12_14->x();
    y = ui->ButtonHav_12_14->y();

    CurrentMove = std::make_pair(ui->ButtonHav_12_14->x(), ui->ButtonHav_12_14->y());
ROPMove=std::make_pair(12,14);
    ui->ButtonHav_12_14->setIcon(ChangeIcon());
    ui->ButtonHav_12_14->move(x - 9, y - 8);
    ui->ButtonHav_12_14->setFixedSize(44, 44);
    ui->ButtonHav_12_14->setIconSize(QSize(44, 44));
    ui->ButtonHav_12_14->setEnabled(false);

    game.PlayerTurn(12, 14, playerCurrent);
    if (game.VerifyRules(12, 14))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_12_15_clicked()
{
    int x, y;
    x = ui->ButtonHav_12_15->x();
    y = ui->ButtonHav_12_15->y();

    CurrentMove = std::make_pair(ui->ButtonHav_12_15->x(), ui->ButtonHav_12_15->y());
ROPMove=std::make_pair(12,15);
    ui->ButtonHav_12_15->setIcon(ChangeIcon());
    ui->ButtonHav_12_15->move(x - 9, y - 8);
    ui->ButtonHav_12_15->setFixedSize(44, 44);
    ui->ButtonHav_12_15->setIconSize(QSize(44, 44));
    ui->ButtonHav_12_15->setEnabled(false);

    game.PlayerTurn(12, 15, playerCurrent);
    if (game.VerifyRules(12, 15))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_13_0_clicked()
{
    int x, y;
    x = ui->ButtonHav_13_0->x();
    y = ui->ButtonHav_13_0->y();

    CurrentMove = std::make_pair(ui->ButtonHav_13_0->x(), ui->ButtonHav_13_0->y());
ROPMove=std::make_pair(13,0);
    ui->ButtonHav_13_0->setIcon(ChangeIcon());
    ui->ButtonHav_13_0->move(x - 9, y - 8);
    ui->ButtonHav_13_0->setFixedSize(44, 44);
    ui->ButtonHav_13_0->setIconSize(QSize(44, 44));
    ui->ButtonHav_13_0->setEnabled(false);

    game.PlayerTurn(13, 0, playerCurrent);
    if (game.VerifyRules(13, 0))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_13_1_clicked()
{
    int x, y;
    x = ui->ButtonHav_13_1->x();
    y = ui->ButtonHav_13_1->y();

    CurrentMove = std::make_pair(ui->ButtonHav_13_1->x(), ui->ButtonHav_13_1->y());
ROPMove=std::make_pair(13,1);
    ui->ButtonHav_13_1->setIcon(ChangeIcon());
    ui->ButtonHav_13_1->move(x - 9, y - 8);
    ui->ButtonHav_13_1->setFixedSize(44, 44);
    ui->ButtonHav_13_1->setIconSize(QSize(44, 44));
    ui->ButtonHav_13_1->setEnabled(false);

    game.PlayerTurn(13, 1, playerCurrent);
    if (game.VerifyRules(13, 1))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_13_2_clicked()
{
    int x, y;
    x = ui->ButtonHav_13_2->x();
    y = ui->ButtonHav_13_2->y();

    CurrentMove = std::make_pair(ui->ButtonHav_13_2->x(), ui->ButtonHav_13_2->y());
ROPMove=std::make_pair(13,2);
    ui->ButtonHav_13_2->setIcon(ChangeIcon());
    ui->ButtonHav_13_2->move(x - 9, y - 8);
    ui->ButtonHav_13_2->setFixedSize(44, 44);
    ui->ButtonHav_13_2->setIconSize(QSize(44, 44));
    ui->ButtonHav_13_2->setEnabled(false);

    game.PlayerTurn(13, 2, playerCurrent);
    if (game.VerifyRules(13, 2))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_13_3_clicked()
{
    int x, y;
    x = ui->ButtonHav_13_3->x();
    y = ui->ButtonHav_13_3->y();

    CurrentMove = std::make_pair(ui->ButtonHav_13_3->x(), ui->ButtonHav_13_3->y());
ROPMove=std::make_pair(13,3);
    ui->ButtonHav_13_3->setIcon(ChangeIcon());
    ui->ButtonHav_13_3->move(x - 9, y - 8);
    ui->ButtonHav_13_3->setFixedSize(44, 44);
    ui->ButtonHav_13_3->setIconSize(QSize(44, 44));
    ui->ButtonHav_13_3->setEnabled(false);

    game.PlayerTurn(13, 3, playerCurrent);
    if (game.VerifyRules(13, 3))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_13_4_clicked()
{
    int x, y;
    x = ui->ButtonHav_13_4->x();
    y = ui->ButtonHav_13_4->y();

    CurrentMove = std::make_pair(ui->ButtonHav_13_4->x(), ui->ButtonHav_13_4->y());
ROPMove=std::make_pair(13,4);
    ui->ButtonHav_13_4->setIcon(ChangeIcon());
    ui->ButtonHav_13_4->move(x - 9, y - 8);
    ui->ButtonHav_13_4->setFixedSize(44, 44);
    ui->ButtonHav_13_4->setIconSize(QSize(44, 44));
    ui->ButtonHav_13_4->setEnabled(false);

    game.PlayerTurn(13, 4, playerCurrent);
    if (game.VerifyRules(13, 4))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_13_5_clicked()
{
    int x, y;
    x = ui->ButtonHav_13_5->x();
    y = ui->ButtonHav_13_5->y();

    CurrentMove = std::make_pair(ui->ButtonHav_13_5->x(), ui->ButtonHav_13_5->y());
ROPMove=std::make_pair(13,5);
    ui->ButtonHav_13_5->setIcon(ChangeIcon());
    ui->ButtonHav_13_5->move(x - 9, y - 8);
    ui->ButtonHav_13_5->setFixedSize(44, 44);
    ui->ButtonHav_13_5->setIconSize(QSize(44, 44));
    ui->ButtonHav_13_5->setEnabled(false);

    game.PlayerTurn(13, 5, playerCurrent);
    if (game.VerifyRules(13, 5))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_13_6_clicked()
{
    int x, y;
    x = ui->ButtonHav_13_6->x();
    y = ui->ButtonHav_13_6->y();

    CurrentMove = std::make_pair(ui->ButtonHav_13_6->x(), ui->ButtonHav_13_6->y());
ROPMove=std::make_pair(13,6);
    ui->ButtonHav_13_6->setIcon(ChangeIcon());
    ui->ButtonHav_13_6->move(x - 9, y - 8);
    ui->ButtonHav_13_6->setFixedSize(44, 44);
    ui->ButtonHav_13_6->setIconSize(QSize(44, 44));
    ui->ButtonHav_13_6->setEnabled(false);

    game.PlayerTurn(13, 6, playerCurrent);
    if (game.VerifyRules(13, 6))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_13_7_clicked()
{
    int x, y;
    x = ui->ButtonHav_13_7->x();
    y = ui->ButtonHav_13_7->y();

    CurrentMove = std::make_pair(ui->ButtonHav_13_7->x(), ui->ButtonHav_13_7->y());
ROPMove=std::make_pair(13,7);
    ui->ButtonHav_13_7->setIcon(ChangeIcon());
    ui->ButtonHav_13_7->move(x - 9, y - 8);
    ui->ButtonHav_13_7->setFixedSize(44, 44);
    ui->ButtonHav_13_7->setIconSize(QSize(44, 44));
    ui->ButtonHav_13_7->setEnabled(false);

    game.PlayerTurn(13, 7, playerCurrent);
    if (game.VerifyRules(13, 7))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_13_8_clicked()
{
    int x, y;
    x = ui->ButtonHav_13_8->x();
    y = ui->ButtonHav_13_8->y();

    CurrentMove = std::make_pair(ui->ButtonHav_13_8->x(), ui->ButtonHav_13_8->y());
ROPMove=std::make_pair(13,8);
    ui->ButtonHav_13_8->setIcon(ChangeIcon());
    ui->ButtonHav_13_8->move(x - 9, y - 8);
    ui->ButtonHav_13_8->setFixedSize(44, 44);
    ui->ButtonHav_13_8->setIconSize(QSize(44, 44));
    ui->ButtonHav_13_8->setEnabled(false);

    game.PlayerTurn(13, 8, playerCurrent);
    if (game.VerifyRules(13, 8))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_13_9_clicked()
{
    int x, y;
    x = ui->ButtonHav_13_9->x();
    y = ui->ButtonHav_13_9->y();

    CurrentMove = std::make_pair(ui->ButtonHav_13_9->x(), ui->ButtonHav_13_9->y());
ROPMove=std::make_pair(13,9);
    ui->ButtonHav_13_9->setIcon(ChangeIcon());
    ui->ButtonHav_13_9->move(x - 9, y - 8);
    ui->ButtonHav_13_9->setFixedSize(44, 44);
    ui->ButtonHav_13_9->setIconSize(QSize(44, 44));
    ui->ButtonHav_13_9->setEnabled(false);

    game.PlayerTurn(13, 9, playerCurrent);
    if (game.VerifyRules(13, 9))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_13_10_clicked()
{
    int x, y;
    x = ui->ButtonHav_13_10->x();
    y = ui->ButtonHav_13_10->y();

    CurrentMove = std::make_pair(ui->ButtonHav_13_10->x(), ui->ButtonHav_13_10->y());
ROPMove=std::make_pair(13,10);
    ui->ButtonHav_13_10->setIcon(ChangeIcon());
    ui->ButtonHav_13_10->move(x - 9, y - 8);
    ui->ButtonHav_13_10->setFixedSize(44, 44);
    ui->ButtonHav_13_10->setIconSize(QSize(44, 44));
    ui->ButtonHav_13_10->setEnabled(false);

    game.PlayerTurn(13, 10, playerCurrent);
    if (game.VerifyRules(13, 10))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_13_11_clicked()
{
    int x, y;
    x = ui->ButtonHav_13_11->x();
    y = ui->ButtonHav_13_11->y();

    CurrentMove = std::make_pair(ui->ButtonHav_13_11->x(), ui->ButtonHav_13_11->y());
ROPMove=std::make_pair(13,11);
    ui->ButtonHav_13_11->setIcon(ChangeIcon());
    ui->ButtonHav_13_11->move(x - 9, y - 8);
    ui->ButtonHav_13_11->setFixedSize(44, 44);
    ui->ButtonHav_13_11->setIconSize(QSize(44, 44));
    ui->ButtonHav_13_11->setEnabled(false);

    game.PlayerTurn(13, 11, playerCurrent);
    if (game.VerifyRules(13, 11))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_13_12_clicked()
{
    int x, y;
    x = ui->ButtonHav_13_12->x();
    y = ui->ButtonHav_13_12->y();

    CurrentMove = std::make_pair(ui->ButtonHav_13_12->x(), ui->ButtonHav_13_12->y());
ROPMove=std::make_pair(13,12);
    ui->ButtonHav_13_12->setIcon(ChangeIcon());
    ui->ButtonHav_13_12->move(x - 9, y - 8);
    ui->ButtonHav_13_12->setFixedSize(44, 44);
    ui->ButtonHav_13_12->setIconSize(QSize(44, 44));
    ui->ButtonHav_13_12->setEnabled(false);

    game.PlayerTurn(13, 12, playerCurrent);
    if (game.VerifyRules(13, 12))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_13_13_clicked()
{
    int x, y;
    x = ui->ButtonHav_13_13->x();
    y = ui->ButtonHav_13_13->y();

    CurrentMove = std::make_pair(ui->ButtonHav_13_13->x(), ui->ButtonHav_13_13->y());
ROPMove=std::make_pair(13,13);
    ui->ButtonHav_13_13->setIcon(ChangeIcon());
    ui->ButtonHav_13_13->move(x - 9, y - 8);
    ui->ButtonHav_13_13->setFixedSize(44, 44);
    ui->ButtonHav_13_13->setIconSize(QSize(44, 44));
    ui->ButtonHav_13_13->setEnabled(false);

    game.PlayerTurn(13, 13, playerCurrent);
    if (game.VerifyRules(13, 13))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_13_14_clicked()
{
    int x, y;
    x = ui->ButtonHav_13_14->x();
    y = ui->ButtonHav_13_14->y();

    CurrentMove = std::make_pair(ui->ButtonHav_13_14->x(), ui->ButtonHav_13_14->y());
ROPMove=std::make_pair(13,14);
    ui->ButtonHav_13_14->setIcon(ChangeIcon());
    ui->ButtonHav_13_14->move(x - 9, y - 8);
    ui->ButtonHav_13_14->setFixedSize(44, 44);
    ui->ButtonHav_13_14->setIconSize(QSize(44, 44));
    ui->ButtonHav_13_14->setEnabled(false);

    game.PlayerTurn(13, 14, playerCurrent);
    if (game.VerifyRules(13, 14))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_14_1_clicked()
{
    int x, y;
    x = ui->ButtonHav_14_1->x();
    y = ui->ButtonHav_14_1->y();

    CurrentMove = std::make_pair(ui->ButtonHav_14_1->x(), ui->ButtonHav_14_1->y());
ROPMove=std::make_pair(14,1);
    ui->ButtonHav_14_1->setIcon(ChangeIcon());
    ui->ButtonHav_14_1->move(x - 9, y - 8);
    ui->ButtonHav_14_1->setFixedSize(44, 44);
    ui->ButtonHav_14_1->setIconSize(QSize(44, 44));
    ui->ButtonHav_14_1->setEnabled(false);

    game.PlayerTurn(14, 1, playerCurrent);
    if (game.VerifyRules(14, 1))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_14_2_clicked()
{
    int x, y;
    x = ui->ButtonHav_14_2->x();
    y = ui->ButtonHav_14_2->y();

    CurrentMove = std::make_pair(ui->ButtonHav_14_2->x(), ui->ButtonHav_14_2->y());
ROPMove=std::make_pair(14,2);
    ui->ButtonHav_14_2->setIcon(ChangeIcon());
    ui->ButtonHav_14_2->move(x - 9, y - 8);
    ui->ButtonHav_14_2->setFixedSize(44, 44);
    ui->ButtonHav_14_2->setIconSize(QSize(44, 44));
    ui->ButtonHav_14_2->setEnabled(false);

    game.PlayerTurn(14, 2, playerCurrent);
    if (game.VerifyRules(14, 2))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_14_3_clicked()
{
    int x, y;
    x = ui->ButtonHav_14_3->x();
    y = ui->ButtonHav_14_3->y();

    CurrentMove = std::make_pair(ui->ButtonHav_14_3->x(), ui->ButtonHav_14_3->y());
ROPMove=std::make_pair(14,3);
    ui->ButtonHav_14_3->setIcon(ChangeIcon());
    ui->ButtonHav_14_3->move(x - 9, y - 8);
    ui->ButtonHav_14_3->setFixedSize(44, 44);
    ui->ButtonHav_14_3->setIconSize(QSize(44, 44));
    ui->ButtonHav_14_3->setEnabled(false);

    game.PlayerTurn(14, 3, playerCurrent);
    if (game.VerifyRules(14, 3))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_14_4_clicked()
{
    int x, y;
    x = ui->ButtonHav_14_4->x();
    y = ui->ButtonHav_14_4->y();

    CurrentMove = std::make_pair(ui->ButtonHav_14_4->x(), ui->ButtonHav_14_4->y());
ROPMove=std::make_pair(14,4);
    ui->ButtonHav_14_4->setIcon(ChangeIcon());
    ui->ButtonHav_14_4->move(x - 9, y - 8);
    ui->ButtonHav_14_4->setFixedSize(44, 44);
    ui->ButtonHav_14_4->setIconSize(QSize(44, 44));
    ui->ButtonHav_14_4->setEnabled(false);

    game.PlayerTurn(14, 4, playerCurrent);
    if (game.VerifyRules(14, 4))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_14_5_clicked()
{
    int x, y;
    x = ui->ButtonHav_14_5->x();
    y = ui->ButtonHav_14_5->y();

    CurrentMove = std::make_pair(ui->ButtonHav_14_5->x(), ui->ButtonHav_14_5->y());
ROPMove=std::make_pair(14,5);
    ui->ButtonHav_14_5->setIcon(ChangeIcon());
    ui->ButtonHav_14_5->move(x - 9, y - 8);
    ui->ButtonHav_14_5->setFixedSize(44, 44);
    ui->ButtonHav_14_5->setIconSize(QSize(44, 44));
    ui->ButtonHav_14_5->setEnabled(false);

    game.PlayerTurn(14, 5, playerCurrent);
    if (game.VerifyRules(14, 5))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_14_6_clicked()
{
    int x, y;
    x = ui->ButtonHav_14_6->x();
    y = ui->ButtonHav_14_6->y();

    CurrentMove = std::make_pair(ui->ButtonHav_14_6->x(), ui->ButtonHav_14_6->y());
ROPMove=std::make_pair(14,6);
    ui->ButtonHav_14_6->setIcon(ChangeIcon());
    ui->ButtonHav_14_6->move(x - 9, y - 8);
    ui->ButtonHav_14_6->setFixedSize(44, 44);
    ui->ButtonHav_14_6->setIconSize(QSize(44, 44));
    ui->ButtonHav_14_6->setEnabled(false);

    game.PlayerTurn(14, 6, playerCurrent);
    if (game.VerifyRules(14, 6))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_14_7_clicked()
{
    int x, y;
    x = ui->ButtonHav_14_7->x();
    y = ui->ButtonHav_14_7->y();

    CurrentMove = std::make_pair(ui->ButtonHav_14_7->x(), ui->ButtonHav_14_7->y());
ROPMove=std::make_pair(14,7);
    ui->ButtonHav_14_7->setIcon(ChangeIcon());
    ui->ButtonHav_14_7->move(x - 9, y - 8);
    ui->ButtonHav_14_7->setFixedSize(44, 44);
    ui->ButtonHav_14_7->setIconSize(QSize(44, 44));
    ui->ButtonHav_14_7->setEnabled(false);

    game.PlayerTurn(14, 7, playerCurrent);
    if (game.VerifyRules(14, 7))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_14_8_clicked()
{
    int x, y;
    x = ui->ButtonHav_14_8->x();
    y = ui->ButtonHav_14_8->y();

    CurrentMove = std::make_pair(ui->ButtonHav_14_8->x(), ui->ButtonHav_14_8->y());
ROPMove=std::make_pair(14,8);
    ui->ButtonHav_14_8->setIcon(ChangeIcon());
    ui->ButtonHav_14_8->move(x - 9, y - 8);
    ui->ButtonHav_14_8->setFixedSize(44, 44);
    ui->ButtonHav_14_8->setIconSize(QSize(44, 44));
    ui->ButtonHav_14_8->setEnabled(false);

    game.PlayerTurn(14, 8, playerCurrent);
    if (game.VerifyRules(14, 8))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_14_9_clicked()
{
    int x, y;
    x = ui->ButtonHav_14_9->x();
    y = ui->ButtonHav_14_9->y();

    CurrentMove = std::make_pair(ui->ButtonHav_14_9->x(), ui->ButtonHav_14_9->y());
ROPMove=std::make_pair(14,9);
    ui->ButtonHav_14_9->setIcon(ChangeIcon());
    ui->ButtonHav_14_9->move(x - 9, y - 8);
    ui->ButtonHav_14_9->setFixedSize(44, 44);
    ui->ButtonHav_14_9->setIconSize(QSize(44, 44));
    ui->ButtonHav_14_9->setEnabled(false);

    game.PlayerTurn(14, 9, playerCurrent);
    if (game.VerifyRules(14, 9))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_14_10_clicked()
{
    int x, y;
    x = ui->ButtonHav_14_10->x();
    y = ui->ButtonHav_14_10->y();

    CurrentMove = std::make_pair(ui->ButtonHav_14_10->x(), ui->ButtonHav_14_10->y());
ROPMove=std::make_pair(14,10);
    ui->ButtonHav_14_10->setIcon(ChangeIcon());
    ui->ButtonHav_14_10->move(x - 9, y - 8);
    ui->ButtonHav_14_10->setFixedSize(44, 44);
    ui->ButtonHav_14_10->setIconSize(QSize(44, 44));
    ui->ButtonHav_14_10->setEnabled(false);

    game.PlayerTurn(14, 10, playerCurrent);
    if (game.VerifyRules(14, 10))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_14_11_clicked()
{
    int x, y;
    x = ui->ButtonHav_14_11->x();
    y = ui->ButtonHav_14_11->y();

    CurrentMove = std::make_pair(ui->ButtonHav_14_11->x(), ui->ButtonHav_14_11->y());
ROPMove=std::make_pair(14,11);
    ui->ButtonHav_14_11->setIcon(ChangeIcon());
    ui->ButtonHav_14_11->move(x - 9, y - 8);
    ui->ButtonHav_14_11->setFixedSize(44, 44);
    ui->ButtonHav_14_11->setIconSize(QSize(44, 44));
    ui->ButtonHav_14_11->setEnabled(false);

    game.PlayerTurn(14, 11, playerCurrent);
    if (game.VerifyRules(14, 11))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_14_12_clicked()
{
    int x, y;
    x = ui->ButtonHav_14_12->x();
    y = ui->ButtonHav_14_12->y();

    CurrentMove = std::make_pair(ui->ButtonHav_14_12->x(), ui->ButtonHav_14_12->y());
ROPMove=std::make_pair(14,12);
    ui->ButtonHav_14_12->setIcon(ChangeIcon());
    ui->ButtonHav_14_12->move(x - 9, y - 8);
    ui->ButtonHav_14_12->setFixedSize(44, 44);
    ui->ButtonHav_14_12->setIconSize(QSize(44, 44));
    ui->ButtonHav_14_12->setEnabled(false);

    game.PlayerTurn(14, 12, playerCurrent);
    if (game.VerifyRules(14, 12))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_14_13_clicked()
{
    int x, y;
    x = ui->ButtonHav_14_13->x();
    y = ui->ButtonHav_14_13->y();

    CurrentMove = std::make_pair(ui->ButtonHav_14_13->x(), ui->ButtonHav_14_13->y());
ROPMove=std::make_pair(14,13);
    ui->ButtonHav_14_13->setIcon(ChangeIcon());
    ui->ButtonHav_14_13->move(x - 9, y - 8);
    ui->ButtonHav_14_13->setFixedSize(44, 44);
    ui->ButtonHav_14_13->setIconSize(QSize(44, 44));
    ui->ButtonHav_14_13->setEnabled(false);

    game.PlayerTurn(14, 13, playerCurrent);
    if (game.VerifyRules(14, 13))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_15_1_clicked()
{
    int x, y;
    x = ui->ButtonHav_15_1->x();
    y = ui->ButtonHav_15_1->y();

    CurrentMove = std::make_pair(ui->ButtonHav_15_1->x(), ui->ButtonHav_15_1->y());
ROPMove=std::make_pair(15,1);
    ui->ButtonHav_15_1->setIcon(ChangeIcon());
    ui->ButtonHav_15_1->move(x - 9, y - 8);
    ui->ButtonHav_15_1->setFixedSize(44, 44);
    ui->ButtonHav_15_1->setIconSize(QSize(44, 44));
    ui->ButtonHav_15_1->setEnabled(false);

    game.PlayerTurn(15, 1, playerCurrent);
    if (game.VerifyRules(15, 1))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_15_2_clicked()
{
    int x, y;
    x = ui->ButtonHav_15_2->x();
    y = ui->ButtonHav_15_2->y();

    CurrentMove = std::make_pair(ui->ButtonHav_15_2->x(), ui->ButtonHav_15_2->y());
ROPMove=std::make_pair(15,2);
    ui->ButtonHav_15_2->setIcon(ChangeIcon());
    ui->ButtonHav_15_2->move(x - 9, y - 8);
    ui->ButtonHav_15_2->setFixedSize(44, 44);
    ui->ButtonHav_15_2->setIconSize(QSize(44, 44));
    ui->ButtonHav_15_2->setEnabled(false);

    game.PlayerTurn(15, 2, playerCurrent);
    if (game.VerifyRules(15, 2))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_15_3_clicked()
{
    int x, y;
    x = ui->ButtonHav_15_3->x();
    y = ui->ButtonHav_15_3->y();

    CurrentMove = std::make_pair(ui->ButtonHav_15_3->x(), ui->ButtonHav_15_3->y());
ROPMove=std::make_pair(15,3);
    ui->ButtonHav_15_3->setIcon(ChangeIcon());
    ui->ButtonHav_15_3->move(x - 9, y - 8);
    ui->ButtonHav_15_3->setFixedSize(44, 44);
    ui->ButtonHav_15_3->setIconSize(QSize(44, 44));
    ui->ButtonHav_15_3->setEnabled(false);

    game.PlayerTurn(15, 3, playerCurrent);
    if (game.VerifyRules(15, 3))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_15_4_clicked()
{
    int x, y;
    x = ui->ButtonHav_15_4->x();
    y = ui->ButtonHav_15_4->y();

    CurrentMove = std::make_pair(ui->ButtonHav_15_4->x(), ui->ButtonHav_15_4->y());
ROPMove=std::make_pair(15,4);
    ui->ButtonHav_15_4->setIcon(ChangeIcon());
    ui->ButtonHav_15_4->move(x - 9, y - 8);
    ui->ButtonHav_15_4->setFixedSize(44, 44);
    ui->ButtonHav_15_4->setIconSize(QSize(44, 44));
    ui->ButtonHav_15_4->setEnabled(false);

    game.PlayerTurn(15, 4, playerCurrent);
    if (game.VerifyRules(15, 4))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_15_5_clicked()
{
    int x, y;
    x = ui->ButtonHav_15_5->x();
    y = ui->ButtonHav_15_5->y();

    CurrentMove = std::make_pair(ui->ButtonHav_15_5->x(), ui->ButtonHav_15_5->y());
ROPMove=std::make_pair(15,5);
    ui->ButtonHav_15_5->setIcon(ChangeIcon());
    ui->ButtonHav_15_5->move(x - 9, y - 8);
    ui->ButtonHav_15_5->setFixedSize(44, 44);
    ui->ButtonHav_15_5->setIconSize(QSize(44, 44));
    ui->ButtonHav_15_5->setEnabled(false);

    game.PlayerTurn(15, 5, playerCurrent);
    if (game.VerifyRules(15, 5))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_15_6_clicked()
{
    int x, y;
    x = ui->ButtonHav_15_6->x();
    y = ui->ButtonHav_15_6->y();

    CurrentMove = std::make_pair(ui->ButtonHav_15_6->x(), ui->ButtonHav_15_6->y());
ROPMove=std::make_pair(15,6);
    ui->ButtonHav_15_6->setIcon(ChangeIcon());
    ui->ButtonHav_15_6->move(x - 9, y - 8);
    ui->ButtonHav_15_6->setFixedSize(44, 44);
    ui->ButtonHav_15_6->setIconSize(QSize(44, 44));
    ui->ButtonHav_15_6->setEnabled(false);

    game.PlayerTurn(15, 6, playerCurrent);
    if (game.VerifyRules(15, 6))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_15_7_clicked()
{
    int x, y;
    x = ui->ButtonHav_15_7->x();
    y = ui->ButtonHav_15_7->y();

    CurrentMove = std::make_pair(ui->ButtonHav_15_7->x(), ui->ButtonHav_15_7->y());
ROPMove=std::make_pair(15,7);
    ui->ButtonHav_15_7->setIcon(ChangeIcon());
    ui->ButtonHav_15_7->move(x - 9, y - 8);
    ui->ButtonHav_15_7->setFixedSize(44, 44);
    ui->ButtonHav_15_7->setIconSize(QSize(44, 44));
    ui->ButtonHav_15_7->setEnabled(false);

    game.PlayerTurn(15, 7, playerCurrent);
    if (game.VerifyRules(15, 7))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_15_8_clicked()
{
    int x, y;
    x = ui->ButtonHav_15_8->x();
    y = ui->ButtonHav_15_8->y();

    CurrentMove = std::make_pair(ui->ButtonHav_15_8->x(), ui->ButtonHav_15_8->y());
ROPMove=std::make_pair(15,8);
    ui->ButtonHav_15_8->setIcon(ChangeIcon());
    ui->ButtonHav_15_8->move(x - 9, y - 8);
    ui->ButtonHav_15_8->setFixedSize(44, 44);
    ui->ButtonHav_15_8->setIconSize(QSize(44, 44));
    ui->ButtonHav_15_8->setEnabled(false);

    game.PlayerTurn(15, 8, playerCurrent);
    if (game.VerifyRules(15, 8))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_15_9_clicked()
{
    int x, y;
    x = ui->ButtonHav_15_9->x();
    y = ui->ButtonHav_15_9->y();

    CurrentMove = std::make_pair(ui->ButtonHav_15_9->x(), ui->ButtonHav_15_9->y());
ROPMove=std::make_pair(15,9);
    ui->ButtonHav_15_9->setIcon(ChangeIcon());
    ui->ButtonHav_15_9->move(x - 9, y - 8);
    ui->ButtonHav_15_9->setFixedSize(44, 44);
    ui->ButtonHav_15_9->setIconSize(QSize(44, 44));
    ui->ButtonHav_15_9->setEnabled(false);

    game.PlayerTurn(15, 9, playerCurrent);
    if (game.VerifyRules(15, 9))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_15_10_clicked()
{
    int x, y;
    x = ui->ButtonHav_15_10->x();
    y = ui->ButtonHav_15_10->y();

    CurrentMove = std::make_pair(ui->ButtonHav_15_10->x(), ui->ButtonHav_15_10->y());
ROPMove=std::make_pair(15,10);
    ui->ButtonHav_15_10->setIcon(ChangeIcon());
    ui->ButtonHav_15_10->move(x - 9, y - 8);
    ui->ButtonHav_15_10->setFixedSize(44, 44);
    ui->ButtonHav_15_10->setIconSize(QSize(44, 44));
    ui->ButtonHav_15_10->setEnabled(false);

    game.PlayerTurn(15, 10, playerCurrent);
    if (game.VerifyRules(15, 10))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_15_11_clicked()
{
    int x, y;
    x = ui->ButtonHav_15_11->x();
    y = ui->ButtonHav_15_11->y();

    CurrentMove = std::make_pair(ui->ButtonHav_15_11->x(), ui->ButtonHav_15_11->y());
ROPMove=std::make_pair(15,11);
    ui->ButtonHav_15_11->setIcon(ChangeIcon());
    ui->ButtonHav_15_11->move(x - 9, y - 8);
    ui->ButtonHav_15_11->setFixedSize(44, 44);
    ui->ButtonHav_15_11->setIconSize(QSize(44, 44));
    ui->ButtonHav_15_11->setEnabled(false);

    game.PlayerTurn(15, 11, playerCurrent);
    if (game.VerifyRules(15, 11))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_15_12_clicked()
{
    int x, y;
    x = ui->ButtonHav_15_12->x();
    y = ui->ButtonHav_15_12->y();

    CurrentMove = std::make_pair(ui->ButtonHav_15_12->x(), ui->ButtonHav_15_12->y());
ROPMove=std::make_pair(15,12);
    ui->ButtonHav_15_12->setIcon(ChangeIcon());
    ui->ButtonHav_15_12->move(x - 9, y - 8);
    ui->ButtonHav_15_12->setFixedSize(44, 44);
    ui->ButtonHav_15_12->setIconSize(QSize(44, 44));
    ui->ButtonHav_15_12->setEnabled(false);

    game.PlayerTurn(15, 12, playerCurrent);
    if (game.VerifyRules(15, 12))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_16_1_clicked()
{
    int x, y;
    x = ui->ButtonHav_16_1->x();
    y = ui->ButtonHav_16_1->y();

    CurrentMove = std::make_pair(ui->ButtonHav_16_1->x(), ui->ButtonHav_16_1->y());
ROPMove=std::make_pair(16,1);
    ui->ButtonHav_16_1->setIcon(ChangeIcon());
    ui->ButtonHav_16_1->move(x - 9, y - 8);
    ui->ButtonHav_16_1->setFixedSize(44, 44);
    ui->ButtonHav_16_1->setIconSize(QSize(44, 44));
    ui->ButtonHav_16_1->setEnabled(false);

    game.PlayerTurn(16, 1, playerCurrent);
    if (game.VerifyRules(16, 1))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_16_2_clicked()
{
    int x, y;
    x = ui->ButtonHav_16_2->x();
    y = ui->ButtonHav_16_2->y();

    CurrentMove = std::make_pair(ui->ButtonHav_16_2->x(), ui->ButtonHav_16_2->y());
ROPMove=std::make_pair(16,2);
    ui->ButtonHav_16_2->setIcon(ChangeIcon());
    ui->ButtonHav_16_2->move(x - 9, y - 8);
    ui->ButtonHav_16_2->setFixedSize(44, 44);
    ui->ButtonHav_16_2->setIconSize(QSize(44, 44));
    ui->ButtonHav_16_2->setEnabled(false);

    game.PlayerTurn(16, 2, playerCurrent);
    if (game.VerifyRules(16, 2))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_16_3_clicked()
{
    int x, y;
    x = ui->ButtonHav_16_3->x();
    y = ui->ButtonHav_16_3->y();

    CurrentMove = std::make_pair(ui->ButtonHav_16_3->x(), ui->ButtonHav_16_3->y());
ROPMove=std::make_pair(16,3);
    ui->ButtonHav_16_3->setIcon(ChangeIcon());
    ui->ButtonHav_16_3->move(x - 9, y - 8);
    ui->ButtonHav_16_3->setFixedSize(44, 44);
    ui->ButtonHav_16_3->setIconSize(QSize(44, 44));
    ui->ButtonHav_16_3->setEnabled(false);

    game.PlayerTurn(16, 3, playerCurrent);
    if (game.VerifyRules(16, 3))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_16_4_clicked()
{
    int x, y;
    x = ui->ButtonHav_16_4->x();
    y = ui->ButtonHav_16_4->y();

    CurrentMove = std::make_pair(ui->ButtonHav_16_4->x(), ui->ButtonHav_16_4->y());
ROPMove=std::make_pair(16,4);
    ui->ButtonHav_16_4->setIcon(ChangeIcon());
    ui->ButtonHav_16_4->move(x - 9, y - 8);
    ui->ButtonHav_16_4->setFixedSize(44, 44);
    ui->ButtonHav_16_4->setIconSize(QSize(44, 44));
    ui->ButtonHav_16_4->setEnabled(false);

    game.PlayerTurn(16, 4, playerCurrent);
    if (game.VerifyRules(16, 4))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_16_5_clicked()
{
    int x, y;
    x = ui->ButtonHav_16_5->x();
    y = ui->ButtonHav_16_5->y();

    CurrentMove = std::make_pair(ui->ButtonHav_16_5->x(), ui->ButtonHav_16_5->y());
ROPMove=std::make_pair(16,5);
    ui->ButtonHav_16_5->setIcon(ChangeIcon());
    ui->ButtonHav_16_5->move(x - 9, y - 8);
    ui->ButtonHav_16_5->setFixedSize(44, 44);
    ui->ButtonHav_16_5->setIconSize(QSize(44, 44));
    ui->ButtonHav_16_5->setEnabled(false);

    game.PlayerTurn(16, 5, playerCurrent);
    if (game.VerifyRules(16, 5))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_16_6_clicked()
{
    int x, y;
    x = ui->ButtonHav_16_6->x();
    y = ui->ButtonHav_16_6->y();

    CurrentMove = std::make_pair(ui->ButtonHav_16_6->x(), ui->ButtonHav_16_6->y());
ROPMove=std::make_pair(16,6);
    ui->ButtonHav_16_6->setIcon(ChangeIcon());
    ui->ButtonHav_16_6->move(x - 9, y - 8);
    ui->ButtonHav_16_6->setFixedSize(44, 44);
    ui->ButtonHav_16_6->setIconSize(QSize(44, 44));
    ui->ButtonHav_16_6->setEnabled(false);

    game.PlayerTurn(16, 6, playerCurrent);
    if (game.VerifyRules(16, 6))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_16_7_clicked()
{
    int x, y;
    x = ui->ButtonHav_16_7->x();
    y = ui->ButtonHav_16_7->y();

    CurrentMove = std::make_pair(ui->ButtonHav_16_7->x(), ui->ButtonHav_16_7->y());
ROPMove=std::make_pair(16,7);
    ui->ButtonHav_16_7->setIcon(ChangeIcon());
    ui->ButtonHav_16_7->move(x - 9, y - 8);
    ui->ButtonHav_16_7->setFixedSize(44, 44);
    ui->ButtonHav_16_7->setIconSize(QSize(44, 44));
    ui->ButtonHav_16_7->setEnabled(false);

    game.PlayerTurn(16, 7, playerCurrent);
    if (game.VerifyRules(16, 7))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_16_8_clicked()
{
    int x, y;
    x = ui->ButtonHav_16_8->x();
    y = ui->ButtonHav_16_8->y();

    CurrentMove = std::make_pair(ui->ButtonHav_16_8->x(), ui->ButtonHav_16_8->y());
ROPMove=std::make_pair(16,8);
    ui->ButtonHav_16_8->setIcon(ChangeIcon());
    ui->ButtonHav_16_8->move(x - 9, y - 8);
    ui->ButtonHav_16_8->setFixedSize(44, 44);
    ui->ButtonHav_16_8->setIconSize(QSize(44, 44));
    ui->ButtonHav_16_8->setEnabled(false);

    game.PlayerTurn(16, 8, playerCurrent);
    if (game.VerifyRules(16, 8))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_16_9_clicked()
{
    int x, y;
    x = ui->ButtonHav_16_9->x();
    y = ui->ButtonHav_16_9->y();

    CurrentMove = std::make_pair(ui->ButtonHav_16_9->x(), ui->ButtonHav_16_9->y());
ROPMove=std::make_pair(16,9);
    ui->ButtonHav_16_9->setIcon(ChangeIcon());
    ui->ButtonHav_16_9->move(x - 9, y - 8);
    ui->ButtonHav_16_9->setFixedSize(44, 44);
    ui->ButtonHav_16_9->setIconSize(QSize(44, 44));
    ui->ButtonHav_16_9->setEnabled(false);

    game.PlayerTurn(16, 9, playerCurrent);
    if (game.VerifyRules(16, 9))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_16_10_clicked()
{
    int x, y;
    x = ui->ButtonHav_16_10->x();
    y = ui->ButtonHav_16_10->y();

    CurrentMove = std::make_pair(ui->ButtonHav_16_10->x(), ui->ButtonHav_16_10->y());
ROPMove=std::make_pair(16,10);
    ui->ButtonHav_16_10->setIcon(ChangeIcon());
    ui->ButtonHav_16_10->move(x - 9, y - 8);
    ui->ButtonHav_16_10->setFixedSize(44, 44);
    ui->ButtonHav_16_10->setIconSize(QSize(44, 44));
    ui->ButtonHav_16_10->setEnabled(false);

    game.PlayerTurn(16, 10, playerCurrent);
    if (game.VerifyRules(16, 10))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_16_11_clicked()
{
    int x, y;
    x = ui->ButtonHav_16_11->x();
    y = ui->ButtonHav_16_11->y();

    CurrentMove = std::make_pair(ui->ButtonHav_16_11->x(), ui->ButtonHav_16_11->y());
ROPMove=std::make_pair(16,11);
    ui->ButtonHav_16_11->setIcon(ChangeIcon());
    ui->ButtonHav_16_11->move(x - 9, y - 8);
    ui->ButtonHav_16_11->setFixedSize(44, 44);
    ui->ButtonHav_16_11->setIconSize(QSize(44, 44));
    ui->ButtonHav_16_11->setEnabled(false);

    game.PlayerTurn(16, 11, playerCurrent);
    if (game.VerifyRules(16, 11))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_17_1_clicked()
{
    int x, y;
    x = ui->ButtonHav_17_1->x();
    y = ui->ButtonHav_17_1->y();

    CurrentMove = std::make_pair(ui->ButtonHav_17_1->x(), ui->ButtonHav_17_1->y());
ROPMove=std::make_pair(17,1);
    ui->ButtonHav_17_1->setIcon(ChangeIcon());
    ui->ButtonHav_17_1->move(x - 9, y - 8);
    ui->ButtonHav_17_1->setFixedSize(44, 44);
    ui->ButtonHav_17_1->setIconSize(QSize(44, 44));
    ui->ButtonHav_17_1->setEnabled(false);

    game.PlayerTurn(17, 1, playerCurrent);
    if (game.VerifyRules(17, 1))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_17_2_clicked()
{
    int x, y;
    x = ui->ButtonHav_17_2->x();
    y = ui->ButtonHav_17_2->y();

    CurrentMove = std::make_pair(ui->ButtonHav_17_2->x(), ui->ButtonHav_17_2->y());
ROPMove=std::make_pair(17,2);
    ui->ButtonHav_17_2->setIcon(ChangeIcon());
    ui->ButtonHav_17_2->move(x - 9, y - 8);
    ui->ButtonHav_17_2->setFixedSize(44, 44);
    ui->ButtonHav_17_2->setIconSize(QSize(44, 44));
    ui->ButtonHav_17_2->setEnabled(false);

    game.PlayerTurn(17, 2, playerCurrent);
    if (game.VerifyRules(17, 2))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_17_3_clicked()
{
    int x, y;
    x = ui->ButtonHav_17_3->x();
    y = ui->ButtonHav_17_3->y();

    CurrentMove = std::make_pair(ui->ButtonHav_17_3->x(), ui->ButtonHav_17_3->y());
ROPMove=std::make_pair(17,3);
    ui->ButtonHav_17_3->setIcon(ChangeIcon());
    ui->ButtonHav_17_3->move(x - 9, y - 8);
    ui->ButtonHav_17_3->setFixedSize(44, 44);
    ui->ButtonHav_17_3->setIconSize(QSize(44, 44));
    ui->ButtonHav_17_3->setEnabled(false);

    game.PlayerTurn(17, 3, playerCurrent);
    if (game.VerifyRules(17, 3))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_17_4_clicked()
{
    int x, y;
    x = ui->ButtonHav_17_4->x();
    y = ui->ButtonHav_17_4->y();

    CurrentMove = std::make_pair(ui->ButtonHav_17_4->x(), ui->ButtonHav_17_4->y());
ROPMove=std::make_pair(17,4);
    ui->ButtonHav_17_4->setIcon(ChangeIcon());
    ui->ButtonHav_17_4->move(x - 9, y - 8);
    ui->ButtonHav_17_4->setFixedSize(44, 44);
    ui->ButtonHav_17_4->setIconSize(QSize(44, 44));
    ui->ButtonHav_17_4->setEnabled(false);

    game.PlayerTurn(17, 4, playerCurrent);
    if (game.VerifyRules(17, 4))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_17_5_clicked()
{
    int x, y;
    x = ui->ButtonHav_17_5->x();
    y = ui->ButtonHav_17_5->y();

    CurrentMove = std::make_pair(ui->ButtonHav_17_5->x(), ui->ButtonHav_17_5->y());
ROPMove=std::make_pair(17,5);
    ui->ButtonHav_17_5->setIcon(ChangeIcon());
    ui->ButtonHav_17_5->move(x - 9, y - 8);
    ui->ButtonHav_17_5->setFixedSize(44, 44);
    ui->ButtonHav_17_5->setIconSize(QSize(44, 44));
    ui->ButtonHav_17_5->setEnabled(false);

    game.PlayerTurn(17, 5, playerCurrent);
    if (game.VerifyRules(17, 5))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_17_6_clicked()
{
    int x, y;
    x = ui->ButtonHav_17_6->x();
    y = ui->ButtonHav_17_6->y();

    CurrentMove = std::make_pair(ui->ButtonHav_17_6->x(), ui->ButtonHav_17_6->y());
ROPMove=std::make_pair(17,6);
    ui->ButtonHav_17_6->setIcon(ChangeIcon());
    ui->ButtonHav_17_6->move(x - 9, y - 8);
    ui->ButtonHav_17_6->setFixedSize(44, 44);
    ui->ButtonHav_17_6->setIconSize(QSize(44, 44));
    ui->ButtonHav_17_6->setEnabled(false);

    game.PlayerTurn(17, 6, playerCurrent);
    if (game.VerifyRules(17, 6))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_17_7_clicked()
{
    int x, y;
    x = ui->ButtonHav_17_7->x();
    y = ui->ButtonHav_17_7->y();

    CurrentMove = std::make_pair(ui->ButtonHav_17_7->x(), ui->ButtonHav_17_7->y());
ROPMove=std::make_pair(17,7);
    ui->ButtonHav_17_7->setIcon(ChangeIcon());
    ui->ButtonHav_17_7->move(x - 9, y - 8);
    ui->ButtonHav_17_7->setFixedSize(44, 44);
    ui->ButtonHav_17_7->setIconSize(QSize(44, 44));
    ui->ButtonHav_17_7->setEnabled(false);

    game.PlayerTurn(17, 7, playerCurrent);
    if (game.VerifyRules(17, 7))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_17_9_clicked()
{
    int x, y;
    x = ui->ButtonHav_17_9->x();
    y = ui->ButtonHav_17_9->y();

    CurrentMove = std::make_pair(ui->ButtonHav_17_9->x(), ui->ButtonHav_17_9->y());
ROPMove=std::make_pair(17,9);
    ui->ButtonHav_17_9->setIcon(ChangeIcon());
    ui->ButtonHav_17_9->move(x - 9, y - 8);
    ui->ButtonHav_17_9->setFixedSize(44, 44);
    ui->ButtonHav_17_9->setIconSize(QSize(44, 44));
    ui->ButtonHav_17_9->setEnabled(false);

    game.PlayerTurn(17, 9, playerCurrent);
    if (game.VerifyRules(17, 9))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_17_10_clicked()
{
    int x, y;
    x = ui->ButtonHav_17_10->x();
    y = ui->ButtonHav_17_10->y();

    CurrentMove = std::make_pair(ui->ButtonHav_17_10->x(), ui->ButtonHav_17_10->y());
ROPMove=std::make_pair(17,10);
    ui->ButtonHav_17_10->setIcon(ChangeIcon());
    ui->ButtonHav_17_10->move(x - 9, y - 8);
    ui->ButtonHav_17_10->setFixedSize(44, 44);
    ui->ButtonHav_17_10->setIconSize(QSize(44, 44));
    ui->ButtonHav_17_10->setEnabled(false);

    game.PlayerTurn(17, 10, playerCurrent);
    if (game.VerifyRules(17, 10))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_18_1_clicked()
{
    int x, y;
    x = ui->ButtonHav_18_1->x();
    y = ui->ButtonHav_18_1->y();

    CurrentMove = std::make_pair(ui->ButtonHav_18_1->x(), ui->ButtonHav_18_1->y());
ROPMove=std::make_pair(18,1);
    ui->ButtonHav_18_1->setIcon(ChangeIcon());
    ui->ButtonHav_18_1->move(x - 9, y - 8);
    ui->ButtonHav_18_1->setFixedSize(44, 44);
    ui->ButtonHav_18_1->setIconSize(QSize(44, 44));
    ui->ButtonHav_18_1->setEnabled(false);

    game.PlayerTurn(18, 1, playerCurrent);
    if (game.VerifyRules(18, 1))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_18_2_clicked()
{
    int x, y;
    x = ui->ButtonHav_18_2->x();
    y = ui->ButtonHav_18_2->y();

    CurrentMove = std::make_pair(ui->ButtonHav_18_2->x(), ui->ButtonHav_18_2->y());
ROPMove=std::make_pair(18,2);
    ui->ButtonHav_18_2->setIcon(ChangeIcon());
    ui->ButtonHav_18_2->move(x - 9, y - 8);
    ui->ButtonHav_18_2->setFixedSize(44, 44);
    ui->ButtonHav_18_2->setIconSize(QSize(44, 44));
    ui->ButtonHav_18_2->setEnabled(false);

    game.PlayerTurn(18, 2, playerCurrent);
    if (game.VerifyRules(18, 2))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_18_3_clicked()
{
    int x, y;
    x = ui->ButtonHav_18_3->x();
    y = ui->ButtonHav_18_3->y();

    CurrentMove = std::make_pair(ui->ButtonHav_18_3->x(), ui->ButtonHav_18_3->y());
ROPMove=std::make_pair(18,3);
    ui->ButtonHav_18_3->setIcon(ChangeIcon());
    ui->ButtonHav_18_3->move(x - 9, y - 8);
    ui->ButtonHav_18_3->setFixedSize(44, 44);
    ui->ButtonHav_18_3->setIconSize(QSize(44, 44));
    ui->ButtonHav_18_3->setEnabled(false);

    game.PlayerTurn(18, 3, playerCurrent);
    if (game.VerifyRules(18, 3))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_18_4_clicked()
{
    int x, y;
    x = ui->ButtonHav_18_4->x();
    y = ui->ButtonHav_18_4->y();

    CurrentMove = std::make_pair(ui->ButtonHav_18_4->x(), ui->ButtonHav_18_4->y());
ROPMove=std::make_pair(18,4);
    ui->ButtonHav_18_4->setIcon(ChangeIcon());
    ui->ButtonHav_18_4->move(x - 9, y - 8);
    ui->ButtonHav_18_4->setFixedSize(44, 44);
    ui->ButtonHav_18_4->setIconSize(QSize(44, 44));
    ui->ButtonHav_18_4->setEnabled(false);

    game.PlayerTurn(18, 4, playerCurrent);
    if (game.VerifyRules(18, 4))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_18_5_clicked()
{
    int x, y;
    x = ui->ButtonHav_18_5->x();
    y = ui->ButtonHav_18_5->y();

    CurrentMove = std::make_pair(ui->ButtonHav_18_5->x(), ui->ButtonHav_18_5->y());
ROPMove=std::make_pair(18,5);
    ui->ButtonHav_18_5->setIcon(ChangeIcon());
    ui->ButtonHav_18_5->move(x - 9, y - 8);
    ui->ButtonHav_18_5->setFixedSize(44, 44);
    ui->ButtonHav_18_5->setIconSize(QSize(44, 44));
    ui->ButtonHav_18_5->setEnabled(false);

    game.PlayerTurn(18, 5, playerCurrent);
    if (game.VerifyRules(18, 5))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_18_6_clicked()
{
    int x, y;
    x = ui->ButtonHav_18_6->x();
    y = ui->ButtonHav_18_6->y();

    CurrentMove = std::make_pair(ui->ButtonHav_18_6->x(), ui->ButtonHav_18_6->y());
ROPMove=std::make_pair(18,6);
    ui->ButtonHav_18_6->setIcon(ChangeIcon());
    ui->ButtonHav_18_6->move(x - 9, y - 8);
    ui->ButtonHav_18_6->setFixedSize(44, 44);
    ui->ButtonHav_18_6->setIconSize(QSize(44, 44));
    ui->ButtonHav_18_6->setEnabled(false);

    game.PlayerTurn(18, 6, playerCurrent);
    if (game.VerifyRules(18, 6))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_18_7_clicked()
{
    int x, y;
    x = ui->ButtonHav_18_7->x();
    y = ui->ButtonHav_18_7->y();

    CurrentMove = std::make_pair(ui->ButtonHav_18_7->x(), ui->ButtonHav_18_7->y());
ROPMove=std::make_pair(18,7);
    ui->ButtonHav_18_7->setIcon(ChangeIcon());
    ui->ButtonHav_18_7->move(x - 9, y - 8);
    ui->ButtonHav_18_7->setFixedSize(44, 44);
    ui->ButtonHav_18_7->setIconSize(QSize(44, 44));
    ui->ButtonHav_18_7->setEnabled(false);

    game.PlayerTurn(18, 7, playerCurrent);
    if (game.VerifyRules(18, 7))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_18_8_clicked()
{
    int x, y;
    x = ui->ButtonHav_18_8->x();
    y = ui->ButtonHav_18_8->y();

    CurrentMove = std::make_pair(ui->ButtonHav_18_8->x(), ui->ButtonHav_18_8->y());
ROPMove=std::make_pair(18,8);
    ui->ButtonHav_18_8->setIcon(ChangeIcon());
    ui->ButtonHav_18_8->move(x - 9, y - 8);
    ui->ButtonHav_18_8->setFixedSize(44, 44);
    ui->ButtonHav_18_8->setIconSize(QSize(44, 44));
    ui->ButtonHav_18_8->setEnabled(false);

    game.PlayerTurn(18, 8, playerCurrent);
    if (game.VerifyRules(18, 8))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_18_9_clicked()
{
    int x, y;
    x = ui->ButtonHav_18_9->x();
    y = ui->ButtonHav_18_9->y();

    CurrentMove = std::make_pair(ui->ButtonHav_18_9->x(), ui->ButtonHav_18_9->y());
ROPMove=std::make_pair(18,9);
    ui->ButtonHav_18_9->setIcon(ChangeIcon());
    ui->ButtonHav_18_9->move(x - 9, y - 8);
    ui->ButtonHav_18_9->setFixedSize(44, 44);
    ui->ButtonHav_18_9->setIconSize(QSize(44, 44));
    ui->ButtonHav_18_9->setEnabled(false);

    game.PlayerTurn(18, 9, playerCurrent);
    if (game.VerifyRules(18, 9))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_0_4_clicked()
{
    int x, y;
    x = ui->ButtonHav_0_3->x();
    y = ui->ButtonHav_0_3->y();

    CurrentMove = std::make_pair(ui->ButtonHav_0_3->x(), ui->ButtonHav_0_3->y());
ROPMove=std::make_pair(0,4);
    ui->ButtonHav_0_3->setIcon(ChangeIcon());
    ui->ButtonHav_0_3->move(x - 9, y - 8);
    ui->ButtonHav_0_3->setFixedSize(44, 44);
    ui->ButtonHav_0_3->setIconSize(QSize(44, 44));
    ui->ButtonHav_0_3->setEnabled(false);

    game.PlayerTurn(0, 3, playerCurrent);
    if (game.VerifyRules(0, 3))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_14_0_clicked()
{
    int x, y;
    x = ui->ButtonHav_14_0->x();
    y = ui->ButtonHav_14_0->y();

    CurrentMove = std::make_pair(ui->ButtonHav_14_0->x(), ui->ButtonHav_14_0->y());
ROPMove=std::make_pair(14,0);
    ui->ButtonHav_14_0->setIcon(ChangeIcon());
    ui->ButtonHav_14_0->move(x - 9, y - 8);
    ui->ButtonHav_14_0->setFixedSize(44, 44);
    ui->ButtonHav_14_0->setIconSize(QSize(44, 44));
    ui->ButtonHav_14_0->setEnabled(false);

    game.PlayerTurn(14, 0, playerCurrent);
    if (game.VerifyRules(14, 0))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_15_0_clicked()
{
    int x, y;
    x = ui->ButtonHav_15_0->x();
    y = ui->ButtonHav_15_0->y();

    CurrentMove = std::make_pair(ui->ButtonHav_15_0->x(), ui->ButtonHav_15_0->y());
ROPMove=std::make_pair(15,0);
    ui->ButtonHav_15_0->setIcon(ChangeIcon());
    ui->ButtonHav_15_0->move(x - 9, y - 8);
    ui->ButtonHav_15_0->setFixedSize(44, 44);
    ui->ButtonHav_15_0->setIconSize(QSize(44, 44));
    ui->ButtonHav_15_0->setEnabled(false);

    game.PlayerTurn(15, 0, playerCurrent);
    if (game.VerifyRules(15, 0))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_16_0_clicked()
{
    int x, y;
    x = ui->ButtonHav_16_0->x();
    y = ui->ButtonHav_16_0->y();

    CurrentMove = std::make_pair(ui->ButtonHav_16_0->x(), ui->ButtonHav_16_0->y());
ROPMove=std::make_pair(16,0);
    ui->ButtonHav_16_0->setIcon(ChangeIcon());
    ui->ButtonHav_16_0->move(x - 9, y - 8);
    ui->ButtonHav_16_0->setFixedSize(44, 44);
    ui->ButtonHav_16_0->setIconSize(QSize(44, 44));
    ui->ButtonHav_16_0->setEnabled(false);

    game.PlayerTurn(18, 0, playerCurrent);
    if (game.VerifyRules(18, 0))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_17_0_clicked()
{
    int x, y;
    x = ui->ButtonHav_17_0->x();
    y = ui->ButtonHav_17_0->y();

    CurrentMove = std::make_pair(ui->ButtonHav_17_0->x(), ui->ButtonHav_17_0->y());
ROPMove=std::make_pair(17,0);
    ui->ButtonHav_17_0->setIcon(ChangeIcon());
    ui->ButtonHav_17_0->move(x - 9, y - 8);
    ui->ButtonHav_17_0->setFixedSize(44, 44);
    ui->ButtonHav_17_0->setIconSize(QSize(44, 44));
    ui->ButtonHav_17_0->setEnabled(false);

    game.PlayerTurn(17, 0, playerCurrent);
    if (game.VerifyRules(17, 0))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_18_0_clicked()
{
    int x, y;
    x = ui->ButtonHav_18_0->x();
    y = ui->ButtonHav_18_0->y();

    CurrentMove = std::make_pair(ui->ButtonHav_18_0->x(), ui->ButtonHav_18_0->y());
ROPMove=std::make_pair(18,0);
    ui->ButtonHav_18_0->setIcon(ChangeIcon());
    ui->ButtonHav_18_0->move(x - 9, y - 8);
    ui->ButtonHav_18_0->setFixedSize(44, 44);
    ui->ButtonHav_18_0->setIconSize(QSize(44, 44));
    ui->ButtonHav_18_0->setEnabled(false);

    game.PlayerTurn(18, 0, playerCurrent);
    if (game.VerifyRules(18, 0))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}

void HavannahUI::on_ButtonHav_17_8_clicked()
{
    int x, y;
    x = ui->ButtonHav_17_8->x();
    y = ui->ButtonHav_17_8->y();

    CurrentMove = std::make_pair(ui->ButtonHav_17_8->x(), ui->ButtonHav_17_8->y());
ROPMove=std::make_pair(17,8);
    ui->ButtonHav_0_3->setIcon(ChangeIcon());
    ui->ButtonHav_0_3->move(x - 9, y - 8);
    ui->ButtonHav_0_3->setFixedSize(44, 44);
    ui->ButtonHav_0_3->setIconSize(QSize(44, 44));
    ui->ButtonHav_0_3->setEnabled(false);

    game.PlayerTurn(17, 8, playerCurrent);
    if (game.VerifyRules(17, 8))
    {
        ui->Winner->setText(playerCurrent.GetName()+" a castigat"); ui->stackedWidget->setCurrentIndex(2);
    }

    ChangeTurn();
}


void HavannahUI::on_DaRop_clicked()
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

void HavannahUI::on_NuROP_clicked()
{
    ui->DaRop->setVisible(false);
    ui->NuROP->setVisible(false);
    ui->IntrebareROP->setVisible(false);
    ui->stackedWidget->setCurrentIndex(1);
}
