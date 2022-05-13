#include "stats.h"

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    int i;
    float max = numberset[0];
    float min = numberset[0];
    float average = numberset[0];
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
        average = (average + numberset[i])/2;
    }

    s.average = average;
    s.min = min;
    s.max = max;
    return s;
}

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;
