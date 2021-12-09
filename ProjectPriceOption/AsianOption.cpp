#include "AsianOption.h"

AsianOption::AsianOption(double x ,std::vector<double> vect) : Option(x)
{
    this->vec = vect;
}

double AsianOption::payoffPath(std::vector<double>)
{
    return 0.0;
}

double AsianOption::payoff()
{
    return 0.0;
}
