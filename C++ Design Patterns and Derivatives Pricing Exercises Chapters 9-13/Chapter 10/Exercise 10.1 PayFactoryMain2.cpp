// C++ Design Patterns and Derivatives Pricing---Listing 10.5, page 183

/* 
Uses
    PayOff3.cpp
    PayOffStraddle.cpp
    PayOffBridge.cpp
    PayOffFactory.cpp
    PayOffRegistration.cpp
    PayOffRegistration2.cpp
*/

#include <iostream>
#include <string>
#include "PayOff3.h"
#include "PayOffStraddle.h"
#include "PayOffBridge.h"
#include "PayOffConstructible.h"
#include "PayOffFactory.h"
using namespace std;

int main()
{
	double Strike, Spot;
	string name;

	cout << "strike: ";
	cin >> Strike;

	cout << "spot: ";
	cin >> Spot;

	cout << "pay-off name: ";
	cin >> name;

	PayOff* PayOffPtr = PayOffFactory::Instance().CreatePayOff(name, Strike);

	if (PayOffPtr) {
		cout << "option price: " << PayOffPtr->operator()(Spot) << endl;

		cout << "new spot: ";
		cin >> Spot;
		cout << "option price: " << PayOffPtr->operator()(Spot) << endl;

		delete PayOffPtr;
	}

	cout << "\n~~~~~~~~~~~~~~~~~~\n";
	cout << "pay-off name: ";
	cin >> name;

	PayOff* PayOffPtr2 = PayOffFactory::Instance().CreatePayOff(name, Strike);

	if (PayOffPtr2) {
		cout << "option price: " << PayOffPtr2->operator()(Spot) << endl;
		delete PayOffPtr2;
	}

	cout <<"Done.\n";
	return 0;
}