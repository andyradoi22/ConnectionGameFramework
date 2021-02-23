#ifndef HAVANNAHMENU_H
#define HAVANNAHMENU_H

#include <QFrame>

namespace Ui {
class HavannahMenu;
}

class HavannahMenu : public QFrame
{
    Q_OBJECT

public:
    explicit HavannahMenu(QWidget *parent = nullptr);
    ~HavannahMenu();

private slots:
    void on_HavPlayButton_clicked();

    void on_HavRulesButton_clicked();

    void on_HavBackButton_clicked();

private:
    Ui::HavannahMenu *ui;
};

#endif // HAVANNAHMENU_H
