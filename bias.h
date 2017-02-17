#ifndef BIAS_H
#define BIAS_H
#include "opencv.hpp"
using namespace cv;
class bias
{
public:
    bias(int startY,int height,int roiNum=32,int roiThresh=40);
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
};



#endif // BIAS_H
