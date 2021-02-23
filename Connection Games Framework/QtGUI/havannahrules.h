#ifndef HAVANNAHRULES_H
#define HAVANNAHRULES_H

#include <QFrame>

namespace Ui {
class HavannahRules;
}

class HavannahRules : public QFrame
{
    Q_OBJECT

public:
    explicit HavannahRules(QWidget *parent = nullptr);
    ~HavannahRules();

private slots:
    void on_Back_clicked();

private:
    Ui::HavannahRules *ui;
};

#endif // HAVANNAHRULES_H
