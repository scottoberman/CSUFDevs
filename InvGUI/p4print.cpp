#include "p4print.h"
#include "ui_p4print.h"
#include "ims.h"

P4print::P4print(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::P4print)
{
    ui->setupUi(this);
}

P4print::~P4print()
{
    delete ui;
}

void P4print::on_pushButton_clicked()
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
	else if (ui->ALL->isChecked())
	{
		db.print_all_items();
		db.print_result_set(ui->textBrowser);
	}
	else
	{
		// Error case
	}
}
