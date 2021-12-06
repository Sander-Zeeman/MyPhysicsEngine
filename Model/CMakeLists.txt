add_library(Model
    World.cpp
    Shapes/Square.cpp
)

target_include_directories(Model PUBLIC Shapes)