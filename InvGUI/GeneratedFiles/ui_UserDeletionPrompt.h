/********************************************************************************
** Form generated from reading UI file 'UserDeletionPrompt.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERDELETIONPROMPT_H
#define UI_USERDELETIONPROMPT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserDeletionPrompt
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;

    void setupUi(QWidget *UserDeletionPrompt)
    {
        if (UserDeletionPrompt->objectName().isEmpty())
            UserDeletionPrompt->setObjectName(QStringLiteral("UserDeletionPrompt"));
        UserDeletionPrompt->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(UserDeletionPrompt->sizePolicy().hasHeightForWidth());
        UserDeletionPrompt->setSizePolicy(sizePolicy);
        pushButton = new QPushButton(UserDeletionPrompt);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(60, 260, 75, 23));
        pushButton_2 = new QPushButton(UserDeletionPrompt);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(290, 260, 75, 23));
        label = new QLabel(UserDeletionPrompt);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 50, 301, 141));
        QFont font;
        font.setPointSize(24);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);

        retranslateUi(UserDeletionPrompt);
        QObject::connect(pushButton_2, SIGNAL(clicked()), UserDeletionPrompt, SLOT(hide()));

        QMetaObject::connectSlotsByName(UserDeletionPrompt);
    } // setupUi

    void retranslateUi(QWidget *UserDeletionPrompt)
    {
        UserDeletionPrompt->setWindowTitle(QApplication::translate("UserDeletionPrompt", "UserDeletionPrompt", 0));
        pushButton->setText(QApplication::translate("UserDeletionPrompt", "Ok", 0));
        pushButton_2->setText(QApplication::translate("UserDeletionPrompt", "Cancel", 0));
        label->setText(QApplication::translate("UserDeletionPrompt", "Delete user?", 0));
    } // retranslateUi

};

namespace Ui {
    class UserDeletionPrompt: public Ui_UserDeletionPrompt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERDELETIONPROMPT_H
