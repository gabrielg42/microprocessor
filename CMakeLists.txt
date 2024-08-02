cmake_minimum_required(VERSION 3.16)
project(MicroProcessor VERSION 0.0.1 LANGUAGES C CXX)

set(CMAKE_CXX_CLANG_TIDE clang-tidy;-checks=-*,performance-*,portability-*,readability-*)
set(CMAKE_CXX_CPPCHECK cppcheck)

add_subdirectory(src)