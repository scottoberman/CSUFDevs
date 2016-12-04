#include "UserMain.h"
#include "ims.h"

UserMain::UserMain(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	userMod = new UserMod();
	deletePrompt = new UserDeletionPrompt();

	ResetTable();

	// If a cell is clicked, activate the buttons to allow item modification and deletion
	connect(ui.tableWidget, &QTableWidget::cellClicked,
			this, &UserMain::CellClicked);

	// If the table was modified, reload the table and reload the state of itemmain.
	connect(userMod, &UserMod::ReturnToUserMain,
			this, &UserMain::LoadUserMain);

	// If the delete item button was clicked open the deletion prompt
	connect(ui.DeleteSelectedUserButton, &QPushButton::clicked,
			this, &UserMain::DeleteSelectedUserButtonClicked);
	connect(this, &UserMain::ChangePageToDeleteSelectedUser,
			deletePrompt, &UserDeletionPrompt::SetDeleteUserPrompt);

	// If a row was deleted, reload the table and relate the state of itemman.
	connect(deletePrompt, &UserDeletionPrompt::UserDeleted,
			this, &UserMain::LoadUserMain);

	// If the user clicks the add user button, open the add user window.
	connect(ui.AddUserButton, &QPushButton::clicked,
			userMod, &UserMod::ShowAddPage);

	// If the user clicks the modify user window, open the modify user window.
	connect(ui.ModifySelectedUserButton, &QPushButton::clicked,
			this, &UserMain::ModifySelectedUserButtonClicked);
	connect(this, &UserMain::ChangePageToModifySelectedUser,
			userMod, &UserMod::ShowModPage);

	// If the user submits a user to be added, check
	// if the table will be updated
	connect(userMod, &UserMod::ReturnToUserMain,
		this, &UserMain::LoadUserMain);
}

UserMain::~UserMain()
{
}

void UserMain::ResetTable()
{
	// Ensure that the table is empty
	ui.tableWidget->setRowCount(0);

	// Only rows can be selected from the table.
	ui.tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

	// Only one row can be selected from the table.
	ui.tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);

	// Disable the ability to edit elements of the table.
	ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

	// Allow the table to be sorted
	ui.tableWidget->setSortingEnabled(true);

	// Set the number of columns in the table.
	ui.tableWidget->setColumnCount(6);

	// Populate the table with users from the database.
	db.print_users_to_table(ui.tableWidget);

	// Disable the buttons that control user deletion and modification.
	// This prevents trying to modify/delete when nothing is selected.
	ui.DeleteSelectedUserButton->setDisabled(true);
	ui.ModifySelectedUserButton->setDisabled(true);
}

void UserMain::CellClicked()
{
	ui.DeleteSelectedUserButton->setDisabled(false);
	ui.ModifySelectedUserButton->setDisabled(false);
}

void UserMain::LoadUserMain(bool changeMade)
{
	if (changeMade)
	{
		ResetTable();
	}
	else
	{

	}

}

void UserMain::DeleteSelectedUserButtonClicked()
{
	emit ChangePageToDeleteSelectedUser(ui.tableWidget->selectionModel()->selectedIndexes().at(0).data().toInt());
}

void UserMain::ModifySelectedUserButtonClicked()
{
	emit ChangePageToModifySelectedUser(ui.tableWidget->selectionModel()->selectedIndexes());
}