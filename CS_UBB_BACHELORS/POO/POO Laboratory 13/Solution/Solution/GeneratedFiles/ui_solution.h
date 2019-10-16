/********************************************************************************
** Form generated from reading UI file 'solution.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOLUTION_H
#define UI_SOLUTION_H

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

class Ui_SolutionClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SolutionClass)
    {
        if (SolutionClass->objectName().isEmpty())
            SolutionClass->setObjectName(QStringLiteral("SolutionClass"));
        SolutionClass->resize(600, 400);
        menuBar = new QMenuBar(SolutionClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        SolutionClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SolutionClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SolutionClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(SolutionClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        SolutionClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(SolutionClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SolutionClass->setStatusBar(statusBar);

        retranslateUi(SolutionClass);

        QMetaObject::connectSlotsByName(SolutionClass);
    } // setupUi

    void retranslateUi(QMainWindow *SolutionClass)
    {
        SolutionClass->setWindowTitle(QApplication::translate("SolutionClass", "Solution", 0));
    } // retranslateUi

};

namespace Ui {
    class SolutionClass: public Ui_SolutionClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOLUTION_H
