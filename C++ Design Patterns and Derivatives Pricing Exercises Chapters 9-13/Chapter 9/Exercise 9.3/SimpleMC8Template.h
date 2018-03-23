// C++ Design Patterns and Derivatives Pricing---Exercise 9.3, page 174

#ifndef SIMPLE_MC8_TEMPLATE
#define SIMPLE_MC8_TEMPLATE
#include "Arrays.h"
#include <cmath>

template<class T1, class T2, class T3, class T4>
void SimpleMonteCarlo6Template(const T1& TheOption,
                               double Spot,
                               const T2& Vol,
                               const T2& r,
                               unsigned long NumberOfPaths,
                               T3& gatherer,
                               T4& generator) 
{
    generator.ResetDimensionality(1);

    double Expiry = TheOption.GetExpiry();
    double variance = Vol.IntegralSquare(0, Expiry);
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5 * variance;

    double movedSpot = Spot * exp(r.Integral(0, Expiry) + itoCorrection);
    double thisSpot;
    double discounting = exp(-r.Integral(0, Expiry));

    MJArray VariateArray(1);

    for (unsigned long i = 0; i < NumberOfPaths; i++)
    {
      generator.GetGaussians(VariateArray);
      thisSpot = movedSpot * exp(rootVariance * VariateArray[0]);
      double thisPayOff = TheOption.OptionPayOff(thisSpot);
      gatherer.DumpOneResult(thisPayOff * discounting);
    }

    return;
}

#endif