#include "ItemMain.h"
#include "ims.h"

ItemMain::ItemMain(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	
	// This column is made extra long for the "item description"
	ui.tableWidget->setColumnWidth(4, 500);

	// Only rows can be selected from the table.
	//ui.tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

	// Only one row can be selected from the table.
	ui.tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);

	// Disable the ability to edit elements of the table.
	ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

	ui.tableWidget->setSortingEnabled(true);
	

	ui.tableWidget->setColumnCount(5);
	ui.tableWidget->setRowCount(500);

	db.print_items_to_table(ui.tableWidget);
}

ItemMain::~ItemMain()
{
}
