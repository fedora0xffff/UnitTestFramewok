cmake_minimum_required(VERSION 3.11)

project(UnitTestFW CXX)
set(CMAKE_CXX_STANDARD 20)

#include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
#conan_basic_setup()

#find_package(Boost 1.78.0 REQUIRED)
#if(Boost_FOUND)
#  include_directories(${Boost_INCLUDE_DIRS})
#endif()

#set(THREADS_PREFER_PTHREAD_FLAG ON)
#find_package(Threads REQUIRED)


#need to compile it as a shared lib
add_executable(UnitTestFW src/TestRunner.h src/TestRunner.cpp)
#target_link_libraries(cafeteria PRIVATE Threads::Threads)
