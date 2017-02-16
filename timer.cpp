#include "timer.h"
#include "stdio.h"
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

void timer::setlabel(QLabel *uilabel)
{
    label=uilabel;
}

void timer::getms()
{
    sumtime += getTickCount() - time;
    sumfrequency += getTickFrequency();
    if (i == 10)
    {
       sprintf(mystring,"%.2fms\r\n", sumtime / sumfrequency * 1000);
       label->setText(mystring);
       i = 0;
    }
}