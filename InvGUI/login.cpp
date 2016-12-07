#include "login.h"
#include "ui_login.h"
#include "ims.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

	createUser = new UserMod();

	connect(ui->ExitButton, &QPushButton::clicked,
			this, &Login::Exit);

	connect(ui->CreateAccountButton, &QPushButton::clicked,
			createUser, &UserMod::ShowModPageFromLogin);


}

Login::~Login()
{
    delete ui;
}

void Login::Exit()
{
	QApplication::exit();
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


