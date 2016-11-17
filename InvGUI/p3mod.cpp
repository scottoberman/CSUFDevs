#include "p3mod.h"
#include "ui_p3mod.h"

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
}
