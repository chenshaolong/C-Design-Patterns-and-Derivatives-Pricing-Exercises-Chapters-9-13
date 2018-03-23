// C++ Design Patterns and Derivatives Pricing---Listing 8.5, page 146

#include "TreeAmerican.h"
#include <algorithm>

TreeAmerican::TreeAmerican(double FinalTime,
                           const PayOffBridge& ThePayOff_)
                 : TreeProduct(FinalTime),
                   ThePayOff(ThePayOff_)
{
}

TreeProduct* TreeAmerican::clone() const
{
     return new TreeAmerican(*this);
}

double TreeAmerican::FinalPayOff(double Spot) const
{
    return ThePayOff(Spot);
}

double TreeAmerican::PreFinalValue(double Spot,
                                 double Time, // Borland compiler doesnt like unused named variables
                                 double DiscountedFutureValue) const
{
    return std::max(ThePayOff(Spot), DiscountedFutureValue);
}