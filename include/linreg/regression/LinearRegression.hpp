#pragma once

#include <numeric>

#include "../structures/Vector.hpp"

namespace linreg { namespace regression {

class LinearRegression {
	structures::Vector<double> args;
	structures::Vector<double> vals;
	structures::Vector<double> valsHat;
	double argsMean;
	double valsMean;
	double b0;
	double b1;
public:
	LinearRegression() {}
	LinearRegression(structures::Vector<double>& args, structures::Vector<double>& vals) : args(args), vals(vals) {
		if(args.size() != vals.size()) {
			throw std::runtime_error("Args and vals should have same size");
		}
		this->argsMean = (std::accumulate(this->args.begin(),this->args.end(),0.0) / (double)this->args.size());
		this->valsMean = (std::accumulate(this->vals.begin(),this->vals.end(),0.0) / (double)this->vals.size());
		this->CalcB1();
		this->CalcB0();
		this->valsHat = this->CalcValsHat();
	}
	const structures::Vector<double> Calculate();
	double CalcError();
private:
	void CalcB0();
	void CalcB1();
	structures::Vector<double> CalcValsHat();
};

}}
