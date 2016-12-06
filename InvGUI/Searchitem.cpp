#include "SearchItem.h"
#include "ui_SearchItem.h"
#include "ims.h"

SearchItem::SearchItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchItem)
{
    ui->setupUi(this);
}

SearchItem::~SearchItem()
{
    delete ui;
}

void SearchItem::on_pushButton_clicked()
{
	if (ui->ByName->isChecked())
	{
		db.print_item_by_name(ui->textEdit->toPlainText().toStdString());
		db.print_result_set(ui->textBrowser);
	}
	else if (ui->ByNum->isChecked())
	{
		db.print_item_by_id(ui->textEdit->toPlainText().toStdString());
		db.print_result_set(ui->textBrowser);
	}
	else
	{
		// Error case
	}
}

void SearchItem::LoadSearchItem()
{
	show();
}
