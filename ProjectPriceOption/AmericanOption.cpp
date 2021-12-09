#include "AmericanOption.h"

bool AmericanOption::isAmericanOption()
{
	return true;
}

AmericanOption::AmericanOption(double x, std::vector<double> vect) : Option(x)
{
	this->vec = vect;
}

OptionType AmericanOption::GetOptionType()
{
	return type;
}

void AmericanOption::SetOptionType(OptionType nouv)
{
	type = nouv;
}