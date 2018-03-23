// C++ Design Patterns and Derivatives Pricing---Listing 8.9, page 153      

/*
requires
    Arrays.cpp
    BinomialTree.cpp
    BlackScholesFormulas.cpp
    Normals.cpp
    Parameters.cpp
    PayOff3.cpp
    PayOffBridge.cpp
    PayOffForward.cpp
    TreeAmerican.cpp
    TreeEuropean.cpp
    TreeMain.cpp
    TreeProducts.cpp
  */
#include "BinomialTree.h"
#include "TreeAmerican.h"
#include "TreeEuropean.h"
#include "BlackScholesFormulas.h"
#include "PayOffForward.h"
#include <iostream>
using namespace std;
#include <cmath>

int main()
{
    double Expiry;
    double Strike; 
    double Spot; 
    double Vol; 
    double r;
    double d;
    unsigned long Steps;

    cout << "Expiry: ";
    cin >> Expiry;
    cout << "Strike: ";
    cin >> Strike;
    cout << "Spot: ";
    cin >> Spot;
    cout << "Vol: ";
    cin >> Vol;
    cout << "r: ";
    cin >> r;
    cout << "d: ";
    cin >> d;
    cout << "Number of steps: ";
    cin >> Steps;

    PayOffCall thePayOff(Strike);

    ParametersConstant rParam(r);
    ParametersConstant dParam(d);

    TreeEuropean europeanOption(Expiry,thePayOff);
    TreeAmerican americanOption(Expiry,thePayOff);

    SimpleBinomialTree theTree(Spot,rParam,dParam,Vol,Steps,Expiry);
    double euroPrice = theTree.GetThePrice(europeanOption);
    double americanPrice = theTree.GetThePrice(americanOption);
    cout << "European option price " << euroPrice 
         << "\nAmerican option price " << americanPrice << "\n";

    double BSPrice = BlackScholesCall(Spot,Strike,r,d,Vol,Expiry);
    cout << "BS formula European option price " << BSPrice << "\n";
    
    PayOffForward forwardPayOff(Strike);
    TreeEuropean forward(Expiry,forwardPayOff);

    double forwardPrice = theTree.GetThePrice(forward);
    cout << "forward price by tree " << forwardPrice << "\n";

    double actualForwardPrice = exp(-r*Expiry)*(Spot*exp((r-d)*Expiry)-Strike);
    cout << "forward price " << actualForwardPrice << "\n";

    Steps++; // now redo the trees with one more step
    SimpleBinomialTree theNewTree(Spot,rParam,dParam,Vol,Steps,Expiry);

    double euroNewPrice = theNewTree.GetThePrice(europeanOption);
    double americanNewPrice = theNewTree.GetThePrice(americanOption);

    cout << "European option new price: " << euroNewPrice 
         << "\nAmerican option new price: " << americanNewPrice << "\n";

    double forwardNewPrice = theNewTree.GetThePrice(forward);

    cout << "forward price by new tree: " << forwardNewPrice << "\n";

    double averageEuro = 0.5*(euroPrice + euroNewPrice);
    double averageAmer = 0.5*(americanPrice + americanNewPrice);
    double averageForward = 0.5*(forwardPrice + forwardNewPrice);

    cout << "European option average price: " << averageEuro 
         << "\nAmerican option average price: " << averageAmer << "\n";
    cout << "average forward price: " << averageForward << "\n";

    cout <<"Done.\n";
	  return 0;
}