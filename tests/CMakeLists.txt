add_executable(TestRunner VectorTest.cpp LinearRegressionTest.cpp MathTest.cpp)
target_link_libraries(TestRunner PRIVATE gtest gtest_main linreg_regression)
