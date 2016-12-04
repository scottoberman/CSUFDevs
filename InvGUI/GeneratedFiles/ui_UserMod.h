/********************************************************************************
** Form generated from reading UI file 'UserMod.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERMOD_H
#define UI_USERMOD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserMod
{
public:
    QLineEdit *LastnameInput;
    QLineEdit *UsernameInput;
    QLineEdit *FirstnameInput;
    QLineEdit *Password1Input;
    QLineEdit *Password2Input;
    QLineEdit *EmailInput;
    QPushButton *SubmitButton;
    QPushButton *CancelButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QComboBox *PrivilegeComboBox;
    QLineEdit *IdInput;

    void setupUi(QWidget *UserMod)
    {
        if (UserMod->objectName().isEmpty())
            UserMod->setObjectName(QStringLiteral("UserMod"));
        UserMod->resize(463, 431);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(UserMod->sizePolicy().hasHeightForWidth());
        UserMod->setSizePolicy(sizePolicy);
        LastnameInput = new QLineEdit(UserMod);
        LastnameInput->setObjectName(QStringLiteral("LastnameInput"));
        LastnameInput->setGeometry(QRect(170, 100, 113, 20));
        UsernameInput = new QLineEdit(UserMod);
        UsernameInput->setObjectName(QStringLiteral("UsernameInput"));
        UsernameInput->setGeometry(QRect(30, 40, 113, 20));
        FirstnameInput = new QLineEdit(UserMod);
        FirstnameInput->setObjectName(QStringLiteral("FirstnameInput"));
        FirstnameInput->setGeometry(QRect(30, 100, 113, 20));
        Password1Input = new QLineEdit(UserMod);
        Password1Input->setObjectName(QStringLiteral("Password1Input"));
        Password1Input->setGeometry(QRect(30, 160, 113, 20));
        Password1Input->setEchoMode(QLineEdit::Password);
        Password2Input = new QLineEdit(UserMod);
        Password2Input->setObjectName(QStringLiteral("Password2Input"));
        Password2Input->setGeometry(QRect(30, 200, 113, 20));
        Password2Input->setEchoMode(QLineEdit::Password);
        EmailInput = new QLineEdit(UserMod);
        EmailInput->setObjectName(QStringLiteral("EmailInput"));
        EmailInput->setGeometry(QRect(30, 260, 113, 20));
        SubmitButton = new QPushButton(UserMod);
        SubmitButton->setObjectName(QStringLiteral("SubmitButton"));
        SubmitButton->setGeometry(QRect(40, 380, 75, 23));
        CancelButton = new QPushButton(UserMod);
        CancelButton->setObjectName(QStringLiteral("CancelButton"));
        CancelButton->setGeometry(QRect(350, 380, 75, 23));
        label = new QLabel(UserMod);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 20, 51, 16));
        label_2 = new QLabel(UserMod);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 80, 51, 16));
        label_3 = new QLabel(UserMod);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(170, 80, 47, 13));
        label_4 = new QLabel(UserMod);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 140, 47, 13));
        label_5 = new QLabel(UserMod);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 180, 91, 16));
        label_6 = new QLabel(UserMod);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(30, 240, 47, 13));
        label_7 = new QLabel(UserMod);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(30, 300, 47, 13));
        PrivilegeComboBox = new QComboBox(UserMod);
        PrivilegeComboBox->setObjectName(QStringLiteral("PrivilegeComboBox"));
        PrivilegeComboBox->setGeometry(QRect(30, 320, 69, 22));
        IdInput = new QLineEdit(UserMod);
        IdInput->setObjectName(QStringLiteral("IdInput"));
        IdInput->setEnabled(false);
        IdInput->setGeometry(QRect(370, 40, 41, 20));

        retranslateUi(UserMod);
        QObject::connect(CancelButton, SIGNAL(clicked()), UserMod, SLOT(hide()));

        QMetaObject::connectSlotsByName(UserMod);
    } // setupUi

    void retranslateUi(QWidget *UserMod)
    {
        UserMod->setWindowTitle(QApplication::translate("UserMod", "User Management", 0));
        SubmitButton->setText(QApplication::translate("UserMod", "Submit", 0));
        CancelButton->setText(QApplication::translate("UserMod", "Cancel", 0));
        label->setText(QApplication::translate("UserMod", "Username", 0));
        label_2->setText(QApplication::translate("UserMod", "First Name", 0));
        label_3->setText(QApplication::translate("UserMod", "LastName", 0));
        label_4->setText(QApplication::translate("UserMod", "Password", 0));
        label_5->setText(QApplication::translate("UserMod", "Repeat Password", 0));
        label_6->setText(QApplication::translate("UserMod", "Email", 0));
        label_7->setText(QApplication::translate("UserMod", "Privilege", 0));
        PrivilegeComboBox->clear();
        PrivilegeComboBox->insertItems(0, QStringList()
         << QApplication::translate("UserMod", "0", 0)
         << QApplication::translate("UserMod", "1", 0)
         << QApplication::translate("UserMod", "2", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class UserMod: public Ui_UserMod {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERMOD_H
