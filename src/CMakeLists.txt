add_executable(main "main.cpp")

add_subdirectory(algorithm)
add_subdirectory(core)
add_subdirectory(common)

target_link_libraries(main PRIVATE core)
target_link_libraries(main PRIVATE algorithm)
