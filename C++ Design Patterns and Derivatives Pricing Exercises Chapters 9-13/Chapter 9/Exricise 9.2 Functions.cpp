// C++ Design Patterns and Derivatives Pricing, Exercise 9.2, page 174

#include "Functions.h"
#include <cmath>

// must implement virtual destructor when it's pure
// from C++ Primer Plus(6th Edition)-Stephen Prata, page 826
// Function::~Function() {} 

double Linear::operator()(double x) const
{
	return x;
}

double Exponential::operator()(double x) const
{
	return exp(x);
}

double Logarithmic::operator()(double x) const
{
	return log(x);
}

double NormalDensity::operator()(double x) const
{
	return exp(-x*x/2) / sqrt(2*3.1415926);
}