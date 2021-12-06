find_package(SDL2 REQUIRED)

add_library(View
    Screen.cpp
    ShapeRenderer.cpp
)

target_include_directories(View PUBLIC ${SDL2_INCLUDE_DIRS})
target_link_libraries(View PUBLIC ${SDL2_LIBRARIES})