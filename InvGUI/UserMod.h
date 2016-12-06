#pragma once

#include <QWidget>
#include "ui_UserMod.h"


class UserMod : public QWidget
{
	Q_OBJECT

public:
	UserMod(QWidget *parent = Q_NULLPTR);
	~UserMod();

public slots:
	void ShowAddPage();
	void ShowModPage(QModelIndexList row);

private slots:
	void SubmitButtonClicked();

signals:
	void ReturnToUserMain(bool changeMade);

private:
	Ui::UserMod ui;
	int userMode;
};
