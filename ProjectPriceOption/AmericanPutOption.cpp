#include "AmericanPutOption.h"
#include "AmericanOption.h"

AmericanPutOption::AmericanPutOption(double expiry, double strike) : AmericanOption(expiry, strike)
{

}

double AmericanPutOption::payoff(double z)
{
	if (Getstrike() >= z) { return Getstrike() - z; }
	return 0;
}

bool AmericanPutOption::isAmericanOption()
{
	return true;
}
