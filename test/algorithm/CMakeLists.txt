add_executable(algorithm_test "algorithms_tests.cpp")

target_link_libraries(algorithm_test PRIVATE algorithm)

AddTests(algorithm_test)
