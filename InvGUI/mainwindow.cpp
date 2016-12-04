#include "mainwindow.h"

#include "ui_mainwindow.h"

#include "ims.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    stack = new QStackedWidget();

	Login *loginPage = new Login(this);
	InvMain *invMain = new InvMain(this);

    stack->addWidget(loginPage);
    stack->addWidget(invMain);

    ui->horizontalLayout->addWidget(stack);

	connect(invMain, &InvMain::LogoutPressed,
			this, &MainWindow::ChangeToLoginScreen);

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
	this->setFixedSize(1275, 746);
	stack->setCurrentIndex(1);
}