#include <functional>
#include <string>

#include "top_level.hpp"
#include "unique_name.hpp"

/*
struct BeforeMain {
    BeforeMain(std::function<void()> funk) {funk();}
};
*/

struct BeforeMain {
    BeforeMain(std::function<void()> func) {func();}
    template <class Function, class ... Args>
    BeforeMain(Function func, Args...args) {func(args...);}

};

#define BEFORE_MAIN(func)                  CHECK_TOP_LEVEL; static BeforeMain UNIQUE_NAME (func)
#define BEFORE_MAIN_WITH_ARGS(func, ...)   CHECK_TOP_LEVEL; static BeforeMain UNIQUE_NAME (func, __VA_ARGS__)
 