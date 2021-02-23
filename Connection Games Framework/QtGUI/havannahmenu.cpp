#include "havannahmenu.h"
#include "ui_havannahmenu.h"
#include "mainmenu.h"
#include "havannahui.h"
#include "havannahrules.h"

HavannahMenu::HavannahMenu(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::HavannahMenu)
{
    ui->setupUi(this);
    QPixmap bkgd("../GUI pictures/MenuBackground.jpg");
           bkgd=bkgd.scaled(this->size(),Qt::IgnoreAspectRatio);
           QPalette palette;
           palette.setBrush(QPalette::Background, bkgd);
           this->setPalette(palette);
}

HavannahMenu::~HavannahMenu()
{
    delete ui;
}

void HavannahMenu::on_HavPlayButton_clicked()
{
    HavannahUI *havannah_ui = new HavannahUI;
    havannah_ui->setVisible(true);
    close();
}

void HavannahMenu::on_HavRulesButton_clicked()
{
    HavannahRules *rules=new HavannahRules;
    rules->show();
    rules->setVisible(true);
    close();
}


void HavannahMenu::on_HavBackButton_clicked()
{
    MainMenu *menu = new MainMenu;
    menu->show();
    menu->setVisible(true);
    close();
}
