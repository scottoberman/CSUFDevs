/********************************************************************************
** Form generated from reading UI file 'SearchItem.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHITEM_H
#define UI_SEARCHITEM_H

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

class Ui_SearchItem
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QRadioButton *ByName;
    QRadioButton *ByNum;
    QTextBrowser *textBrowser;
    QTextEdit *textEdit;
    QPushButton *pushButton_2;

    void setupUi(QWidget *SearchItem)
    {
        if (SearchItem->objectName().isEmpty())
            SearchItem->setObjectName(QStringLiteral("SearchItem"));
        SearchItem->resize(467, 338);
        label = new QLabel(SearchItem);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(25, 20, 81, 16));
        pushButton = new QPushButton(SearchItem);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(40, 150, 75, 23));
        ByName = new QRadioButton(SearchItem);
        ByName->setObjectName(QStringLiteral("ByName"));
        ByName->setGeometry(QRect(20, 50, 82, 17));
        ByNum = new QRadioButton(SearchItem);
        ByNum->setObjectName(QStringLiteral("ByNum"));
        ByNum->setGeometry(QRect(20, 80, 101, 17));
        textBrowser = new QTextBrowser(SearchItem);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(155, 15, 281, 306));
        QFont font;
        font.setFamily(QStringLiteral("Courier"));
        textBrowser->setFont(font);
        textEdit = new QTextEdit(SearchItem);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(20, 110, 106, 26));
        pushButton_2 = new QPushButton(SearchItem);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(40, 290, 75, 23));

        retranslateUi(SearchItem);
        QObject::connect(pushButton_2, SIGNAL(clicked()), SearchItem, SLOT(hide()));

        QMetaObject::connectSlotsByName(SearchItem);
    } // setupUi

    void retranslateUi(QWidget *SearchItem)
    {
        SearchItem->setWindowTitle(QApplication::translate("SearchItem", "Search for Item", 0));
        label->setText(QApplication::translate("SearchItem", "Search for Item", 0));
        pushButton->setText(QApplication::translate("SearchItem", "Search", 0));
        ByName->setText(QApplication::translate("SearchItem", "by name", 0));
        ByNum->setText(QApplication::translate("SearchItem", "by item number", 0));
        pushButton_2->setText(QApplication::translate("SearchItem", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class SearchItem: public Ui_SearchItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHITEM_H
