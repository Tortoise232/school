/********************************************************************************
** Form generated from reading UI file 'moviesgui.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOVIESGUI_H
#define UI_MOVIESGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MoviesGUIClass
{
public:

    void setupUi(QWidget *MoviesGUIClass)
    {
        if (MoviesGUIClass->objectName().isEmpty())
            MoviesGUIClass->setObjectName(QStringLiteral("MoviesGUIClass"));
        MoviesGUIClass->resize(600, 400);

        retranslateUi(MoviesGUIClass);

        QMetaObject::connectSlotsByName(MoviesGUIClass);
    } // setupUi

    void retranslateUi(QWidget *MoviesGUIClass)
    {
        MoviesGUIClass->setWindowTitle(QApplication::translate("MoviesGUIClass", "MoviesGUI", 0));
    } // retranslateUi

};

namespace Ui {
    class MoviesGUIClass: public Ui_MoviesGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOVIESGUI_H
