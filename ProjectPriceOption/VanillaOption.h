#pragma once
#include "Option.h"
enum class OptionType { Call,Put };
class VanillaOption : public Option
{
public:
	VanillaOption(double, double);
	double Getstrike();
	OptionType GetOptionType();
	void SetOptionType(OptionType);

private:
	double _strike;
	OptionType type;
};