#ifndef BIAS_H
#define BIAS_H
#include "opencv.hpp"
using namespace cv;
class bias
{
public:
    int getResult();
    bias(Mat original,int startY,int height,int roiNum=32,int roiThresh=40);
private:
    Mat ori;
    int y0;
    int h;
    int num;
    int thresh;
};



#endif // BIAS_H
