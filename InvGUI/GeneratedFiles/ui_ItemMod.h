/********************************************************************************
** Form generated from reading UI file 'ItemMod.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ITEMMOD_H
#define UI_ITEMMOD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ItemMod
{
public:
    QPushButton *SubmitButton;
    QLabel *label;
    QLabel *modOut;
    QLineEdit *NameInput;
    QLineEdit *PriceInput;
    QLineEdit *QuantityInput;
    QLineEdit *MakeInput;
    QPushButton *CancelButton;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QComboBox *comboBox;
    QLabel *label_7;
    QLineEdit *IdInput;
    QLabel *ModSuccessfulLabel;
    QTextEdit *DescriptionInput;

    void setupUi(QWidget *ItemMod)
    {
        if (ItemMod->objectName().isEmpty())
            ItemMod->setObjectName(QStringLiteral("ItemMod"));
        ItemMod->resize(481, 391);
        ItemMod->setMinimumSize(QSize(481, 391));
        ItemMod->setMaximumSize(QSize(481, 391));
        SubmitButton = new QPushButton(ItemMod);
        SubmitButton->setObjectName(QStringLiteral("SubmitButton"));
        SubmitButton->setGeometry(QRect(30, 350, 81, 23));
        label = new QLabel(ItemMod);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 10, 111, 16));
        modOut = new QLabel(ItemMod);
        modOut->setObjectName(QStringLiteral("modOut"));
        modOut->setGeometry(QRect(170, 300, 181, 16));
        NameInput = new QLineEdit(ItemMod);
        NameInput->setObjectName(QStringLiteral("NameInput"));
        NameInput->setGeometry(QRect(50, 60, 113, 20));
        PriceInput = new QLineEdit(ItemMod);
        PriceInput->setObjectName(QStringLiteral("PriceInput"));
        PriceInput->setGeometry(QRect(50, 200, 113, 20));
        QuantityInput = new QLineEdit(ItemMod);
        QuantityInput->setObjectName(QStringLiteral("QuantityInput"));
        QuantityInput->setGeometry(QRect(50, 160, 113, 20));
        MakeInput = new QLineEdit(ItemMod);
        MakeInput->setObjectName(QStringLiteral("MakeInput"));
        MakeInput->setGeometry(QRect(50, 110, 113, 20));
        CancelButton = new QPushButton(ItemMod);
        CancelButton->setObjectName(QStringLiteral("CancelButton"));
        CancelButton->setGeometry(QRect(380, 350, 75, 23));
        label_2 = new QLabel(ItemMod);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 40, 47, 13));
        label_3 = new QLabel(ItemMod);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 90, 47, 13));
        label_4 = new QLabel(ItemMod);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(50, 180, 47, 13));
        label_5 = new QLabel(ItemMod);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(50, 230, 61, 16));
        label_6 = new QLabel(ItemMod);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(50, 140, 47, 13));
        comboBox = new QComboBox(ItemMod);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(200, 110, 111, 22));
        label_7 = new QLabel(ItemMod);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(180, 90, 161, 16));
        IdInput = new QLineEdit(ItemMod);
        IdInput->setObjectName(QStringLiteral("IdInput"));
        IdInput->setEnabled(false);
        IdInput->setGeometry(QRect(380, 30, 51, 20));
        ModSuccessfulLabel = new QLabel(ItemMod);
        ModSuccessfulLabel->setObjectName(QStringLiteral("ModSuccessfulLabel"));
        ModSuccessfulLabel->setGeometry(QRect(330, 190, 101, 61));
        DescriptionInput = new QTextEdit(ItemMod);
        DescriptionInput->setObjectName(QStringLiteral("DescriptionInput"));
        DescriptionInput->setGeometry(QRect(50, 250, 211, 91));
        QWidget::setTabOrder(NameInput, MakeInput);
        QWidget::setTabOrder(MakeInput, comboBox);
        QWidget::setTabOrder(comboBox, QuantityInput);
        QWidget::setTabOrder(QuantityInput, PriceInput);
        QWidget::setTabOrder(PriceInput, SubmitButton);
        QWidget::setTabOrder(SubmitButton, CancelButton);

        retranslateUi(ItemMod);
        QObject::connect(SubmitButton, SIGNAL(clicked()), ItemMod, SLOT(SubmitButtonPressed()));
        QObject::connect(comboBox, SIGNAL(currentIndexChanged(QString)), MakeInput, SLOT(setText(QString)));
        QObject::connect(CancelButton, SIGNAL(clicked()), ItemMod, SLOT(hide()));

        QMetaObject::connectSlotsByName(ItemMod);
    } // setupUi

    void retranslateUi(QWidget *ItemMod)
    {
        ItemMod->setWindowTitle(QApplication::translate("ItemMod", "Product Management", 0));
        SubmitButton->setText(QApplication::translate("ItemMod", "Submit", 0));
        label->setText(QApplication::translate("ItemMod", "Product Management", 0));
        modOut->setText(QString());
        CancelButton->setText(QApplication::translate("ItemMod", "Cancel", 0));
        label_2->setText(QApplication::translate("ItemMod", "Name", 0));
        label_3->setText(QApplication::translate("ItemMod", "Make", 0));
        label_4->setText(QApplication::translate("ItemMod", "Price", 0));
        label_5->setText(QApplication::translate("ItemMod", "Description", 0));
        label_6->setText(QApplication::translate("ItemMod", "Quantity", 0));
        label_7->setText(QApplication::translate("ItemMod", "Existing Makes to Choose From", 0));
        ModSuccessfulLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ItemMod: public Ui_ItemMod {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ITEMMOD_H
