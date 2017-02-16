#ifndef TIMER_H
#define TIMER_H
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "opencv.hpp"
using namespace cv;
using namespace std;

class timer
{
public:
    timer();
    void setlabel(QLabel *uilabel);
    void getstart();
    void getms();
private:
    QLabel *label;
    int time;
    int sumtime;
    double sumfrequency;
    int i;
    char mystring[30];
};


#endif // TIMER_H
