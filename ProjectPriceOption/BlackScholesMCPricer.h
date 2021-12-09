#pragma once
#include "Option.h"
class BlackScholesMCPricer
{
public :
	BlackScholesMCPricer(Option*, double, double, double);
	int getNbPaths();
	void setnbpaths(int);
	double generate(int);
	double operatorfunc();
private :
	int NbPaths;
	double asset_price;
	double interest_rate;
	double volatility;
	double expiry;
	double strike;
	Option* option;
	double currentestimation;
};

