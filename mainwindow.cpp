#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "FileHandler.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->toolButtonBold, &QToolButton::clicked, this, &MainWindow::onFontButtonClicked);
    connect(ui->toolButtonItalic, &QToolButton::clicked, this, &MainWindow::onFontButtonClicked);
    connect(ui->toolButtonUnderline, &QToolButton::clicked, this, &MainWindow::onFontButtonClicked);

    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::onLoadButtonClicked);
    connect(ui->toolButtonOpen, &QToolButton::clicked, this, &MainWindow::onLoadButtonClicked);
    connect(ui->actionSave, &QAction::triggered, this, &MainWindow::onSaveButtonClicked);
    connect(ui->toolButtonSave, &QToolButton::clicked, this, &MainWindow::onSaveButtonClicked);
    connect(ui->actionSaveAs, &QAction::triggered, this, &MainWindow::onSaveAsButtonClicked);
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

void MainWindow::onLoadButtonClicked() {
    std::string path = fh.openFileDialog();
    if (path != "") {
        filePath = QString::fromStdString(path);
        QString sanitizedString = fh.sanitizeString(filePath);

        std::string contents;

        fh.openFromFile(contents, path);

        // Convert to QString now since it's referenced twice ahead
        QString contents_Q = QString::fromStdString(contents);

        lastSavedText = contents_Q;

        ui->mainTextField->setText(contents_Q);
        setWindowTitle(windowTitle + " - " + sanitizedString);
    }
}

void MainWindow::onSaveButtonClicked() {
    if (filePath == "") {
        filePath = QString::fromStdString(fh.saveFileDialog());
    }
    std::string textField = ui->mainTextField->toHtml().toStdString();
    fh.saveToFile(textField, filePath.toStdString());

    QString sanitizedString = fh.sanitizeString(filePath);
    setWindowTitle(windowTitle + " - " + sanitizedString);
}

void MainWindow::onSaveAsButtonClicked() {
    filePath = QString::fromStdString(fh.saveFileDialog());

    std::string textField = ui->mainTextField->toHtml().toStdString();
    fh.saveToFile(textField, filePath.toStdString());

    // FIX THIS
    QString sanitizedPath = fh.sanitizeString(filePath);
    QString sanitizedString = " - " + sanitizedPath;
    setWindowTitle(windowTitle + sanitizedString);
}
