#include <iostream>
#include <algorithm>
#include <linreg/structures/Vector.hpp>
#include <linreg/regression/LinearRegression.hpp>

void linreg::regression::LinearRegression::CalcB1() {
	double numerator = 0;
	double denominator = 0;
	auto argsIter = this->args.begin();
	auto valsIter = this->vals.begin();
	while(argsIter != this->args.end()) {
		numerator += (*argsIter - this->argsMean) * (*valsIter - this->valsMean);
		denominator += (*argsIter - this->argsMean) * (*argsIter - this->argsMean);
		argsIter++;
		valsIter++;
	}

	this->b1 = numerator / denominator;
}

void linreg::regression::LinearRegression::CalcB0() {
	this->b0 = this->valsMean - this->argsMean * this->b1;
}

const linreg::structures::Vector<double> linreg::regression::LinearRegression::Calculate() {
	linreg::structures::Vector<double> result(this->args.size());
	std::transform(this->args.begin(),this->args.end(),result.begin(),[this](double el) {
		return el * this->b1 + this->b0;
	});

	return result;
}

linreg::structures::Vector<double> linreg::regression::LinearRegression::CalcValsHat() {
	structures::Vector<double> res(this->args.size());
	std::transform(this->args.begin(),this->args.end(),res.begin(),[this](double el) {
		return this->valsMean + this->b1 * (el - this->argsMean);
	});

	return res;
}

double linreg::regression::LinearRegression::CalcError() {
	double ssr = 0;
	double sse = 0;
		
	std::for_each(this->valsHat.begin(),this->valsHat.end(),[this,&ssr](double el) {
		ssr += (el - this->valsMean) * (el - this->valsMean);
	});

	for(uint32_t i = 0; i < this->vals.size(); i++) {
		sse += (this->vals[i] - this->valsHat[i]) * (this->vals[i] - this->valsHat[i]);
	}

	double sst = ssr + sse;

	return sse / sst;
}
