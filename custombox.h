// custombox.h
#ifndef CUSTOMBOX_H
#define CUSTOMBOX_H

#include <QWidget>

class CustomBox : public QWidget
{
    Q_OBJECT
public:
    explicit CustomBox(QWidget *parent = nullptr);

    void adjustSize();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    QPoint lastMousePos;
    bool isDragging;

signals:
};

#endif // CUSTOMBOX_H
