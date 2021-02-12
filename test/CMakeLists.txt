include_directories(include)
add_executable(c_tests src/test_c_wargame.cpp)
add_executable(cpp_tests src/test_cpp_wargame.cpp)

target_link_libraries(c_tests wargame_c)
target_link_libraries(cpp_tests wargame_cpp)

# Declare that c_test and cpp_tests should be consider test executables
# These will be executed when running "ctest" in the build directory
add_test(wargame_c_tests c_tests)
add_test(wargame_cpp_tests cpp_tests)