cmake_minimum_required(VERSION 2.8.12)
project(bomba)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



include(CheckCXXCompilerFlag)
include(CheckCCompilerFlag)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${flag}  -faggressive-loop-optimizations  -ftree-vectorize -ffast-math -Ofast   -funroll-loops -march=native -mtune=native ")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${flag}  -faggressive-loop-optimizations  -ftree-vectorize -ffast-math -Ofast   -funroll-loops  -march=native -mtune=native ")


add_executable(bomba
  main.cpp
  )

