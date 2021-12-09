#include "AsianOption.h"

AsianOption::AsianOption(std::vector<double> timeseries) 
{
    this->vec = timeseries;
}
double AsianOption::payoffPath(std::vector<double> x)
{
    double somme = 0;
    for (int i = 0; i <= x.size(); i++)
    {
        somme += x[i];
    }
    somme = somme / x.size();
    return payoff(somme);
}

double AsianOption::payoff(double somme)
{
    return 0.0;
}

std::vector<double> AsianOption::getvec()
{
    return vec;
}

bool AsianOption::isAsianOption()
{
    return true;
}
