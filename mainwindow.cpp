#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtCore"
#include <QDebug>
QTimer *showtimer=new QTimer();
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(showtimer,SIGNAL(timeout()),this,SLOT(showtime()));
    showtimer->start(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void  MainWindow::showtime()
{
    //qDebug()<<"123";


}
