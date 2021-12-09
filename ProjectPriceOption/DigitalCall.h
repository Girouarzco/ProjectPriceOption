#pragma once
#include "DigitalOption.h"
class DigitalCall :
    public DigitalOption
{
	DigitalCall(double, double);
	double payoff(double);
	OptionType GetOptionType();
};

