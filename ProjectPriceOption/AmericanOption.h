#pragma once
#include "Option.h"
#include "VanillaOption.h"

class AmericanOption : public Option
{
public:
	AmericanOption(double, std::vector<double>);
	bool isAmericanOption();
	OptionType GetOptionType();
	void SetOptionType(OptionType);

private:
	std::vector<double> vec;
	OptionType type;
};

