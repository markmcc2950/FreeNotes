#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->toolButtonBold, &QToolButton::clicked, this, &MainWindow::onFontButtonClicked);
    connect(ui->toolButtonItalic, &QToolButton::clicked, this, &MainWindow::onFontButtonClicked);
    connect(ui->toolButtonUnderline, &QToolButton::clicked, this, &MainWindow::onFontButtonClicked);

    connect(ui->actionExit, &QAction::triggered, this, &MainWindow::close);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onFontButtonClicked() {
    QTextCursor cursor = ui->mainTextField->textCursor();
    QTextCharFormat fmt;

    isBold = ui->toolButtonBold->isChecked();
    isItalic = ui->toolButtonItalic->isChecked();
    isUnderline = ui->toolButtonUnderline->isChecked();

    fmt.setFontWeight(isBold ? QFont::Bold : QFont::Normal);
    fmt.setFontItalic(isItalic);
    fmt.setFontUnderline(isUnderline);

    if (cursor.hasSelection()) {
        cursor.mergeCharFormat(fmt);
    } else {
        ui->mainTextField->setCurrentCharFormat(fmt);
    }

    ui->mainTextField->setFocus();
}
