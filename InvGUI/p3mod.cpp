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

//void P3mod::on_pushButton_clicked()
//{
//	if (db.modify_item(ui->comboBox->currentText().toStdString(), (stoi(ui->ItemID->toPlainText().toStdString())), ui->NewVal->toPlainText().toStdString()))
//	{
//		ui->modOut->setText("Item successfully modified!");
//	}
//	else
//	{
//		ui->modOut->setText("No modifications executed!");
//	}
//}

void P3mod::ModifySelectedItemClicked(QModelIndexList itemRow)
{
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
	qDebug() << "Submit button pressed in modify window";
	emit ReturnToItemMain(db.modify_item(ui->IdInput->text().toInt(), ui->NameInput->text().toStdString(), ui->MakeInput->text().toStdString(), ui->PriceInput->text().toDouble(), ui->QuantityInput->text().toInt(), ui->DescriptionInput->text().toStdString()));

	hide();
	
	qDebug() << "End of submit modify button function";
}