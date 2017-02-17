#ifndef BLANK_H
#define BLANK_H
#include "opencv.hpp"
using namespace cv;

class blank
{
public:
    int getResult();
    blank(Mat original,int startY,int height,int roiNum=32,int roiThresh=40,int roiDegree=70);
private:
    Mat ori;
    int y0;
    int h;
    int num;
    int thresh;
    int degree;
};


#endif // BLANK_H
