/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *Pass;
    QLineEdit *Sn;
    QPushButton *ExitButton;
    QPushButton *CreateAccountButton;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(324, 327);
        pushButton = new QPushButton(Login);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(40, 160, 75, 23));
        label = new QLabel(Login);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 100, 61, 16));
        label_2 = new QLabel(Login);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 30, 81, 16));
        Pass = new QLineEdit(Login);
        Pass->setObjectName(QStringLiteral("Pass"));
        Pass->setGeometry(QRect(40, 120, 151, 31));
        Pass->setEchoMode(QLineEdit::Password);
        Sn = new QLineEdit(Login);
        Sn->setObjectName(QStringLiteral("Sn"));
        Sn->setGeometry(QRect(40, 50, 151, 31));
        ExitButton = new QPushButton(Login);
        ExitButton->setObjectName(QStringLiteral("ExitButton"));
        ExitButton->setGeometry(QRect(200, 250, 75, 23));
        CreateAccountButton = new QPushButton(Login);
        CreateAccountButton->setObjectName(QStringLiteral("CreateAccountButton"));
        CreateAccountButton->setGeometry(QRect(40, 250, 91, 23));
        QWidget::setTabOrder(Sn, Pass);
        QWidget::setTabOrder(Pass, pushButton);

        retranslateUi(Login);

        pushButton->setDefault(true);


        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Form", 0));
        pushButton->setText(QApplication::translate("Login", "Login", 0));
        label->setText(QApplication::translate("Login", "Password", 0));
        label_2->setText(QApplication::translate("Login", "Screenname", 0));
        ExitButton->setText(QApplication::translate("Login", "Exit", 0));
        CreateAccountButton->setText(QApplication::translate("Login", "Create Account", 0));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
