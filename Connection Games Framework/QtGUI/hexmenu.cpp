#include "hexmenu.h"
#include "ui_hexmenu.h"
#include "mainmenu.h"
#include "hexrules.h"
#include "hexui.h"

HexMenu::HexMenu(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::HexMenu)
{
    ui->setupUi(this);
    QPixmap bkgd("../GUI pictures/MenuBackground.jpg");
           bkgd=bkgd.scaled(this->size(),Qt::IgnoreAspectRatio);
           QPalette palette;
           palette.setBrush(QPalette::Background, bkgd);
           this->setPalette(palette);
}

HexMenu::~HexMenu()
{
    delete ui;
}

void HexMenu::on_HexPlayButton_clicked()
{
    HexUI *hex_ui = new HexUI;
    hex_ui->setVisible(true);
    close();
}

void HexMenu::on_HexRulesButton_clicked()
{
    HexRules *rules=new HexRules;
    rules->show();
    rules->setVisible(true);
    close();
}

void HexMenu::on_HexBackButton_clicked()
{
    MainMenu *menu = new MainMenu;
    menu->show();
    menu->setVisible(true);
    close();
}
