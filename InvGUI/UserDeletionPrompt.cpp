#include "UserDeletionPrompt.h"
#include "ims.h"

UserDeletionPrompt::UserDeletionPrompt(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	// When the ok to delete button is pressed,
	// attempt to delete item
	connect(ui.pushButton, &QPushButton::clicked,
		this, &UserDeletionPrompt::DeleteUser);
}

UserDeletionPrompt::~UserDeletionPrompt()
{
}

void UserDeletionPrompt::SetDeleteUserPrompt(const int ID)
{
	QString prompt;

	idToDelete = ID;

	qDebug() << "Attempting to delete ID OF" << idToDelete;
	prompt = "Delete user of id ";
	prompt.append(QString::number(idToDelete));
	prompt.append("?");

	ui.label->setText(prompt);

	show();
}

void UserDeletionPrompt::DeleteUser()
{
	qDebug() << "(IN deletion prompt) USER ID IS " << idToDelete;
	emit UserDeleted(db.delete_user(idToDelete));
	hide();
}
