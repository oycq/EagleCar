#include "blank.h"
#include "roi.h"
#include "math.h"
#include "opencv.hpp"
using namespace cv;

blank::blank(Mat original,int startY,int height,int roiNum,int roiThresh,int roiDegree)
{
    ori=original;
    y0=startY;
    h=height;
    num=roiNum;
    degree=roiDegree;
    thresh=roiThresh;
}

int blank::getResult()
{
    int b=0;
    for (int i=0;i<num;i++)
    {
        if (abs(i-num/2)>num/2*degree/100) continue;
        ROI roi(ori,i,y0,h,640/num,thresh);
        if (roi.returnValue()){
            b=1;
        }
    }
    return b;
}

