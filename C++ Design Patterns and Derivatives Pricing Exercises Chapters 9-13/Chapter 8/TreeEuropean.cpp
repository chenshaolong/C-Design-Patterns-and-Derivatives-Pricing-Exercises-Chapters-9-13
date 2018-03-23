// C++ Design Patterns and Derivatives Pricing---Listing 8.6, page 146

#include "TreeEuropean.h"
#include <algorithm>

TreeEuropean::TreeEuropean(double FinalTime,
                           const PayOffBridge& ThePayOff_)
                 : TreeProduct(FinalTime),
                   ThePayOff(ThePayOff_)
{
}

double TreeEuropean::FinalPayOff(double Spot) const
{
    return ThePayOff(Spot);
}

double TreeEuropean::PreFinalValue(double Spot, //Spot, Borland compiler
                                 double Time, //Time,   doesnt like unused named variables
                                 double DiscountedFutureValue) const
{
    return DiscountedFutureValue;
}

TreeProduct* TreeEuropean::clone() const
{
    return new TreeEuropean(*this);
}