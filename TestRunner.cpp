#include "TestRunner.h"


TestRunner::~TestRunner() 
{
        if (fail_count > 0) 
        {
            std::cerr << fail_count << " unit tests failed. Terminate" << std::endl;
            exit(1);
        }
}
