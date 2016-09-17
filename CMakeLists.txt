cmake_minimum_required(VERSION 3.5)
project(libsat)

add_library(sat libsat.cpp satvector.cpp satcircle.cpp satpolygon.cpp satbox.cpp)
