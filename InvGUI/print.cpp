#include "print.h"
#include "ui_print.h"

print::print(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::print)
{
    ui->setupUi(this);
}

print::~print()
{
    delete ui;
}
