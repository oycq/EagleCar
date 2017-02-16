#include "runtimer.h"
#include "stdio.h"
#include "QDebug"
runtimer::runtimer()
{
    i = 0;
    time = 0;
    sumtime = 0;
    sumfrequency = 0;
}



void runtimer::getstart()
{
    i = i + 1;
    time = getTickCount();
}


void runtimer::getms()
{
    sumtime += getTickCount() - time;
    sumfrequency += getTickFrequency();
    if ((sumtime / sumfrequency *i* 1000)>=100)
    {
       sprintf(mystring,"%.2fms", sumtime / sumfrequency * 1000);
       data=mystring;
       qDebug()<<data;
       i = 0;
       sumtime=0;
       sumfrequency=0;
    }
}
