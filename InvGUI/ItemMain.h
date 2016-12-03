#pragma once

#include <QWidget>
#include "ui_ItemMain.h"

#include "p3mod.h"
#include "itemdeletionprompt.h"

class P3mod;
class ItemMain : public QWidget
{
	Q_OBJECT

public:
	ItemMain(QWidget *parent = Q_NULLPTR);
	~ItemMain();

	P3mod *p3mod;
	ItemDeletionPrompt *deletePrompt;

private slots:
	void AddItemButtonClicked();
    void on_AddItemButton_clicked();
    void on_ModifySelectedItemButton_clicked();
    void on_DeleteSelectedItemButton_clicked();
	void LoadItemMainPage(bool changeMade);
	void ResetTable();

public slots:
	void cellClicked();

private:
	Ui::ItemMain ui;
	

signals:
	void ChangePageToAddItem();
	void ChangePageToModifySelectedItem(QModelIndexList);
	void ChangePageToDeleteSelectedItem(const int ID);
};
