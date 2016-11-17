#ifndef PRINT_H
#define PRINT_H

#include <QWidget>

namespace Ui {
class print;
}

class print : public QWidget
{
    Q_OBJECT

public:
    explicit print(QWidget *parent = 0);
    ~print();

private:
    Ui::print *ui;
};

#endif // PRINT_H
