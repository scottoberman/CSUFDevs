#include "del.h"
#include "ui_del.h"

Delete::Del(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Del)
{
    ui->setupUi(this);
}

Delete::~Del()
{
    delete ui;
}
