#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

#include "login.h"
#include "invmain.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QStackedWidget* handle;
    QStackedWidget* stack;
	Login *loginPage;
	InvMain *invMain;
	void closeEvent(QCloseEvent *event);

private slots:
	void ChangeToLoginScreen();
	void ChangeToInvMainScreen();
};

#endif // MAINWINDOW_H
