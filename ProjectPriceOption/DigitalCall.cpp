#include "DigitalCall.h"
DigitalCall::DigitalCall(double x, double y) : DigitalOption(x, y)
{
    SetOptionType(OptionType::Call);
}
double DigitalCall::payoff(double z )
{
    if (Getstrike() <= z) { return 1; }
    return 0;
}

OptionType DigitalCall::GetOptionType()
{
    return OptionType::Call;
}
