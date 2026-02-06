#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void onFontButtonClicked();
    void onSaveButtonClicked();

    bool isBold = true;
    bool isItalic = true;
    bool isUnderline = true;
};
#endif // MAINWINDOW_H
