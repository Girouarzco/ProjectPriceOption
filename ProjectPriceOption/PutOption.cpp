#include "PutOption.h"

PutOption::PutOption(double x, double y ) : VanillaOption(x,y)
{
	SetOptionType(OptionType::Put);
}

double PutOption::payoff(double z )
{
	if (Getstrike() >= z) { return Getstrike() - z; }
	return 0;
}

OptionType PutOption::GetOptionType()
{
	return OptionType::Put;
}
