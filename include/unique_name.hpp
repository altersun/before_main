#include <string_view>

constexpr std::string_view file_name(const char * file_macro)
{
    std::string_view filename(file_macro);
    return filename.substr(0, filename.find_first_of('.'));
}

#define FILENAME file_name(__FILE__)

// Shout out to stackoverflow contributers:
// https://stackoverflow.com/a/1597129
#define UNIQUE_NAME_INNER(x, y, z) x ## y ## z
#define UNIQUE_NAME_OUTER(x, y, z) UNIQUE_NAME_INNER(x, y, z)
#define UNIQUE_NAME UNIQUE_NAME_OUTER(Unique_, FILENAME, __LINE__)
