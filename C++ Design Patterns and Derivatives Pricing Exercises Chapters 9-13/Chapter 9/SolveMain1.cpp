// C++ Design Patterns and Derivatives Pricing, Listing 9.4, page 165

/* 
Needs
    BlackScholesFormulas.cpp
    BSCallClass.cpp
    Normals.cpp
*/

#include <iostream>
#include <cmath>
#include "Bisection.h"
#include "BSCallClass.h"
#include "BlackScholesFormulas.h"
using namespace std;

int main()
{
	double Expiry;
    double Strike;
    double Spot;
    double Vol0;
    double r;
    double d;

    cout << "Expiry: ";
    cin >> Expiry;
    cout << "Strike: ";
    cin >> Strike;
    cout << "Spot: ";
    cin >> Spot;
    cout << "vol: ";
    cin >> Vol0;
    cout << "r: ";
    cin >> r;
    cout << "d: ";
    cin >> d;

    double BSPrice = BlackScholesCall(Spot, Strike, r, d, Vol0, Expiry);

    cout << "Black Scholes call price: " << BSPrice << endl;

    double Price;
    cout << "Price: ";
    cin >> Price;

    double low, high;

    cout << "low guess for volatility: ";
    cin >> low;
    cout << "high guess for volatility: ";
    cin >> high;

    double tolerance;
    cout << "Tolerance: ";
    cin >> tolerance;

    BSCall theCall(r, d, Expiry, Spot, Strike);

    double vol = Bisection(Price, low, high, tolerance, theCall);
    double PriceTwo = BlackScholesCall(Spot, Strike, r, d, vol, Expiry);

    cout << "vol = " << vol
         << "\npricetwo = " << PriceTwo << endl;

	cout << "Done.\n";
	return 0;
}