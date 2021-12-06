find_package(SDL2 REQUIRED)

add_library(Brain
    Brain.cpp
)

target_include_directories(Brain PUBLIC "../Model/Shapes")
target_include_directories(Brain PUBLIC "../Model")
target_include_directories(Brain PUBLIC "../View")
target_include_directories(Brain PUBLIC ${SDL2_INCLUDE_DIRS})
target_link_libraries(Brain PUBLIC ${SDL2_LIBRARIES})