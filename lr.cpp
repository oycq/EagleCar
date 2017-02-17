#include "lr.h"
#include "roi.h"

lr::lr(int startY,int height,int roiNum,int roiThresh,int roiDegree)
{
    y0=startY;
    h=height;
    num=roiNum;
    degree=roiDegree;
    thresh=roiThresh;
}

int lr::feed(Mat feedmat)
{
    int b=0;
    char mystring[30];
    ori=feedmat;
    int left=0,right=0;
    for (int i=0;i<num;i++)
    {
        ROI roi(ori,i,y0,h,640/num,thresh);
        if (roi.returnValue()){
            if (i<(num/2)) left++;
              else right++;
        }
    }
    sprintf(mystring,"rect=    ");
    if ((left>(num*degree/100/2))&&(right>(num*degree/100/2)))
         {b=3;    sprintf(mystring,"rect=LLRR");}
    if ((left>(num*degree/100/2))&&(right<=(num*degree/100/2)))
         {b=1;    sprintf(mystring,"rect=LL  ");}
    if ((left<=(num*degree/100/2))&&(right>(num*degree/100/2)))
         {b=2;    sprintf(mystring,"blank=  RR");}
    putText(ori,mystring,Point(15,90),CV_FONT_HERSHEY_SIMPLEX,1.0,Scalar(50),2);
    return b;


}
void lr::y0down()
{
    if ((y0+1+h)<480-1) y0++;
}

void lr::y0up()
{
    y0--;
}

void lr::addh()
{
   if ((y0+1+h)<480-1) h++;
}

void lr::reduceh()
{
   h--;
}
