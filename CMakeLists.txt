cmake_minimum_required(VERSION 3.10)
project(Studentai CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Jei build tipas nenurodytas, kompiliuojama su optimizacija (Release)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

add_executable(studentai main.cpp)
