add_library(algorithm dfs.cpp)

target_include_directories(algorithm PUBLIC .)

target_link_libraries(algorithm common)