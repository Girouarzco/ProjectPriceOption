#include "DigitalPutOption.h"
DigitalPutOption::DigitalPutOption(double x, double y) : DigitalOption(x, y)
{
	SetOptionType(OptionType::Put);
}
double DigitalPutOption::payoff(double z) 
{
	if (z <=Getstrike()) { return 1; }
	return 0;
}

OptionType DigitalPutOption::GetOptionType()
{
	return OptionType::Put;
}
