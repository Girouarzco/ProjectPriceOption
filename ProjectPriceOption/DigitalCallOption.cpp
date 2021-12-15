#include "DigitalCallOption.h"
#include "DigitalOption.h"
DigitalCallOption::DigitalCallOption(double x, double y) : DigitalOption(x, y)
{
    SetOptionType(OptionType::Call);
}
double DigitalCallOption::payoff(double z ) 
{
    if (z>= Getstrike() ) { return 1; }
    return 0;
}

OptionType DigitalCallOption::GetOptionType()
{
    return OptionType::Call;
}
