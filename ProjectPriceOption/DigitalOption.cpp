#include "DigitalOption.h"

DigitalOption::DigitalOption(double x , double y ) : Option(x)
{
	if (y < 0)
	{
		this->_strike = 0;
	}
	else { this->_strike = y; }
}

double DigitalOption::Getstrike()
{
	return _strike;
}

OptionType DigitalOption::GetOptionType()
{
	return type;
}

void DigitalOption::SetOptionType(OptionType nouv)
{
	type = nouv;
}
