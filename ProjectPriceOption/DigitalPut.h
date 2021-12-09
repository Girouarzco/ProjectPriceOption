#pragma once
#include "DigitalOption.h"
class DigitalPut :
    public DigitalOption
{
    DigitalPut(double, double);
    double payoff(double);
    OptionType GetOptionType();
};

