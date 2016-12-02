#pragma once

#include <QWidget>
#include "ui_ItemMain.h"

class ItemMain : public QWidget
{
	Q_OBJECT

public:
	ItemMain(QWidget *parent = Q_NULLPTR);
	~ItemMain();

private slots:
    void on_AddItemButton_clicked();
    void on_ModifySelectedItemButton_clicked();
    void on_DeleteSelectedItemButton_clicked();

public slots:
	void cellClicked();

private:
	Ui::ItemMain ui;

signals:
	void ChangePageToAddItem();
	void ChangePageToModifySelectedItem(QModelIndexList);
	void ChangePageToDeleteSelectedItem();
};
