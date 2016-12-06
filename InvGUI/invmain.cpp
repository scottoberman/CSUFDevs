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

	// The pages will be stored in a StackedQWidget Class
	// which will then be placed in a QHBoxLayout Class in
	// the mainwindow.
	// The StackedQWidget class allows only one widget
	// to be displayed at once.
	ui->horizontalLayout->addWidget(pages);

	connect(ui->ExitButton, &QPushButton::clicked,
			this, &InvMain::Exit);

	connect(ui->UsersButton, &QPushButton::clicked,
			this, &InvMain::ShowUserMain);

	connect(ui->InventoryButton, &QPushButton::clicked,
		this, &InvMain::ShowItemMain);

	if (userPriv > 0)
	{
		ui->UsersButton->setHidden(true);
	}

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

void InvMain::on_Logout_clicked()
{
	emit LogoutPressed();

	qApp->quit();
	QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}

void InvMain::Exit()
{
	QApplication::exit();
}

void InvMain::ShowItemMain()
{
	pages->setCurrentIndex(0);
}

void InvMain::ShowUserMain()
{
	pages->setCurrentIndex(1);
}
