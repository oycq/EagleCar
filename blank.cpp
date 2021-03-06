#include "blank.h"
#include "roi.h"
#include "math.h"
#include "opencv.hpp"
using namespace cv;
blank::blank(int startY,int height,int roiNum,int roiThresh,int roiDegree)
{
    y0=startY;
    h=height;
    num=roiNum;
    degree=roiDegree;
    thresh=roiThresh;
}

int blank::feed(Mat feedmat)
{
    char mystring[20];
    ori=feedmat;
    int b=1;
    for (int i=0;i<num;i++)
    {
        if (abs(i-num/2)>num/2*degree/100) continue;
        ROI roi(ori,i,y0,h,640/num,thresh);
        if (roi.returnValue()){
            b=0;
        }
    }
    sprintf(mystring,"blank=%d",b);
    putText(ori,mystring,Point(15,30),CV_FONT_HERSHEY_SIMPLEX,1.0,Scalar(50),2);
    return b;
}

void blank::y0down()
{
    if ((y0+1+h)<480-1) y0++;
}

void blank::y0up()
{
    y0--;
}

void blank::addh()
{
   if ((y0+1+h)<480-1) h++;
}

void blank::reduceh()
{
   h--;
}
