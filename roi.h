#ifndef ROI_H
#define ROI_H
#include "opencv.hpp"
using namespace cv;
class ROI
{
public:
    ROI(Mat ori,int sequence,int roiWidth=32,int roiHeight=50,int whetherDraw=0);
    int returnValue();
private:
    Mat roi;
    int sequence;
    bool draw;
    int width;
    int height;
    int startPlace;
    void drawLine();

};

#endif // ROIS_H
