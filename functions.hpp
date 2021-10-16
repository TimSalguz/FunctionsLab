#pragma once
// Created by TimSalguz on 15.10.2021.
//
#include "constants.hpp"
namespace ts
{
    int ReadFileInput(int intarray[N_STOLBY][N_STROKI]);

    void WriteFileOutput(int intarray[N_STOLBY][N_STROKI]);

    void SovpadenieDvuhStolbcov(int intarray[N_STOLBY][N_STROKI], bool &stolbySovpadayut);

    bool ContainsPrime(int intarray[N_STOLBY][N_STROKI]);

    void SortStrok(int intarray[N_STOLBY][N_STROKI]);
}