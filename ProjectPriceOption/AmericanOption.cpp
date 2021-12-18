#include "AmericanOption.h"

AmericanOption::AmericanOption(double x, double y) : Option(x)
{
	if (y < 0)
	{
		this->strike = 0;
	}
	else { this->strike = y; }
}

OptionType AmericanOption::GetOptionType()
{
	return type;
}

double AmericanOption::Getstrike()
{
	return strike;
}

void AmericanOption::SetOptionType(OptionType nouv)
{
	type = nouv;
}

bool AmericanOption::isAmericanOption()
{
	return true;
}