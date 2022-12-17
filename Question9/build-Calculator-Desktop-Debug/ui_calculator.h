/********************************************************************************
** Form generated from reading UI file 'calculator.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATOR_H
#define UI_CALCULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Calculator
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *keypad;
    QPushButton *btnp;
    QPushButton *btnmi;
    QPushButton *btn5;
    QPushButton *btn0;
    QPushButton *btn1;
    QPushButton *btn4;
    QPushButton *btnmu;
    QPushButton *btn6;
    QPushButton *btn3;
    QPushButton *btnd;
    QPushButton *btn8;
    QPushButton *btn9;
    QPushButton *btn7;
    QPushButton *btne;
    QPushButton *btn2;
    QLabel *label_3;
    QWidget *widget;
    QGridLayout *gresult;
    QLabel *preview;
    QLabel *result;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Calculator)
    {
        if (Calculator->objectName().isEmpty())
            Calculator->setObjectName(QString::fromUtf8("Calculator"));
        Calculator->resize(351, 600);
        QFont font;
        font.setPointSize(15);
        Calculator->setFont(font);
        centralwidget = new QWidget(Calculator);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QFont font1;
        font1.setPointSize(20);
        centralwidget->setFont(font1);
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 130, 351, 411));
        keypad = new QGridLayout(gridLayoutWidget);
        keypad->setSpacing(0);
        keypad->setObjectName(QString::fromUtf8("keypad"));
        keypad->setContentsMargins(5, 0, 5, 0);
        btnp = new QPushButton(gridLayoutWidget);
        btnp->setObjectName(QString::fromUtf8("btnp"));

        keypad->addWidget(btnp, 0, 3, 1, 1);

        btnmi = new QPushButton(gridLayoutWidget);
        btnmi->setObjectName(QString::fromUtf8("btnmi"));

        keypad->addWidget(btnmi, 1, 3, 1, 1);

        btn5 = new QPushButton(gridLayoutWidget);
        btn5->setObjectName(QString::fromUtf8("btn5"));
        btn5->setEnabled(true);
        btn5->setFont(font1);

        keypad->addWidget(btn5, 2, 1, 1, 1);

        btn0 = new QPushButton(gridLayoutWidget);
        btn0->setObjectName(QString::fromUtf8("btn0"));

        keypad->addWidget(btn0, 4, 1, 1, 1);

        btn1 = new QPushButton(gridLayoutWidget);
        btn1->setObjectName(QString::fromUtf8("btn1"));

        keypad->addWidget(btn1, 3, 0, 1, 1);

        btn4 = new QPushButton(gridLayoutWidget);
        btn4->setObjectName(QString::fromUtf8("btn4"));
        btn4->setFont(font1);

        keypad->addWidget(btn4, 2, 0, 1, 1);

        btnmu = new QPushButton(gridLayoutWidget);
        btnmu->setObjectName(QString::fromUtf8("btnmu"));

        keypad->addWidget(btnmu, 2, 3, 1, 1);

        btn6 = new QPushButton(gridLayoutWidget);
        btn6->setObjectName(QString::fromUtf8("btn6"));

        keypad->addWidget(btn6, 2, 2, 1, 1);

        btn3 = new QPushButton(gridLayoutWidget);
        btn3->setObjectName(QString::fromUtf8("btn3"));

        keypad->addWidget(btn3, 3, 2, 1, 1);

        btnd = new QPushButton(gridLayoutWidget);
        btnd->setObjectName(QString::fromUtf8("btnd"));

        keypad->addWidget(btnd, 3, 3, 1, 1);

        btn8 = new QPushButton(gridLayoutWidget);
        btn8->setObjectName(QString::fromUtf8("btn8"));
        btn8->setFont(font1);

        keypad->addWidget(btn8, 1, 1, 1, 1);

        btn9 = new QPushButton(gridLayoutWidget);
        btn9->setObjectName(QString::fromUtf8("btn9"));
        btn9->setFont(font1);

        keypad->addWidget(btn9, 1, 2, 1, 1);

        btn7 = new QPushButton(gridLayoutWidget);
        btn7->setObjectName(QString::fromUtf8("btn7"));
        btn7->setFont(font1);

        keypad->addWidget(btn7, 1, 0, 1, 1);

        btne = new QPushButton(gridLayoutWidget);
        btne->setObjectName(QString::fromUtf8("btne"));

        keypad->addWidget(btne, 4, 3, 1, 1);

        btn2 = new QPushButton(gridLayoutWidget);
        btn2->setObjectName(QString::fromUtf8("btn2"));

        keypad->addWidget(btn2, 3, 1, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(100, 0, 151, 41));
        label_3->setAlignment(Qt::AlignCenter);
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(90, 40, 251, 72));
        gresult = new QGridLayout(widget);
        gresult->setObjectName(QString::fromUtf8("gresult"));
        gresult->setContentsMargins(0, 0, 0, 0);
        preview = new QLabel(widget);
        preview->setObjectName(QString::fromUtf8("preview"));
        preview->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gresult->addWidget(preview, 0, 0, 1, 1);

        result = new QLabel(widget);
        result->setObjectName(QString::fromUtf8("result"));
        result->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gresult->addWidget(result, 1, 0, 1, 1);

        Calculator->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Calculator);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 351, 28));
        Calculator->setMenuBar(menubar);
        statusbar = new QStatusBar(Calculator);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Calculator->setStatusBar(statusbar);

        retranslateUi(Calculator);

        QMetaObject::connectSlotsByName(Calculator);
    } // setupUi

    void retranslateUi(QMainWindow *Calculator)
    {
        Calculator->setWindowTitle(QCoreApplication::translate("Calculator", "Calculator", nullptr));
        btnp->setText(QCoreApplication::translate("Calculator", "+", nullptr));
        btnmi->setText(QCoreApplication::translate("Calculator", "-", nullptr));
        btn5->setText(QCoreApplication::translate("Calculator", "5", nullptr));
        btn0->setText(QCoreApplication::translate("Calculator", "0", nullptr));
        btn1->setText(QCoreApplication::translate("Calculator", "1", nullptr));
        btn4->setText(QCoreApplication::translate("Calculator", "4", nullptr));
        btnmu->setText(QCoreApplication::translate("Calculator", "*", nullptr));
        btn6->setText(QCoreApplication::translate("Calculator", "6", nullptr));
        btn3->setText(QCoreApplication::translate("Calculator", "3", nullptr));
        btnd->setText(QCoreApplication::translate("Calculator", "/", nullptr));
        btn8->setText(QCoreApplication::translate("Calculator", "8", nullptr));
        btn9->setText(QCoreApplication::translate("Calculator", "9", nullptr));
        btn7->setText(QCoreApplication::translate("Calculator", "7", nullptr));
        btne->setText(QCoreApplication::translate("Calculator", "=", nullptr));
        btn2->setText(QCoreApplication::translate("Calculator", "2", nullptr));
        label_3->setText(QCoreApplication::translate("Calculator", "\354\273\264\354\206\214 \352\263\204\354\202\260\352\270\260", nullptr));
        preview->setText(QCoreApplication::translate("Calculator", "0", nullptr));
        result->setText(QCoreApplication::translate("Calculator", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Calculator: public Ui_Calculator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATOR_H
