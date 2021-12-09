#pragma once
#include "VanillaOption.h"
class BlackScholesPricer
{
public:
	BlackScholesPricer(VanillaOption* option, double asset_price, double interest_rate, double volatility);
	double Operator();
	double norm_pdf(const double& x);
	double norm_cdf(const double& x);
	double d1calculator();
	double d2calculator();
	double delta();

private:
	friend class VanillaOption;
	VanillaOption* option;
	double asset_price;
	double interest_rate;
	double volatility;
};

