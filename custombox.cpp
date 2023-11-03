// custombox.cpp
#include "custombox.h"
#include <QMouseEvent>

CustomBox::CustomBox(QWidget *parent)
    : QWidget(parent),
    isDragging(false)
{
    setAutoFillBackground(true);
    setPalette(QPalette(QColor(0, 0, 255))); // RGB values for blue
    setCursor(Qt::PointingHandCursor);
}

void CustomBox::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        isDragging = true;
        lastMousePos = event->globalPos();
    }
}

void CustomBox::mouseMoveEvent(QMouseEvent *event)
{
    if (isDragging) {
        int newX = x() + event->globalX() - lastMousePos.x();
        int newY = y() + event->globalY() - lastMousePos.y();

        // Limit the movement within the window boundaries
        newX = qBound(0, newX, parentWidget()->width() - width());
        newY = qBound(0, newY, parentWidget()->height() - height());

        move(newX, newY);
        lastMousePos = event->globalPos();
    }
}

void CustomBox::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        isDragging = false;
    }
}

void CustomBox::adjustSize()
{
    // This function is empty as we don't want to change the size when the window is resized
}
