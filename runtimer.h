#ifndef RUNTIMER_H
#define RUNTIMER_H
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "opencv.hpp"
using namespace cv;
using namespace std;

class runtimer
{
public:
    runtimer();
    void getstart();
    void getms();
    QString data;
private:
    int time;
    int sumtime;
    double sumfrequency;
    int i;
    char mystring[30];
};


#endif // RUNTIMER_H
