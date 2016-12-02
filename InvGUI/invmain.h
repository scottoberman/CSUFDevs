#ifndef INVMAIN_H
#define INVMAIN_H


#include <QtWidgets>

#include "P1add.h"
#include "P2del.h"
#include "P3mod.h"
#include "P4print.h"
#include "P5extra.h"
#include "ItemMain.h"

namespace Ui {
class InvMain;
}

class InvMain : public QWidget
{
    Q_OBJECT

public:
    explicit InvMain(QWidget *parent = 0);
    ~InvMain();

public slots:
    void GoToPage(int newPageIndex);

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

    QListWidget *mainWindowStuff;
    QStackedWidget *pages;
};

#endif // INVMAIN_H




