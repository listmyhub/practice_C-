/********************************************************************************
** Form generated from reading UI file 'minidraw.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MINIDRAW_H
#define UI_MINIDRAW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MiniDraw
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MiniDraw)
    {
        if (MiniDraw->objectName().isEmpty())
            MiniDraw->setObjectName("MiniDraw");
        MiniDraw->resize(800, 600);
        centralwidget = new QWidget(MiniDraw);
        centralwidget->setObjectName("centralwidget");
        MiniDraw->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MiniDraw);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MiniDraw->setMenuBar(menubar);
        statusbar = new QStatusBar(MiniDraw);
        statusbar->setObjectName("statusbar");
        MiniDraw->setStatusBar(statusbar);

        retranslateUi(MiniDraw);

        QMetaObject::connectSlotsByName(MiniDraw);
    } // setupUi

    void retranslateUi(QMainWindow *MiniDraw)
    {
        MiniDraw->setWindowTitle(QCoreApplication::translate("MiniDraw", "MiniDraw", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MiniDraw: public Ui_MiniDraw {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MINIDRAW_H
