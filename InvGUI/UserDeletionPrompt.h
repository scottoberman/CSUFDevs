#pragma once

#include <QWidget>
#include "ui_UserDeletionPrompt.h"

#include "UserMain.h"

// Class prototype to deal with circular dependency (might not be any but ok)
class UserMain;

class UserDeletionPrompt : public QWidget
{
	Q_OBJECT

public:
	UserDeletionPrompt(QWidget *parent = Q_NULLPTR);
	~UserDeletionPrompt();

public slots:
	void SetDeleteUserPrompt(const int ID);

private slots:
	void DeleteUser();

signals:
	void UserDeleted(bool deleted);

private:
	Ui::UserDeletionPrompt ui;

	int idToDelete;
};
