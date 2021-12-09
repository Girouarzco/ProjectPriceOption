#include "DigitalPut.h"
DigitalPut::DigitalPut(double x, double y) : DigitalOption(x, y)
{
	SetOptionType(OptionType::Put);
}
double DigitalPut::payoff(double z)
{
	if (Getstrike()>= z) { return 1; }
	return 0;
}

OptionType DigitalPut::GetOptionType()
{
	return OptionType::Put;
}
