#include "p3mod.h"
#include "ui_p3mod.h"
#include "ims.h"

P3mod::P3mod(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::P3mod)
{
    ui->setupUi(this);
	ui->IdInput->setVisible(false);
}

P3mod::~P3mod()
{
    delete ui;
}

void P3mod::AddItemClicked()
{
	itemMode = 0;

	// Populate combo box of unique item makes
	vector<string> makes;
	db.get_vector_of_unique_makes(makes);

	// Make sure the combobox is empty
	// (Prevents duplicate makes on repeated executions.
	ui->comboBox->clear();

	while (!makes.empty())
	{
		ui->comboBox->insertItem(0, QString::fromStdString(makes.back()));
		makes.pop_back();
	}

	// Ensure all input boxes are empty
	ui->NameInput->clear();
	ui->MakeInput->clear();
	ui->PriceInput->clear();
	ui->QuantityInput->clear();
	ui->DescriptionInput->clear();

	show();
}

void P3mod::ModifySelectedItemClicked(QModelIndexList itemRow)
{
	itemMode = 1;

	// Populate combo box of unique item makes
	vector<string> makes;
	db.get_vector_of_unique_makes(makes);

	// Make sure the combobox is empty
	// (Prevents duplicate makes on repeated executions.
	ui->comboBox->clear();

	while (!makes.empty())
	{
		ui->comboBox->insertItem(0, QString::fromStdString(makes.back()));
		makes.pop_back();
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

void P3mod::CancelButtonPressed()
{
	qDebug() << "Cancel button pressed in modify window";
	hide();
}

void P3mod::SubmitButtonPressed()
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