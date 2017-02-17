#ifndef ROI_H
#define ROI_H
#include "opencv.hpp"
using namespace cv;
class ROI
{
public:
    ROI(Mat ori,int sequence,int startY,int roiHeight=50,int roiWidth=20,int threshold=500);
    int returnValue();
private:
    Mat roi;
    int sequence;
    int width;
    int height;
    int startPlace;
    int number;
    int y;
    int thresh;
    void drawLine();

};

#endif // ROIS_H
