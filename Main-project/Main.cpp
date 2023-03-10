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

bool (*criterions[2])(rainfall_sub* left, rainfall_sub* right) = { volume_increasing, type_increasing }; 
//bool (*filters[2])(rainfall_sub* element) = {filter_by_volume, filter_by_type};


void output(rainfall_sub* subscriptions) {
    cout << "????: ";
    cout << setw(2) << setfill('0') << subscriptions->OurDay.day << ' ';
    cout << setw(2) << setfill('0') << subscriptions->OurDay.month << '\n';
    cout << "?????????? ??????? ? ??: ";
    cout << subscriptions->OurVolume.volume << '\n';
    cout << "??? ???????: ";
    cout << subscriptions->OurType.type << '\n';
    cout << '\n';
    cout << '\n';
};

void gg(rainfall_sub* subscriptions[ ], int size, bool (*check)(rainfall_sub* element), int& result_size) {
    rainfall_sub** filtered = filter(subscriptions, size, check, result_size);
    for (int i = 0; i < result_size; i++)
    {
        output(filtered[i]);
    }
    delete[] filtered;
}

void output(rainfall_sub* subs[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << subs[i]->OurDay.day << ' ';
        cout << subs[i]->OurDay.month << ' ';
        cout << subs[i]->OurVolume.volume << ' ';
        cout << subs[i]->OurType.type << ' \n'<< endl;
    }
}
int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "???????????? ?????? ?9. GIT\n";
    cout << "??????? ?3. ??????\n";
    cout << "?????: ?????? ??????\n";
    cout << "??????: 14\n\n";
    rainfall_sub* subscriptions[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", subscriptions, size);
        for (int i = 0; i < size; i++)
        { 
            output(subscriptions[i]);
        }

		bool (*check_function)(rainfall_sub*)=0; 

		int new_size;
		
	/*	for (int i = 0; i < new_size; i++)
		{
			output(filtered[i]);
		}*/
        cout << "\n";
        cout << "1. Filter data" << endl;
        cout << "2. Sort data" << endl;
        cout << "3. Exit" << endl;
        select();
		switch (item)
		{   
        case 1:
            cout << "\n??? ?? ?????? ????????\n";
            cout << "1) ????? ??? ???, ? ??????? ??? ?????.\n";
            cout << "2) ????? ??? ???, ? ??????? ????? ??????? ??? ?????? 1,5.\n";
            cout << "\n??? ????? : "; 
            select();
            switch (item) {
            case 1:
                check_function = check_rainfall_sub_by_rain;
                cout << "*****        *****\n\n";
                gg(subscriptions, size, check_function, new_size);
                break;
            case 2:
                check_function = check_rainfall_sub_by_volume;
                cout << "*****         *****\n\n";
                gg(subscriptions, size, check_function, new_size);
                break;
            }
        case 2: 
            cout << "1. Shaker sort" << endl;
            cout << "2. Merge sort" << endl;
            select();
            switch (item) {
            case 1:
                cout << "1. Volume increasing" << endl;
                cout << "2. Type increasing" << endl;
                select();
                switch (item) {
                case 1:
                    shaker_sort(subscriptions, size, criterions[0]);
                    cout << "Sorted:" << endl;
                    output(subscriptions, size);
                    break;
                case 2:
                    shaker_sort(subscriptions, size, criterions[1]);
                    cout << "Sorted:" << endl;
                    output(subscriptions, size);
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
                    merge_sort(subscriptions, 0, size - 1, criterions[0]);
                    cout << "Sorted:" << endl;
                    output(subscriptions, size);
                    break;
                case 2:
                    merge_sort(subscriptions, 0, size - 1, criterions[1]);
                    cout << "Sorted:" << endl;
                    output(subscriptions, size);
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

        for (int i = 0; i < size; i++)
        {
            delete subscriptions[i];
        }
    } catch (const char* error)
    {
        cout << error << '\n';
    }
    return 0;
}