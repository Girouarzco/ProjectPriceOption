#pragma once
#include "Option.h"
class AsianOption :
    public Option
{
public :
    AsianOption(std::vector<double>);
    double payoffPath(std::vector <double>);
    double payoff(double);
    std::vector<double> getvec();
    bool isAsianOption();
private : 
    std::vector<double> vec;
};

