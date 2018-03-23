// C++ Design Patterns and Derivatives Pricing, Exercise 9.2, page 174

#include <iostream>
#include "Functions.h"
#include "Trapezium.h"
using namespace std;

int main()
{
	unsigned long n = 1000;

	cout << "Apply Trapezium rule for various functions.\n";
    
    Linear f1;
    double a = 0.0;
	double b = 1.0;
    double y = Trapezium<Linear>(a, b, n, f1);
	cout << "Linear function y = x (a = " << a << ", b = " << b << "): " << y << endl;

	Exponential f2;
	y = Trapezium<Function>(a, b, n, f2);
	cout << "Exponential function y = exp(x) (a = " << a << ", b = " << b << "): " << y << endl;

	Logarithmic f3;
	a = 1.0;
    b = 2.0;
	y = Trapezium<Function>(a, b, n, f3);
	cout << "Logarithmic function y = log(x) (a = " << a << ", b = " << b << "): " << y << endl;

	NormalDensity f4;
	a = -1.96;
	b = 1.96;
	y = Trapezium<Function>(a, b, n, f4);
	cout << "Normal density function y = exp(-x^2)/sqrt(2Pi) (a = " << a << ", b = " << b << "): " << y << endl;

	cout << "Done.\n";
	return 0;
}
