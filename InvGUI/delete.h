#ifndef DEL_H
#define DEL_H

#include <QWidget>

namespace Ui {
class Del;
}

class Del : public QWidget
{
    Q_OBJECT

public:
    explicit Del(QWidget *parent = 0);
    ~Del();

private:
    Ui::Del *ui;
};

#endif // DEL_H
