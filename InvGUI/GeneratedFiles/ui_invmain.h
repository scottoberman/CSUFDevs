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
    QPushButton *Page1Button;
    QPushButton *Page2Button;
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
        Page1Button = new QPushButton(InvMain);
        Page1Button->setObjectName(QStringLiteral("Page1Button"));
        Page1Button->setGeometry(QRect(20, 60, 75, 23));
        Page1Button->setMinimumSize(QSize(75, 23));
        Page1Button->setMaximumSize(QSize(75, 23));
        Page2Button = new QPushButton(InvMain);
        Page2Button->setObjectName(QStringLiteral("Page2Button"));
        Page2Button->setGeometry(QRect(20, 110, 75, 23));
        Page2Button->setMinimumSize(QSize(75, 23));
        Page2Button->setMaximumSize(QSize(75, 23));
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
        Page1Button->setText(QApplication::translate("InvMain", "Inventory", 0));
        Page2Button->setText(QApplication::translate("InvMain", "Users", 0));
        Logout->setText(QApplication::translate("InvMain", "Logout", 0));
        ExitButton->setText(QApplication::translate("InvMain", "Exit", 0));
    } // retranslateUi

};

namespace Ui {
    class InvMain: public Ui_InvMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVMAIN_H
