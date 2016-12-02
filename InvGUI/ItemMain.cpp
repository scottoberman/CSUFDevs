#include "ItemMain.h"
#include "ims.h"

ItemMain::ItemMain(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	
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

	// If a cell is clicked, activate the buttons to allow item modification and deletion
	connect(ui.tableWidget, &QTableWidget::cellClicked,
			this, &ItemMain::cellClicked);

	// Disable the buttons that control item deletion and modification.
	// This prevents trying to modify/delete when nothing is selected.
	ui.DeleteSelectedItemButton->setDisabled(true);
	ui.ModifySelectedItemButton->setDisabled(true);
}

ItemMain::~ItemMain()
{
}

void ItemMain::on_AddItemButton_clicked()
{
	emit ChangePageToAddItem();
}

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
	emit ChangePageToDeleteSelectedItem();
}

void ItemMain::cellClicked()
{
	ui.DeleteSelectedItemButton->setDisabled(false);
	ui.ModifySelectedItemButton->setDisabled(false);
}
