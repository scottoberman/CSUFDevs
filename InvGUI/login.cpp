#include "login.h"
#include "ui_login.h"

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
   if(ui->Sn->toPlainText()=="1" && ui->Pass->toPlainText()=="2")
        outerHandle->setCurrentIndex(1);
}
