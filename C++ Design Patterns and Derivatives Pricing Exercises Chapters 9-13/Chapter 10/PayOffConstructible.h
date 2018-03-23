// C++ Design Patterns and Derivatives Pricing---Listing 10.3, page 181

#ifndef PAYOFF_CONSTRUCTIBLE_H
#define PAYOFF_CONSTRUCTIBLE_H

#if defined(_MSC_VER)
#pragma warning( disable : 4786)
#endif

#include <iostream>
#include <string>
#include "PayOff3.h"
#include "PayOffFactory.h"

template<class T>
class PayOffHelper
{
public:
	PayOffHelper(std::string);
	static PayOff* Create(double);
};

template<class T>
PayOff* PayOffHelper<T>::Create(double Strike)
{
	return new T(Strike);
}

template<class T>
PayOffHelper<T>::PayOffHelper(std::string id)
{
	PayOffFactory& thePayOffFactory = PayOffFactory::Instance();
	thePayOffFactory.RegisterPayOff(id, PayOffHelper<T>::Create);
}

#endif
