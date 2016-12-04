/********************************************************************************
** Form generated from reading UI file 'UserMain.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERMAIN_H
#define UI_USERMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserMain
{
public:
    QTableWidget *tableWidget;
    QPushButton *AddUserButton;
    QPushButton *ModifySelectedUserButton;
    QPushButton *DeleteSelectedUserButton;

    void setupUi(QWidget *UserMain)
    {
        if (UserMain->objectName().isEmpty())
            UserMain->setObjectName(QStringLiteral("UserMain"));
        UserMain->resize(1087, 531);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(UserMain->sizePolicy().hasHeightForWidth());
        UserMain->setSizePolicy(sizePolicy);
        tableWidget = new QTableWidget(UserMain);
        if (tableWidget->columnCount() < 7)
            tableWidget->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(0, 10, 1061, 471));
        AddUserButton = new QPushButton(UserMain);
        AddUserButton->setObjectName(QStringLiteral("AddUserButton"));
        AddUserButton->setGeometry(QRect(20, 490, 75, 23));
        ModifySelectedUserButton = new QPushButton(UserMain);
        ModifySelectedUserButton->setObjectName(QStringLiteral("ModifySelectedUserButton"));
        ModifySelectedUserButton->setGeometry(QRect(650, 490, 181, 23));
        DeleteSelectedUserButton = new QPushButton(UserMain);
        DeleteSelectedUserButton->setObjectName(QStringLiteral("DeleteSelectedUserButton"));
        DeleteSelectedUserButton->setGeometry(QRect(850, 490, 191, 23));

        retranslateUi(UserMain);

        QMetaObject::connectSlotsByName(UserMain);
    } // setupUi

    void retranslateUi(QWidget *UserMain)
    {
        UserMain->setWindowTitle(QApplication::translate("UserMain", "UserMain", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("UserMain", "ID", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("UserMain", "Username", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("UserMain", "First Name", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("UserMain", "Last Name", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("UserMain", "Email", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("UserMain", "Privilege Level", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("UserMain", "Password", 0));
        AddUserButton->setText(QApplication::translate("UserMain", "Add User", 0));
        ModifySelectedUserButton->setText(QApplication::translate("UserMain", "Modify Selected User", 0));
        DeleteSelectedUserButton->setText(QApplication::translate("UserMain", "Delete Selected User", 0));
    } // retranslateUi

};

namespace Ui {
    class UserMain: public Ui_UserMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERMAIN_H
