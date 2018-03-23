// C++ Design Patterns and Derivatives Pricing---Listing 10.5, page 183

/* 
Uses
    PayOff3.cpp
    PayOffBridge.cpp
    PayOffFactory.cpp
    PayOffRegistration.cpp
*/

#include <iostream>
#include <string>
#include "PayOff3.h"
#include "PayOffBridge.h"
#include "PayOffConstructible.h"
#include "PayOffFactory.h"
using namespace std;

int main()
{
	double Strike;
	string name;

	cout << "strike: ";
	cin >> Strike;

	cout << "pay-off name: ";
	cin >> name;

	PayOff* PayOffPtr = PayOffFactory::Instance().CreatePayOff(name, Strike);

	if (PayOffPtr) {
		double Spot;

		cout << "spot: ";
		cin >> Spot;

		cout << "option price: " << PayOffPtr->operator()(Spot) << endl;
		delete PayOffPtr;
	}

	cout <<"Done.\n";
	return 0;
}