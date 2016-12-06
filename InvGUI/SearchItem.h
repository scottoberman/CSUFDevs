#ifndef SearchItem_H
#define SearchItem_H

#include <QWidget>

namespace Ui {
class SearchItem;
}

class SearchItem : public QWidget
{
    Q_OBJECT

public:
    explicit SearchItem(QWidget *parent = 0);
    ~SearchItem();

public slots:
	void LoadSearchItem();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SearchItem *ui;
};

#endif // SearchItem_H
