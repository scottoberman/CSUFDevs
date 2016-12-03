#include "ItemMain.h"
#include "ims.h"

ItemMain::ItemMain(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	p3mod = new P3mod();

	deletePrompt = new ItemDeletionPrompt();
	
	ResetTable();

	// If a cell is clicked, activate the buttons to allow item modification and deletion
	connect(ui.tableWidget, &QTableWidget::cellClicked,
			this, &ItemMain::cellClicked);

	// If the table was modified, reload the table and reload the state of itemmain.
	connect(p3mod, &P3mod::ReturnToItemMain,
			this, &ItemMain::LoadItemMainPage);

	// If the delete item button was clicked open the deletion prompt
	connect(this, &ItemMain::ChangePageToDeleteSelectedItem,
			deletePrompt, &ItemDeletionPrompt::SetDeleteItemPrompt);

	// If a row was deleted, reload the table and relate the state of itemman.
	connect(deletePrompt, &ItemDeletionPrompt::ItemDeleted,
			this, &ItemMain::LoadItemMainPage);

	// If the user clicks the add item button, open the add item window
	// (which is the same as the modify item window, there can be a
	// unification of their signal-slot relationships probably).
	connect(ui.AddItemButton, &QPushButton::clicked,
			this, &ItemMain::AddItemButtonClicked);
	connect(this, &ItemMain::ChangePageToAddItem,
			p3mod, &P3mod::AddItemClicked);

}

ItemMain::~ItemMain()
{
}

void ItemMain::AddItemButtonClicked()
{
	emit ChangePageToAddItem();
}


void ItemMain::on_AddItemButton_clicked()
{
	emit ChangePageToAddItem();
}

// Uses QT creator method of signaling
void ItemMain::on_ModifySelectedItemButton_clicked()
{
	qDebug() << "how many rows/cols/indices are selected?";
	qDebug() << ui.tableWidget->selectionModel()->selectedRows().size();
	qDebug() << ui.tableWidget->selectionModel()->selectedColumns().size();
	qDebug() << ui.tableWidget->selectionModel()->selectedIndexes().size();

	emit ChangePageToModifySelectedItem(ui.tableWidget->selectionModel()->selectedIndexes());
}

void ItemMain::on_DeleteSelectedItemButton_clicked()
{
	emit ChangePageToDeleteSelectedItem(ui.tableWidget->selectionModel()->selectedIndexes().at(0).data().toInt());
}

void ItemMain::cellClicked()
{
	ui.DeleteSelectedItemButton->setDisabled(false);
	ui.ModifySelectedItemButton->setDisabled(false);
}

void ItemMain::LoadItemMainPage(bool changeMade)
{
	// If the item table was altered, reload the
	// table to reflect these changes.
	if (changeMade)
	{
		qDebug() << "Item being modified from table...";

		ResetTable();
	}
	else
	{
		qDebug() << "No modification to table detected...";
	}

	qDebug() << "Returning to item main...";
}

void ItemMain::ResetTable()
{
	// Ensure that the table is empty
	ui.tableWidget->setRowCount(0);

	// This column is made extra long for the "item description"
	ui.tableWidget->setColumnWidth(5, 544);

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

	// Populate the table with items from the database.
	db.print_items_to_table(ui.tableWidget);

	// Disable the buttons that control item deletion and modification.
	// This prevents trying to modify/delete when nothing is selected.
	ui.DeleteSelectedItemButton->setDisabled(true);
	ui.ModifySelectedItemButton->setDisabled(true);
}