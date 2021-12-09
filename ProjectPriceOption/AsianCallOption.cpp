#include "AsianCallOption.h"
#include "AsianOption.h"
#include <algorithm>


AsianCallOption::AsianCallOption(std::vector<double> vec, double St) : AsianOption(vec)
{
	this->strike = St;
}

double AsianCallOption::payoff(double z)
{
	return std::max(z - strike , 0.0);
}
