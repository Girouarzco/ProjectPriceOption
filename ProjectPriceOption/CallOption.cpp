#include "CallOption.h"
#include "VanillaOption.h"



CallOption::CallOption(double x , double y ) : VanillaOption(x,y)
{

    SetOptionType(OptionType::Call);
}



double CallOption::payoff(double z )
{
    if (Getstrike() <= z) { return z - Getstrike() ; }
    return 0;
}

OptionType CallOption::GetOptionType()
{
    return OptionType::Call;
}
