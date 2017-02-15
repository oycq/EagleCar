#include "mainwindow.h"
#include <QApplication>
#include "opencv.hpp"
using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.show();
    namedWindow("video");
    VideoCapture webcam(0);
    Mat pin;
    while (1){
        webcam >> pin;
        imshow("video",pin);
        waitKey(1);
    }




    return a.exec();
}
