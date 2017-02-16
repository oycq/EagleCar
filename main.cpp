#include "mainwindow.h"
#include <QApplication>
#include <QtCore>
#include "runtimer.h"
#include "opencv.hpp"
using namespace std;
using namespace cv;
int main(int argc, char *argv[])
{
    runtimer t1;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    namedWindow("video");
    VideoCapture webcam(0);
    Mat pin;
    while (1){
        t1.getstart();
        webcam >> pin;
        imshow("video",pin);
        waitKey(1);
        t1.getms();
    }


    return a.exec();
}
