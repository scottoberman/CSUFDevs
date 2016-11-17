#ifndef EXTRA_H
#define EXTRA_H

#include <QWidget>

namespace Ui {
class extra;
}

class extra : public QWidget
{
    Q_OBJECT

public:
    explicit extra(QWidget *parent = 0);
    ~extra();

private:
    Ui::extra *ui;
};

#endif // EXTRA_H
