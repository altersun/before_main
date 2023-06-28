#include <iostream>

#include "../include/before_main.hpp"


void say_whatup(void)
{
    static int count = 0;
    std::cout << "WHATUPPPP " << count++ << std::endl;
}

void say_two_integers(int a, int b)
{
    std::cout << "Two ints for ya: " << a << " and " << b << std::endl;
}


BEFORE_MAIN(say_whatup);
BEFORE_MAIN_WITH_ARGS(say_two_integers, 45, 67);
BEFORE_MAIN(say_whatup);
BEFORE_MAIN_WITH_ARGS(say_two_integers, 21, 600);


int main()
{
    std::cout << "Actual main" << std::endl;
    return 0;
}
