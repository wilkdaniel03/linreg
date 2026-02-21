#include <algorithm>
#include <linreg/structures//Vector.hpp>
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
