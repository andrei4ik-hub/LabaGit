#include <iostream>

using namespace std;

#include "rainfall.h"
#include "file_reader.h"
#include "const.h"


int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Лабораторная работа №9. GIT\n";
    cout << "Вариант №3. Осадки\n";
    cout << "Автор: Будняк Андрей\n\n";
    rainfall_sub* subscriptions[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", subscriptions, size);
        for (int i = 0; i < size; i++)
        {
            cout << subscriptions[i]->OurDay.day << ' ';
            cout << subscriptions[i]->OurDay.month << '\n';
            cout << subscriptions[i]->OurVolume.volume << '\n';
            cout << subscriptions[i]->OurType.type << '\n';
            cout << '\n';
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