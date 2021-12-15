#pragma once
#include "Option.h"
class BlackScholesMCPricer
{
public :
	BlackScholesMCPricer(Option*, double, double, double);
	int getNbPaths();
	void setnbpaths(int);
	void generate(int);
	double operator()();
	double Variance(std::vector<double>);
	std::vector<double> confidenceInterval();
	
private :
	int NbPaths;
	double assetprice;
	double interest_rate;
	double volatility;
	double expiry;
	double strike;
	Option* option;
	double currentestimation;
	double sum_sqrt;
	double sum;
};

