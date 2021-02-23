#include "hexrules.h"
#include "ui_hexrules.h"
#include "hexmenu.h"

HexRules::HexRules(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::HexRules)
{
    ui->setupUi(this);
    QPixmap bkgd("../GUI pictures/HexRules.jpg");
           bkgd=bkgd.scaled(this->size(),Qt::IgnoreAspectRatio);
           QPalette palette;
           palette.setBrush(QPalette::Background, bkgd);
           this->setPalette(palette);

}

HexRules::~HexRules()
{
    delete ui;
}


void HexRules::on_Back_clicked()
{
    HexMenu *menu=new HexMenu;
        menu->show();
        menu->setVisible(true);
        close();
}
