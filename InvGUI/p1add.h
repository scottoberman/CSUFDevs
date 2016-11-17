#ifndef P1ADD_H
#define P1ADD_H

#include <QWidget>

namespace Ui {
class P1add;
}

class P1add : public QWidget
{
    Q_OBJECT

public:
    explicit P1add(QWidget *parent = 0);
    ~P1add();

private slots:
    void on_pushButton_clicked();

private:
    Ui::P1add *ui;
};

#endif // P1ADD_H
