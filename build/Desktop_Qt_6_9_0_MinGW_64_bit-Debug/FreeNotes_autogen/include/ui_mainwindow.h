/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionExit;
    QWidget *centralwidget;
    QTextEdit *mainTextField;
    QToolButton *toolButtonBold;
    QToolButton *toolButtonItalic;
    QToolButton *toolButtonUnderline;
    QToolButton *toolButtonSave;
    QToolButton *toolButtonOpen;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        mainTextField = new QTextEdit(centralwidget);
        mainTextField->setObjectName("mainTextField");
        mainTextField->setGeometry(QRect(10, 40, 781, 501));
        toolButtonBold = new QToolButton(centralwidget);
        toolButtonBold->setObjectName("toolButtonBold");
        toolButtonBold->setGeometry(QRect(700, 10, 26, 27));
        QFont font;
        font.setBold(true);
        toolButtonBold->setFont(font);
        toolButtonBold->setCheckable(true);
        toolButtonItalic = new QToolButton(centralwidget);
        toolButtonItalic->setObjectName("toolButtonItalic");
        toolButtonItalic->setGeometry(QRect(730, 10, 26, 27));
        QFont font1;
        font1.setBold(false);
        font1.setItalic(true);
        toolButtonItalic->setFont(font1);
        toolButtonItalic->setCheckable(true);
        toolButtonUnderline = new QToolButton(centralwidget);
        toolButtonUnderline->setObjectName("toolButtonUnderline");
        toolButtonUnderline->setGeometry(QRect(760, 10, 26, 27));
        QFont font2;
        font2.setBold(false);
        font2.setItalic(false);
        font2.setUnderline(true);
        toolButtonUnderline->setFont(font2);
        toolButtonUnderline->setCheckable(true);
        toolButtonSave = new QToolButton(centralwidget);
        toolButtonSave->setObjectName("toolButtonSave");
        toolButtonSave->setGeometry(QRect(10, 10, 26, 27));
        toolButtonSave->setFont(font);
        toolButtonSave->setCheckable(true);
        toolButtonOpen = new QToolButton(centralwidget);
        toolButtonOpen->setObjectName("toolButtonOpen");
        toolButtonOpen->setGeometry(QRect(40, 10, 26, 27));
        toolButtonOpen->setFont(font);
        toolButtonOpen->setCheckable(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        toolButtonBold->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
#if QT_CONFIG(shortcut)
        toolButtonBold->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+B", nullptr));
#endif // QT_CONFIG(shortcut)
        toolButtonItalic->setText(QCoreApplication::translate("MainWindow", "I", nullptr));
#if QT_CONFIG(shortcut)
        toolButtonItalic->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+I", nullptr));
#endif // QT_CONFIG(shortcut)
        toolButtonUnderline->setText(QCoreApplication::translate("MainWindow", "U", nullptr));
#if QT_CONFIG(shortcut)
        toolButtonUnderline->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+U", nullptr));
#endif // QT_CONFIG(shortcut)
        toolButtonSave->setText(QCoreApplication::translate("MainWindow", "\360\237\222\276", nullptr));
#if QT_CONFIG(shortcut)
        toolButtonSave->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        toolButtonOpen->setText(QCoreApplication::translate("MainWindow", "\360\237\223\201", nullptr));
#if QT_CONFIG(shortcut)
        toolButtonOpen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
