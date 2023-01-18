#include "filter.h"
#include <cstring>
#include <iostream>

rainfall_sub** filter(rainfall_sub* array[], int size, bool (*check)(rainfall_sub* element), int& result_size)
{
	rainfall_sub** result = new rainfall_sub * [size];
	result_size = 0;
	for (int i = 0; i < size; i++)
	{
		if (check(array[i]))
		{
			result[result_size++] = array[i];
		}
	}
	return result;
}

bool check_rainfall_sub_by_rain(rainfall_sub* element)
{

	return strstr(element->OurType.type, "rain") == 0;
}

bool check_rainfall_sub_by_volume(rainfall_sub* element)
{
	return element->OurVolume.volume < 1.5;
}
