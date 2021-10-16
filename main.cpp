#include <iostream>
#include "functions.hpp"
#include "constants.hpp"
//При выполнении лабораторной работы используйте процедуры и функции:
//1.	Функция чтения
//2.	Функция обработки (может быть несколько)
//3.	Функция записи
//Их необходимо расположить в отдельных файлах (*.hpp и *.cpp) в отдельном пространстве имен.
//Вариант-1.
//Дана целочисленная матрица {Aij}i=1...n;j=1..n , n<=100. Если в матрице есть два одинаковых
// столбца и есть хотя бы один элемент, абсолютная величина которого - простое число,
// упорядочить строки матрицы по неубыванию суммы модулей элементов.


int main() {
    system("chcp 65001");
    std::cout << "Start" << std::endl;
    int intarray[N_STOLBY][N_STROKI];
    bool stolbySovpadayut = false;
    int opened = ts::ReadFileInput(intarray);

    if (opened == -1)
        return -1;
    else
    {
        ts::WriteFileOutput(intarray);
        //Проверяю, есть ли одинаковые значения в первой строке
        ts::SovpadenieDvuhStolbcov(intarray, stolbySovpadayut);

        if(!stolbySovpadayut)
        {
            return -2;
        }
        else
        {
            if (!ts::ContainsPrime(intarray))
            {
                return -4;
            }
            else
            {

                return 1000;//Продолжать работу, проверить, простое ли
            }
        }
        std::cout << "Finish" << std::endl;
        return 0;
    }
}
