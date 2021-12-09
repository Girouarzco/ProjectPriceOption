#pragma once
#include "Option.h"
#include "VanillaOption.h"
class DigitalOption :
    public Option
{
public:
	DigitalOption(double, double);
	double Getstrike();
	OptionType GetOptionType();
	void SetOptionType(OptionType);

private:
	double _strike;
	OptionType type;
};

