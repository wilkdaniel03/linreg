#include <iostream>
#include <cstdint>
#include <gtest/gtest.h>
#include <linreg/structures/Vector.hpp>
#include <linreg/regression/LinearRegression.hpp>

TEST(LinearRegressionTest,FirstTest) {
	linreg::structures::Vector<double> args = {30, 32, 33, 35, 37, 38, 40, 41, 43, 45, 46, 48, 49, 53, 54};
	linreg::structures::Vector<double> vals = {2.15, 2.28, 2.35, 2.52, 2.74, 2.86, 3.05, 3.18, 3.36, 3.58, 3.72, 3.94, 4.08, 4.45, 4.82};
	linreg::regression::LinearRegression regression(args,vals);
	auto res = regression.Calculate();
	for(uint32_t i = 0; i < res.size(); i++) {
		std::cout << args[i] << " -> " << res[i] << std::endl;
	}
	double error = regression.CalcError();
	std::cout << "error -> " << error << std::endl;
}
