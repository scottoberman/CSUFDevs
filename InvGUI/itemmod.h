#ifndef ItemMod_H
#define ItemMod_H

#include <QWidget>
#include "invmain.h"

namespace Ui {
class ItemMod;
}

class ItemMod : public QWidget
{
    Q_OBJECT

public:
    explicit ItemMod(QWidget *parent = 0);
    ~ItemMod();

private slots:
    //void on_pushButton_clicked();

public slots :
	void AddItemClicked();
	void ModifySelectedItemClicked(QModelIndexList);
	void CancelButtonPressed();
	void SubmitButtonPressed();

signals:
	void ReturnToItemMain(bool changeMade);

private:
    Ui::ItemMod *ui;

	// Item Modes
	// 0: Add
	// 1: Modify
	int itemMode;
};

#endif // ItemMod_H
