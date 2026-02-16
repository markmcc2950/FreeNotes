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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
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
    QAction *actionSaveAs;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QToolButton *toolButtonItalic;
    QTextEdit *mainTextField;
    QToolButton *toolButtonUnderline;
    QToolButton *toolButtonBold;
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
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::DocumentNew));
        MainWindow->setWindowIcon(icon);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        actionSaveAs = new QAction(MainWindow);
        actionSaveAs->setObjectName("actionSaveAs");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        toolButtonItalic = new QToolButton(centralwidget);
        toolButtonItalic->setObjectName("toolButtonItalic");
        QFont font;
        font.setBold(false);
        font.setItalic(true);
        toolButtonItalic->setFont(font);
        toolButtonItalic->setCheckable(true);

        gridLayout->addWidget(toolButtonItalic, 0, 6, 1, 1);

        mainTextField = new QTextEdit(centralwidget);
        mainTextField->setObjectName("mainTextField");

        gridLayout->addWidget(mainTextField, 2, 0, 1, 8);

        toolButtonUnderline = new QToolButton(centralwidget);
        toolButtonUnderline->setObjectName("toolButtonUnderline");
        QFont font1;
        font1.setBold(false);
        font1.setItalic(false);
        font1.setUnderline(true);
        toolButtonUnderline->setFont(font1);
        toolButtonUnderline->setCheckable(true);

        gridLayout->addWidget(toolButtonUnderline, 0, 7, 1, 1);

        toolButtonBold = new QToolButton(centralwidget);
        toolButtonBold->setObjectName("toolButtonBold");
        QFont font2;
        font2.setBold(true);
        toolButtonBold->setFont(font2);
        toolButtonBold->setCheckable(true);

        gridLayout->addWidget(toolButtonBold, 0, 5, 1, 1);

        toolButtonSave = new QToolButton(centralwidget);
        toolButtonSave->setObjectName("toolButtonSave");
        toolButtonSave->setFont(font2);
        toolButtonSave->setCheckable(false);

        gridLayout->addWidget(toolButtonSave, 0, 0, 1, 1);

        toolButtonOpen = new QToolButton(centralwidget);
        toolButtonOpen->setObjectName("toolButtonOpen");
        toolButtonOpen->setFont(font2);
        toolButtonOpen->setCheckable(false);

        gridLayout->addWidget(toolButtonOpen, 0, 1, 1, 1);

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
        menuFile->addAction(actionSaveAs);
        menuFile->addAction(actionExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "FreeNotes", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionSaveAs->setText(QCoreApplication::translate("MainWindow", "Save As", nullptr));
        toolButtonItalic->setText(QCoreApplication::translate("MainWindow", "I", nullptr));
#if QT_CONFIG(shortcut)
        toolButtonItalic->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+I", nullptr));
#endif // QT_CONFIG(shortcut)
        toolButtonUnderline->setText(QCoreApplication::translate("MainWindow", "U", nullptr));
#if QT_CONFIG(shortcut)
        toolButtonUnderline->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+U", nullptr));
#endif // QT_CONFIG(shortcut)
        toolButtonBold->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
#if QT_CONFIG(shortcut)
        toolButtonBold->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+B", nullptr));
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
