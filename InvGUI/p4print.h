#ifndef P4PRINT_H
#define P4PRINT_H

#include <QWidget>

namespace Ui {
class P4print;
}

class P4print : public QWidget
{
    Q_OBJECT

public:
    explicit P4print(QWidget *parent = 0);
    ~P4print();

private slots:
    void on_pushButton_clicked();

private:
    Ui::P4print *ui;
};

#endif // P4PRINT_H
