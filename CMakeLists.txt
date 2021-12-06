cmake_minimum_required(VERSION 3.10)
project(PhysicsEngine)

add_executable(PhysicsEngine main.cpp)

target_include_directories(PhysicsEngine PUBLIC Interfaces)

add_subdirectory(Model)
add_subdirectory(View)
add_subdirectory(Controller)

target_link_libraries(PhysicsEngine PUBLIC Model)
target_link_libraries(PhysicsEngine PUBLIC View)
target_link_libraries(PhysicsEngine PUBLIC Brain)