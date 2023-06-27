#include <functional>
#include <string>
#include <string_view>

// Shout out to stackoverflow contributers:
// https://stackoverflow.com/a/1597129
#define UNIQUE_NAME_INNER(x, y) x ## y
#define UNIQUE_NAME_OUTER(x, y) UNIQUE_NAME_INNER(x, y)
#define UNIQUE(Name) UNIQUE_NAME_OUTER(Name, __LINE__)


constexpr bool check_top_level(char const * scope) {
    return std::string_view("top level")==scope;
}

    
#define CHECK_TOP_LEVEL   static_assert(check_top_level(__FUNCTION__), "Not defined at top level!")


struct BeforeMain {
    BeforeMain(std::function<void()> funk) {funk();}
};



#define BEFORE_MAIN(id, funk)   CHECK_TOP_LEVEL;static BeforeMain UNIQUE(id)(funk);
 