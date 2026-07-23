// gui/mainwindow.cpp

#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    setWindowTitle("Activity Manager");
    resize(900, 600);
}

MainWindow::~MainWindow() = default;