#pragma once
#include "DigitalOption.h"
class DigitalCallOption :
    public DigitalOption
{
public:
	DigitalCallOption(double, double);
	double payoff(double); 
	OptionType GetOptionType();
};

