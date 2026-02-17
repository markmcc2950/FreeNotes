#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "FileHandler.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->menuBar->installEventFilter(this);
    ui->menuBar->setCursor(Qt::OpenHandCursor);
    this->setWindowFlags(Qt::WindowType::FramelessWindowHint);

    connect(ui->toolButtonBold, &QToolButton::clicked, this, &MainWindow::onFontButtonClicked);
    connect(ui->toolButtonItalic, &QToolButton::clicked, this, &MainWindow::onFontButtonClicked);
    connect(ui->toolButtonUnderline, &QToolButton::clicked, this, &MainWindow::onFontButtonClicked);

    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::onLoadButtonClicked);
    connect(ui->toolButtonOpen, &QToolButton::clicked, this, &MainWindow::onLoadButtonClicked);
    connect(ui->actionSave, &QAction::triggered, this, &MainWindow::onSaveButtonClicked);
    connect(ui->toolButtonSave, &QToolButton::clicked, this, &MainWindow::onSaveButtonClicked);
    connect(ui->actionSaveAs, &QAction::triggered, this, &MainWindow::onSaveAsButtonClicked);
    connect(ui->actionExit, &QAction::triggered, this, &MainWindow::close);

    qDebug() << "Window flags: " << this->windowFlags();
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event) {
    // Disable the menu file (drop down menu) when we're dragging the window around
    ui->menuFile->menuAction()->setEnabled(!isDragging);

    if (watched == ui->menuBar) {
        if (event->type() == QEvent::MouseButtonPress)
        {
            QMouseEvent* mouse_event = dynamic_cast<QMouseEvent*>(event);
            QAction* hovered = ui->menuBar->actionAt(mouse_event->pos());
            if (hovered == ui->menuFile->menuAction()) {
                return false;
            }
            this->setCursor(Qt::OpenHandCursor);
            if (mouse_event->button() == Qt::LeftButton && hovered != ui->menuFile->menuAction()) {
                cur_pos = mouse_event->globalPosition().toPoint();
                return false;
            }
        }
        else if (event->type() == QEvent::MouseMove) {
            QMouseEvent* mouse_event = dynamic_cast<QMouseEvent*>(event);
            QAction* hovered = ui->menuBar->actionAt(mouse_event->pos());
            if (hovered == ui->menuFile->menuAction()) {
                return false;
            }
            if (mouse_event->buttons() & Qt::LeftButton && !ui->menuFile->isVisible()) {
                this->setCursor(Qt::ClosedHandCursor);
                isDragging = true;
                new_pos = QPoint(mouse_event->globalPosition().toPoint() - cur_pos);
                move(x() + new_pos.x(), y() + new_pos.y());
                cur_pos = mouse_event->globalPosition().toPoint();
                return false;
            }
        }
        else if (event->type() == QEvent::MouseButtonRelease) {
            isDragging = false;
        }
    }
    return false;
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

        changeWindowTitle(filePath);
    }
}

void MainWindow::changeWindowTitle(const QString& filePath) {
    QString sanitizedPath = fh.sanitizeString(filePath);
    setWindowTitle(windowTitle + " - " + sanitizedPath);
}

void MainWindow::onSaveButtonClicked() {
    if (filePath == "") {
        filePath = QString::fromStdString(fh.saveFileDialog());
    }
    std::string textField = ui->mainTextField->toHtml().toStdString();
    fh.saveToFile(textField, filePath.toStdString());

    changeWindowTitle(filePath);
}

void MainWindow::onSaveAsButtonClicked() {
    filePath = QString::fromStdString(fh.saveFileDialog());

    std::string textField = ui->mainTextField->toHtml().toStdString();
    fh.saveToFile(textField, filePath.toStdString());

    changeWindowTitle(filePath);
}
