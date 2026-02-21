cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(linreg VERSION 1.0.0 LANGUAGES CXX)
enable_testing()
add_subdirectory(oatpp)
add_subdirectory(googletest)
add_subdirectory(src)
add_subdirectory(tests)
target_link_libraries(Linreg PRIVATE oatpp)
target_include_directories(Linreg PRIVATE include)
target_include_directories(TestRunner PRIVATE include)
add_test(
	NAME linreg
	COMMAND tests/TestRunner
)
