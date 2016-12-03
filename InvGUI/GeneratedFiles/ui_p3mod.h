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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_P3mod
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

    void setupUi(QWidget *P3mod)
    {
        if (P3mod->objectName().isEmpty())
            P3mod->setObjectName(QStringLiteral("P3mod"));
        P3mod->resize(481, 391);
        P3mod->setMinimumSize(QSize(481, 391));
        P3mod->setMaximumSize(QSize(481, 391));
        SubmitButton = new QPushButton(P3mod);
        SubmitButton->setObjectName(QStringLiteral("SubmitButton"));
        SubmitButton->setGeometry(QRect(30, 350, 81, 23));
        label = new QLabel(P3mod);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 10, 111, 16));
        modOut = new QLabel(P3mod);
        modOut->setObjectName(QStringLiteral("modOut"));
        modOut->setGeometry(QRect(170, 300, 181, 16));
        NameInput = new QLineEdit(P3mod);
        NameInput->setObjectName(QStringLiteral("NameInput"));
        NameInput->setGeometry(QRect(50, 60, 113, 20));
        PriceInput = new QLineEdit(P3mod);
        PriceInput->setObjectName(QStringLiteral("PriceInput"));
        PriceInput->setGeometry(QRect(50, 200, 113, 20));
        QuantityInput = new QLineEdit(P3mod);
        QuantityInput->setObjectName(QStringLiteral("QuantityInput"));
        QuantityInput->setGeometry(QRect(50, 160, 113, 20));
        MakeInput = new QLineEdit(P3mod);
        MakeInput->setObjectName(QStringLiteral("MakeInput"));
        MakeInput->setGeometry(QRect(50, 110, 113, 20));
        CancelButton = new QPushButton(P3mod);
        CancelButton->setObjectName(QStringLiteral("CancelButton"));
        CancelButton->setGeometry(QRect(380, 350, 75, 23));
        label_2 = new QLabel(P3mod);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 40, 47, 13));
        label_3 = new QLabel(P3mod);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 90, 47, 13));
        label_4 = new QLabel(P3mod);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(50, 180, 47, 13));
        label_5 = new QLabel(P3mod);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(50, 230, 61, 16));
        label_6 = new QLabel(P3mod);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(50, 140, 47, 13));
        comboBox = new QComboBox(P3mod);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(200, 110, 111, 22));
        label_7 = new QLabel(P3mod);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(180, 90, 161, 16));
        IdInput = new QLineEdit(P3mod);
        IdInput->setObjectName(QStringLiteral("IdInput"));
        IdInput->setEnabled(false);
        IdInput->setGeometry(QRect(380, 30, 51, 20));
        ModSuccessfulLabel = new QLabel(P3mod);
        ModSuccessfulLabel->setObjectName(QStringLiteral("ModSuccessfulLabel"));
        ModSuccessfulLabel->setGeometry(QRect(330, 190, 101, 61));
        DescriptionInput = new QTextEdit(P3mod);
        DescriptionInput->setObjectName(QStringLiteral("DescriptionInput"));
        DescriptionInput->setGeometry(QRect(50, 250, 211, 91));
        QWidget::setTabOrder(NameInput, MakeInput);
        QWidget::setTabOrder(MakeInput, comboBox);
        QWidget::setTabOrder(comboBox, QuantityInput);
        QWidget::setTabOrder(QuantityInput, PriceInput);
        QWidget::setTabOrder(PriceInput, SubmitButton);
        QWidget::setTabOrder(SubmitButton, CancelButton);

        retranslateUi(P3mod);
        QObject::connect(SubmitButton, SIGNAL(clicked()), P3mod, SLOT(SubmitButtonPressed()));
        QObject::connect(comboBox, SIGNAL(currentIndexChanged(QString)), MakeInput, SLOT(setText(QString)));
        QObject::connect(CancelButton, SIGNAL(clicked()), P3mod, SLOT(hide()));

        QMetaObject::connectSlotsByName(P3mod);
    } // setupUi

    void retranslateUi(QWidget *P3mod)
    {
        P3mod->setWindowTitle(QApplication::translate("P3mod", "Product Management", 0));
        SubmitButton->setText(QApplication::translate("P3mod", "Submit", 0));
        label->setText(QApplication::translate("P3mod", "Product Management", 0));
        modOut->setText(QString());
        CancelButton->setText(QApplication::translate("P3mod", "Cancel", 0));
        label_2->setText(QApplication::translate("P3mod", "Name", 0));
        label_3->setText(QApplication::translate("P3mod", "Make", 0));
        label_4->setText(QApplication::translate("P3mod", "Price", 0));
        label_5->setText(QApplication::translate("P3mod", "Description", 0));
        label_6->setText(QApplication::translate("P3mod", "Quantity", 0));
        label_7->setText(QApplication::translate("P3mod", "Existing Makes to Choose From", 0));
        ModSuccessfulLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class P3mod: public Ui_P3mod {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_P3MOD_H
