#include "timer.h"
#include "stdio.h"
#include "QDebug"
timer::timer()
{
    i = 0;
    time = 0;
    sumtime = 0;
    sumfrequency = 0;
}



void timer::getstart()
{
    i = i + 1;
    time = getTickCount();
}


void timer::getms()
{
    sumtime += getTickCount() - time;
    sumfrequency += getTickFrequency();
    if (i == 10)
    {
       sprintf(mystring,"%.2fms", sumtime / sumfrequency * 1000);
       data=mystring;
       i = 0;
       sumtime=0;
       sumfrequency=0;
    }
}
