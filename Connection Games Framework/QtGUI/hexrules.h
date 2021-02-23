#ifndef HEXRULES_H
#define HEXRULES_H

#include <QFrame>

namespace Ui {
class HexRules;
}

class HexRules : public QFrame
{
    Q_OBJECT

public:
    explicit HexRules(QWidget *parent = nullptr);
    ~HexRules();

private slots:
    void on_Back_clicked();

private:
    Ui::HexRules *ui;
};

#endif // HEXRULES_H
