cmake_minimum_required(VERSION 3.16)
project(MicroProcessor VERSION 0.0.1 LANGUAGES C CXX)

set(CMAKE_CXX_CLANG_TIDE clang-tidy;-checks=-*,performance-*,portability-*,readability-*)
# set(CMAKE_CXX_CPPCHECK cppcheck)
set (CMAKE_CXX_STANDARD 11)

enable_testing()
include_directories(include)
include_directories(include/memory)
include_directories(include/proc)
add_subdirectory(src)
add_subdirectory(tests)