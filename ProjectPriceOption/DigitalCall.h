#pragma once
#include "DigitalOption.h"
class DigitalCall :
    public DigitalOption
{
public:
	DigitalCall(double, double);
	double payoff(double);
	OptionType GetOptionType();
};

