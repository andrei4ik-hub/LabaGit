#ifndef rainfall_H
#define rainfall_H

#include "const.h"

struct date
{
    int day;
    int month;
    double number;
};

struct type_sub
{
    char type[MAX_STRING_SIZE];
   
};

struct rainfall_subscription
{
    
    date day;
    date month;
    date number;
    type_sub type;
    char title[MAX_STRING_SIZE];
};

#endif