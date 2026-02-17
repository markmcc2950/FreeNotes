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
    QToolButton *toolButtonUnderline;
    QTextEdit *mainTextField;
    QToolButton *toolButtonOpen;
    QToolButton *toolButtonSave;
    QToolButton *toolButtonItalic;
    QToolButton *toolButtonBold;
    QStatusBar *statusbar;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuX;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setWindowModality(Qt::WindowModality::NonModal);
        MainWindow->resize(800, 665);
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::DocumentNew));
        MainWindow->setWindowIcon(icon);
        MainWindow->setTabShape(QTabWidget::TabShape::Rounded);
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
        toolButtonUnderline = new QToolButton(centralwidget);
        toolButtonUnderline->setObjectName("toolButtonUnderline");
        QFont font;
        font.setBold(false);
        font.setItalic(false);
        font.setUnderline(true);
        toolButtonUnderline->setFont(font);
        toolButtonUnderline->setCheckable(true);

        gridLayout->addWidget(toolButtonUnderline, 0, 9, 1, 1);

        mainTextField = new QTextEdit(centralwidget);
        mainTextField->setObjectName("mainTextField");
        mainTextField->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CursorShape::IBeamCursor)));

        gridLayout->addWidget(mainTextField, 1, 0, 1, 10);

        toolButtonOpen = new QToolButton(centralwidget);
        toolButtonOpen->setObjectName("toolButtonOpen");
        QFont font1;
        font1.setBold(true);
        toolButtonOpen->setFont(font1);
        toolButtonOpen->setCheckable(false);

        gridLayout->addWidget(toolButtonOpen, 0, 1, 1, 1);

        toolButtonSave = new QToolButton(centralwidget);
        toolButtonSave->setObjectName("toolButtonSave");
        toolButtonSave->setFont(font1);
        toolButtonSave->setCheckable(false);

        gridLayout->addWidget(toolButtonSave, 0, 0, 1, 1);

        toolButtonItalic = new QToolButton(centralwidget);
        toolButtonItalic->setObjectName("toolButtonItalic");
        QFont font2;
        font2.setBold(false);
        font2.setItalic(true);
        toolButtonItalic->setFont(font2);
        toolButtonItalic->setCheckable(true);

        gridLayout->addWidget(toolButtonItalic, 0, 8, 1, 1);

        toolButtonBold = new QToolButton(centralwidget);
        toolButtonBold->setObjectName("toolButtonBold");
        toolButtonBold->setFont(font1);
        toolButtonBold->setCheckable(true);

        gridLayout->addWidget(toolButtonBold, 0, 7, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 800, 25));
        menuBar->setAutoFillBackground(true);
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName("menuFile");
        menuX = new QMenu(menuBar);
        menuX->setObjectName("menuX");
        menuX->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::ApplicationExit));
        menuX->setIcon(icon1);
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuX->menuAction());
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
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open...", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionSaveAs->setText(QCoreApplication::translate("MainWindow", "Save As...", nullptr));
#if QT_CONFIG(shortcut)
        actionSaveAs->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        toolButtonUnderline->setText(QCoreApplication::translate("MainWindow", "U", nullptr));
#if QT_CONFIG(shortcut)
        toolButtonUnderline->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+U", nullptr));
#endif // QT_CONFIG(shortcut)
        toolButtonOpen->setText(QCoreApplication::translate("MainWindow", "\360\237\223\201", nullptr));
        toolButtonSave->setText(QCoreApplication::translate("MainWindow", "\360\237\222\276", nullptr));
        toolButtonItalic->setText(QCoreApplication::translate("MainWindow", "I", nullptr));
#if QT_CONFIG(shortcut)
        toolButtonItalic->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+I", nullptr));
#endif // QT_CONFIG(shortcut)
        toolButtonBold->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
#if QT_CONFIG(shortcut)
        toolButtonBold->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+B", nullptr));
#endif // QT_CONFIG(shortcut)
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuX->setTitle(QCoreApplication::translate("MainWindow", "X", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
