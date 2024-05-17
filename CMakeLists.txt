cmake_minimum_required(VERSION 3.11)

project(UnitTestLib version 1.0 DESCRIPTION "a simple unit test framework")
set(CMAKE_CXX_STANDARD 17)
set(PROJECT_VERSION 1)
set(PROJECT_VERSION_MAJOR 0)
set(API 
    hdrs/TestRunner.h		
    hdrs/helperFunctions.h	
    hdrs/helperMacros.h
)
include(GNUInstallDirs)

add_library(UnitTestLib SHARED
    src/TestRunner.cpp
)

set_target_properties(UnitTestLib PROPERTIES 
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
    PUBLIC_HEADER ${API} #Declare public API of your library. 
)
configure_file(UnitTestLib.pc.in mylib.pc @ONLY)
target_include_directories(UnitTestLib PRIVATE hdrs)

install(TARGETS UnitTestLib
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(FILES ${CMAKE_SOURCE_DIR}/UnitTestLib.pc 
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig
)


# cmake_minimum_required(VERSION 3.11)
# project(UnitTestLib VERSION 1.0 DESCRIPTION "mylib description")
# include(GNUInstallDirs)
# add_library(UnitTestLib SHARED src/mylib.c)
# set_target_properties(mylib PROPERTIES
#     VERSION ${PROJECT_VERSION}
#     SOVERSION ${PROJECT_VERSION_MAJOR}
#     PUBLIC_HEADER api/mylib.h)
# configure_file(mylib.pc.in mylib.pc @ONLY)
# target_include_directories(mylib PRIVATE .)
# install(TARGETS mylib
#     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#     PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
# install(FILES ${CMAKE_BINARY_DIR}/mylib.pc
#     DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)

