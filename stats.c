#include "stats.h"
#include <stdio.h>
#include <math.h>


struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    int i;
    float max = numberset[0];
    float min = numberset[0];
    float average = numberset[0];
    if(setlength != 0)
    {
        for(i=1; i<setlength; i++)
        {
            if(numberset[i]<min)
            {
                min = numberset[i];
            }
            if(numberset[i]>max)
            {
                max = numberset[i];
            }
            average = average + numberset[i];
        }

        s.average = average/setlength;
        s.min = min;
        s.max = max;
        return s;
    }
    else
    {
        s.average = NAN;
        s.min = NAN;
        s.max = NAN;
        return s;
    }
    
}
void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{
    if(computedStats.average>maxThreshold)
    {
        alerters[0];
        alerters[1];
    }
}


