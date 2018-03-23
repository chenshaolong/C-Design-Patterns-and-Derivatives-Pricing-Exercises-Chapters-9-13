// C++ Design Patterns and Derivatives Pricing---Listing 8.2, page 144

#include "TreeProducts.h"

TreeProduct::TreeProduct(double FinalTime_) 
: FinalTime(FinalTime_)
{
}

double TreeProduct::GetFinalTime() const
{
    return FinalTime; 
}