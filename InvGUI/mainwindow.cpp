#include "mainwindow.h"

#include "ui_mainwindow.h"

#include "ims.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    stack = new QStackedWidget();

	Login *loginPage = new Login(this, stack);
	InvMain *invMain = new InvMain(this);

    stack->addWidget(loginPage);
    stack->addWidget(invMain);

    ui->horizontalLayout->addWidget(stack);

	connect(invMain, &InvMain::LogoutPressed,
			this, &MainWindow::ChangeToLoginScreen);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ChangeToLoginScreen()
{
	stack->setCurrentIndex(0);
}
