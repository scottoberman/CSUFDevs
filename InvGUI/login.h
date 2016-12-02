#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QtWidgets>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0, QStackedWidget *handle = 0);
    ~Login();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Login *ui;
    QStackedWidget *outerHandle;
signals:
	void LoginPressed();
};

#endif // LOGIN_H
