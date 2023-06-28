#include <functional>
#include <string>

#include "top_level.hpp"
#include "unique_name.hpp"


struct BeforeMain {
    BeforeMain(std::function<void()> funk) {funk();}
};

#define BEFORE_MAIN(funk)   CHECK_TOP_LEVEL; static BeforeMain UNIQUE_NAME (funk)
 