#include "lr.h"
#include "roi.h"

lr::lr(Mat original,int startY,int height,int roiNum,int roiThresh,int roiDegree)
{
    ori=original;
    y0=startY;
    h=height;
    num=roiNum;
    degree=roiDegree;
    thresh=roiThresh;
}

int lr::getResult()
{
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

