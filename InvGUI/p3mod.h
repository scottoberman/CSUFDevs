#ifndef P3MOD_H
#define P3MOD_H

#include <QWidget>

namespace Ui {
class P3mod;
}

class P3mod : public QWidget
{
    Q_OBJECT

public:
    explicit P3mod(QWidget *parent = 0);
    ~P3mod();

private slots:
    void on_pushButton_clicked();

private:
    Ui::P3mod *ui;
};

#endif // P3MOD_H
