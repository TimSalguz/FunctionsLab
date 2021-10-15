//
// Created by TimSalguz on 15.10.2021.
//
#include "functions.hpp"
#include "constants.hpp"
#include <fstream>
#include <iostream>
void WriteFileOutput(int intarray[N_STOLBY][N_STROKI])
{
    for(int i = 0; i < N_STROKI; i++)
    {
        for (int j = 0; j < N_STOLBY; j++)
        {
            std::cout << intarray[j][i] << " ";
        }
        std::cout << std::endl;
    }
}

int ReadFileInput(int intarray[N_STOLBY][N_STROKI])
{
    std::ifstream in("input.txt");
    if (!in)
    {
        std::cout << "File do not opened!\n";
        return -1;
    }
    else
    {
        std::cout << "File opened!\n";
        for(int i = 0; i < N_STROKI; i++)
            for(int j = 0; j < N_STOLBY; j++)
               in >> intarray[j][i];

        return 1;

    }
}