#pragma once

#include <cstdint>
#include <concepts>

namespace linreg { namespace math {

template <typename T>
concept Numerical = std::integral<T> || std::floating_point<T>;

template <typename T>
requires std::unsigned_integral<T>
T fact(T x) {
	T res = 1;
	uint32_t i = 1;
	while(i <= x) {
		res *= i++;
	}

	return res;
}

}}
