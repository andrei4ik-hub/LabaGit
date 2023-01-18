#ifndef rainfall_H
#define rainfall_H

#include "const.h"

struct date
{
    int day;
    int month;
};

struct volume_sub
{
    double volume;
};

struct type_sub
{
    char type[MAX_STRING_SIZE];
};

struct rainfall_sub
{
    date OurDay;
    volume_sub OurVolume;
    type_sub OurType;
   // char title[MAX_STRING_SIZE];
};

#endif