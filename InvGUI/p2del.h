#ifndef P2DEL_H
#define P2DEL_H

#include <QWidget>

namespace Ui {
class P2del;
}

class P2del : public QWidget
{
    Q_OBJECT

public:
    explicit P2del(QWidget *parent = 0);
    ~P2del();

private slots:
    void on_pushButton_clicked();

private:
    Ui::P2del *ui;
};

#endif // P2DEL_H
