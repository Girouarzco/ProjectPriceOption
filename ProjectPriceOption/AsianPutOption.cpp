#include "AsianPutOption.h"


AsianPutOption::AsianPutOption(std::vector<double> vec , double St) : AsianOption(vec)
{
	this->strike = St;
}

double AsianPutOption::payoff(double z)
{
	return std::max(strike-z, 0.0);
}
bool AsianPutOption::isAsianOption()
{
	return true;
}
