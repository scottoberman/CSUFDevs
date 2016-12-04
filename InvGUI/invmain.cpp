#include "invmain.h"
#include "ui_invmain.h"

#include "ims.h"


InvMain::InvMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InvMain)
{
    ui->setupUi(this);

	itemMain = new ItemMain(this);
	userMain = new UserMain(this);

// Add each page to the widget stack.
// The QStackedWidget allows only one widget
// to be displayed at once.
    pages = new QStackedWidget;
    pages->addWidget(itemMain);
    pages->addWidget(userMain);

	// PLACE HOLDER SINCE P3MOD IS NOT GONA BE IN THE STACKED WIDGET ATM
    pages->addWidget(new QWidget);

    pages->addWidget(new P4print(this));
    pages->addWidget(new P5extra(this));
    pages->addWidget(new QStackedWidget(this));


	// The pages will be stored in a StackedQWidget Class
	// which will then be placed in a QHBoxLayout Class in
	// the mainwindow.
	// The StackedQWidget class allows only one widget
	// to be displayed at once.
	ui->horizontalLayout->addWidget(pages);

	connect(ui->ExitButton, &QPushButton::clicked,
			this, &InvMain::Exit);

}
InvMain::~InvMain()
{
    delete ui;
}

void InvMain::LoadItemMainPage(bool changeMade)
{
	// If the item table was altered, reload the
	// table to reflect these changes.
	if (changeMade)
	{
		qDebug() << "Item being modified...";
		pages->removeWidget(itemMain);

		delete itemMain;

		itemMain = new ItemMain(this);
	}
	qDebug() << "Returning to new item main";
	pages->insertWidget(0, itemMain);
	pages->setCurrentIndex(0);
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

void InvMain::Exit()
{
	QApplication::exit();
}
