/********************************************************************************
** Form generated from reading UI file 'ItemMain.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ITEMMAIN_H
#define UI_ITEMMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ItemMain
{
public:
    QTableWidget *tableWidget;
    QPushButton *AddItemButton;
    QPushButton *ModifySelectedItemButton;
    QPushButton *DeleteSelectedItemButton;
    QPushButton *SearchForItemButton;

    void setupUi(QWidget *ItemMain)
    {
        if (ItemMain->objectName().isEmpty())
            ItemMain->setObjectName(QStringLiteral("ItemMain"));
        ItemMain->resize(1087, 531);
        tableWidget = new QTableWidget(ItemMain);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
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
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(0, 10, 1061, 461));
        tableWidget->horizontalHeader()->setDefaultSectionSize(100);
        AddItemButton = new QPushButton(ItemMain);
        AddItemButton->setObjectName(QStringLiteral("AddItemButton"));
        AddItemButton->setGeometry(QRect(20, 480, 75, 23));
        ModifySelectedItemButton = new QPushButton(ItemMain);
        ModifySelectedItemButton->setObjectName(QStringLiteral("ModifySelectedItemButton"));
        ModifySelectedItemButton->setGeometry(QRect(650, 490, 181, 23));
        DeleteSelectedItemButton = new QPushButton(ItemMain);
        DeleteSelectedItemButton->setObjectName(QStringLiteral("DeleteSelectedItemButton"));
        DeleteSelectedItemButton->setGeometry(QRect(850, 490, 191, 23));
        SearchForItemButton = new QPushButton(ItemMain);
        SearchForItemButton->setObjectName(QStringLiteral("SearchForItemButton"));
        SearchForItemButton->setGeometry(QRect(110, 480, 91, 23));
        QWidget::setTabOrder(AddItemButton, SearchForItemButton);
        QWidget::setTabOrder(SearchForItemButton, ModifySelectedItemButton);
        QWidget::setTabOrder(ModifySelectedItemButton, DeleteSelectedItemButton);
        QWidget::setTabOrder(DeleteSelectedItemButton, tableWidget);

        retranslateUi(ItemMain);

        QMetaObject::connectSlotsByName(ItemMain);
    } // setupUi

    void retranslateUi(QWidget *ItemMain)
    {
        ItemMain->setWindowTitle(QApplication::translate("ItemMain", "ItemMain", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ItemMain", "ID", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ItemMain", "Name", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ItemMain", "Make", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("ItemMain", "Price", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("ItemMain", "Quantity", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("ItemMain", "Description", 0));
        AddItemButton->setText(QApplication::translate("ItemMain", "Add Item", 0));
        ModifySelectedItemButton->setText(QApplication::translate("ItemMain", "Modify Selected Item", 0));
        DeleteSelectedItemButton->setText(QApplication::translate("ItemMain", "Delete Selected Item", 0));
        SearchForItemButton->setText(QApplication::translate("ItemMain", "Search for item", 0));
    } // retranslateUi

};

namespace Ui {
    class ItemMain: public Ui_ItemMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ITEMMAIN_H
