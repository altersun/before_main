#include <iostream>

#include "../include/before_main.hpp"



void say_whatup()
{
    static int count = 0;
    std::cout << "WHATUPPPP " << count << std::endl;
}


//BEFORE_MAIN(say_whatup);
//BEFORE_MAIN(say_whatup);
//BEFORE_MAIN(say_whatup);
//BEFORE_MAIN(say_whatup);
//BEFORE_MAIN(say_whatup);



int main()
{
    std::cout << "Actual main" << std::endl;
    std::cout << FILENAME <<  std::endl;
    std::cout << UNIQUE_NAME << std::endl;

    return 0;
}