#pragma once
#include "Option.h"
class BlackScholesMCPricer
{
private:
	long generated_paths; //Total number of paths created
	Option* option;
	double price; //Price
	double S0; //Initial price
	double r; //Interest rate
	double sigma; //Volatility
public:
	BlackScholesMCPricer(Option*, double, double, double); //Option* option, double initial_price, double interest rate, double volatility)
	long getNbPaths();
	double generate(int);
	double operator()(); //throws an exception if not defined
	std::vector<double> confidenceInterval();
};
