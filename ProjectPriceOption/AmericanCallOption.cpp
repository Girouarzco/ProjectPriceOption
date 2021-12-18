#include "AmericanCallOption.h"
#include "AmericanOption.h"

AmericanCallOption::AmericanCallOption(double expiry, double strike) : AmericanOption(expiry, strike)
{
}

double AmericanCallOption::payoff(double z)
{
	if (Getstrike() <= z) { return z - Getstrike(); }
	return 0;
}

bool AmericanCallOption::isAmericanOption()
{
	return true;
}
