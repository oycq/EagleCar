#include "mainwindow.h"
#include <QApplication>
#include <QtCore>
#include <QtDebug>
#include "runtimer.h"
#include "roi.h"
#include "opencv.hpp"
#include "lr.h"
#include "bias.h"
#include "blank.h"
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
        blank myBlank(pin2,80,50,32,100,70);
        line(pin2,Point(320,0),Point(320,480),Scalar(0),1);
        qDebug()<<myBlank.getResult();
        //lr mylr(pin2,300,100,32,50,70);
        // lr(Mat original,int startY,int height,int roiNum=32,int roiThresh=40,int roiDegree=70);
        //qDebug()<<mylr.getResult();
        imshow("video",pin);
        imshow("equalizeHist",pin2);
        waitKey(1);
        t1.getms();
    }


    return a.exec();
}
