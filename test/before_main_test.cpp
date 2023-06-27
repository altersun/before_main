#include <iostream>

#include "../include/before_main.hpp"



void say_whatup()
{
    std::cout << "WHATUPPPP" << std::endl;
}


BEFORE_MAIN(first,say_whatup);

int main()
{
    std::cout << "Actual main" << std::endl;
    return 0;
}