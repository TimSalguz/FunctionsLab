//
// Created by TimSalguz on 15.10.2021.
//
#include "functions.hpp"
#include "constants.hpp"
#include <fstream>
#include <iostream>

namespace ts
{
    bool ContainsPrime(int intarray[N_STOLBY][N_STROKI])
    {
        for (int i = 0; i < N_STOLBY; ++i)
        {
            for (int j = 0; j < N_STROKI; ++j)
            {
                if(intarray[i][j] < 2)
                    break;
                for(int d = 2; d <= sqrt(intarray[i][j]); ++d)
                    if((intarray[i][j]) % d == 0)
                        break;
                return true;
            }
        }
        return false;
    }

    void SovpadenieDvuhStolbcov(int intarray[N_STOLBY][N_STROKI], bool &stolbySovpadayut) {
        for (int ii = 0; ii < N_STOLBY - 1 && !stolbySovpadayut; ii++) {
            std::cout << "1) ii = " << ii << " " << std::endl;
            for (int i = ii + 1; i < N_STOLBY && !stolbySovpadayut; i++) {
                std::cout << "2) ii = " << ii << "; i = " << i << " " << std::endl;
                //Если есть, проверяю, сходятся ли первые строки столбцов
                if (intarray[ii][0] == intarray[i][0]) {
                    std::cout << "Первые строки столбца " << ii << " и столбца " << i << " сходятся!" << std::endl;
                    for (int aa = 0; aa < N_STROKI - 1 && !stolbySovpadayut; aa++) {
                        std::cout << "3) ii = " << ii << "; i = " << i << " " << "aa = " << aa << std::endl;
                        int b = 0;
                        for (int a = aa + 1; a < N_STROKI && !stolbySovpadayut; a++) {
                            std::cout << "4) ii = " << ii << "; i = " << i << " " << "aa = " << aa << " " << "a = " << a
                                      << std::endl;
                            //Если сходится, то считаю сколько сошлось.
                            if (intarray[ii][a] == intarray[i][a]) {
                                std::cout << "Первые строки столбца " << ii << " и столбца " << i << " сошлись!"
                                          << std::endl;
                                std::cout << "еще строки " << aa << " и " << a << " сошлись!!!!!" << std::endl;
                                b++;
                                std::cout << "b = " << b << " РАЗ! " << std::endl;
                                if (b >= N_STROKI - 1) {
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
    }

    void WriteFileOutput(int intarray[N_STOLBY][N_STROKI]) {
        for (int i = 0; i < N_STROKI; i++) {
            for (int j = 0; j < N_STOLBY; j++) {
                std::cout << intarray[j][i] << " ";
            }
            std::cout << std::endl;
        }
    }

    int ReadFileInput(int intarray[N_STOLBY][N_STROKI]) {
        std::ifstream in("input.txt");
        if (!in) {
            std::cout << "File do not opened!\n";
            return -1;
        } else {
            std::cout << "File opened!\n";
            for (int i = 0; i < N_STROKI; i++)
                for (int j = 0; j < N_STOLBY; j++)
                    in >> intarray[j][i];

            return 1;

        }
    }
}