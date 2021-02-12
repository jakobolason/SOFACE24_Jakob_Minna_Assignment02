cmake_minimum_required(VERSION 3.1)
project(template)

# enable testing using ctest
enable_testing()

# include other cmake projects
add_subdirectory(wargame_c)
add_subdirectory(wargame_cpp)
add_subdirectory(test)
add_subdirectory(sandbox)