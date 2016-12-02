#include "invmain.h"
#include "ui_invmain.h"

#include "ims.h"


InvMain::InvMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InvMain)
{
    ui->setupUi(this);

	ItemMain *itemMain = new ItemMain(this);
	P3mod *p3mod = new P3mod(this);

// Add each page to the widget stack.
// The QStackedWidget allows only one widget
// to be displayed at once.
    pages = new QStackedWidget;
    pages->addWidget(itemMain);
    pages->addWidget(new P2del(this));
    pages->addWidget(p3mod);
    pages->addWidget(new P4print(this));
    pages->addWidget(new P5extra(this));
    pages->addWidget(new QStackedWidget(this));


// The pages will be stored in a StackedQWidget Class
// which will then be placed in a QHBoxLayout Class in
// the mainwindow.
// The StackedQWidget class allows only one widget
// to be displayed at once.
ui->horizontalLayout->addWidget(pages);

// Signal-Slot connection to change the active widget
// to the modify item page
connect(itemMain, &ItemMain::ChangePageToModifySelectedItem,
		this, &InvMain::ModifySelectedItemClicked);

// Signal-Slot connection to auto-fill the
// line edits of the modify item page
connect(this, &InvMain::ModifySelectedItem,
		p3mod, &P3mod::ModifySelectedItem);



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

void InvMain::ModifySelectedItemClicked(QModelIndexList selectedRow)
{
	emit ModifySelectedItem(selectedRow);
	pages->setCurrentIndex(2);
}

void InvMain::on_Logout_clicked()
{
	emit LogoutPressed();
}
