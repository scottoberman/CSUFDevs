#include "p5extra.h"
#include "ui_p5extra.h"
#include "ims.h"

extern Ims db;

P5extra::P5extra(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::P5extra)
{
    ui->setupUi(this);
}

P5extra::~P5extra()
{
    delete ui;
}

void P5extra::on_pushButton_clicked()
{
	if (ui->Password->toPlainText() != ui->ConfPass->toPlainText())
	{
		ui->label_5->setText("Your passwords do not match.");
	}
	else
	{
		if (db.add_user(ui->UserName->toPlainText().toStdString(), ui->FirstName->toPlainText().toStdString(), ui->LastName->toPlainText().toStdString(), ui->Email->toPlainText().toStdString(), ui->Password->toPlainText().toStdString(), 1))
		{
			ui->label_5->setText("User created successfully!");
		}
		else
		{
			ui->label_5->setText("User could not be created.");
		}
	}
}
