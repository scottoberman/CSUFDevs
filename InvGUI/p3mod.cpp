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
//
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

void P3mod::ModifySelectedItem(QModelIndexList itemRow)
{
	qDebug() << "Mod1";
	qDebug() << itemRow.size();
	qDebug() << itemRow.at(0).data().toString();
	ui->NameInput->setText(itemRow.at(1).data().toString());
	qDebug() << "Mod2";
	ui->PriceInput->setText(itemRow.at(2).data().toString());
	ui->QuantityInput->setText(itemRow.at(3).data().toString());
	ui->DescriptionInput->setText(itemRow.at(4).data().toString());
}
