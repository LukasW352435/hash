cmake_minimum_required(VERSION 3.14)
project(hash)

set(CMAKE_CXX_STANDARD 17)

add_executable(hash main.cpp Block.cpp Block.hpp BlockFactory.cpp BlockFactory.hpp SHA1.cpp SHA1.hpp)