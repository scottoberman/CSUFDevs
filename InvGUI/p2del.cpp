#include "p2del.h"
#include "ui_p2del.h"

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
}
