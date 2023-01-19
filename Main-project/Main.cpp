#include <iostream>
#include <iomanip>

using namespace std;

#include "rainfall.h"
#include "file_reader.h"
#include "const.h"
#include "filter.h"
#include "Sort.h"


int item;
void select() {
    cout << ">> ";
    cin >> item;
    system("cls");
}

bool (*criterions[2])(rainfall_sub* left, rainfall_sub* right) = { volume_increasing, type_increasing }; // array of functions for sorts
bool (*filters[2])(rainfall_sub* element) = {filter_by_volume, filter_by_type}; // array of functions for sorts

void output(rainfall_sub* subscriptions) {
    /********** вывод даты осадков **********/
    // вывод числа
    cout << "Дата...: ";
    cout << setw(2) << setfill('0') << subscriptions->OurDay.day << ' ';
    // вывод месяца
    cout << setw(2) << setfill('0') << subscriptions->OurDay.month << '\n';
    /********** вывод количества осадков **********/
    cout << "Количество осадков в мм...: ";
    cout << subscriptions->OurVolume.volume << '\n';
    /********** вывод типа осадков **********/
    cout << "Тип осадков...: ";
    cout << subscriptions->OurType.type << '\n';
    cout << '\n';
    cout << '\n';
};

void output(rainfall_sub* subs[], int size) { // output
    for (int i = 0; i < size; ++i) {
        cout << subs[i]->date.day << ' ';
        cout << subs[i]->date.month << ' ';
        cout << subs[i]->wind.direction << ' ';
        cout << subs[i]->wind.speed << '\n';
    }
}
int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Лабораторная работа №9. GIT\n";
    cout << "Вариант №3. Осадки\n";
    cout << "Автор: Будняк Андрей\n";
    cout << "Группа: 14\n\n";
    rainfall_sub* subscriptions[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", subscriptions, size);
        for (int i = 0; i < size; i++)
        { 
            output(subscriptions[i]);
        }

		bool (*check_function)(rainfall_sub*); 
		

        cout << "\n";
        cout << "1. Filter data" << endl;
        cout << "2. Sort data" << endl;
        cout << "3. Exit" << endl;
        select();
		switch (item)
		{   
        case 1:
            cout << "\nЧто вы хотите сделать?\n";
            cout << "1) Найти все дни, в которые шёл дождь.\n";
            cout << "2) Найти все дни, в которые объём осадков был меньше 1,5.\n";
            cout << "\nВаш выбор : "; 
            select();
            switch (item) {
            case 1:
                check_function = check_rainfall_sub_by_rain;
                cout << "*****        *****\n\n";
                break;
            case 2:
                check_function = check_rainfall_sub_by_volume;
                cout << "*****         *****\n\n";
                break;
            }
        case 2: cout << "1. Shaker sort" << endl;
            cout << "2. Merge sort" << endl;
            select();
            switch (item) {
            case 1:
                cout << "1. Volume increasing" << endl;
                cout << "2. Type increasing" << endl;
                select();
                switch (item) {
                case 1:
                    shaker_sort(rainfall_sub, size, criterions[0]);
                    cout << "Sorted:" << endl;
                    output(rainfall_sub, size);
                    break;
                case 2:
                    shaker_sort(rainfall_sub, size, criterions[1]);
                    cout << "Sorted:" << endl;
                    output(rainfall_sub, size);
                    break;
                default:
                    cout << "Error";
                }
                break;
            case 2:
                cout << "1. Volume increasing" << endl;
                cout << "2. Type increasing" << endl;
                select();
                switch (item) {
                case 1:
                    merge_sort(rainfall_sub, 0, size - 1, criterions[0]);
                    cout << "Sorted:" << endl;
                    output(rainfall_sub, size);
                    break;
                case 2:
                    merge_sort(rainfall_sub, 0, size - 1, criterions[1]);
                    cout << "Sorted:" << endl;
                    output(rainfall_sub, size);
                    break;
                default:
                    cout << "Error";
                }
                break;
            default:
                cout << "Error";
            }
            break;
        case 3:
            cout << "Exitting...";
            return 0;
        default:
            cout << "Error";
        }
		int new_size;
		rainfall_sub** filtered = filter(subscriptions, size, check_function, new_size);
		for (int i = 0; i < new_size; i++)
		{
			output(filtered[i]);
		}
		delete[] filtered;
	}
	

        for (int i = 0; i < size; i++)
        {
            delete subscriptions[i];
        }
    }

    catch (const char* error)
    {
        cout << error << '\n';
    }
    return 0;
}