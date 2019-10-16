/********************************************************************************
** Form generated from reading UI file 'exampoo.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXAMPOO_H
#define UI_EXAMPOO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EXAMPOOClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *EXAMPOOClass)
    {
        if (EXAMPOOClass->objectName().isEmpty())
            EXAMPOOClass->setObjectName(QStringLiteral("EXAMPOOClass"));
        EXAMPOOClass->resize(600, 400);
        menuBar = new QMenuBar(EXAMPOOClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        EXAMPOOClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(EXAMPOOClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        EXAMPOOClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(EXAMPOOClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        EXAMPOOClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(EXAMPOOClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        EXAMPOOClass->setStatusBar(statusBar);

        retranslateUi(EXAMPOOClass);

        QMetaObject::connectSlotsByName(EXAMPOOClass);
    } // setupUi

    void retranslateUi(QMainWindow *EXAMPOOClass)
    {
        EXAMPOOClass->setWindowTitle(QApplication::translate("EXAMPOOClass", "EXAMPOO", 0));
    } // retranslateUi

};

namespace Ui {
    class EXAMPOOClass: public Ui_EXAMPOOClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXAMPOO_H
