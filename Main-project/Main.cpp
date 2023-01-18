#include <iostream>
#include <iomanip>

using namespace std;

#include "rainfall.h"
#include "file_reader.h"
#include "const.h"


int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "������������ ������ �9. GIT\n";
    cout << "������� �3. ������\n";
    cout << "�����: ������ ������\n\n";
    rainfall_sub* subscriptions[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", subscriptions, size);
        for (int i = 0; i < size; i++)
        { 
            /********** ����� ���� ������� **********/
            // ����� �����
            cout << "����...: ";
            cout << setw(2) << setfill('0') << subscriptions[i]->OurDay.day << ' ';
            // ����� ������
            cout << setw(2) << setfill('0') << subscriptions[i]->OurDay.month << '\n';
            /********** ����� ���������� ������� **********/
            cout << "���������� ������� � ��...: ";
            cout << subscriptions[i]->OurVolume.volume << '\n';
            /********** ����� ���� ������� **********/
            cout << "��� �������...: ";
            cout << subscriptions[i]->OurType.type << '\n';
            cout << '\n';
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