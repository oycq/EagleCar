#ifndef LR_H
#define LR_H
#include "opencv.hpp"
using namespace cv;
class lr
{
public:
    lr(int startY,int height,int roiNum=32,int roiThresh=40,int roiDegree=70);
    int feed(Mat feedmat);
    void y0up();
    void y0down();
    void addh();
    void reduceh();
private:
    Mat ori;
    int y0;
    int h;
    int num;
    int thresh;
    int degree;
};




#endif // LR_H
