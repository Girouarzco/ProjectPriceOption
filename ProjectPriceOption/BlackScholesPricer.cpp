#include "BlackScholesPricer.h"
#include "VanillaOption.h"

#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>

BlackScholesPricer::BlackScholesPricer(VanillaOption* option, double asset_price, double interest_rate, double volatility)
{
	this->option = option;
	this->asset_price = asset_price;
	this->interest_rate = interest_rate;
	this->volatility = volatility;
    this->strike = option->Getstrike();
    this->type = option->GetOptionType();
}
BlackScholesPricer::BlackScholesPricer(DigitalOption* option2, double asset_price, double interest_rate, double volatility)
{
    this->option = option2;
    this->asset_price = asset_price;
    this->interest_rate = interest_rate;
    this->volatility = volatility;
    this->strike = option2->Getstrike();
    this->type = option2->GetOptionType();
}
double BlackScholesPricer::norm_pdf(const double& x) {
    return (1.0 / (pow(2 * M_PI, 0.5))) * exp(-0.5 * x * x);
}
double BlackScholesPricer::norm_cdf(const double& x)
{
    double k = 1.0 / (1.0 + 0.2316419 * x);
    double k_sum = k * (0.319381530 + k * (-0.356563782 + k * (1.781477937 + k * (-1.821255978 + 1.330274429 * k))));

    if (x >= 0.0) {
        return (1.0 - (1.0 / (pow(2 * M_PI, 0.5))) * exp(-0.5 * x * x) * k_sum);
    }
    else {
        return 1.0 - norm_cdf(-x);
    }
}

double BlackScholesPricer::d1calculator()
{
    return (log(asset_price / strike) + (interest_rate + volatility*volatility*0.5) * option->getExpiry()) / (volatility * (pow(option->getExpiry(), 0.5)));
}
double BlackScholesPricer::d2calculator()
{
    return d1calculator() - volatility * (pow(option->getExpiry(), 0.5));
}
double BlackScholesPricer::Operator()
{
    if (type == OptionType::Call)
    {
        return asset_price * norm_cdf(d1calculator()) -  strike * exp(-interest_rate * option->getExpiry()) * norm_cdf(d2calculator());
    }
    else
    {
        return -asset_price * norm_cdf(-d1calculator()) + strike * exp(-interest_rate * option->getExpiry()) * norm_cdf(-d2calculator());
    }

}
double BlackScholesPricer::delta()
{
    if (type == OptionType::Call)
    {
        return norm_cdf(d1calculator());
    }
    else
    {
        return norm_cdf(d1calculator()) - 1;
    }
}