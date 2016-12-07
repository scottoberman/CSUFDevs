#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QtWidgets>
#include "usermod.h"

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

public slots:
	void Exit();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Login *ui;
    QStackedWidget *outerHandle;
	UserMod *createUser;

signals:
	void LoginPressed();
	void CreateAccountButtonPressed();
};

#endif // LOGIN_H
