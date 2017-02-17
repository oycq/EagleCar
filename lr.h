#ifndef LR_H
#define LR_H
#include "opencv.hpp"
using namespace cv;
class lr
{
public:
    int getResult();
    lr(Mat original,int startY,int height,int roiNum=32,int roiThresh=40,int roiDegree=70);
private:
    Mat ori;
    int y0;
    int h;
    int num;
    int thresh;
    int degree;
};




#endif // LR_H
