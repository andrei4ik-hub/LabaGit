#include "processing.h"



int process(rainfall_sub* array[], int size, int b)
{
	int s = 0;
	for (int i = 0; i < size; i++) {
		if (array[i]->OurDay.month == b) {
			s += array[i]->OurVolume.volume;
		}
	}
	return s;
}
