#include <string_view>

// Shout out to stackoverflow contributers:
// https://stackoverflow.com/a/1597129
#define UNIQUE_NAME_INNER(x, y, z) x ## y ## z
#define UNIQUE_NAME_OUTER(x, y, z) UNIQUE_NAME_INNER(x, y, z)
#define UNIQUE_NAME UNIQUE_NAME_OUTER(Unique_, __COUNTER__, __LINE__)


// Below is the first attempt, which relied on stripping the .* out of 
// the filename. However, since it's done via constexpr, which is compiler,
// but is then called via a macro, which is in the preprocessor, it's
// kind of out of order and won't work.
/*
constexpr std::string_view file_name(const char * file_macro)
{
    std::string_view filename(file_macro);
    return filename.substr(0, filename.find_first_of('.'));
}
#define FILENAME file_name(__FILE__)
*/