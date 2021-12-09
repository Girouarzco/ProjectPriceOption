#include "VanillaOption.h"

VanillaOption::VanillaOption(double x, double y) : Option(x)
{
	if (y < 0)
	{
		this->_strike = 0;
	}
	else { this->_strike = y; }
}


double VanillaOption::Getstrike()
{
	return _strike;
}

OptionType VanillaOption::GetOptionType()
{
	return type;
}

void VanillaOption::SetOptionType(OptionType nouv)
{
	type = nouv;
}
