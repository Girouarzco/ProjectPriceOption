#pragma once
#include "DigitalOption.h"
class DigitalPutOption :
    public DigitalOption
{
public:
    DigitalPutOption(double, double);
    double payoff(double);
    OptionType GetOptionType();

};

