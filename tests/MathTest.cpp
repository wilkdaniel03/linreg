#include <iostream>
#include <gtest/gtest.h>
#include <linreg/math/Function.hpp>
#include <array>
#include <cstdint>
#include <cmath>

TEST(MathTest,FactorialFunction) {
	std::array<uint32_t,10> expectedResults = {
		1,2,6,24,120,720,5040,40320,362880,3628800
	};

	uint32_t i = 1;
	for(auto el : expectedResults) {
		EXPECT_EQ(el,linreg::math::fact(i++));
	}
}

TEST(MathTest,ExpFunction) {
	std::array<double,10> vals = {
		-2.0, -1.5555555555555556, -1.1111111111111112, -0.6666666666666667, -0.22222222222222232, 0.22222222222222232, 0.6666666666666665, 1.1111111111111107, 1.5555555555555554, 2.0
	};

	std::array<double,10> expectedResults = {
		0.1353352832366127, 0.2110720877910902, 0.32919298780790557, 0.513417119032592, 0.800737402916808, 1.2488488690016823, 1.9477340410546755, 3.0377317775174815, 4.7377178596430785, 7.38905609893065
	};

	for(uint32_t i = 0; i < vals.size(); i++) {
		EXPECT_LE((std::abs(linreg::math::exp(vals[i]) - expectedResults[i]) / expectedResults[i]),0.01);
	}
}
