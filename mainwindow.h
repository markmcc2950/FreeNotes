#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPoint>

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
    // Private functions
    Ui::MainWindow *ui;
    bool eventFilter(QObject* obj, QEvent* event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void onFontButtonClicked();
    void onSaveButtonClicked();
    void onSaveAsButtonClicked();
    void onLoadButtonClicked();
    void changeWindowTitle(const QString& filePath);

    // Private variables
    QPoint cur_pos;
    QPoint new_pos;
    QString windowTitle = "FreeNotes";
    QString lastSavedText = "";
    QString filePath = "";
    bool isBold = true;
    bool isItalic = true;
    bool isUnderline = true;
};
#endif // MAINWINDOW_H
