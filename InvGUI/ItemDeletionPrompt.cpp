#include "ItemDeletionPrompt.h"

ItemDeletionPrompt::ItemDeletionPrompt(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.pushButton, &QPushButton::clicked,
			this, &ItemDeletionPrompt::DeleteItem);
}

ItemDeletionPrompt::~ItemDeletionPrompt()
{
}

void ItemDeletionPrompt::SetDeleteItemPrompt(const int ID)
{
	QString prompt;

	idToDelete = ID;

	qDebug() << "Attempting to delete ID OF" << idToDelete;
	prompt = "Delete item of id ";
	prompt.append(QString::number(idToDelete));
	prompt.append("?");

	ui.label->setText(prompt);

	show();
}

void ItemDeletionPrompt::DeleteItem()
{

	qDebug() << "(IN deletion prompt) ITEM ID IS " << idToDelete;
	emit ItemDeleted(db.delete_item(idToDelete));
	hide();
}
