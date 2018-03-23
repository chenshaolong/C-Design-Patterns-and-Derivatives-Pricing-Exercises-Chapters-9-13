// C++ Design Patterns and Derivatives Pricing---Listing 13.5, page 213

// requires PayOff3.cpp

#include <iostream>
#include "Wrapper2.h"
#include "PayOff3.h"
using namespace std;

int main()
{
    double S, K1, K2, K3;

    cout <<"Spot: ";
    cin >> S;
    cout << "Strike1: ";
    cin >> K1;
    cout << "Strike2: ";
    cin >> K2;

    PayOffCall one(K1);
    PayOffPut two(K2);

    PayOff* p = one.clone();
    Wrapper<PayOff> four = p;

    {
        PayOff* q = two.clone();
        Wrapper<PayOff> five = q;

        cout << "four: " << (*four)(S) << endl;
        cout << "five: " << (*five)(S) << endl;

        four = five;
    }
    cout << "four: " << (*four)(S) << endl;

    cout << "Done.\n";
    return 0;
}