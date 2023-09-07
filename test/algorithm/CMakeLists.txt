add_executable(algorithm_test dfs_test.cpp)

target_link_libraries(algorithm_test PRIVATE algorithm)

AddTests(algorithm_test)
