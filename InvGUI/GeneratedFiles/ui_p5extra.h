/********************************************************************************
** Form generated from reading UI file 'p5extra.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_P5EXTRA_H
#define UI_P5EXTRA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_P5extra
{
public:
    QPushButton *pushButton;
    QTextEdit *Email;
    QLabel *label_7;
    QLabel *label_6;
    QTextEdit *UserName;
    QTextEdit *Password;
    QTextEdit *ConfPass;
    QLabel *label_2;
    QLabel *label_8;
    QLabel *label;

    void setupUi(QWidget *P5extra)
    {
        if (P5extra->objectName().isEmpty())
            P5extra->setObjectName(QStringLiteral("P5extra"));
        P5extra->resize(471, 424);
        pushButton = new QPushButton(P5extra);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(75, 310, 75, 23));
        Email = new QTextEdit(P5extra);
        Email->setObjectName(QStringLiteral("Email"));
        Email->setGeometry(QRect(55, 135, 181, 26));
        label_7 = new QLabel(P5extra);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(55, 175, 71, 16));
        label_6 = new QLabel(P5extra);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(55, 115, 71, 16));
        UserName = new QTextEdit(P5extra);
        UserName->setObjectName(QStringLiteral("UserName"));
        UserName->setGeometry(QRect(55, 80, 181, 26));
        Password = new QTextEdit(P5extra);
        Password->setObjectName(QStringLiteral("Password"));
        Password->setGeometry(QRect(55, 195, 181, 26));
        ConfPass = new QTextEdit(P5extra);
        ConfPass->setObjectName(QStringLiteral("ConfPass"));
        ConfPass->setGeometry(QRect(55, 255, 181, 26));
        label_2 = new QLabel(P5extra);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(55, 60, 71, 16));
        label_8 = new QLabel(P5extra);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(55, 235, 91, 16));
        label = new QLabel(P5extra);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(55, 30, 71, 16));

        retranslateUi(P5extra);

        QMetaObject::connectSlotsByName(P5extra);
    } // setupUi

    void retranslateUi(QWidget *P5extra)
    {
        P5extra->setWindowTitle(QApplication::translate("P5extra", "Form", 0));
        pushButton->setText(QApplication::translate("P5extra", "Submit", 0));
        label_7->setText(QApplication::translate("P5extra", "Password", 0));
        label_6->setText(QApplication::translate("P5extra", "Email", 0));
        label_2->setText(QApplication::translate("P5extra", "User Name", 0));
        label_8->setText(QApplication::translate("P5extra", "Confirm Password", 0));
        label->setText(QApplication::translate("P5extra", "Create User", 0));
    } // retranslateUi

};

namespace Ui {
    class P5extra: public Ui_P5extra {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_P5EXTRA_H
