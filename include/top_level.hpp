#include <string_view>

constexpr std::string_view top_level = __FUNCTION__;

constexpr bool check_top_level(char const * scope) {
    return top_level == scope;
}

#define CHECK_TOP_LEVEL   static_assert(check_top_level(__FUNCTION__), "Not defined at top level!")
