#ifndef INVMAIN_H
#define INVMAIN_H


#include <QtWidgets>

#include "P3mod.h"
#include "ItemMain.h"
#include "UserMain.h"

namespace Ui {
class InvMain;
}

// Forward declaration due to circular dependency
class P3mod;
class ItemMain;

class InvMain : public QWidget
{
    Q_OBJECT

public:
    explicit InvMain(QWidget *parent = 0);
    ~InvMain();

public slots:
	void LoadItemMainPage(bool changeMade);
    void GoToPage(int newPageIndex);
	void Exit();

private slots:
    void on_Page1Button_clicked();

    void on_Page2Button_clicked();

    void on_Page3Button_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_Logout_clicked();

	void ModifySelectedItemClicked(QModelIndexList);

signals:
	void LogoutPressed();
	void ModifySelectedItem(QModelIndexList);

private:
    Ui::InvMain *ui;

	ItemMain *itemMain;
	UserMain *userMain;

    QListWidget *mainWindowStuff;
    QStackedWidget *pages;
};

#endif // INVMAIN_H




