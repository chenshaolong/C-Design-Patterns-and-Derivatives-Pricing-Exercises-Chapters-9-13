// C++ Design Patterns and Derivatives Pricing---Exercise 10.1, page 185

#include "PayOff3.h"
#include "PayOffStraddle.h"
#include <cmath>
#include <algorithm> 

PayOffStraddle::PayOffStraddle(double Strike_) : Strike(Strike_) {}

double PayOffStraddle::operator()(double Spot) const
{
    return std::fabs(Spot - Strike);
}

PayOff* PayOffStraddle::clone() const
 {
 	return new PayOffStraddle(*this);
 }
