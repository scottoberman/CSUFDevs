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

public slots:
	void CellClicked();

private slots:
	void AddItemButtonClicked();
    void on_AddItemButton_clicked();
    void on_ModifySelectedItemButton_clicked();
    void on_DeleteSelectedItemButton_clicked();
	void LoadItemMainPage(bool changeMade);
	void ResetTable();

signals:
	void ChangePageToAddItem();
	void ChangePageToModifySelectedItem(QModelIndexList itemRow);
	void ChangePageToDeleteSelectedItem(const int ID);

private:
	Ui::ItemMain ui;

	ItemMod *itemMod;
	ItemDeletionPrompt *deletePrompt;
	SearchItem *searchItem;
};
