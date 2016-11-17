#include "extra.h"
#include "ui_extra.h"

extra::extra(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::extra)
{
    ui->setupUi(this);
}

extra::~extra()
{
    delete ui;
}
