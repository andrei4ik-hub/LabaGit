#ifndef FILTER_H
#define FILTER_H

#include "rainfall.h"

rainfall_sub** filter(rainfall_sub* array[], int size, bool (*check)(rainfall_sub* element), int& result_size);


bool check_rainfall_sub_by_rain(rainfall_sub* element);



bool check_rainfall_sub_by_volume(rainfall_sub* element);

#endif
