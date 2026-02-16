#pragma once
#include <QMenuBar>
#include <QMouseEvent>
#include <QWindow>

class MenuBar : public QMenuBar {
    Q_OBJECT
public:
    using QMenuBar::QMenuBar;

protected:
    void mousePressEvent(QMouseEvent* e) override {
        if (e->button() == Qt::LeftButton && actionAt(e->pos()) == nullptr) {
            if (auto w = window()->windowHandle()) {
                w->startSystemMove();
                return;
            }
        }
        QMenuBar::mousePressEvent(e);
    }
};
