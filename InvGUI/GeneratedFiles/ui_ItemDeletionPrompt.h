/********************************************************************************
** Form generated from reading UI file 'ItemDeletionPrompt.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ITEMDELETIONPROMPT_H
#define UI_ITEMDELETIONPROMPT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ItemDeletionPrompt
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;

    void setupUi(QWidget *ItemDeletionPrompt)
    {
        if (ItemDeletionPrompt->objectName().isEmpty())
            ItemDeletionPrompt->setObjectName(QStringLiteral("ItemDeletionPrompt"));
        ItemDeletionPrompt->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ItemDeletionPrompt->sizePolicy().hasHeightForWidth());
        ItemDeletionPrompt->setSizePolicy(sizePolicy);
        pushButton = new QPushButton(ItemDeletionPrompt);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(60, 260, 75, 23));
        pushButton_2 = new QPushButton(ItemDeletionPrompt);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(260, 260, 75, 23));
        label = new QLabel(ItemDeletionPrompt);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(76, 72, 241, 131));
        label->setMinimumSize(QSize(241, 131));
        label->setMaximumSize(QSize(241, 131));
        QFont font;
        font.setPointSize(24);
        label->setFont(font);
        label->setWordWrap(true);

        retranslateUi(ItemDeletionPrompt);
        QObject::connect(pushButton_2, SIGNAL(clicked()), ItemDeletionPrompt, SLOT(hide()));

        QMetaObject::connectSlotsByName(ItemDeletionPrompt);
    } // setupUi

    void retranslateUi(QWidget *ItemDeletionPrompt)
    {
        ItemDeletionPrompt->setWindowTitle(QApplication::translate("ItemDeletionPrompt", "ItemDeletionPrompt", 0));
        pushButton->setText(QApplication::translate("ItemDeletionPrompt", "Ok", 0));
        pushButton_2->setText(QApplication::translate("ItemDeletionPrompt", "Cancel", 0));
        label->setText(QApplication::translate("ItemDeletionPrompt", "Delete item of id", 0));
    } // retranslateUi

};

namespace Ui {
    class ItemDeletionPrompt: public Ui_ItemDeletionPrompt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ITEMDELETIONPROMPT_H
