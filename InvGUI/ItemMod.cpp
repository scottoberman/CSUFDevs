#include "ItemMod.h"
#include "ui_ItemMod.h"
#include "ims.h"

ItemMod::ItemMod(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ItemMod)
{
    ui->setupUi(this);
	
	// The id input is disabled and invisible since the
	// only real need for the id is to find the item
	// to update in the SQL table when a modification
	// is made.
	ui->IdInput->setVisible(false);
}

ItemMod::~ItemMod()
{
    delete ui;
}

void ItemMod::AddItemClicked()
{
	// ItemMode 0: Item is being added NOT modified
	itemMode = 0;

	// Populate combo box of unique item makes
	map<string, string> makes;
	map<string, string>::const_iterator makesIter;
	db.get_map_of_unique_makes(makes);

	// Make sure the combobox is empty
	// (Prevents duplicate makes on repeated executions.
	ui->comboBox->clear();

	makesIter = makes.begin();
	while (makesIter != makes.end())
	{
		ui->comboBox->insertItem(0, QString::fromStdString(makesIter->first));
		makesIter++;
	}

	// Ensure all input boxes are empty
	ui->NameInput->clear();
	ui->MakeInput->clear();
	ui->PriceInput->clear();
	ui->QuantityInput->clear();
	ui->DescriptionInput->clear();

	show();
}

void ItemMod::ModifySelectedItemClicked(QModelIndexList itemRow)
{
	// ItemMode 1: Item is being modified NOT added
	itemMode = 1;

	// Populate combo box of unique item makes
	map<string, string> makes;
	map<string, string>::const_iterator makesIter;
	db.get_map_of_unique_makes(makes);

	// Make sure the combobox is empty
	// (Prevents duplicate makes on repeated executions.
	ui->comboBox->clear();

	makesIter = makes.begin();
	while (makesIter != makes.end())
	{
		ui->comboBox->insertItem(0, QString::fromStdString(makesIter->first));
		makesIter++;
	}
	
	// Populate line edits with the old information of the item
	// being modified
	ui->IdInput->setText(itemRow.at(0).data().toString());
	ui->NameInput->setText(itemRow.at(1).data().toString());
	ui->MakeInput->setText(itemRow.at(2).data().toString());
	ui->PriceInput->setText(itemRow.at(3).data().toString());
	ui->QuantityInput->setText(itemRow.at(4).data().toString());
	ui->DescriptionInput->setText(itemRow.at(5).data().toString());

	show();
}

void ItemMod::CancelButtonPressed()
{
	qDebug() << "Cancel button pressed in modify window";
	hide();
}

void ItemMod::SubmitButtonPressed()
{
	qDebug() << "Submit button pressed in product management window";
	if (itemMode == 0)
	{
		qDebug() << "Item mode: add";
		emit ReturnToItemMain(db.add_item(ui->NameInput->text().toStdString(), ui->MakeInput->text().toStdString(), ui->DescriptionInput->toPlainText().toStdString(), ui->PriceInput->text().toDouble(), ui->QuantityInput->text().toInt(), 1));
	}
	else if (itemMode == 1)
	{
		qDebug() << "Item mode: modify";
		emit ReturnToItemMain(db.modify_item(ui->IdInput->text().toInt(), ui->NameInput->text().toStdString(), ui->MakeInput->text().toStdString(), ui->PriceInput->text().toDouble(), ui->QuantityInput->text().toInt(), ui->DescriptionInput->toPlainText().toStdString()));
	}
	else
	{
		qDebug() << "INVALID ITEM MODE";
	}
	

	hide();
	
	qDebug() << "End of submit item function";
}