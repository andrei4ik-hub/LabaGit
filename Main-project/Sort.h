#pragma once
#include "rainfall.h"

void shaker_sort(rainfall_sub* array[], int size, bool (*criteria)(rainfall_sub* left, rainfall_sub* right));

void merge_sort(rainfall_sub* arr[], int first, int last, bool (*criteria)(rainfall_sub* left, rainfall_sub* right));
bool volume_increasing(rainfall_sub* left, rainfall_sub* right);
bool type_increasing(rainfall_sub* left, rainfall_sub* right);