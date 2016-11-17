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
}
