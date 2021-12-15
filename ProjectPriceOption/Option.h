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
	virtual double payoffPath(vector<double>);
	virtual bool isAsianOption();
	bool isAmericanOption();
	void SetExpiry(double);
private:
	double expiry;
};

