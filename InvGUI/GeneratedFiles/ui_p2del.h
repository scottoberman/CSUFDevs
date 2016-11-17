/********************************************************************************
** Form generated from reading UI file 'p2del.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_P2DEL_H
#define UI_P2DEL_H

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

class Ui_P2del
{
public:
    QLabel *label_3;
    QPushButton *pushButton;
    QLabel *label_2;
    QTextEdit *textEdit;
    QLabel *label;

    void setupUi(QWidget *P2del)
    {
        if (P2del->objectName().isEmpty())
            P2del->setObjectName(QStringLiteral("P2del"));
        P2del->resize(401, 447);
        label_3 = new QLabel(P2del);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(70, 70, 71, 16));
        pushButton = new QPushButton(P2del);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(70, 140, 75, 23));
        label_2 = new QLabel(P2del);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 30, 101, 16));
        textEdit = new QTextEdit(P2del);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(105, 65, 101, 26));
        label = new QLabel(P2del);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 180, 141, 21));

        retranslateUi(P2del);

        QMetaObject::connectSlotsByName(P2del);
    } // setupUi

    void retranslateUi(QWidget *P2del)
    {
        P2del->setWindowTitle(QApplication::translate("P2del", "Form", 0));
        label_3->setText(QApplication::translate("P2del", "P_id", 0));
        pushButton->setText(QApplication::translate("P2del", "Submit", 0));
        label_2->setText(QApplication::translate("P2del", "Delete Product", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class P2del: public Ui_P2del {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_P2DEL_H
