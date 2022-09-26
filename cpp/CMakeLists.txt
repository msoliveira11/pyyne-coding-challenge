cmake_minimum_required(VERSION 3.10.0)
project(challenge VERSION 0.1.0)

include_directories(include)
add_subdirectory(src)
add_subdirectory(test)
include_directories(${Boost_INCLUDE_DIRS})