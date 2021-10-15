#include <iostream>
#include "functions.hpp"
#include "constants.hpp"

int main() {
    system("chcp 65001");
    std::cout << "Start" << std::endl;
    int intarray[N_STOLBY][N_STROKI];
    bool stolbySovpadayut = false;
    int opened = ReadFileInput(intarray);
    int b = 0;
    if (opened == -1)
        return -1;
    else
    {
        WriteFileOutput(intarray);
        //Проверяю, есть ли одинаковые значения в первой строке
        for(int ii = 0; ii < N_STOLBY-1 && stolbySovpadayut == false; ii++)
        {
            std::cout << "1) ii = " << ii << " " << std::endl;
            for (int i = ii+1; i < N_STOLBY && stolbySovpadayut == false; i++)
            {
                std::cout << "2) ii = " << ii << "; i = " << i << " " << std::endl;
                //Если есть, проверяю, сходятся ли первые строки столбцов
                if (intarray[ii][0] == intarray[i][0])
                {
                    std::cout << "Первые строки столбца " << ii << " и столбца " << i << " сходятся!" << std::endl;
                    for(int aa = 0; aa < N_STROKI-1 && stolbySovpadayut == false; aa++)
                    {
                        std::cout << "3) ii = " << ii << "; i = " << i << " " << "aa = " << aa << std::endl;
                        //int b = 0;
                        for(int a = aa+1; a < N_STROKI && stolbySovpadayut == false; a++)
                        {
                            std::cout << "4) ii = " << ii << "; i = " << i << " " << "aa = " << aa << " " << "a = " << a << std::endl;
                            //Если сходится, то считаю сколько сошлось.
                            if(intarray[ii][a] == intarray[i][a])
                            {
                                std::cout << "Первые строки столбца " << ii << " и столбца " << i << " сошлись!" << std::endl;
                                std::cout << "еще строки " << aa << " и " << a << " сошлись!!!!!" << std::endl;
                                b++;
                                std::cout << "b = " << b << " РАЗ! " << std::endl;
                                if(b >= N_STROKI)
                                {
                                    std::cout << "Столбы совпадают целиком" << std::endl;
                                    stolbySovpadayut = true;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
        if(stolbySovpadayut == false)
        {
            return -2;
        }
        else
        {
            return 1000;//Продолжать работу
        }
        std::cout << "Finish" << std::endl;
        return 0;
    }
}
