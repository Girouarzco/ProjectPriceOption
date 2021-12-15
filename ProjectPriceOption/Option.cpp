#include "Option.h"
#include "Option.h"
Option::Option(double x)
{
	this->expiry = x;
}
Option::Option()
{}
double Option::getExpiry()
{
	return expiry;
}
double Option::payoff(double x)
{
	return 0.0;
}
double Option::payoffPath(vector<double> vect )
{
	return payoff(vect.back());
}

bool Option::isAsianOption()
{
	return false;
}
bool Option::isAmericanOption()
{
	return false;
}

void Option::SetExpiry(double x)
{
	this->expiry = x;
}
