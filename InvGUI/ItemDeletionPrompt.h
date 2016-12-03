#pragma once

#include <QWidget>
#include "ui_ItemDeletionPrompt.h"

#include "ims.h"

class ItemDeletionPrompt : public QWidget
{
	Q_OBJECT

public:
	ItemDeletionPrompt(QWidget *parent = Q_NULLPTR);
	~ItemDeletionPrompt();

private:
	Ui::ItemDeletionPrompt ui;

	int idToDelete;

public slots:
	void SetDeleteItemPrompt(const int ID);
	void DeleteItem();

signals:
	void ItemDeleted(bool deleted);
};
