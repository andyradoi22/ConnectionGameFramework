#ifndef YMENU_H
#define YMENU_H

#include <QFrame>

namespace Ui {
class YMenu;
}

class YMenu : public QFrame
{
    Q_OBJECT

public:
    explicit YMenu(QWidget *parent = nullptr);
    ~YMenu();

private slots:
    void on_YPlayButton_clicked();

    void on_YRulesButton_clicked();

    void on_YBackButton_clicked();

private:
    Ui::YMenu *ui;
};

#endif // YMENU_H
