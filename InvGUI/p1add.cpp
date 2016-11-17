#include "p1add.h"
#include "ui_p1add.h"
#include "ims.h"

extern Ims db;

P1add::P1add(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::P1add)
{
    ui->setupUi(this);
}

P1add::~P1add()
{
    delete ui;
}

void P1add::on_pushButton_clicked()
{
    if(db.add_item(ui->ItemName->toPlainText().toStdString(), ui->ItemDesc->toPlainText().toStdString(), stod(ui->price->toPlainText().toStdString()), stoi(ui->StockCount->toPlainText().toStdString()), stoi(ui->Status->toPlainText().toStdString())))
    {
        ui->label_3->setText("SUCCESS!");
        ui->label_5->setText(ui->price->toPlainText());
    }
    else
    {
        //ui->label_3 = "FAILURE!";
        //ui->label_4 = "Product Not Added: " + ui->comboBox->itemData(ui->comboBox->currentIndex());
        //ui->label_5 = ""
    }
}
