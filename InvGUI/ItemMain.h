#pragma once

#include <QWidget>
#include "ui_ItemMain.h"

class ItemMain : public QWidget
{
	Q_OBJECT

public:
	ItemMain(QWidget *parent = Q_NULLPTR);
	~ItemMain();

private:
	Ui::ItemMain ui;
};
