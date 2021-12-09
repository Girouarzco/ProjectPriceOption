#pragma once
#include <vector>
using namespace std;
class Option
{
public:
	Option(double);
	Option();
	double getExpiry();
	virtual double payoff(double);
	double payoffPath(vector<double>);
	bool isAsianOption();
	bool isAmericanOption();
private:
	double expiry;
};

