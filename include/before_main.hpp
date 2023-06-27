
#include <iostream>
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

//CHECK_MAIN;
CHECK_TOP_LEVEL;


