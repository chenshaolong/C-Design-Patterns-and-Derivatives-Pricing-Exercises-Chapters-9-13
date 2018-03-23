// C++ Design Patterns and Derivatives Pricing---Listing 10.1, page 178

#ifndef PAYOFF_FACTORY_H
#define PAYOFF_FACTORY_H

#include <iostream>
#include <unordered_map>
#include <string>
#include "PayOff3.h"

#if defined(_MSC_VER)
#pragma warning( disable : 4786)
#endif

class PayOffFactory
{
public:
	typedef PayOff* (*CreatePayOffFunction)(double);

	static PayOffFactory& Instance();
	void RegisterPayOff(std::string, CreatePayOffFunction);
	PayOff* CreatePayOff(std::string PayOffId, double Strike);
	~PayOffFactory() { std::cout << "Object left: " << --count << "\n"; }

private:
	static unsigned long count;
	std::unordered_map<std::string, CreatePayOffFunction> TheCreatorFunctions;
	PayOffFactory() {count++;}
	PayOffFactory(const PayOffFactory&) {count++;}
	PayOffFactory& operator=(const PayOffFactory&) { return *this; }
};

#endif