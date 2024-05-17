#include <string>
#include "helperFunctions.h"
#include "TestRunner.h"

//nice output
#define AS_KV(x) #x << " = " << x

#define ASSERT(x) {         \ 
    std::ostringstream os;              \
    os << #x << " is false, "           \
    << __FILE__ << ":" << __LINE__;     \
    AssertEqual(x, y, os.str());        \
}

#define ASSERT_EQUAL(x, y) {         \ 
    std::ostringstream os;              \
    os << #x << "!=" << #y << ", "      \
    << __FILE__ << ":" << __LINE__;     \
    AssertEqual(x, y, os.str());        \
}

#define RUN_TEST(tr, func) \
            tr.RunTest(func, #func)

