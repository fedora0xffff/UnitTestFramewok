cmake_minimum_required(VERSION 3.11)

project(unittest CXX)

set(CMAKE_CXX_STANDARD 17)
set(PROJECT_VERSION 1)
set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_DESCRIPTION "A unit test lib")

set(API include/TestRunner.h)
include(GNUInstallDirs)

add_library(unittest SHARED
    source/TestRunner.cpp
)

set_target_properties(unittest PROPERTIES 
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
    PUBLIC_HEADER ${API} #Declare public API
)

set(CONF_FILE "${PROJECT_NAME}.pc.in")
configure_file(${CONF_FILE} "${CMAKE_SOURCE_DIR}/${PROJECT_NAME}.pc" @ONLY)
target_include_directories(unittest PRIVATE hdrs)

install(TARGETS unittest
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(FILES "${CMAKE_SOURCE_DIR}/${PROJECT_NAME}.pc" 
    DESTINATION "${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig"
)
