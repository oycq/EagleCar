#include "bias.h"
#include "math.h"
#include "roi.h"
#include "opencv.hpp"
#include "QDebug"
using namespace cv;
bias::bias(Mat original,int startY,int height,int roiNum,int roiThresh)
{
    ori=original;
    y0=startY;
    h=height;
    num=roiNum;
    thresh=roiThresh;
}

int bias::getResult()
{
    double a=0;
    double b=0;
    int n=0;
    for (int i=0;i<num;i++)
    {
        ROI roi(ori,i,y0,h,640/num,thresh);
        if (roi.returnValue()){
            b=i-(num-1)/2.0;
            if (n==0) a=b;
              else if( abs(b)<abs(a) ) a=b;
            n++;
        }
    }
  return (int)a;
}
