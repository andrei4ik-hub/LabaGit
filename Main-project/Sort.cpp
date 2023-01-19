#include "filter.h"
#include <cstring>
#include <iostream>
#include "rainfall.h"
#include "sort.h"
#include "cstring"
using namespace std;



bool volume_increasing(rainfall_sub* left, rainfall_sub* right) {
	return left->OurVolume.volume < right->OurVolume.volume;
}

bool type_increasing(rainfall_sub* left, rainfall_sub* right) {
	enum types {
		Rain, HeavyRain, Snow, HeavySnow, Shrad
	};
	int leftNum;
	int rightNum;
	if (!strcmp(left->OurType.type, "Rain")) {
		leftNum = Rain;
	}
	else if (!strcmp(left->OurType.type, " HeavyRain")) {
		leftNum = HeavyRain;
	}
	else if (!strcmp(left->OurType.type, "Snow")) {
		leftNum = Snow;
	}
	else if (!strcmp(left->OurType.type, "HeavySnow")) {
		leftNum = HeavySnow;
	}
	else if (!strcmp(left->OurType.type, "Shrad")) {
		leftNum = Shrad;
	}
	if (!strcmp(right->OurType.type, "Rain")) {
		rightNum = Rain;
	}
	else if (!strcmp(right->OurType.type, " HeavyRain")) {
		rightNum = HeavyRain;
	}
	else if (!strcmp(right->OurType.type, "Snow")) {
		rightNum = Snow;
	}
	else if (!strcmp(right->OurType.type, "HeavySnow")) {
		rightNum = HeavySnow;
	}
	else if (!strcmp(right->OurType.type, "Shrad")) {
		rightNum = Shrad;
	}
	if (rightNum == leftNum) {
		if (left->OurDay.month == right->OurDay.month) {
			return left->OurDay.day > right->OurDay.day;
		}
		else {
			return left->OurDay.month > right->OurDay.month;
		}
	}
	else {
		return leftNum > rightNum;
	}
}
void shaker_sort(rainfall_sub* array[], int size, bool (*criteria)(rainfall_sub* left, rainfall_sub* right)) {
	int leftMark = 1;
	int rightMark = size - 1;
	while (leftMark <= rightMark)
	{
		for (int i = rightMark; i >= leftMark; i--)
			if (criteria(array[i - 1], array[i])) swap(array[i - 1], array[i]);
		leftMark++;

		for (int i = leftMark; i <= rightMark; i++)
			if (criteria(array[i - 1], array[i])) swap(array[i - 1], array[i]);
		rightMark--;
	}
}

void Merge(rainfall_sub* arr[], int first, int last, bool (*criteria)(rainfall_sub* left, rainfall_sub* right)) {
	int middle, start, final, j;
	rainfall_sub** mas = new rainfall_sub * [100];
	middle = (first + last) / 2;	//вычисление среднего элемента
	start = first;					//начало левой части
	final = middle + 1;				//начало правой части
	for (j = first; j <= last; j++) //выполнять от начала до конца
		if ((start <= middle) && ((final > last) || criteria(arr[final], arr[start]))) {
			mas[j] = arr[start];
			start++;
		}
		else {
			mas[j] = arr[final];
			final++;
		}
	//возвращение результата в список
	for (j = first; j <= last; j++)
		arr[j] = mas[j];
	delete[] mas;
};
//рекурсивная процедура сортировки
void merge_sort(rainfall_sub* arr[], int first, int last, bool (*criteria)(rainfall_sub* left, rainfall_sub* right)) {
	if (first < last) {
		merge_sort(arr, first, (first + last) / 2, criteria);  //сортировка левой части
		merge_sort(arr, (first + last) / 2 + 1, last, criteria);  //сортировка правой части
		Merge(arr, first, last, criteria);  //слияние двух частей
	}
}