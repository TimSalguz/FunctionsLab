#include <iostream>
#include "functions.hpp"
#include "constants.hpp"

int main() {
    system("chcp 65001");
    std::cout << "Start" << std::endl;
    int intarray[N_STOLBY][N_STROKI];
    bool stolbySovpadayut = false;
    int opened = ReadFileInput(intarray);

    if (opened == -1)
        return -1;
    else
    {
        WriteFileOutput(intarray);
        //Проверяю, есть ли одинаковые значения в первой строке
        SovpadenieDvuhStolbcov(intarray, stolbySovpadayut);

        if(!stolbySovpadayut)
        {
            return -2;
        }
        else
        {
            return 1000;//Продолжать работу, проверить, простое ли

        }
        std::cout << "Finish" << std::endl;
        return 0;
    }
}
