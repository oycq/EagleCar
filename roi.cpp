#include "roi.h"

ROI:: ROI(Mat ori,int sequence,int roiWidth,int roiHeight,int whetherDraw)
{
    width=roiWidth;
    height=roiHeight;
    startPlace=sequence*roiWidth;
    roi=ori(Rect(startPlace, 0, width, height));
    if (whetherDraw) draw=1;
     else draw=0;
}

int ROI::returnValue()
{
    for (int j=0;j<height;j++)
    {
        unsigned char *data=roi.ptr<unsigned char>(j);
        for (int i=0;i<width;i++)
            data[i]=0;
    }
    return 0;
}
