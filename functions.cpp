//
// Created by TimSalguz on 15.10.2021.
//
#include "functions.hpp"
#include <fstream>
#include <iostream>

namespace ts
{

    void SortStrok(int intarray[N_STOLBY][N_STROKI])
    {
        for (int i = 0; i < N_STROKI; ++i)
        {
            for (int j = 0; j < N_STOLBY-1; ++j) {
                for (int k = j+1; k < N_STOLBY; ++k) {
                    if(intarray[j][i] >= intarray[k][i])
                    {
                        std::swap(intarray[j][i], intarray[k][i]);
                    }
                }
            }
        }
    }

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

            for (int i = ii + 1; i < N_STOLBY && !stolbySovpadayut; i++) {

                //Если есть, проверяю, сходятся ли первые строки столбцов
                if (intarray[ii][0] == intarray[i][0]) {

                    int b = 0;
                    for (int a = 1; a < N_STROKI && !stolbySovpadayut; a++) {

                        //Если сходится, то считаю сколько сошлось.
                        if (intarray[ii][a] == intarray[i][a]) {

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