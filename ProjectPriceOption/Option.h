#pragma once
#include <vector>
using namespace std;
class Option
{
public:
	Option(double);
	double getExpiry();
	virtual double payoff(double);
	double payoffPath(vector<double>);
	bool isAsianOption();
private:
	double expiry;
};

