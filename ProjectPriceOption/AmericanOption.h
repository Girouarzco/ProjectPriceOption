#pragma once
#include "Option.h"
#include "VanillaOption.h"

class AmericanOption : public Option
{
public:
	AmericanOption(double, double);
	bool isAmericanOption();
	OptionType GetOptionType();
	double Getstrike();
	void SetOptionType(OptionType);

private:
	double strike;
	OptionType type;
};

