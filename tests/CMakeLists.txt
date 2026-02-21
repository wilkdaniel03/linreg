add_executable(TestRunner VectorTest.cpp LinearRegressionTest.cpp)
target_link_libraries(TestRunner PRIVATE gtest gtest_main regression)
