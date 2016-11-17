/********************************************************************************
** Form generated from reading UI file 'invmain.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVMAIN_H
#define UI_INVMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InvMain
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *Page3Button;
    QPushButton *Page1Button;
    QPushButton *Page2Button;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *InvMain)
    {
        if (InvMain->objectName().isEmpty())
            InvMain->setObjectName(QStringLiteral("InvMain"));
        InvMain->resize(640, 480);
        horizontalLayoutWidget = new QWidget(InvMain);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(130, 40, 491, 431));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Page3Button = new QPushButton(InvMain);
        Page3Button->setObjectName(QStringLiteral("Page3Button"));
        Page3Button->setGeometry(QRect(20, 140, 91, 23));
        Page1Button = new QPushButton(InvMain);
        Page1Button->setObjectName(QStringLiteral("Page1Button"));
        Page1Button->setGeometry(QRect(20, 40, 75, 23));
        Page2Button = new QPushButton(InvMain);
        Page2Button->setObjectName(QStringLiteral("Page2Button"));
        Page2Button->setGeometry(QRect(20, 90, 91, 23));
        pushButton = new QPushButton(InvMain);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 235, 91, 23));
        pushButton_2 = new QPushButton(InvMain);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 190, 75, 23));

        retranslateUi(InvMain);

        QMetaObject::connectSlotsByName(InvMain);
    } // setupUi

    void retranslateUi(QWidget *InvMain)
    {
        InvMain->setWindowTitle(QApplication::translate("InvMain", "Form", 0));
        Page3Button->setText(QApplication::translate("InvMain", "Modify Product", 0));
        Page1Button->setText(QApplication::translate("InvMain", "Add Product", 0));
        Page2Button->setText(QApplication::translate("InvMain", "Delete Product", 0));
        pushButton->setText(QApplication::translate("InvMain", "Print Database", 0));
        pushButton_2->setText(QApplication::translate("InvMain", "Create User", 0));
    } // retranslateUi

};

namespace Ui {
    class InvMain: public Ui_InvMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVMAIN_H
