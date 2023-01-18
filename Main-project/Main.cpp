#include <iostream>
#include <iomanip>

using namespace std;

#include "rainfall.h"
#include "file_reader.h"
#include "const.h"
#include "filter.h"

void output(rainfall_sub* subscriptions) {
    /********** ����� ���� ������� **********/
    // ����� �����
    cout << "����...: ";
    cout << setw(2) << setfill('0') << subscriptions->OurDay.day << ' ';
    // ����� ������
    cout << setw(2) << setfill('0') << subscriptions->OurDay.month << '\n';
    /********** ����� ���������� ������� **********/
    cout << "���������� ������� � ��...: ";
    cout << subscriptions->OurVolume.volume << '\n';
    /********** ����� ���� ������� **********/
    cout << "��� �������...: ";
    cout << subscriptions->OurType.type << '\n';
    cout << '\n';
    cout << '\n';
};

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "������������ ������ �9. GIT\n";
    cout << "������� �3. ������\n";
    cout << "�����: ������ ������\n";
    cout << "������: 14\n\n";
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
		cout << "\n��� �� ������ �������?\n";
		cout << "1) ����� ��� ���, � ������� ��� �����.\n";
		cout << "2) ����� ��� ���, � ������� ����� ������� ��� ������ 1,5.\n";
		cout << "\n��� ����� : ";
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