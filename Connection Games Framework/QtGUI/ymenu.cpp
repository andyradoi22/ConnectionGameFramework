#include "ymenu.h"
#include "ui_ymenu.h"
#include "mainmenu.h"
#include "yui.h"
#include "yrules.h"

YMenu::YMenu(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::YMenu)
{
    ui->setupUi(this);
    QPixmap bkgd("../GUI pictures/MenuBackground.jpg");
           bkgd=bkgd.scaled(this->size(),Qt::IgnoreAspectRatio);
           QPalette palette;
           palette.setBrush(QPalette::Background, bkgd);
           this->setPalette(palette);
}

YMenu::~YMenu()
{
    delete ui;
}

void YMenu::on_YPlayButton_clicked()
{
   YUI *y_ui = new YUI;
    y_ui->setVisible(true);
    close();
}

void YMenu::on_YRulesButton_clicked()
{
    YRules *rules=new YRules;
    rules->show();
    rules->setVisible(true);
    close();
}

void YMenu::on_YBackButton_clicked()
{
    MainMenu *menu = new MainMenu;
    menu->show();
    menu->setVisible(true);
    close();
}
