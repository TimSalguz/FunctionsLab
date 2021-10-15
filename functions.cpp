//
// Created by TimSalguz on 15.10.2021.
//
#include "functions.hpp"
#include "constants.hpp"
#include <fstream>
#include <iostream>
void WriteFileOutput(int intarray[N][N])
{
    for(int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cout << intarray[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int ReadFileInput(int intarray[N][N])
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
        for(int i = 0; !in.eof(); i++)
            for(int j = 0; j < N; j++)
               in >> intarray[i][j];

        return 1;

    }
}