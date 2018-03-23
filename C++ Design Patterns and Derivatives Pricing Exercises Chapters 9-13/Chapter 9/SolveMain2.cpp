// C++ Design Patterns and Derivatives Pricing, Listing 9.8, page 170

/* 
Needs
    BlackScholesFormulas.cpp
    BSCallTwo.cpp
    Normals.cpp
*/

#include <iostream>
#include <cmath>
#include "NewtonRaphson.h"
#include "BSCallTwo.h"
#include "BlackScholesFormulas.h"
#include "Format.h"
using namespace std;

int main()
{
    Formatting format;
	double Expiry;
    double Strike;
    double Spot;
    double r;
    double d;
    double Price;

    cout << "Expiry: ";
    cin >> Expiry;
    cout << "Strike: ";
    cin >> Strike;
    cout << "Spot: ";
    cin >> Spot;
    cout << "r: ";
    cin >> r;
    cout << "d: ";
    cin >> d;
    cout << "Price: ";
    cin >> Price;

    double start;
    cout << "start guess for volatility:";
    cin >> start;

    double tolerance;
    cout << "Tolerance: ";
    cin >> tolerance;

    BSCallTwo theCall(r, d, Expiry, Spot, Strike);

    double vol = NewtonRaphson<BSCallTwo, &BSCallTwo::Price, &BSCallTwo::Vega>(Price, start, tolerance, theCall);
    double PriceTwo = BlackScholesCall(Spot, Strike, r, d, vol, Expiry);

    cout << "vol = " << vol
         << "\npricetwo = " << PriceTwo << endl;

    format.restore();
	cout << "Done.\n";
	return 0;
}