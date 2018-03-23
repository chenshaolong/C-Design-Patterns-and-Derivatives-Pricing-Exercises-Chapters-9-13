// C++ Design Patterns and Derivatives Pricing---Exercise 10.1, page 185

#ifndef PAYOFF_STRADDLE_H
#define PAYOFF_STRADDLE_H

#include "PayOff3.h"

class PayOffStraddle : public PayOff
{
public:
	PayOffStraddle(double Strike_);

	virtual double operator()(double Spot) const;
	virtual ~PayOffStraddle() {}
	virtual PayOff* clone() const;
private:
	double Strike; 
};

#endif