add_library(core maze_manager.cpp)

target_include_directories(core PUBLIC .)

target_link_libraries(core PRIVATE algorithm common)