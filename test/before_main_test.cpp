
#include <iostream>
#include <functional>
#include <string>
#include <string_view>

using namespace std;
static const string str(__FUNCTION__);


constexpr bool check_top_level(char const * scope) {
    return std::string_view("top level")==scope;
}

constexpr bool check_main(char const * scope) {
    return std::string_view("main")==scope;
}
    
#define CHECK_TOP_LEVEL   static_assert(check_top_level(__FUNCTION__), "Top level!")
#define CHECK_MAIN        static_assert(check_main(__FUNCTION__), "Main!")


struct BeforeMain {
    BeforeMain(std::function<void()> funk) {funk();}
};

void say_whatup()
{
    std::cout << "WHATUPPPP" << std::endl;
}

#define BEFORE_MAIN(funk)   CHECK_TOP_LEVEL;static\
 BeforeMain f(funk);



BEFORE_MAIN(say_whatup);


//CHECK_MAIN;
//CHECK_TOP_LEVEL;


int main()
{
    cout<<__FUNCTION__<<endl;
    cout<<str<<endl;
    //CHECK_TOP_LEVEL;
    CHECK_MAIN;
    return 0;
}