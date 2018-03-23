// C++ Design Patterns and Derivatives Pricing---Listing A.1, page 284

#ifndef BLACK_SCHOLES_FORMULAS_H
#define BLACK_SCHOLES_FORMULAS_H

double BlackScholesCall(double Spot, double Strike, double r, double d, double Vol, double Expiry);

double BlackScholesPut(double Spot, double Strike, double r, double d, double Vol, double Expiry);

double BlackScholesDigitalCall(double Spot, double Strike, double r, double d, double Vol, double Expiry);

double BlackScholesDigitalPut(double Spot, double Strike, double r, double d, double Vol, double Expiry);

double BlackScholesCallVega(double Spot, double Strike, double r, double d, double Vol, double Expiry);

#endif