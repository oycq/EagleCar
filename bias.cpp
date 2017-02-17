#include "bias.h"
#include "math.h"
#include "roi.h"
#include "opencv.hpp"
#include "QDebug"
using namespace cv;
bias::bias(int startY,int height,int roiNum,int roiThresh)
{
    y0=startY;
    h=height;
    num=roiNum;
    thresh=roiThresh;
}

int bias::feed(Mat feedmat)
{
    ori=feedmat;
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

void bias::y0down()
{
    if ((y0+1+h)<480-1) y0++;
}

void bias::y0up()
{
    y0--;
}

void bias::addh()
{
   if ((y0+1+h)<480-1) h++;
}

void bias::reduceh()
{
   h--;
}

