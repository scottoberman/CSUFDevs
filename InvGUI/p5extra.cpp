#include "p5extra.h"
#include "ui_p5extra.h"
#include "ims.h"

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
}
