#include "login.h"
#include "ui_login.h"
#include "ims.h"

extern Ims db;

Login::Login(QWidget *parent, QStackedWidget *handle) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    outerHandle = handle;
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
	if (db.login(ui->Sn->toPlainText().toStdString(), ui->Pass->toPlainText().toStdString()))
	{
		outerHandle->setCurrentIndex(1);
	}        
}
