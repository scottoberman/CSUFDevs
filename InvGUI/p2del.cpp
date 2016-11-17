#include "p2del.h"
#include "ui_p2del.h"
#include "ims.h"

extern Ims db;

P2del::P2del(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::P2del)
{
    ui->setupUi(this);
}

P2del::~P2del()
{
    delete ui;
}

void P2del::on_pushButton_clicked()
{
	if (db.delete_item(stoi(ui->textEdit->toPlainText().toStdString())))
	{
		// Change a text box to success
	}
	else
	{
		// Output a deletion failed
	}
}
