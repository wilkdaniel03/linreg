#pragma once

#include <iostream>
#include <limits>
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

template <typename T>
requires Numerical<T>
T exp(T x) {
	T res = std::numeric_limits<T>::denorm_min();

	T lastVal = 1;
	T lastFact = 1; 
	for(uint32_t i = 0; i < 10; i++) {
		res += lastVal / lastFact;
		lastVal *= x;
		lastFact = fact(i+1);
	}

	return res;
}

}}
