#pragma once

#include <QWidget>
#include "ui_UserMain.h"

#include "UserMod.h"
#include "UserDeletionPrompt.h"

// Class prototype for cyclical dependency
class UserMod;
class UserDeletionPrompt;

class UserMain : public QWidget
{
	Q_OBJECT

public:
	UserMain(QWidget *parent = Q_NULLPTR);
	~UserMain();

private slots:
	void ResetTable();
	void CellClicked();
	void LoadUserMain(bool changeMade);
	void DeleteSelectedUserButtonClicked();
	void ModifySelectedUserButtonClicked();

private:
	Ui::UserMain ui;

	UserMod *userMod;
	UserDeletionPrompt *deletePrompt;

signals:
	void ChangePageToDeleteSelectedUser(const int ID);
	void ChangePageToModifySelectedUser(QModelIndexList row);
};
