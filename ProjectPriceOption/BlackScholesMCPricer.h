#pragma once
#include "Option.h"
class BlackScholesMCPricer
{
public:
	BlackScholesMCPricer(Option*, double, double, double);
	int getNbPaths();
	void setnbpaths(int);
	void generate(int);
	double operator()();
	std::vector<double> confidenceInterval();

private:
	int NbPaths;
	double assetprice;
	double interest_rate;
	double volatility;
	Option* option;
	double currentestimation;
	double sum;
	double sum_squared;

};

