cmake_minimum_required(VERSION 3.5)

project(algos LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(algos main.cpp arrayalgos.cpp arrayalgos.h
    recursionsAlgos.h recursionsAlgos.cpp
    arrayalgosTest.cpp
    arrayalgostest.h
    recusrsionalgosttest.h recusrsionalgosttest.cpp
    stdh.h )

install(TARGETS algos
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
