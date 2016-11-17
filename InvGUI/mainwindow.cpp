#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    stack = new QStackedWidget();

    stack->addWidget(new Login(this, stack));
    stack->addWidget(new InvMain(this));

    ui->horizontalLayout->addWidget(stack);
}

MainWindow::~MainWindow()
{
    delete ui;
}
