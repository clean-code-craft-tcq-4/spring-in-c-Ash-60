#include "stats.h"
#include <stdio.h>
#include <math.h>

#ifdef NAN
/* NAN is supported */
#endif
#ifdef INFINITY
/* INFINITY is supported */
#endif

int emailAlertCallCount;
int ledAlertCallCount;

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    int i;
    float max = numberset[0];
    float min = numberset[0];
    float average = numberset[0];
    if(numberset != 0)
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
    }
    else
    {
        s.average = NAN;
        s.min = NAN;
        s.max = NAN;
    }
    return s;
    
}
void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{
    if(computedStats.average>maxThreshold)
    {
        alerters[0];
        alerters[1];
        emailAlertCallCount+=1;
        ledAlertCallCount+=1;
    }
}


