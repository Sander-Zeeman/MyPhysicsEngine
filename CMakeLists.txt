cmake_minimum_required(VERSION 3.16)

project(PhysicsEngine)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -std=c++11 -pedantic -O2")

add_executable(PhysicsEngine main.cpp)