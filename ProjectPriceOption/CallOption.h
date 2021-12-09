#pragma once
#include "VanillaOption.h"
class CallOption : public VanillaOption
{
public :
	CallOption(double, double);
	double payoff(double);
	OptionType GetOptionType();
};

