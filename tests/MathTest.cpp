#include <iostream>
#include <gtest/gtest.h>
#include <linreg/math/Function.hpp>
#include <array>
#include <cstdint>

TEST(MathTest,FactorialFunction) {
	std::array<uint32_t,10> expectedResults = {
		1,2,6,24,120,720,5040,40320,362880,3628800
	};

	uint32_t i = 1;
	for(auto el : expectedResults) {
		EXPECT_EQ(el,linreg::math::fact(i++));
	}
}
