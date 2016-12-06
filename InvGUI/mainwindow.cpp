#include "mainwindow.h"

#include "ui_mainwindow.h"

#include "ims.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    stack = new QStackedWidget();
	loginPage = new Login(this);

    stack->addWidget(loginPage);

    ui->horizontalLayout->addWidget(stack);

	connect(loginPage, &Login::LoginPressed,
			this, &MainWindow::ChangeToInvMainScreen);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
	QApplication::exit();
}

void MainWindow::ChangeToLoginScreen()
{
	this->setFixedSize(300, 300);
	stack->setCurrentIndex(0);
}

void MainWindow::ChangeToInvMainScreen()
{
	invMain = new InvMain(this);
	stack->addWidget(invMain);

	connect(invMain, &InvMain::LogoutPressed,
		this, &MainWindow::ChangeToLoginScreen);

	this->setFixedSize(1275, 746);
	stack->setCurrentIndex(1);
}