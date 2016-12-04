#include "UserMod.h"
#include "qdebug.h"

#include "ims.h"

UserMod::UserMod(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.SubmitButton, &QPushButton::clicked,
			this, &UserMod::SubmitButtonClicked);
}

UserMod::~UserMod()
{
}

void UserMod::ShowAddPage()
{
	qDebug() << "Showing add user page...";
	userMode = 0;
	// Ensure that the page is in a "clean" state
	ui.Password1Input->setEnabled(true);
	ui.Password2Input->setEnabled(true);
	ui.Password2Input->setHidden(false);

	ui.UsernameInput->clear();
	ui.FirstnameInput->clear();
	ui.LastnameInput->clear();
	ui.Password1Input->clear();
	ui.Password2Input->clear();
	ui.EmailInput->clear();
	ui.PrivilegeComboBox->setCurrentIndex(0);

	show();
}

void UserMod::ShowModPage(QModelIndexList row)
{
	qDebug() << "Showing mod user page...";

	// ItemMode 1: Item is being modified NOT added
	userMode = 1;

	// Populate line edits with the old information of the user
	// being modified
	ui.IdInput->setText(row.at(0).data().toString());
	ui.UsernameInput->setText(row.at(1).data().toString());
	ui.FirstnameInput->setText(row.at(2).data().toString());
	ui.LastnameInput->setText(row.at(3).data().toString());
	ui.EmailInput->setText(row.at(4).data().toString());

	// Clear password lineedits
	ui.Password1Input->clear();
	ui.Password2Input->clear();

	if (row.at(5).data().toInt() <= 3)
	{
		ui.PrivilegeComboBox->setCurrentIndex(row.at(5).data().toInt() - 1);
	}
	else
	{
		ui.PrivilegeComboBox->setCurrentIndex(3);
	}
	

	show();
}

void UserMod::SubmitButtonClicked()
{

	if (ui.Password1Input->text() != ui.Password2Input->text())
	{
		// Output error stating passwords do not match
	}
	else if (ui.Password1Input->text().isEmpty())
	{
		// Output error stating no empty passwords allowed
	}
	else
	{
		if (userMode == 0)
		{
			emit ReturnToUserMain(db.add_user(ui.UsernameInput->text().toStdString(), ui.FirstnameInput->text().toStdString(), ui.LastnameInput->text().toStdString(), ui.EmailInput->text().toStdString(), ui.Password1Input->text().toStdString(), ui.PrivilegeComboBox->currentText().toInt()));
		}
		else if (userMode == 1)
		{
			emit ReturnToUserMain(db.modify_user(ui.IdInput->text().toInt(), ui.UsernameInput->text().toStdString(), ui.FirstnameInput->text().toStdString(), ui.LastnameInput->text().toStdString(), ui.EmailInput->text().toStdString(), ui.Password1Input->text().toStdString(), ui.PrivilegeComboBox->currentText().toInt()));
		}
		else
		{
			qDebug() << "INVALID USER MODE";
		}
	}


}