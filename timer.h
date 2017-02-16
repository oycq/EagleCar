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
    void getstart();
    void getms();
private:
    int time;
    int sumtime;
    double sumfrequency;
    int i;
    char mystring[30];
    QString data;
};


#endif // TIMER_H
