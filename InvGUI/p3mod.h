#ifndef P3MOD_H
#define P3MOD_H

#include <QWidget>
#include "invmain.h"

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
    //void on_pushButton_clicked();

public slots:
	void ModifySelectedItemClicked(QModelIndexList);
	void CancelButtonPressed();
	void SubmitButtonPressed();

signals:
	void ReturnToItemMain(bool changeMade);

private:
    Ui::P3mod *ui;
};

#endif // P3MOD_H
