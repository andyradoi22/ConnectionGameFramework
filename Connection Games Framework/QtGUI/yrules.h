#ifndef YRULES_H
#define YRULES_H

#include <QFrame>

namespace Ui {
class YRules;
}

class YRules : public QFrame
{
    Q_OBJECT

public:
    explicit YRules(QWidget *parent = nullptr);
    ~YRules();

private slots:
    void on_Back_clicked();

private:
    Ui::YRules *ui;
};

#endif // YRULES_H
