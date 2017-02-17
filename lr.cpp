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
    if ((left>(num*degree/100/2))&&(right>(num*degree/100/2)))
         return 3;
    if ((left>(num*degree/100/2))&&(right<=(num*degree/100/2)))
         return 1;
    if ((left<=(num*degree/100/2))&&(right>(num*degree/100/2)))
         return 2;
    return 0;


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
