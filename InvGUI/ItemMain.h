#pragma once

#include <QWidget>
#include "ui_ItemMain.h"

#include "ItemMod.h"
#include "itemdeletionprompt.h"
#include "SearchItem.h"

class ItemMod;
class ItemMain : public QWidget
{
	Q_OBJECT

public:
	ItemMain(QWidget *parent = Q_NULLPTR);
	~ItemMain();

	ItemMod *itemMod;
	ItemDeletionPrompt *deletePrompt;
	SearchItem *searchItem;

private slots:
	void AddItemButtonClicked();
    void on_AddItemButton_clicked();
    void on_ModifySelectedItemButton_clicked();
    void on_DeleteSelectedItemButton_clicked();
	void LoadItemMainPage(bool changeMade);
	void ResetTable();

public slots:
	void CellClicked();

private:
	Ui::ItemMain ui;
	

signals:
	void ChangePageToAddItem();
	void ChangePageToModifySelectedItem(QModelIndexList);
	void ChangePageToDeleteSelectedItem(const int ID);
};
