#ifndef P5EXTRA_H
#define P5EXTRA_H

#include <QWidget>

namespace Ui {
class P5extra;
}

class P5extra : public QWidget
{
    Q_OBJECT

public:
    explicit P5extra(QWidget *parent = 0);
    ~P5extra();

private slots:
    void on_pushButton_clicked();

private:
    Ui::P5extra *ui;
};

#endif // P5EXTRA_H
