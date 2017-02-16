#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "timer.h"
extern timer t1;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    t1.setlabel(ui->label);
}

MainWindow::~MainWindow()
{
    delete ui;
}
