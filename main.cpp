#include <iostream>
#include "functions.hpp"
#include "constants.hpp"

int main() {
    std::cout << "Start" << std::endl;
    int intarray[N][N];
    int opened = ReadFileInput(intarray);
    if (opened == -1)
        return -1;
    else
    {
        WriteFileOutput(intarray);
        std::cout << "Finish" << std::endl;
        return 0;
    }
}
