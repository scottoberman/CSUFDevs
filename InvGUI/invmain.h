#ifndef INVMAIN_H
#define INVMAIN_H


#include <QtWidgets>

#include "ItemMod.h"
#include "ItemMain.h"
#include "UserMain.h"

namespace Ui {
class InvMain;
}

// Forward declaration due to circular dependency
class ItemMod;
class ItemMain;

class InvMain : public QWidget
{
    Q_OBJECT

public:
    explicit InvMain(QWidget *parent = 0);
    ~InvMain();

public slots:
	void LoadItemMainPage(bool changeMade);
	void Exit();

private slots:
    void on_Logout_clicked();
	void ShowItemMain();
	void ShowUserMain();

signals:
	void LogoutPressed();

private:
    Ui::InvMain *ui;

	ItemMain *itemMain;
	UserMain *userMain;

    QStackedWidget *pages;
};

#endif // INVMAIN_H




