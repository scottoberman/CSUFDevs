/********************************************************************************
** Form generated from reading UI file 'p1add.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_P1ADD_H
#define UI_P1ADD_H

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

class Ui_P1add
{
public:
    QLabel *label_2;
    QPushButton *pushButton;
    QLabel *label_3;
    QLabel *label_4;
    QTextEdit *price;
    QLabel *label_5;
    QLabel *label;
    QTextEdit *StockCount;
    QTextEdit *Status;
    QTextEdit *ItemName;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QTextEdit *ItemDesc;

    void setupUi(QWidget *P1add)
    {
        if (P1add->objectName().isEmpty())
            P1add->setObjectName(QStringLiteral("P1add"));
        P1add->resize(482, 432);
        label_2 = new QLabel(P1add);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 55, 71, 16));
        pushButton = new QPushButton(P1add);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(80, 250, 75, 23));
        label_3 = new QLabel(P1add);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 290, 221, 16));
        label_4 = new QLabel(P1add);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 320, 211, 16));
        price = new QTextEdit(P1add);
        price->setObjectName(QStringLiteral("price"));
        price->setGeometry(QRect(130, 130, 71, 26));
        label_5 = new QLabel(P1add);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 350, 231, 16));
        label = new QLabel(P1add);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 30, 71, 16));
        StockCount = new QTextEdit(P1add);
        StockCount->setObjectName(QStringLiteral("StockCount"));
        StockCount->setGeometry(QRect(130, 170, 71, 26));
        Status = new QTextEdit(P1add);
        Status->setObjectName(QStringLiteral("Status"));
        Status->setGeometry(QRect(130, 210, 71, 26));
        ItemName = new QTextEdit(P1add);
        ItemName->setObjectName(QStringLiteral("ItemName"));
        ItemName->setGeometry(QRect(130, 50, 181, 26));
        label_7 = new QLabel(P1add);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(60, 135, 71, 16));
        label_8 = new QLabel(P1add);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(60, 175, 71, 16));
        label_9 = new QLabel(P1add);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(60, 215, 71, 16));
        label_10 = new QLabel(P1add);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(230, 90, 91, 16));
        ItemDesc = new QTextEdit(P1add);
        ItemDesc->setObjectName(QStringLiteral("ItemDesc"));
        ItemDesc->setGeometry(QRect(230, 110, 181, 126));

        retranslateUi(P1add);

        QMetaObject::connectSlotsByName(P1add);
    } // setupUi

    void retranslateUi(QWidget *P1add)
    {
        P1add->setWindowTitle(QApplication::translate("P1add", "Form", 0));
        label_2->setText(QApplication::translate("P1add", "Item Name", 0));
        pushButton->setText(QApplication::translate("P1add", "Submit", 0));
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        label->setText(QApplication::translate("P1add", "Add Product", 0));
        label_7->setText(QApplication::translate("P1add", "Price", 0));
        label_8->setText(QApplication::translate("P1add", "Stock_count", 0));
        label_9->setText(QApplication::translate("P1add", "Status", 0));
        label_10->setText(QApplication::translate("P1add", "Item Description", 0));
    } // retranslateUi

};

namespace Ui {
    class P1add: public Ui_P1add {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_P1ADD_H
