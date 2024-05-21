cmake_minimum_required(VERSION 3.11)

project(libunittest CXX)

set(CMAKE_CXX_STANDARD 17)
set(PROJECT_VERSION 1)
set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_DESCRIPTION "A unit test lib")

set(API include/TestRunner.h)
include(GNUInstallDirs)

add_library(libunittest SHARED
    source/TestRunner.cpp
)

set_target_properties(libunittest PROPERTIES 
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
    PUBLIC_HEADER ${API} #Declare public API
)

configure_file(libunittest.pc.in ${CMAKE_SOURCE_DIR}/libunittest.pc @ONLY)
target_include_directories(libunittest PRIVATE hdrs)

install(TARGETS libunittest
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(FILES ${CMAKE_SOURCE_DIR}/libunittest.pc 
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig
)
