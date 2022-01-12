cmake_minimum_required(VERSION 3.16)

project(PhysicsEngine)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wpedantic -Wextra -O2")

option(CMD "View the program in the CMD" OFF)
option(SDL "View the program using SDL" OFF)
if(CMD)
    add_definitions(-DCMD_VIEW)
else()
    add_definitions(-DSDL_VIEW)
endif()

find_package(SDL2 REQUIRED)

add_subdirectory(Model)
add_subdirectory(View)

add_executable(PhysicsEngine main.cpp)

target_include_directories(PhysicsEngine PUBLIC ${CMAKE_SOURCE_DIR}/Model)
target_link_libraries(PhysicsEngine World)

if(CMD)
    target_include_directories(PhysicsEngine PUBLIC ${CMAKE_SOURCE_DIR}/View/CMD)
elseif()
    target_include_directories(PhysicsEngine PUBLIC ${CMAKE_SOURCE_DIR}/View/SDL)
endif()
target_link_libraries(PhysicsEngine Viewer)

target_include_directories(PhysicsEngine PUBLIC ${SDL2_INCLUDE_DIRS})
target_link_libraries(PhysicsEngine ${SDL2_LIBRARIES})