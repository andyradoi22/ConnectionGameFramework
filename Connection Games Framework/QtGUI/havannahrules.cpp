#include "havannahrules.h"
#include "ui_havannahrules.h"
#include "havannahmenu.h"

HavannahRules::HavannahRules(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::HavannahRules)
{
    ui->setupUi(this);
    QPixmap bkgd("../GUI pictures/HavannahRules.jpg");
           bkgd=bkgd.scaled(this->size(),Qt::IgnoreAspectRatio);
           QPalette palette;
           palette.setBrush(QPalette::Background, bkgd);
           this->setPalette(palette);
}

HavannahRules::~HavannahRules()
{
    delete ui;
}

void HavannahRules::on_Back_clicked()
{
    HavannahMenu *menu=new HavannahMenu;
        menu->show();
        menu->setVisible(true);
        close();
}
