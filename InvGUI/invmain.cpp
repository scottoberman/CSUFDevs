#include "invmain.h"
#include "ui_invmain.h"

#include "ims.h"


InvMain::InvMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InvMain)
{
    ui->setupUi(this);


// Add each page to the widget stack.
// The QStackedWidget allows only one widget
// to be displayed at once.
    pages = new QStackedWidget;
    pages->addWidget(new P1add);
    pages->addWidget(new P2del);
    pages->addWidget(new P3mod);
    pages->addWidget(new P4print);
    pages->addWidget(new P5extra);
    pages->addWidget(new QStackedWidget);


// The pages will be stored in a StackedQWidget Class
// which will then be placed in a QHBoxLayout Class in
// the mainwindow.
// The StackedQWidget class allows only one widget
// to be displayed at once.
ui->horizontalLayout->addWidget(pages);
}
InvMain::~InvMain()
{
    delete ui;
}
void InvMain::GoToPage(int newPageIndex)
{
    // Changes the currently active page
    pages->setCurrentIndex(newPageIndex);
}

void InvMain::on_Page1Button_clicked()
{
    GoToPage(0);
}

void InvMain::on_Page2Button_clicked()
{
    GoToPage(1);
}

void InvMain::on_Page3Button_clicked()
{
    GoToPage(2);
}

void InvMain::on_pushButton_clicked()
{
    GoToPage(3);
}

void InvMain::on_pushButton_2_clicked()
{
        GoToPage(4);
}
