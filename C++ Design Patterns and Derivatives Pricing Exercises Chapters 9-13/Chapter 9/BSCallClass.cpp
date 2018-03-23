// C++ Design Patterns and Derivatives Pricing, Listing 9.2, page 163

#include "BSCallClass.h"
#include "BlackScholesFormulas.h"

BSCall::BSCall(double r_, double d_, double T_, double Spot_, double Strike_)
: r(r_), d(d_), T(T_), Spot(Spot_), Strike(Strike_) {}

double BSCall::operator()(double Vol) const
{
	return BlackScholesCall(Spot, Strike, r, d, Vol, T);
}

