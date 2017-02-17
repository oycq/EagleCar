#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "runtimer.h"
#include "QtCore"
#include <QDebug>
#include "lr.h"
#include "bias.h"
#include "blank.h"
extern runtimer t1;
extern blank myBlank;
extern lr myLr;
extern bias myBias;
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
    ui->label->setText(t1.data);
}

void MainWindow::on_blankUP_clicked()
{
    myBlank.y0up();
}

void MainWindow::on_blankDown_clicked()
{
    myBlank.y0down();
}

void MainWindow::on_lfUP_clicked()
{
    myLr.y0up();
}

void MainWindow::on_lfDown_clicked()
{
    myLr.y0down();
}

void MainWindow::on_pushButton_5_clicked()//no use
{
}

void MainWindow::on_biasUP_clicked()
{
    myBias.y0up();
}

void MainWindow::on_biasDown_clicked()//no use
{
}

void MainWindow::on_pushButton_6_clicked()
{
    myBias.y0down();
}

void MainWindow::on_blank_add_h_clicked()
{
    myBlank.addh();
}

void MainWindow::on_blank_re_h_clicked()
{
    myBlank.reduceh();
}

void MainWindow::on_lr_add_h_clicked()
{
    myLr.addh();
}

void MainWindow::on_lr_re_h_clicked()
{
    myLr.reduceh();
}

void MainWindow::on_bias_add_h_clicked()
{
    myBias.addh();
}

void MainWindow::on_bias_re_h_clicked()
{
    myBias.reduceh();
}
