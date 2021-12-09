#pragma once
#include "VanillaOption.h"
class PutOption :
    public VanillaOption
{
public :
    PutOption(double, double);
    double payoff(double);
    OptionType GetOptionType();
};

