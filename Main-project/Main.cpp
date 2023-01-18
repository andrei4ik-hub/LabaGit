#include <iostream>
#include <iomanip>

using namespace std;

#include "rainfall.h"
#include "file_reader.h"
#include "const.h"
#include "filter.h"

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

		bool (*check_function)(rainfall_sub*); // check_function -    ,    bool,
		//        book_subscription*
		cout << "\nЧто вы хотите сделать?\n";
		cout << "1) Найти все дни, в которые шёл дождь.\n";
		cout << "2) Найти все дни, в которые объём осадков был меньше 1,5.\n";
		cout << "\nВаш выбор : ";
		int item;
		cin >> item;
		cout << '\n';
		switch (item)
		{
		case 1:
			check_function = check_rainfall_sub_by_rain; //       
			cout << "*****        *****\n\n";
			break;
		case 2:
            check_function = check_rainfall_sub_by_volume; //       
			cout << "*****         *****\n\n";
			break;
		default:
			throw "  ";
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