#include "mainwindow.h"
#include <QApplication>
#include <QtCore>
#include "runtimer.h"
#include "roi.h"
#include "opencv.hpp"
using namespace std;
using namespace cv;
 runtimer t1;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    namedWindow("video");
    VideoCapture webcam(0);
    Mat pin,pin2,pin3,pin4;
    while (1){
        t1.getstart();
        webcam >> pin;
        cvtColor( pin, pin, CV_BGR2GRAY );
        equalizeHist(pin,pin2);
        threshold(pin2,pin2,40,200,0);
        ROI myroi(pin2,19);
        myroi.returnValue();
        imshow("video",pin);
        imshow("equalizeHist",pin2);
        waitKey(1);
        t1.getms();
    }


    return a.exec();
}
