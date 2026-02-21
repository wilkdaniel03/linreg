#pragma once

#include <algorithm>
#include <iostream>
#include <cstdint>
#include <vector>
#include <initializer_list>

namespace linreg { namespace structures {

template <typename T>
class Vector : public std::vector<T> {
public:
	Vector() : std::vector<T>() {}
	Vector(size_t size) : std::vector<T>(size) {}
	Vector(std::initializer_list<T> els) : std::vector<T>(els) {}
	void operator+=(T val) {
		auto iter = this->begin();
		while(iter != this->end()) {
			*iter += val;
			iter++;
		}
	}
	void operator+=(Vector<T> vec) {
		auto iter = this->begin();
		uint32_t i = 0;
		while(iter != this->end()) {
			*iter += vec[i++];
			iter++;
		}
	}
	Vector<T> operator+(T val) {
		Vector<T> copy(*this);
		copy += val;
		return copy;
	}
	Vector<T> operator+(Vector<T> vec) {
		Vector<T> copy(*this);
		copy += vec;
		return copy;
	}
	void operator-=(T val) {
		auto iter = this->begin();
		while(iter != this->end()) {
			*iter -= val;
			iter++;
		}
	}
	void operator-=(Vector<T> vec) {
		auto iter = this->begin();
		uint32_t i = 0;
		while(iter != this->end()) {
			*iter -= vec[i++];
			iter++;
		}
	}
	Vector<T> operator-(T val) {
		Vector<T> copy(*this);
		copy -= val;
		return copy;
	}
	Vector<T> operator-(Vector<T> vec) {
		Vector<T> copy(*this);
		copy -= vec;
		return copy;
	}
	void operator*=(T val) {
		auto iter = this->begin();
		while(iter != this->end()) {
			*iter *= val;
			iter++;
		}
	}
	void operator*=(Vector<T> vec) {
		auto iter = this->begin();
		uint32_t i = 0;
		while(iter != this->end()) {
			*iter *= vec[i++];
			iter++;
		}
	}
	Vector<T> operator*(T val) {
		Vector<T> copy(*this);
		copy *= val;
		return copy;
	}
	Vector<T> operator*(Vector<T> vec) {
		Vector<T> copy(*this);
		copy *= vec;
		return copy;
	}
	void operator/=(T val) {
		auto iter = this->begin();
		while(iter != this->end()) {
			*iter /= val;
			iter++;
		}
	}
	void operator/=(Vector<T> vec) {
		auto iter = this->begin();
		uint32_t i = 0;
		while(iter != this->end()) {
			*iter /= vec[i++];
			iter++;
		}
	}
	Vector<T> operator/(T val) {
		Vector<T> copy(*this);
		copy /= val;
		return copy;
	}
	Vector<T> operator/(Vector<T> vec) {
		Vector<T> copy(*this);
		copy /= vec;
		return copy;
	}
};

}}
