#include "p3mod.h"
#include "ui_p3mod.h"
#include "ims.h"

P3mod::P3mod(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::P3mod)
{
    ui->setupUi(this);
}

P3mod::~P3mod()
{
    delete ui;
}

void P3mod::on_pushButton_clicked()
{
	if (db.modify_item(ui->comboBox->currentText().toStdString(), (stoi(ui->ItemID->toPlainText().toStdString())), ui->NewVal->toPlainText().toStdString()))
	{
		ui->modOut->setText("Item successfully modified!");
	}
	else
	{
		ui->modOut->setText("No modifications executed!");
	}
}
