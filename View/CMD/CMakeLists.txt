add_library(Viewer Viewer.cpp)

target_include_directories(Viewer PUBLIC ${CMAKE_SOURCE_DIR}/Model)
target_link_libraries(Viewer World)