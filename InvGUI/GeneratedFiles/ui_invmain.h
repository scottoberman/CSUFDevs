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
    QPushButton *InventoryButton;
    QPushButton *UsersButton;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *Logout;
    QPushButton *ExitButton;

    void setupUi(QWidget *InvMain)
    {
        if (InvMain->objectName().isEmpty())
            InvMain->setObjectName(QStringLiteral("InvMain"));
        InvMain->resize(1377, 692);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(InvMain->sizePolicy().hasHeightForWidth());
        InvMain->setSizePolicy(sizePolicy);
        InvMain->setMinimumSize(QSize(1377, 692));
        InvMain->setMaximumSize(QSize(1377, 692));
        InventoryButton = new QPushButton(InvMain);
        InventoryButton->setObjectName(QStringLiteral("InventoryButton"));
        InventoryButton->setGeometry(QRect(20, 60, 75, 23));
        InventoryButton->setMinimumSize(QSize(75, 23));
        InventoryButton->setMaximumSize(QSize(75, 23));
        UsersButton = new QPushButton(InvMain);
        UsersButton->setObjectName(QStringLiteral("UsersButton"));
        UsersButton->setGeometry(QRect(20, 110, 75, 23));
        UsersButton->setMinimumSize(QSize(75, 23));
        UsersButton->setMaximumSize(QSize(75, 23));
        horizontalLayoutWidget = new QWidget(InvMain);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(120, 50, 1221, 531));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(1, 0, 0, 0);
        Logout = new QPushButton(InvMain);
        Logout->setObjectName(QStringLiteral("Logout"));
        Logout->setGeometry(QRect(20, 620, 75, 23));
        ExitButton = new QPushButton(InvMain);
        ExitButton->setObjectName(QStringLiteral("ExitButton"));
        ExitButton->setGeometry(QRect(20, 660, 75, 23));

        retranslateUi(InvMain);

        QMetaObject::connectSlotsByName(InvMain);
    } // setupUi

    void retranslateUi(QWidget *InvMain)
    {
        InvMain->setWindowTitle(QApplication::translate("InvMain", "Form", 0));
        InventoryButton->setText(QApplication::translate("InvMain", "Inventory", 0));
        UsersButton->setText(QApplication::translate("InvMain", "Users", 0));
        Logout->setText(QApplication::translate("InvMain", "Logout", 0));
        ExitButton->setText(QApplication::translate("InvMain", "Exit", 0));
    } // retranslateUi

};

namespace Ui {
    class InvMain: public Ui_InvMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVMAIN_H
