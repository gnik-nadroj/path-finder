add_library(algorithm "utils.cpp" "dfs.cpp" "bfs.cpp" "a_star.cpp")
 
target_include_directories(algorithm PUBLIC .)

target_link_libraries(algorithm common)