// C++ Design Patterns and Derivatives Pricing---Listing 10.1, page 178

#if defined(_MSC_VER)
#pragma warning( disable : 4786)
#endif

#include <iostream>
#include "PayOffFactory.h"
using namespace std;

void PayOffFactory::RegisterPayOff(string PayOffId, CreatePayOffFunction CreatorFunction)
{
	//TheCreatorFunctions.insert(pair<string, CreatePayOffFunction>(PayOffId, CreatorFunction));
	 TheCreatorFunctions[PayOffId] = CreatorFunction;
}

PayOff* PayOffFactory::CreatePayOff(string PayOffId, double Strike)
{
	unordered_map<string, CreatePayOffFunction>::const_iterator i = TheCreatorFunctions.find(PayOffId);

	if (i == TheCreatorFunctions.end()) {
		cout << PayOffId << " is an unknown payoff" << endl;
		return nullptr;
	}
	return (i->second)(Strike);
}

PayOffFactory& PayOffFactory::Instance()
{
	static PayOffFactory theFactory;
	return theFactory;
}