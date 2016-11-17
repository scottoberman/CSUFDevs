/********************************************************************************
** Form generated from reading UI file 'p4print.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_P4PRINT_H
#define UI_P4PRINT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_P4print
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QRadioButton *ALL;
    QRadioButton *ByName;
    QRadioButton *ByNum;
    QTextBrowser *textBrowser;
    QTextEdit *textEdit;

    void setupUi(QWidget *P4print)
    {
        if (P4print->objectName().isEmpty())
            P4print->setObjectName(QStringLiteral("P4print"));
        P4print->resize(467, 417);
        label = new QLabel(P4print);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(25, 20, 141, 16));
        pushButton = new QPushButton(P4print);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(25, 190, 75, 23));
        ALL = new QRadioButton(P4print);
        ALL->setObjectName(QStringLiteral("ALL"));
        ALL->setGeometry(QRect(25, 45, 82, 26));
        ByName = new QRadioButton(P4print);
        ByName->setObjectName(QStringLiteral("ByName"));
        ByName->setGeometry(QRect(25, 75, 82, 17));
        ByNum = new QRadioButton(P4print);
        ByNum->setObjectName(QStringLiteral("ByNum"));
        ByNum->setGeometry(QRect(25, 100, 101, 17));
        textBrowser = new QTextBrowser(P4print);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(155, 15, 281, 306));
        QFont font;
        font.setFamily(QStringLiteral("Courier"));
        textBrowser->setFont(font);
        textEdit = new QTextEdit(P4print);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(25, 125, 106, 26));

        retranslateUi(P4print);

        QMetaObject::connectSlotsByName(P4print);
    } // setupUi

    void retranslateUi(QWidget *P4print)
    {
        P4print->setWindowTitle(QApplication::translate("P4print", "Form", 0));
        label->setText(QApplication::translate("P4print", "Print database", 0));
        pushButton->setText(QApplication::translate("P4print", "Print", 0));
        ALL->setText(QApplication::translate("P4print", "ALL", 0));
        ByName->setText(QApplication::translate("P4print", "by name", 0));
        ByNum->setText(QApplication::translate("P4print", "by item number", 0));
    } // retranslateUi

};

namespace Ui {
    class P4print: public Ui_P4print {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_P4PRINT_H
