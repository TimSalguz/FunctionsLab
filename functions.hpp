#pragma once
// Created by TimSalguz on 15.10.2021.
//

#ifndef FUNCTIONSLAB_FUNCTIONS_HPP
#define FUNCTIONSLAB_FUNCTIONS_HPP

#endif //FUNCTIONSLAB_FUNCTIONS_HPP


const int N_STROKI = 6;
const int N_STOLBY = 5;
namespace ts
{
    int ReadFileInput(int intarray[N_STOLBY][N_STROKI]);

    void WriteFileOutput(int intarray[N_STOLBY][N_STROKI]);

    void SovpadenieDvuhStolbcov(int intarray[N_STOLBY][N_STROKI], bool &stolbySovpadayut);

    bool ContainsPrime(int intarray[N_STOLBY][N_STROKI]);

    void SortStrok(int intarray[N_STOLBY][N_STROKI]);
}