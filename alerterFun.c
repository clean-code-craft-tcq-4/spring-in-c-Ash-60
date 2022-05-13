#include "alerterFun.h"

int emailAlerter()
{
    return emailAlertCallCount+=1;
}

int ledAlerter()
{
    return ledAlertCallCount+=1;
}