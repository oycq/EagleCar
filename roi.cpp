#include "roi.h"

ROI:: ROI(Mat ori,int sequence,int startY,int roiHeight,int roiWidth,int threshold)
{
    thresh=threshold;
    width=roiWidth;
    height=roiHeight;
    number=0;
    y=startY;
    startPlace=sequence*roiWidth;
    roi=ori(Rect(startPlace, y, width, height));

}

int ROI::returnValue()
{
    for (int j=0;j<height;j++)
    {
        unsigned char *data=roi.ptr<unsigned char>(j);
        for (int i=0;i<width;i++)
            if (data[i]==0) number++;
    }
    if  (number>=thresh) {
        roi=255;
        return number;
    }
    Scalar gray(128);
    rectangle(roi, Point(0,0), Point(width-1,height-1), gray, 1);
    return 0;
}
