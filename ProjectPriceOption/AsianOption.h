#pragma once
#include "Option.h"
class AsianOption :
    public Option
{
public :
    AsianOption(double,std::vector<double>);
    double payoffPath(std::vector<double>);
    double payoff();
private : 
    std::vector<double> vec;
};

