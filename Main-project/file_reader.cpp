#include "file_reader.h"
#include "const.h"

#include <fstream>
#include <cstring>

date convert(char* str)
{
    date result;
    char* context = NULL;
    char* str_number = strtok_s(str, ".", &context);
    result.day = atoi(str_number);
    str_number = strtok_s(NULL, ".", &context);
    result.month = atoi(str_number);
  //  str_number = strtok_s(NULL, ".", &context);
  //  result.year = atoi(str_number);
    return result;
}

void read(const char* file_name, rainfall_sub* array[], int& size)
{
    std::ifstream file(file_name);
    if (file.is_open())
    {
        size = 0;
        char tmp_buffer[MAX_STRING_SIZE];
        while (!file.eof())
        {
            rainfall_sub* item = new rainfall_sub;
         /*   file >> item->reader.last_name;
            file >> item->reader.first_name;
            file >> item->reader.middle_name;*/
            file >> tmp_buffer;
            item->OurDay = convert(tmp_buffer);
            file >> item->OurVolume.volume;
            //file >> item->OurType.type;
            file.read(tmp_buffer, 1); // чтения лишнего символа пробела
            file.getline(item->OurType.type, MAX_STRING_SIZE);
            array[size++] = item;
        }
        file.close();
    }
    else
    {
        throw "Ошибка открытия файла";
    }
}