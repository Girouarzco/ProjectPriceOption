#pragma once
#include "DigitalOption.h"
class DigitalPut :
    public DigitalOption
{
public:
    DigitalPut(double, double);
    double payoff(double);
    OptionType GetOptionType();
};

