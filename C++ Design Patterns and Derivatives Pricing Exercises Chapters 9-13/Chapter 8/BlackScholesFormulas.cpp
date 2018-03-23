// C++ Design Patterns and Derivatives Pricing---Listing A.2, page 285

#include "BlackScholesFormulas.h"
#include "Normals.h"
#include <cmath>

#if !defined(_MSC_VER)
using namespace std;
#endif

double BlackScholesCall(double Spot, double Strike, double r, double d, double Vol, double Expiry)
{
	double StandardDeviation = Vol * sqrt(Expiry);
	double moneyness = log(Spot / Strike);
	double d1 = (moneyness + (r - d) * Expiry + 0.5 * StandardDeviation * StandardDeviation) / StandardDeviation;
	double d2 = d1 - StandardDeviation;
	return Spot * exp(-d * Expiry) * CumulativeNormal(d1) - Strike * exp(-r * Expiry) * CumulativeNormal(d2);
}

double BlackScholesPut(double Spot, double Strike, double r, double d, double Vol, double Expiry)
{
	double StandardDeviation = Vol * sqrt(Expiry);
	double moneyness = log(Spot / Strike);
	double d1 = (moneyness + (r - d) * Expiry + 0.5 * StandardDeviation * StandardDeviation) / StandardDeviation;
	double d2 = d1 - StandardDeviation;
	return Strike * exp(-r * Expiry) * (1.0 - CumulativeNormal(d2)) - Spot * exp(-d * Expiry) * (1.0 - CumulativeNormal(d1));
}

double BlackScholesDigitalCall(double Spot, double Strike, double r, double d, double Vol, double Expiry)
{
	double StandardDeviation = Vol * sqrt(Expiry);
	double moneyness = log(Spot / Strike);
	double d2 = (moneyness + (r - d) * Expiry - 0.5 * StandardDeviation * StandardDeviation) / StandardDeviation;
	return exp(-r * Expiry) * CumulativeNormal(d2);
}

double BlackScholesDigitalPut(double Spot, double Strike, double r, double d, double Vol, double Expiry)
{
	double StandardDeviation = Vol * sqrt(Expiry);
	double moneyness = log(Spot / Strike);
	double d2 = (moneyness + (r - d) * Expiry - 0.5 * StandardDeviation * StandardDeviation) / StandardDeviation;
	return exp(-r * Expiry) * (1.0 - CumulativeNormal(d2));
}

double BlackScholesCallVega(double Spot, double Strike, double r, double d, double Vol, double Expiry)
{
	double StandardDeviation = Vol * sqrt(Expiry);
	double moneyness = log(Spot / Strike);
	double d1 = (moneyness + (r - d) * Expiry + 0.5 * StandardDeviation * StandardDeviation) / StandardDeviation;
	return Spot * exp(-d * Expiry) * sqrt(Expiry) * NormalDensity(d1);
}