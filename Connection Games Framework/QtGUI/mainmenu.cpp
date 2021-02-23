#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    QPixmap bkgd("../GUI pictures/MenuBackground.jpg");
           bkgd=bkgd.scaled(this->size(),Qt::IgnoreAspectRatio);
           QPalette palette;
           palette.setBrush(QPalette::Background, bkgd);
           this->setPalette(palette);
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_YButton_clicked()
{
    YMenu* Y=new YMenu;
      Y->show();
      close();
      Y->setAttribute(Qt::WA_DeleteOnClose);
}

void MainMenu::on_HexButton_clicked()
{
    HexMenu* Hex=new HexMenu;
        Hex->show();
        close();
}

void MainMenu::on_HavannahButton_clicked()
{
    HavannahMenu* Havannah=new HavannahMenu;
       Havannah->show();
        close();
}

void MainMenu::on_ExitButton_clicked()
{
    QApplication::exit();
}


