#include "../include/unittest_test_runner.h"


unittest::TestRunner::~TestRunner() 
{
    if (fail_count > 0) 
    {
        std::cerr << fail_count << " unit tests failed. Terminate" << std::endl;
        exit(1);
    }
}
