#include "yrules.h"
#include "ui_yrules.h"
#include "ymenu.h"

YRules::YRules(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::YRules)
{
    ui->setupUi(this);
    QPixmap bkgd("../GUI pictures/YRules.jpg");
          bkgd=bkgd.scaled(this->size(),Qt::IgnoreAspectRatio);
          QPalette palette;
          palette.setBrush(QPalette::Background, bkgd);
          this->setPalette(palette);
}

YRules::~YRules()
{
    delete ui;
}

void YRules::on_Back_clicked()
{
    YMenu *menu=new YMenu;
        menu->show();
        menu->setVisible(true);
        close();
}
