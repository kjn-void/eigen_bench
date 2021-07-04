cmake_minimum_required(VERSION 3.0)
project(eigen C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Threads REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBGBENCH REQUIRED IMPORTED_TARGET benchmark)
pkg_check_modules(LIBEIGEN3 REQUIRED IMPORTED_TARGET eigen3)

add_executable(eigen main.cpp cpp_mat.cpp c_mat.c)
target_link_libraries(eigen PUBLIC PkgConfig::LIBGBENCH PkgConfig::LIBEIGEN3 Threads::Threads)
