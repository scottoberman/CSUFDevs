/********************************************************************************
** Form generated from reading UI file 'p3mod.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_P3MOD_H
#define UI_P3MOD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_P3mod
{
public:
    QPushButton *pushButton;
    QTextEdit *ItemID;
    QLabel *label_6;
    QTextEdit *NewVal;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_7;
    QLabel *modOut;

    void setupUi(QWidget *P3mod)
    {
        if (P3mod->objectName().isEmpty())
            P3mod->setObjectName(QStringLiteral("P3mod"));
        P3mod->resize(481, 391);
        pushButton = new QPushButton(P3mod);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(310, 245, 75, 23));
        ItemID = new QTextEdit(P3mod);
        ItemID->setObjectName(QStringLiteral("ItemID"));
        ItemID->setGeometry(QRect(310, 65, 71, 26));
        label_6 = new QLabel(P3mod);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(265, 70, 41, 16));
        NewVal = new QTextEdit(P3mod);
        NewVal->setObjectName(QStringLiteral("NewVal"));
        NewVal->setGeometry(QRect(60, 115, 321, 111));
        label = new QLabel(P3mod);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 35, 81, 16));
        comboBox = new QComboBox(P3mod);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(60, 65, 161, 22));
        label_7 = new QLabel(P3mod);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(60, 95, 91, 16));
        modOut = new QLabel(P3mod);
        modOut->setObjectName(QStringLiteral("modOut"));
        modOut->setGeometry(QRect(170, 300, 181, 16));

        retranslateUi(P3mod);

        QMetaObject::connectSlotsByName(P3mod);
    } // setupUi

    void retranslateUi(QWidget *P3mod)
    {
        P3mod->setWindowTitle(QApplication::translate("P3mod", "Form", 0));
        pushButton->setText(QApplication::translate("P3mod", "Submit", 0));
        label_6->setText(QApplication::translate("P3mod", "Item Id", 0));
        label->setText(QApplication::translate("P3mod", "Modify Product", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("P3mod", "Product Name", 0)
         << QApplication::translate("P3mod", "Price", 0)
         << QApplication::translate("P3mod", "Stock_count", 0)
         << QApplication::translate("P3mod", "Status", 0)
         << QApplication::translate("P3mod", "Description", 0)
        );
        label_7->setText(QApplication::translate("P3mod", "Enter New Value", 0));
        modOut->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class P3mod: public Ui_P3mod {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_P3MOD_H
