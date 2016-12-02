#include "login.h"
#include "ui_login.h"
#include "ims.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
	if (db.login(ui->Sn->text().toStdString(), ui->Pass->text().toStdString()))
	{
		ui->Sn->clear();
		ui->Pass->clear();
		emit LoginPressed();
	}        
}
