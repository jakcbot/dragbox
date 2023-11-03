// mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        bool onBox = false;
        for (CustomBox* box : boxes) {
            if (box->geometry().contains(event->pos())) {
                onBox = true;
                break;
            }
        }

        if (!onBox) {
            CustomBox *newBox = new CustomBox(this);

            // Adjust the size of the newly created box
            int boxSize = qMin(width(), height()) * 0.1;
            newBox->setFixedSize(boxSize, boxSize);

            newBox->move(event->pos() - QPoint(newBox->width() / 2, newBox->height() / 2));
            newBox->show();
            boxes.append(newBox);
        }
    }
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    for (CustomBox* box : boxes) {
        box->adjustSize();
    }
    QMainWindow::resizeEvent(event);
}
